<?php
class Connection {
	function __construct() {
		include "config.php";

		$serverName = DB_SERVERNAME;
		$databaseName = DB_NAME;
		$username = DB_USER;
		$password = DB_PASSWORD;

		// Skapar en anslutning till databasen
		try {
			$this->dbConnection = new PDO("mysql:host=$serverName;dbname=$databaseName;charset=utf8", $username, $password);
			$this->dbConnection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		} catch(PDOException $phpError) {
			echo "Connection failed:" . $phpError->getMessage();
			die();
		}
	}

	// Returnera data från tabell och coumner enligt queryn.
	function select($query) {
		$pull = $this->dbConnection->prepare($query);
		$resultArray = array();

		$pull->execute();

		if($pull->execute()) {
			// Loopa igenom alla rader i tabellen och tryck in dessa i arrayen.
			while($result = $pull->fetch(PDO::FETCH_OBJ)) {
				array_push($resultArray, $result);
			}
		}

		return $resultArray;
	}

	//  Uppdatera databasen med information. Antingen lägga till eller ta bort rader.
	function update($query) {
		$push = $this->dbConnection->prepare($query);
		$push->execute();
	}

	private $dbConnection;
}
?>

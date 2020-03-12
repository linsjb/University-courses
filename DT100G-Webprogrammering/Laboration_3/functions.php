<?php
//Dagens datum
function todaysDate() {

	$date = date("d-m-Y H:i:s");

	$weekday = date("l");

	$text = "";

	if ( $weekday == "Friday")
	{
		$text = " - Äntligen fredag!";
	}

	$print = $date . $text;


	echo $print;
}

//Serverns IP adress
function ipAdress() {
	$ip = $_SERVER['REMOTE_ADDR'];

	echo $ip;
}

//Sökväg till den fil man står i
function filePath() {
	$file = getcwd();
	echo $file;
}

 //Information angående webbläsare osv
 function agent() {
 	$agent_string= $_SERVER['HTTP_USER_AGENT'];

 	echo $agent_string;
}
?>

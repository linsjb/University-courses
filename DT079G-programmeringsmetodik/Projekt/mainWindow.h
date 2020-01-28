/*
Filename: MainWindow.h
Created by Linus Sjöbro on 2018-01-15.
*/

#ifndef MainWindow_h
#define MainWindow_h

#include "visitDetails.h"

// core
#include <QApplication>
#include <QWidget>
#include <QtSql>
#include <QDebug>

// Layout
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

// Widgets
#include <QComboBox>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QTableView>

// Other
#include <QVector>
#include <QModelIndex>

/**
* The application's main window.
*
* Can be seen as the "index" page for the application.
*
* From here you can book new visits.
*/
class MainWindow : public QWidget {
  Q_OBJECT

  public:
    /*!
    * The parent takes ownership of the QWidget object.
    */
    explicit MainWindow(const QString &test, QPointer<QWidget> parent = nullptr);

    /*!
    * The applications content area.
    * This area contains all of the app's content.
    */
    void contentArea();

    /*!
	 * This function provides a group box framework with a title
	 */
    QGroupBox *newVisit();

    /*!
    * Fetch employees data from database table and
    * inserts it into popup list
    */
    void pullEmployees();

    /*!
    * Shows visits data from tables in the database
    */
    QSqlQueryModel *visitsTableData();

    /*!
    * Update the data for the show visits table
    */
    void visitsTableDataUpdate();

    /*!
    * Create a visits table and show the data from database
    */
    QGroupBox *visitsTable();

    void getSessionData();

    ~MainWindow();

  private slots:
    /*!
    * Pull the customer information from the SQL database.
    *
    * The customer animals is also fetched.
    */
    void slotPullCustomer();

    /*!
    * Push the information for a new visit to the database
    */
    void slotNewVisitPushData();

    /*!
    * Clear out the new visit fields after a new visit is pushed
    * and when the user want's to clear it.
    */
    void slotNewVisitClearData();

    /*!
    * Bring's upp the details for the visit the row is clicked in the table.
    */
    void slotShowVisitDetails(const QModelIndex &index);

  private:
    QPointer<VisitDetails> visitDetails;
    // Window variables
    QPointer<QHBoxLayout> mainWindowLayout;

    // New visit variables
    QPointer<QGroupBox> newVisitBox;
    QPointer<QFormLayout> newVisitLayout;

    QPointer<QLabel> newVisitOwner;

    QPointer<QCalendarWidget> newVisitCalender;

    QPointer<QLineEdit> newVisitBirtdayField;
    QPointer<QLineEdit> newVisitTimeField;

    QPointer<QComboBox> newVisitVetenarian;
    QPointer<QComboBox> newVisitAnimalsCombo;

    QPointer<QPushButton> fetchCustomerBtn;
    QPointer<QDialogButtonBox> newVisitDialogBtns;

    QPointer<QTextEdit> newVisitDescription;

    struct Animals{
      QString id;
      QString name;
    }animalsData;

    struct Employees{
      QString id;
      QString firstName;
      QString lastName;
    }employeeItems;

    QVector<Animals> animals;
    QVector<Employees> employeesVector;

    // Show visits variables
    QPointer<QGroupBox> showVisitsBox;
    QPointer<QVBoxLayout> showVisitsLayout;
    QPointer<QSqlQueryModel> showVisitsQuery;
    QPointer<QTableView> showVisitsTable;

    QString sessionData;

    QString visitsSqlQuery = "SELECT visits.ID, visits.date, visits.time, employees.firstName, breeds.typeOfAnimal, animals.name FROM visits, employees, animals, breeds WHERE visits.status = 'pending' AND visits.employeeID = employees.ID AND visits.animalID = animals.ID AND animals.breedID = breeds.ID ORDER BY visits.ID DESC";

};
#endif

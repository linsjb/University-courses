#include "mainWindow.h"

MainWindow::MainWindow(const QString &sessionData, QPointer<QWidget> parent):
QWidget(parent), sessionData(sessionData) {
  QSqlDatabase vetClinDb = QSqlDatabase::database();
  setWindowTitle("vetCLin");
  setWindowState(this->windowState() ^ Qt::WindowMaximized);
  contentArea();
  pullEmployees();
}

void MainWindow::contentArea() {
  mainWindowLayout = new QHBoxLayout;
  // Left column of layout
  mainWindowLayout->addWidget(newVisit());

  // Right column of layout
  mainWindowLayout->addWidget(visitsTable());

  this->setLayout(mainWindowLayout);
}

QGroupBox *MainWindow::newVisit() {
  newVisitBox = new QGroupBox("Boka nytt besök", this);
  fetchCustomerBtn = new QPushButton("Hämta", newVisitBox);

  newVisitBirtdayField = new QLineEdit(newVisitBox);
  newVisitBirtdayField->setPlaceholderText("Ange personnummer");

  newVisitTimeField = new QLineEdit(newVisitBox);
  newVisitTimeField->setPlaceholderText("Ange besökstid");

  newVisitVetenarian = new QComboBox(newVisitBox);

  newVisitAnimalsCombo = new QComboBox(newVisitBox);

  newVisitCalender = new QCalendarWidget(newVisitBox);

  newVisitDescription = new QTextEdit(newVisitBox);
  newVisitDescription->setPlaceholderText("Ange besöksbeskrivning");

  newVisitOwner = new QLabel(newVisitBox);

  newVisitDialogBtns = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

  newVisitLayout = new QFormLayout;
  newVisitLayout->addRow("Personnummer", newVisitBirtdayField);
  newVisitLayout->addRow("Hämta person", fetchCustomerBtn);
  newVisitLayout->addRow("Ägare", newVisitOwner);
  newVisitLayout->addRow("Djur", newVisitAnimalsCombo);
  newVisitLayout->addRow("Veterinär", newVisitVetenarian);
  newVisitLayout->addRow("Datum", newVisitCalender);
  newVisitLayout->addRow("Tid", newVisitTimeField);
  newVisitLayout->addRow("Beskrivning", newVisitDescription);
  newVisitLayout->addRow(newVisitDialogBtns);
  //Take care of how the form field grow (grow to fill the available spaces)
  newVisitLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

  newVisitBox->setLayout(newVisitLayout);

  connect(fetchCustomerBtn,     SIGNAL(clicked()),  this, SLOT(slotPullCustomer()));
  connect(newVisitDialogBtns,   SIGNAL(accepted()), this, SLOT(slotNewVisitPushData()));
  connect(newVisitDialogBtns,   SIGNAL(rejected()), this, SLOT(slotNewVisitClearData()));

  return newVisitBox;
}

QSqlQueryModel *MainWindow::visitsTableData() {
  showVisitsQuery = new QSqlQueryModel;
  showVisitsQuery->setQuery(visitsSqlQuery);
  showVisitsQuery->setHeaderData(0, Qt::Horizontal, "Datum");
  showVisitsQuery->setHeaderData(1, Qt::Horizontal, "Datum");
  showVisitsQuery->setHeaderData(2, Qt::Horizontal, "Tid");
  showVisitsQuery->setHeaderData(3, Qt::Horizontal, "Veterinär");
  showVisitsQuery->setHeaderData(4, Qt::Horizontal, "Djur");
  showVisitsQuery->setHeaderData(5, Qt::Horizontal, "Djuret namn");

  return showVisitsQuery;
}

QGroupBox *MainWindow::visitsTable() {
  showVisitsBox = new QGroupBox("Bokade besök", this);


  // Create the table and show the data from the query
  showVisitsTable = new QTableView;
  showVisitsTable->setModel(visitsTableData());
  showVisitsTable->setShowGrid(false);
  showVisitsTable->show();

  //Create vertical layout
  showVisitsLayout = new QVBoxLayout;
  showVisitsLayout->addWidget(showVisitsTable);
  showVisitsBox->setLayout(showVisitsLayout);
  //Integrate with table from database
  connect(showVisitsTable,SIGNAL(clicked(const QModelIndex &)),this,SLOT(slotShowVisitDetails(const QModelIndex &)));

  return showVisitsBox;
}

void MainWindow::slotShowVisitDetails(const QModelIndex &index) {
  if (index.isValid()) {
      if(index.column() == 0) {
          visitDetails = new VisitDetails(index.data().toString());
          visitDetails->show();
        }
    }
}

void MainWindow::visitsTableDataUpdate() {
  // Update the query by select the data from the db again.
  // Not the best way to do it. But it works
  showVisitsQuery->setQuery(visitsSqlQuery);
}

void MainWindow::pullEmployees() {
  QSqlQuery employees;
  employees.exec("SELECT ID, firstName, lastName FROM employees");

  while(employees.next()) {
    employeeItems.id = employees.value(0).toString();
    employeeItems.firstName = employees.value(1).toString();
    employeeItems.lastName = employees.value(2).toString();

    newVisitVetenarian->addItem(employeeItems.firstName + " " + employeeItems.lastName);
  }
}

void MainWindow::slotPullCustomer() {
  QString birthDayField = newVisitBirtdayField->text();

  if(birthDayField.isEmpty()) {
      QMessageBox::warning(this, "", "Personnummer saknas");
  } else {
      if(newVisitAnimalsCombo->count() > 0) {
          newVisitAnimalsCombo->clear();
      }

    QSqlQuery pullCustomer;
    pullCustomer.exec("SELECT animals.ID, animals.name, customers.name FROM animals, customers WHERE customers.ID=" + birthDayField + " AND animals.customerID = customers.ID");

    if(pullCustomer.next()) {
        newVisitOwner->setText(pullCustomer.value(2).toString());
    }

    while(pullCustomer.next()) {
      animalsData.id = pullCustomer.value(0).toString();
      animalsData.name = pullCustomer.value(1).toString();
      animals.push_back(animalsData);

      newVisitAnimalsCombo->addItem(animalsData.name);
    }
  }
}

void MainWindow::slotNewVisitPushData() {
  QString choosenAnimal =  animals.at(newVisitAnimalsCombo->currentIndex()).id;
  QString choosenDate = newVisitCalender->selectedDate().toString("yyyy-MM-dd");
  QString choosenTime = newVisitTimeField->text();
  QString choosenDesc = newVisitDescription->toPlainText();
  int choosenVet = newVisitVetenarian->currentIndex()+1;

  QSqlQuery pushNewVisit;
  pushNewVisit.prepare("INSERT INTO visits(date, time, description, status, animalID, employeeID) VALUES (:date, :time, :description, :status, :animalID, :employeeID)");
  pushNewVisit.bindValue(":date", choosenDate);
  pushNewVisit.bindValue(":time", choosenTime);
  pushNewVisit.bindValue(":description", choosenDesc);
  pushNewVisit.bindValue(":status", "pending");
  pushNewVisit.bindValue(":animalID", choosenAnimal);
  pushNewVisit.bindValue(":employeeID", choosenVet);
  pushNewVisit.exec();

  // Update the table after the insertion to the SQL database is completed.
  visitsTableDataUpdate();
}

void MainWindow::slotNewVisitClearData() {
  newVisitBirtdayField->setText("");
  newVisitTimeField->setText("");
  newVisitDescription->setPlainText("");
  newVisitAnimalsCombo->clear();
}

MainWindow::~MainWindow() {
    qDebug() << "Main window destroyed";
}

/*
Filename: visitDetails.cpp
Created by Linus Sjöbro on 2018-01-18.
*/

#include "visitDetails.h"

VisitDetails::VisitDetails(QString setId, QPointer<QDialog> parent):
QDialog(parent), id(setId) {
  QSqlDatabase vetClinDb = QSqlDatabase::database();
  setWindowState(this->windowState() ^ Qt::WindowMaximized);
  pullData();
  fetchPrescriptionsData();
  layout();
}

void VisitDetails::layout() {
  mainLayout = new QHBoxLayout;
  mainLayout->addLayout(leftLayout());
  mainLayout->addLayout(rightLayout());
  this->setLayout(mainLayout);
}

QFormLayout *VisitDetails::leftLayout() {
    leftFormLayout = new QFormLayout;

    visitDescription = new QPlainTextEdit;
    visitDescription->setPlaceholderText("Ange beskrivning");

    statusComboBox = new QComboBox;
    statusComboBox->addItem("Done");
    statusComboBox->addItem("Pending");

   for(int i = 0; i < infoDataItems; i++) {
     leftFormLayout->addRow(visitInfoLabels[i], visitInfoData[i]);
   }

   leftFormLayout->addRow("Status", statusComboBox);
   leftFormLayout->addRow(visitDescription);

   return leftFormLayout;
}

QVBoxLayout *VisitDetails::rightLayout() {
    prescriptionLabel = new QLabel("Medicin & behandlingar");
    prescriptionTable = new QTableView;
    prescriptionTable->setModel(fetchPrescriptionsData());
    prescriptionTable->show();

    prescriptionTypeComboBox = new QComboBox;
    prescriptionTypeComboBox->addItem("Medicin");
    prescriptionTypeComboBox->addItem("Behandling");

    prescriptionIdField = new QLineEdit(rightLayoutGroupBox);
    prescriptionIdField->setPlaceholderText("Ange ID");

    addPrescriptionBtn = new QPushButton("Lägg till", rightLayoutGroupBox);

    gridFormLayout = new QFormLayout;
    gridFormLayout->addRow("Typ",prescriptionTypeComboBox);
    gridFormLayout->addRow("ID",prescriptionIdField);
    gridFormLayout->addRow(addPrescriptionBtn);

    rightLayoutGroupBox = new QGroupBox("Lägg till medicin/behandling");
    rightLayoutGroupBox->setLayout(gridFormLayout);

    boxBtns = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel);


    rightBoxLayout = new QVBoxLayout;
    rightBoxLayout->addWidget(prescriptionLabel);
    rightBoxLayout->addWidget(prescriptionTable);
    rightBoxLayout->addWidget(rightLayoutGroupBox);
    rightBoxLayout->addWidget(boxBtns);

    connect(addPrescriptionBtn,     SIGNAL(clicked()),  this, SLOT(slotPushPrescriptionsData()));
    connect(boxBtns,                SIGNAL(accepted()), this, SLOT(slotPushVisitData()));
    connect(boxBtns,                SIGNAL(rejected()), this, SLOT(reject()));

    return rightBoxLayout;
}

QSqlQueryModel *VisitDetails::fetchPrescriptionsData() {
    QString select1 ="SELECT 'Med', medications.ID, medications.name, medications.price";
    QString from1 ="FROM visits, visits_medications, medications";
    QString where1 =" WHERE visits.ID= " + id + " AND visits.ID = visits_medications.visitID AND visits_medications.medicationID = medications.ID";
    QString select2 ="SELECT 'Beh', treatments.ID, treatments.name, treatments.price";
    QString from2 = "FROM visits, visits_treatments, treatments";
    QString where2 = "WHERE visits.ID= " + id + " AND visits.ID = visits_treatments.visitID AND visits_treatments.treatmentID = treatments.ID";

    fetchPrescriptions = new QSqlQueryModel;
    fetchPrescriptions->setQuery(select1 + " " + from1 + " " + where1 + " UNION " + select2 + " " + from2 + " " + where2);
    fetchPrescriptions->setHeaderData(0, Qt::Horizontal, "Typ");
    fetchPrescriptions->setHeaderData(1, Qt::Horizontal, "ID");
    fetchPrescriptions->setHeaderData(2, Qt::Horizontal, "Namn");
    fetchPrescriptions->setHeaderData(3, Qt::Horizontal, "Pris");

    return fetchPrescriptions;
}


void VisitDetails::pullData() {
  QSqlQuery pullVisitInformation;
  QString select = "SELECT customers.name, animals.name, animals.dateofBirth, breeds.typeOfAnimal, breeds.name, visits.description";
  QString from = "FROM visits, animals, customers, breeds";
  QString where = "WHERE visits.ID=:id AND visits.animalID = animals.ID AND animals.customerID = customers.ID AND animals.breedID = breeds.ID";

  pullVisitInformation.prepare(select + " " + from + " " + where);
  pullVisitInformation.bindValue(":id", id);
  pullVisitInformation.exec();

  while(pullVisitInformation.next()) {
    for(int i = 0; i < infoDataItems; i++) {
      visitInfoData[i] = new QLabel(pullVisitInformation.value(i).toString());
    }
  }
}


void VisitDetails::slotPushVisitData() {
    QString description = visitDescription->toPlainText();

    QSqlQuery pushData;
    pushData.prepare("UPDATE visits SET visitDescription=:visitDes, status=:status WHERE ID=:id");
    pushData.bindValue(":visitDes", visitDescription->toPlainText());
    pushData.bindValue(":status", statusComboBox->currentText());
    pushData.bindValue(":id", id);
    pushData.exec();
}


void VisitDetails::slotPushPrescriptionsData() {
    QSqlQuery pushNewPrescription;

    if(prescriptionTypeComboBox->currentText() == "Medicin") {
        pushNewPrescription.prepare("INSERT INTO visits_medications VALUES (:id, :prescriptId)");
    } else {
        pushNewPrescription.prepare("INSERT INTO visits_treatments VALUES (:id, :prescriptId)");
    }
    pushNewPrescription.bindValue(":id", id);
    pushNewPrescription.bindValue(":prescriptId", prescriptionIdField->text());
    pushNewPrescription.exec();

    // Clear the fiels data
    prescriptionIdField->text() = "";
}

VisitDetails::~VisitDetails() {
}

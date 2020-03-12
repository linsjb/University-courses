/*
Filename: visitDetails.h
Created by Linus Sjöbro on 2018-01-18.
*/

#ifndef VisitDetails_h
#define VisitDetails_h

// Core
#include <QDialog>
#include <QWidget>
#include <QtSql>

// Layout
#include <QGroupBox>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>

// Widgets
#include <QDialogButtonBox>
#include <QPushButton>
#include <QTableView>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QPlainTextEdit>

class VisitDetails : public QDialog {
  Q_OBJECT

  public:
    explicit VisitDetails(QString setId, QPointer<QDialog> parent = nullptr);

    /*!
    * Fetch the prescriptions data for the visit when the visit details is opened.
    */
    QSqlQueryModel *fetchPrescriptionsData();

    /*!
    * The dialog's structure.
    */
    void layout();

    /*!
    * Left column of the layout
    */
    QFormLayout *leftLayout();

    /*!
    * Right column of the layout
    */
    QVBoxLayout *rightLayout();

    /*!
    * Pull the selected data from the database and display it in the dialog when the visit details is opened
    */
    void pullData();

    ~VisitDetails();

  private slots:
    /*!
    * Push new prescription data for the visit to the database.
    *
    * Either a medical presscription or treatment is pushed, depending on the value of @variable prescriptionTypeComboBox.
    */
    void slotPushPrescriptionsData();

    /*!
    * Push added data for the visit to the visit record in the SQL database.
    */
    void slotPushVisitData();

  private:
    enum {
      infoDataItems = 6
    };

    QPointer<QFormLayout> leftFormLayout;
    QPointer<QVBoxLayout> rightBoxLayout;
    QPointer<QFormLayout> gridFormLayout;
    QPointer<QHBoxLayout> mainLayout;
    QPointer<QGroupBox> rightLayoutGroupBox;
    QString id;

    QPointer<QComboBox> statusComboBox;
    QPointer<QComboBox> prescriptionTypeComboBox;

    QPointer<QTableView> prescriptionTable;
    QPointer<QLabel> prescriptionLabel;   
    QPointer<QLineEdit> prescriptionIdField;

    QPointer<QPlainTextEdit> visitDescription;

    QPointer<QPushButton> addPrescriptionBtn;
    QPointer<QDialogButtonBox> boxBtns;

    QPointer<QLabel> visitInfoData[infoDataItems];

    QPointer<QSqlQueryModel> fetchPrescriptions;

    const QString visitInfoLabels[infoDataItems] = {
      "Ägare: ",
      "Djurets namn: ",
      "Födelsedatum: ",
      "Djurtyp: ",
      "Ras: ",
      "Beskrivning: "
    };
};

#endif

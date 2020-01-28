
#include "login.h"
#include "mainWindow.h"
#include "visitDetails.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

void databaseConnection();

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    databaseConnection();
    Login login;
    login.show();
//    MainWindow mainW("Linus");
//    mainW.show();

//    VisitDetails vd;
//    vd.show();

    return app.exec();
  }

void databaseConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setConnectOptions();
    db.setHostName("127.0.0.1");
    db.setDatabaseName("vetClin");
    db.setUserName("root");
    db.setPassword("");
}

#include "login.h"

Login::Login(QPointer<QWidget> parent):
QDialog(parent) {
    // Attributes for dialog
    setWindowTitle("Login");

    QSqlDatabase vetClinDb = QSqlDatabase::database();
    createLoginWindow();
}

void Login::createLoginWindow() {
    username = new QLineEdit("", this);
    password = new QLineEdit("", this);
    password->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Logga in", this);

    // Connect the button to the slot method
    connect(loginButton, SIGNAL(clicked()), this, SLOT(slotButtonLoginClicked()));

    formLayout = new QFormLayout;
    formLayout->addRow ("Användarnamn", username);
    formLayout->addRow ("Lösenord", password);
    formLayout->addRow (loginButton);

    this->setLayout(formLayout);
}

void Login::slotButtonLoginClicked() {
    QSqlQuery pullLogin;

    pullLogin.prepare("SELECT employees.firstName from logins, employees WHERE logins.username=:username AND logins.password=:password AND logins.employeeID = employees.ID");
    pullLogin.bindValue(":username", username->text());
    pullLogin.bindValue(":password", password->text());
    pullLogin.exec();

        if(username->text().isEmpty() || password->text().isEmpty()) {
            QMessageBox::warning(this,"Login", "Tom fält!");
        }
        else if(pullLogin.size() > 0) {
            while(pullLogin.next()) {
            this->close();

            main = new MainWindow(pullLogin.value(0).toString());
            main->show();
            }
        } else {
            QMessageBox::warning(this,"Login", "Inkorrekt användarnamn och lösenord");
        }
}

Login::~Login() {
    qDebug() << "Login destroyed";
}

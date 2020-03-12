#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QObject>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QFormLayout>
#include <QMessageBox>

#include "mainWindow.h"

/*!
* Login window with SQL database connection.
*
* When login is done the window will close and open up main window
*/
class Login: public QDialog {
	/*!
	 * Tells pre-compiler that this class has to run through the 'moc'.
     *
     * Use the signal/slot mechanism.'
     *
	 * Base class of all Qt objects.
	 */
    Q_OBJECT
public:
	/*!
	 * The parent takes ownership of the QDialog object
     *
	 * and executes the other functions that show the login content
	 */
    explicit Login(QPointer<QWidget> parent = nullptr);

	/*!
	 * Creates all the content that shows on the login window
	 */
    void createLoginWindow();
    ~Login();

private:
    QPointer<QPushButton> loginButton;
    QPointer<QLineEdit> username;
    QPointer<QLineEdit> password;
    QPointer<QVBoxLayout> layout;
    QPointer<MainWindow> main;
    QPointer<QFormLayout> formLayout;

private slots:
	/*!
     * Method for login button
     *
     * When called the information from the text-fields will be matched to the right database record.
     *
     * If it exists the login will proceed.
	 */
    void slotButtonLoginClicked();
};

#endif // LOGIN_H

/* global QApplication */
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(1200, 800);
    window.setWindowTitle("Linus Testar 2.0");

    QPushButton *button = new QPushButton("Test button", &window);

    window.show();
    return app.exec();
}

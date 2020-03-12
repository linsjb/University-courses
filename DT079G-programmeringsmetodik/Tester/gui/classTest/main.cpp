#include <QApplication>
#include "window.h"

int main (int argc, char **argv) {
  QApplication app (argc, argv);

  window window;
  window.show();

  return app.exec();
}

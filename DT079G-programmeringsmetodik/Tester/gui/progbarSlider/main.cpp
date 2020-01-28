#include <QApplication>
#include <QProgressBar>
#include <QSlider>


int main(int argc, char **argv) {
  QApplication app (argc, argv);

 // Create a container window
 QWidget window;
 window.setFixedSize(200, 80);

  // Create the progress bar
  QProgressBar *bar = new QProgressBar(&window);
  bar->setRange(0, 100);
  bar->setValue(0);
  bar->setGeometry(10, 10, 180, 30);

  // Create the slider
  QSlider *slider = new QSlider(&window);
  slider->setOrientation(Qt::Horizontal);
  slider->setRange(0, 100);
  slider->setValue(0);
  slider->setGeometry(10, 40,180, 30);

  window.show();

  // Connect the slider to the progressbar
  QObject::connect(slider, SIGNAL (valueChanged(int)), bar, SLOT(setValue(int)));
  return app.exec();
}

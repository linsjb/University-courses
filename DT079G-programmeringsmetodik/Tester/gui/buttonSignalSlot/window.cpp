/*
Filename: window.cpp
Created by Linus Sjöbro on 2018-01-12.
*/

#include "window.h"
#include <QApplication>
#include <QPushButton>

window::window(QWidget *parent) : QWidget(parent) {
  setFixedSize(500,500);

  m_button = new QPushButton("Quit", this);

  // Do the connection with the buttons signal and applications slot that quits the app.
  connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

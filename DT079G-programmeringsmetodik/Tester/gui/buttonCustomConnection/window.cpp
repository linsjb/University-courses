/*
Filename: window.cpp
Created by Linus Sjöbro on 2018-01-12.
*/

#include "window.h"
#include <QApplication>
#include <QPushButton>

window::window(QWidget *parent) : QWidget(parent) {
  setFixedSize(500,500);

  m_button = new QPushButton("Click me", this);
  m_button->setCheckable(true);
  connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
}

void window::slotButtonClicked(bool checked) {
  if(checked) {
    m_button->setText("Checked");
  } else {
    m_button->setText("Uncheked");
  }
}

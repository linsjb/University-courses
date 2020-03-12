/*
Filename: window.h
Created by Linus Sjöbro on 2018-01-12.
*/

#ifndef window_h
#define window_h

#include <QWidget>

class QPushButton;

class window : public QWidget {
public:
  explicit window(QWidget *parent = 0);

private:
  QPushButton *m_button;
};

#endif
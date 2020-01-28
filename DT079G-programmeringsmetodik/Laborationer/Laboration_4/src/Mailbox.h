//
//  Mailbox.h
//  DT079G-programmeringsmetodik
//
//  Created by <author> on 2018/06/07.
//
//

#ifndef Mailbox_h
#define Mailbox_h

#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Mail.h"

class Mailbox {
public:
    Mailbox(size_t size):
    mailboxVector(size) {}

    friend class Mail;

    void sendMail(Mail& mail);
    void receiveMail();
    void sortWho();
    void sortDate();
    void sortSubject();

private:
  std::vector<Mail> mailboxVector;
};


inline void Mailbox::sendMail(Mail& mail) {
  mailboxVector.push_back(mail);
}

inline void Mailbox::receiveMail() {
  for(auto e: mailboxVector) {
    std::cout << e << '\n';
  }
}

inline void Mailbox::sortWho() {
  std::sort(mailboxVector.begin(), mailboxVector.end(), CompWhoDateSubject());
}

inline void Mailbox::sortDate() {
  std::sort(mailboxVector.begin(), mailboxVector.end(), CompDateWhoSubject());
}

inline void Mailbox::sortSubject() {
  std::sort(mailboxVector.begin(), mailboxVector.end(), CompSubjectWheDate());
}


#endif

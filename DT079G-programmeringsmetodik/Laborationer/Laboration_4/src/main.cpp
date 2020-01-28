#include "Mail.h"
#include "Mailbox.h"

void showMail(const vector<Mail> & object) {
  for(auto &e: obj) {
    std::cout << e << '\n';
  }
}

int main(int argc, char const *argv[]) {

  Mail b("b", "1990-01-02", "subject2");
  Mail e("e", "1990-01-05", "subject5");
  Mail a("a", "1990-01-01", "subject1");
  Mail c("c", "1990-01-03", "subject3");
  Mail d("d", "1990-01-04", "subject4");

  Mailbox box(3);

  box.sendMail(b);
  box.sendMail(a);
  box.sendMail(e);
  box.sendMail(d);
  box.sendMail(c);

  // box.sortSubject();
  // box.sortWho();
  box.sortDate();

  box.receiveMail();
  return 0;
}

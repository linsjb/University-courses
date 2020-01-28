//  Mail.h
//  DT079G-programmeringsmetodik
//  Created by Linus Sjöbro on 2018/06/07.

#ifndef Mail_h
#define Mail_h

#include <stdio.h>
#include <string>
#include <iostream>

class Mail {
public:
	Mail() : Mail(" ", " ", " ") {};
	Mail(std::string name, std::string date, std::string subject):
  who(name), date(date), subject(subject) {};

	friend class CompWhoDateSubject;
	friend class CompDateWhoSubject;
	friend class CompSubjectWheDate;

	friend std::ostream &operator<<(std::ostream &output, const Mail &message);
	friend std::istream &operator>>(std::istream &input, Mail &message);

private:
	std::string who;
	std::string date;
	std::string subject;
};

std::ostream &operator<<(std::ostream &output, const Mail &message) {
	output << "Mail: " << message.who << " " << message.date << " " << message.subject << std::endl;
	return output;
}

std::istream &operator>>(std::istream &input, Mail &message) {
	input >> message.who >> message.date >> message.subject;
	return input;
}

class CompWhoDateSubject {
public:
	bool operator()(const Mail& lhs, const Mail& rhs) {
		if (lhs.who == rhs.who) {
			if (lhs.date == rhs.date) {
				return lhs.subject < rhs.subject;
			} else {
				return lhs.date < rhs.date;
			}
		} else {
			return lhs.who < rhs.who;
		}
	};
};

class CompSubjectWheDate {
public:
	bool operator()(const Mail& lhs, const Mail& rhs) {
		if (lhs.subject == rhs.subject) {
			if (lhs.who == rhs.who) {
				return lhs.date < rhs.date;
			} else {
				return lhs.who < rhs.who;
			}
		} else {
			return lhs.subject < rhs.subject;
		}
	};
};

class CompDateWhoSubject {
public:
	bool operator()(const Mail& lhs, const Mail& rhs) {
		if (lhs.date == rhs.date) {
			if (lhs.who == rhs.who) {
				return lhs.subject < rhs.subject;
			} else {
				return lhs.who < rhs.who;
			}
		} else {
			return lhs.date < rhs.date;
		}
	};
};

#endif

#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

struct Token {
    enum id {
      ID, ADD, STAR, ANY, LOWERCASE, END_PROGRAM,
      LEFT_PARENTESIS, RIGHT_PARENTESIS,
      LEFT_BRACKET, RIGHT_BRACKET
    };
    id id;
    std::string text;
};

using stringIterator = std::string::iterator;

Token next_token(stringIterator& first, stringIterator last) {
  while (std::isspace(*first)) {
    first++;
  }

  if(first == last) {
    return {Token::END_PROGRAM, ""};
  }

  Token token;

  switch (*first) {
    case '+':
      token = {Token::ADD, "+"};
      break;

    case '*':
      token = {Token::STAR, "*"};
      break;

    case '.':
      token = {Token::ANY, "."};
      break;

    case 'I':
      token = {Token::LOWERCASE, "/"};
      break;

    case '(':
      token = {Token::LEFT_PARENTESIS, "("};
      break;

    case ')':
      token = {Token::RIGHT_PARENTESIS, ")"};
      break;

    case '{':
      token = {Token::LEFT_BRACKET, "{"};
      break;

    case '}':
      token = {Token::RIGHT_BRACKET, "}"};
      break;

    default:
      token = {Token::ID, std::string(first, first + 1)};
      break;
  };

  return token;
}
#endif

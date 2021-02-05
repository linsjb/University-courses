#include "headers/parser.h"

Parser::Parser(std::string regexArgument) {
    this->regexArgument = regexArgument;
}

void Parser::setPayload(std::string payload) {
    this->payload = payload;
}
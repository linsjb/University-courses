#ifndef parser_h
#define parser_h

#include <iostream>

class Parser {
private:
    std::string regexArgument;
    std::string payload;

public:
    Parser(std::string regexArgument);

    void setPayload(std::string payload);
};

#endif
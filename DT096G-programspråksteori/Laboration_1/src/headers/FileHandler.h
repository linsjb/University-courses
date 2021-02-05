#ifndef FileHandler_h
#define FileHandler_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

class FileHandler {
private:
  std::fstream file;
  std::string filename;

public:
    FileHandler(std::string filename);
    ~FileHandler();

    std::string readFile();
};

#endif

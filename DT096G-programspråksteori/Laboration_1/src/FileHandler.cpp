#include "headers/FileHandler.h"

FileHandler::FileHandler(std::string filename)  {
  this->filename = filename;
  file.open(this->filename);
}

std::string FileHandler::readFile() {
  if(file.is_open()) {
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  } else {
    std::cout << "File " << this->filename << " does not exist or can't open \n";
    return "";
  }
}

FileHandler::~FileHandler() {
  file.close();
}

#include <exception>

#pragma once

class ParseException : public std::exception {
public:
  virtual const char *what() { return "Parsing error!"; }
};

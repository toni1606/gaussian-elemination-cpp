#include <exception>

class ParseException : public std::exception {
public:
  virtual const char *what() { return "Parsing error!"; }
};

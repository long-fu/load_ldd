#include <string>

class Base {
 public:
  virtual std::string readLine(const std::string &) = 0;

  virtual ~Base() = default;
};
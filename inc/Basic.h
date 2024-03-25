#include <string>

class Base
{
public:
    virtual int Init() = 0;
    virtual int Process() = 0;
    virtual int Deinit() = 0;
    virtual std::string readLine(const std::string &) = 0;

    virtual ~Base() = default;
};
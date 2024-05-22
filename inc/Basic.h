#include <string>

class Base
{
public:
    int data_value{0};
public:
    virtual int Run() {
        printf("Run In bash");
    }

    virtual int Init() {
        printf("Run Init");
    };
    virtual int Process() {
        printf("Process");
    };
    virtual int Deinit() {
        printf("Deinit");
    };
    virtual std::string readLine(const std::string &) {
        printf("readLine");
    };

    virtual ~Base() = default;
};
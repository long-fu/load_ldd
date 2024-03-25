#include <iostream>
#include <string>

#include "Basic.h"

class Module1:public Base
{
private:
    /* data */
public:
    Module1(/* args */);
    virtual int Init();
    virtual int Deinit();
    virtual int Process();
    virtual std::string readLine(const std::string &);
    ~Module1();
};

//必须实现 moduleName_create 函数,来初始化对象
extern "C" Base *module1_create() {
    return new Module1;
}

//必须实现 moduleName_destroy 函数,来回收对象
extern "C" void module1_destroy(Base *obj) {
    delete obj;
}
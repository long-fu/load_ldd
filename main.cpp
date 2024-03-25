#include <iostream>
#include "Basic.h"
#include <dlfcn.h>

// 声明创建对象的函数
typedef Base *(*create)();

// 声明回收对象的函数
typedef void (*destroy)(Base *);

void *loadLib(Base **base, const char *path, const char *funName)
{
    auto handle = dlopen(path, RTLD_LAZY);
    if (!handle)
    {
        return nullptr;
    }
    auto cr = (create)dlsym(handle, funName);
    if (cr)
    {
        *base = cr();
    }
    return handle;
}

// 调用系统函数,卸载动态库
void freeLib(void *handle, Base *obj, const char *funName)
{
    auto free = (destroy)dlsym(handle, funName);
    if (free)
    {
        free(obj);
    }
    dlclose(handle);
}

int main(int, char **)
{
    std::string libPath;
    libPath = std::string("/media/haoshuai/T7/code/load_ldd/build/model/libmodel.so");
    Base *module = nullptr;
    auto handle = loadLib(&module, libPath.c_str(), std::string("module1_create").c_str());

    if (!module)
    {
        std::cout << "load lib module1"
                  << " fail" << std::endl;
        return 1;
    }
    std::cout << module->readLine("abc") << std::endl;

    freeLib(handle,module,"module1_destroy");
}

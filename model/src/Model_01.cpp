#include "Model_01.h"

Module1::Module1(/* args */)
{
}

int Module1::Init() {
    // 初始化数据
    return 0;
}

int Module1::Deinit() {
    // 释放数据
    return 0;
}

int Module1::Process() {
    // 同步
    // 异步
    // 处理获取数据
    return 0;
}

std::string Module1::readLine(const std::string & txt) {

    return "model 01 return " + txt;
}

Module1::~Module1()
{
}



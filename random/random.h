#include <random>

#ifndef _random_H_
#define _random_H_


int randomNum() {
    //定义随机数引擎和分布
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-100,100);
        
    //生成随机数
    return distrib(gen);
    }

#endif


//整型浮点转换损失精度,
#include <iostream>
#include <cstdlib>
using namespace std;

typedef unsigned long long uint64;

int main()
{
    // int money = 0;
    std::string strMoney = "";
    float money = 0;
    strMoney = "35884819";
    money = atof(strMoney.c_str());
    cout << money << "," << (int) static_cast<float>(money) << "," << (int)(float)money << std::endl;

    strMoney = "8388607";
    money = atof(strMoney.c_str());
    cout << money << "," << (int)static_cast<float>(money) << "," << (int)(float)money << std::endl;

    strMoney = "33554431";
    money = atof(strMoney.c_str());
    cout << money << "," << (int)static_cast<float>(money) << "," << (int)(float)money << std::endl;

    strMoney = "67108863";
    money = atof(strMoney.c_str());
    cout << money << "," << (int)static_cast<float>(money) << "," << (int)(float)money << std::endl;

    getchar();
    return 0;
}
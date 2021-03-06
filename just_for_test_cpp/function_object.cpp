//一个关于可调用对象（callable-object）的demo
//TODO: C++11加入了std::function，可以考虑添加一段代码

#include <iostream>
#include <synchapi.h>
#include <string>

using namespace std;

//C风格回调函数（函数指针）
void getin( void (*functionA)(), void (*functionB)() )
{
    string in;
    cin >> in;
    if (in == "a")functionA();
    else functionB();
}

//C++风格仿函数（函数对象）
class printC
{
public:
    printC(int a) :_a(a) {};
    void operator () ()
    {
        if(_a == 0)cout << "class printC" << endl;
        else cout << "no output!" << endl;
    }
private:
    int _a;
};

void printA()
{
    cout << "input a !" << endl;
}

void printB()
{
    cout << "input not a !" << endl;
}

//模板函数既可以接受函数指针，也可以接受函数对象
template<typename T>
void putout(T t)
{
    t();
}

int main()
{
    while (1)
    {
        getin(printA, printB);
        putout(printC(0));
        putout(printC(1));
        putout(printA);
        Sleep(1);
    }
    return 0;
}

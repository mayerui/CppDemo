//重载Overload和重写Override的DEMO

#include <iostream>

using namespace std;

class Father
{
  public:
    void eat() { cout << "father eat" << endl; };
    void eat(const string &food) { cout << "father eat " << food.c_str() << endl; }; //重载
    virtual void seat() { cout << "father seat" << endl; };
};

class Son : public Father
{
  public:
    void eat(const string &food) { cout << "son eat " << food.c_str() << endl; };
    virtual void seat() { cout << "son seat" << endl; };
};

int main()
{
    Father father;
    Son son;
    father.eat();
    father.eat("meat");
    father.seat();
    //son.eat();//“Son::eat”: 函数不接受 0 个参数
    son.eat("meat");
    son.seat();

    Father *pfather = new Father();
    Father *pson = new Son();
    pfather->eat();
    pfather->eat("meat");
    pfather->seat();
    pson->eat();
    pson->eat("meat");
    pson->seat();
    //((Son*)pson)->eat();//“Son::eat”: 函数不接受 0 个参数
    ((Son *)pson)->eat("meat");
    ((Son *)pson)->seat();

    getchar();

    return 0;
}
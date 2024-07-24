//一个可以实现装载成员函数的命令模式DEMO
#include <iostream>

using namespace std;

template <class Receiver>
class Command
{
    typedef void (Receiver::*Action)();

  public:
    Command(Receiver *r, Action a) : _r(r), _a(a){};
    void execute() { (_r->*_a)(); }

  private:
    Receiver *_r;
    Action _a;
};

class Receiver
{
  public:
    void action() { cout << "action" << endl; }
};

int main()
{
    Receiver r;
    Command<Receiver> c(&r, &Receiver::action);
    c.execute();
}
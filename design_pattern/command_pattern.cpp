//一个可以实现装载成员函数的命令模式DEMO
#include <iostream>

using namespace std;

template <class Reciever>
class Command
{
    typedef void (Reciever::*Action)();

  public:
    Command(Reciever *r, Action a) : _r(r), _a(a){};
    void execute() { (_r->*_a)(); }

  private:
    Reciever *_r;
    Action _a;
};

class Reciever
{
  public:
    void action() { cout << "action" << endl; }
};

int main()
{
    Reciever r;
    Command<Reciever> c(&r, &Reciever::action);
    c.execute();
}
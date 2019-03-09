//RAII-shared_ptr
#include <iostream>
#include <memory>

using namespace std;

class test
{
  public:
    test() { cout << "test" << endl; }
    ~test() { cout << "~test" << endl; }
};

class F1
{
  public:
    F1()
    {
        t = make_shared<test>();
    }

    void reset()
    {
        t = nullptr;
    }

  private:
    shared_ptr<test> t;
};

int main()
{
    F1 f;
    f.reset();
    getchar();
    return 0;
}
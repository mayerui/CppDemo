#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;

class CBaseThread
{
  public:
    void run()
    {
        _beginthreadex(nullptr, 1000, &thread_func, this, 0, nullptr);
    }

  protected:
    virtual void real_func() = 0;

  private:
    static unsigned int _stdcall thread_func(void *param)
    {
        CBaseThread *pthis = (CBaseThread *)param;

        while (1)
        {
            Sleep(1000);
            pthis->real_func();
        }
    }
};

class A : public CBaseThread
{
  protected:
    void real_func()
    {
        cout << "a";
    }
};

class B : public CBaseThread
{
  protected:
    void real_func()
    {
        cout << "b";
    }
};

class C : public CBaseThread
{
  protected:
    void real_func()
    {
        cout << "c";
    }
};

int main(int argc, char *argv[])
{
    char *arg = argv[1];

    A a;
    a.run();

    if (1)
    {
        B b;
        b.run();
    }
    else
    {
        C c;
        c.run();
    }

    while (1)
    {
        Sleep(1000);
    }

    return 0;
}
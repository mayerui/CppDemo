//C++部分函数调用形式耗时测试C++部分函数调用形式耗时测试
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <sys/timeb.h>
#include <sys/types.h>

long long getSystemTime()
{
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}

unsigned long long int g_count = 0;

const unsigned int max = 10000000000;

template <class T>
void F1()
{
    g_count++;
}

void F2()
{
    g_count++;
}

inline void F3()
{
    g_count++;
}

class C1
{
  public:
    void F4()
    {
        g_count++;
    }

    virtual void F5()
    {
        g_count++;
    }
};

class C2 : public C1
{
  public:
    virtual void F5()
    {
        g_count++;
    }
};

int main()
{
    C1 c11;
    C2 c22;
    C1 *c1 = new C1;
    C2 *c2 = new C2;
    void (*F)() = F2;

    int i = 10;
    while (i--)
    {
        long long t1 = getSystemTime();

        while (g_count < max)
        {
#if 0
            F1<int>(); //3655 3587 3653 3596 3760 3626 3589 3614 3653 3581
            F2(); //3669 3681 3655 3657 3602 3623 3604 3593 3607 3671
            F3(); //3796 3645 3623 3606 3630 3636 3639 3636 4255 3643
            g_count++; //3574 3570 3561 3588 3647 4217 3807 3705 3581 3573
            F(); //4351 4522 4359 4671 4323 4307 4393 4350 4406 4321
            c11.F4(); //3879 3915 3821 3869 3783 3906 3986 3837 3971 3905
            c11.F5(); //3910 3924 4265 3886 3905 3873 3895 3853 3841 3970
            c1->F4()  //4567 4466 4503 4478 4792 4461 4466 4525 4506 4519
            c1->F5(); //5315 5551 5305 5268 5315 5287 5556 5369 5240 5262
            c22.F5(); //3901 3892 3891 3843 4027 3893 3974 3986 3884 3853
#else
            c2->F5(); //4668 4636 4581 4588 4560 4579 4542 4595 4535 4620
#endif
        }

        long long t2 = getSystemTime();

        std::cout << t2 - t1 << std::endl;

        g_count = 0;
    }

    getchar();
    return 0;
}
// 模板函数参数类型自动推导
using namespace std;

template<class T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    return add(1, 1); // ok
    //return add(1, 1.1); // no matching function for call to 'add(int, double)'
}

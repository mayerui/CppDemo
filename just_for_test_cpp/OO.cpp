//演示C++特性和面向对象特性(封装、继承、多态)的DEMO
//2017.11.13
#include <iostream>
using namespace std;

class Animal
{
  public:
    Animal()
    {
        age = 0;
        birth();
    }
    Animal(int age)
    {
        this->age = age;
        birth();
    }
    ~Animal() { dead(); }
    void eat() { cout << "Animal eat" << endl; }
    virtual void bark() { cout << "Animal bark" << endl; }
    void sleep() { cout << "Animal sleep" << endl; }

  protected:
    void birth() { cout << "Animal birth" << endl; }
    void dead() { cout << "Animal dead" << endl; }
    int age;

  private:
    static int count; //不会被继承
};
class Cat : public Animal
{
  public:
    Cat() : Animal() { birth(); }            //演示父子构造函数调用顺序
    ~Cat() { dead(); }                       //演示父子析构函数调用顺序
    void bark() { cout << "meow~" << endl; } //多态性
  private:
    void birth() { cout << "Cat birth" << endl; } //函数覆写
    void dead() { cout << "Cat dead" << endl; }   //函数覆写
};
//演示多态性
void bark(Animal *animal)
{
    animal->bark();
}
//多态失败，函数重载
void bark(Animal animal)
{
    animal.bark();
}

int main()
{
    //构造
    Animal *animal = new Animal();
    cout << endl;
    Cat *cat = new Cat();
    cout << endl;

    //多态
    bark(animal);
    cout << endl;
    bark(cat);
    cout << endl;

    //多态失败
    bark(*animal);
    cout << endl;
    bark(*cat);
    cout << endl;

    //析构
    delete animal;
    cout << endl;
    delete cat;
    cout << endl;

    return 0;
}

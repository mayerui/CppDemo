#include <iostream>
#include <memory>

using namespace std;

struct Base {
  ~Base() { cout << "~Base()" << endl; }
};

struct Derived : public Base {
  ~Derived() { cout << "~Derived()" << endl; }
};

int main() {
  // ~Base()
  {
    Base *b = new Derived();
    delete b;
  }
  cout << endl;

  // ~Base()
  {
    std::unique_ptr<Base> up = std::make_unique<Derived>();
  }
  cout << endl;

  // ~Derived()
  // ~Base()
  { std::shared_ptr<Base> sp = std::make_shared<Derived>(); }
  cout << endl;

  // ~Derived()
  // ~Base()
  { std::shared_ptr<Base> sp = std::make_unique<Derived>(); }
  cout << endl;

  // ~Base()
  {
    std::unique_ptr<Base> up = std::make_unique<Derived>();
    std::shared_ptr<Base> sp = std::move(up);
  }
  cout << endl;
  return 0;
}

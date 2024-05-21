#include <functional>
#include <iostream>
#include <list>
#include <string>

struct List {
  void emplace(std::string &&s) { l_.push_back(s); }
  template <typename... Args> void emplace(std::string &&s, Args &&...args) {
    l_.push_back(s);
    this->emplace(args...);
  }

  void visit(std::function<void(std::string_view)> f) {
    if (!f) {
      return;
    }
    for (auto const &s : l_) {
      f(s);
    }
  }

  std::list<std::string> l_;
};

int main() {
  List list;
  list.emplace("1", "2");
  list.visit([](std::string_view s) { std::cout << s << std::endl; });
  return 0;
}

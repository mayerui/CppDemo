#include <functional>
#include <iostream>
#include <list>
#include <string>

template <typename T>
struct List {
  void emplace(T s) { l_.push_back(std::move(s)); }
  template <typename... Args> void emplace(T s, Args... args) {
    l_.push_back(std::move(s));
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
  List<std::string> list;
  list.emplace("1", "2");
  list.visit([](std::string_view s) {
    std::cout << s << std::endl;
  });
  return 0;
}

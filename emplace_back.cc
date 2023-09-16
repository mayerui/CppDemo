#include <vector>
#include <string>
#include <iostream>
#include <list>

struct Item {
  Item(std::string s) : name(std::move(s)) { std::cout << "Item(string)" << std::endl; }
  Item(const Item& item) : name(item.name) { std::cout << "Item(const Item&)" << std::endl; }
  Item(Item&& item) : name(std::move(item.name)) { std::cout << "Item(Item&&)" << std::endl; }
  ~Item() { std::cout << "~Item" << std ::endl; }

  std::string name;
};

int main () {
  std::list<Item> items;
  std::vector<Item> items2;

  std::cout << "first case" << std::endl;
  Item item1{"item"};
  std::cout << std::endl;
  items.push_back(item1);
  std::cout << std::endl;
  items.emplace_back(item1);

  std::cout << "second case" << std::endl;
  Item item2{"item2"};
  Item item3{"item3"};
  std::cout << std::endl;
  items.push_back(std::move(item2));
  std::cout << std::endl;
  items.emplace_back(std::move(item3));

  std::cout << "third case" << std::endl;
  items.push_back(Item("item4"));
  std::cout << std::endl;
  items.emplace_back(Item("item5"));

  std::cout << "fourth case" << std::endl;
  //   items.push_back("item4");
  items.emplace_back("item5");
  std::cout << "end" << std::endl;
}
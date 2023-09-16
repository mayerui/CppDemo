#include <future>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<future<bool>> futs;
  auto task = []() -> bool { return true; };
  for (int i = 0; i < 10; i++) {
    futs.emplace_back(async(launch::async, task));
  }
  for (int i = 0; i < 10; i++) {
    cout << futs[i].get();
  }
  return 0;
}
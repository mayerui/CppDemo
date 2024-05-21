#include <cassert>
#include <type_traits>


template <typename T, typename = void>
struct has_auto_cols : std::false_type {};
template <typename T>
struct has_auto_cols<T, std::void_t<decltype(T::auto_cols)>> : std::true_type {
};

class User {
public:
  static int auto_cols;
};

int main() {
  assert(has_auto_cols<User>::value);
  assert(!has_auto_cols<int>::value);
  return 0;
}

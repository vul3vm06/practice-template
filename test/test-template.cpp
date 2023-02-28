#include <iostream>
using namespace std;

template <typename T, typename V> T func(T a, V b) { return a + b; }

int main() {
  int j = 7;
  double i = 5.5;
  cout << func(i, j) << endl;
  return 0;
}

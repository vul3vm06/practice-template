#include <iostream>
using namespace std;
class Base {
public:
  int x = 10;
};

// class Derived : Base {}; compile error:
// compile error: 'x' is a private member of 'Base'

// struct my_derived_struct : Base {}; compile ok.
// class Derived : public Base {}; compile ok.
class Derived : public Base {};
int main() {
  Base b;
  cout << b.x << endl;
  Derived d;
  cout << d.x << endl;
  return 0;
}

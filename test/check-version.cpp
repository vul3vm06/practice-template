#include <iostream>

int main() {
#if __cplusplus == 202002L
  // g++ check-version.cpp -std=c++20
  std::cout << "c++20 " << __cplusplus << std::endl;
#elif __cplusplus == 201703L
  // g++ check-version.cpp -std=c++17
  std::cout << "c++17 " << __cplusplus << std::endl;
#elif __cplusplus == 201402L
  // g++ check-version.cpp -std=c++14
  std::cout << "c++14 " << __cplusplus << std::endl;
#elif __cplusplus == 201103L
  // g++ check-version.cpp -std=c++11
  std::cout << "c++11 " << __cplusplus << std::endl;
#else
  std::cout << "c++ " << __cplusplus << std::endl;
#endif

  return 0;
}

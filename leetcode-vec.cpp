#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
  int totalSteps(vector<int> &nums1) {
    for (int i = 0; i < nums1.size(); i++) {
      cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
  }
};

vector<int> stringToVector(string input) {
  vector<int> result;
  for (char &c : input) {
    if (c == '[' || c == ']' || c == ',') {
      c = ' ';
    }
  }
  stringstream ss(input);
  int val;
  while (ss >> val) {
    result.push_back(val);
  }
  return result;
}

int main() {
  string input;
  int empty_lines = 0;
  Solution sol;

  while (getline(cin, input)) {
    if (input.empty()) {
      empty_lines++;
      if (empty_lines >= 2) {
        break;
      }
      continue;
    }
    empty_lines = 0;

    vector<int> nums = stringToVector(input);

    int result = sol.totalSteps(nums);
    cout << result << endl;
  }

  return 0;
}

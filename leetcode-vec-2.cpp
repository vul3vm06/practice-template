#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
  int find(vector<int> &nums1, vector<int> &nums2) { return 0; }
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
  vector<string> inputs;
  Solution sol;

  while (getline(cin, input)) {
    if (!input.empty() && input.back() == '\r') {
      input.pop_back();
    }

    if (input.empty()) {
      empty_lines++;
      if (empty_lines >= 2) {
        break;
      }
      continue;
    }

    empty_lines = 0;
    inputs.push_back(input);

    if (inputs.size() == 2) {
      vector<int> nums1 = stringToVector(inputs[0]);
      vector<int> nums2 = stringToVector(inputs[1]);

      int result = sol.find(nums1, nums2);
      cout << result << endl;

      inputs.clear();
    }
  }

  return 0;
}

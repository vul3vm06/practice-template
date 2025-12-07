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
  // Remove brackets if present
  if (!input.empty() && input.front() == '[')
    input.erase(0, 1);
  if (!input.empty() && input.back() == ']')
    input.pop_back();

  vector<int> nums;
  stringstream ss(input);
  string token;

  while (getline(ss, token, ',')) {
    try {
      nums.push_back(stoi(token));
    } catch (...) {
      continue;
    }
  }
  return nums;
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

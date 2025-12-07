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

int main() {
  string input;
  int empty_lines = 0;
  while (getline(cin, input)) {
    if (input.empty()) {
      empty_lines++;
      if (empty_lines >= 2) {
        break;
      }
      continue;
    }
    empty_lines = 0;

    // Remove brackets if present
    if (!input.empty() && input.front() == '[')
      input.erase(0, 1);
    if (!input.empty() && input.back() == ']')
      input.pop_back();

    vector<int> nums;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
      nums.push_back(stoi(token));
    }

    int ans = Solution().totalSteps(nums);
    cout << ans << endl;
  }

  return 0;
}

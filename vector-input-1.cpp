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
  vector<int> nums1;

  string input;

  getline(cin, input);
  istringstream ss(input);
  string token;

  while (getline(ss, token, ',')) {
    nums1.push_back(atoi(token.c_str()));
  }

  int ans = Solution().totalSteps(nums1);
  cout << "ans: " << ans << endl;

  return 0;
}

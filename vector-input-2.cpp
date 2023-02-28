#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
  int find(vector<int> &nums1, vector<int> &nums2) { return 0; }
};

int main() {
  vector<int> nums1, nums2;

  int lineCount = 0;
  string line, word;

  while (std::getline(cin, line) && lineCount < 2) {
    stringstream ss(line);
    while (ss >> word) {
      if (lineCount == 0) {
        nums1.push_back(atoi(word.c_str()));
      } else {
        nums2.push_back(atoi(word.c_str()));
      }
    }
    lineCount++;
  }

  int ans = Solution().find(nums1, nums2);
  cout << "ans: " << ans << endl;

  return 0;
}

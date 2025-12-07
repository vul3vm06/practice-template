#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
  int find(vector<int> &nums1, vector<int> &nums2) { return 0; }
};

vector<int> parseVector(string line) {
  vector<int> res;
  for (char &c : line) {
    if (c == '[' || c == ']' || c == ',') {
      c = ' ';
    }
  }
  stringstream ss(line);
  int val;
  while (ss >> val) {
    res.push_back(val);
  }
  return res;
}

int main() {
  string line;
  int consecutiveEmptyLines = 0;
  vector<string> buffer;

  while (std::getline(cin, line)) {
    if (!line.empty() && line.back() == '\r') {
      line.pop_back();
    }

    if (line.empty()) {
      consecutiveEmptyLines++;
      if (consecutiveEmptyLines >= 2) {
        break;
      }
      continue;
    }

    consecutiveEmptyLines = 0;
    buffer.push_back(line);

    if (buffer.size() == 2) {
      vector<int> nums1 = parseVector(buffer[0]);
      vector<int> nums2 = parseVector(buffer[1]);

      int ans = Solution().find(nums1, nums2);
      cout << ans << endl;

      buffer.clear();
    }
  }

  return 0;
}

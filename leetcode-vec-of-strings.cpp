#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    for (auto it = strs.begin(); it != strs.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
    vector<vector<string>> ans;
    return ans;
  }
};

vector<string> parseVector(string line) {
  vector<string> res;
  bool inQuotes = false;
  string current;
  for (char c : line) {
    if (c == '"') {
      inQuotes = !inQuotes;
      if (!inQuotes) {
        res.push_back(current);
        current.clear();
      }
    } else if (inQuotes) {
      current += c;
    }
  }
  return res;
}

int main() {
  string line;
  int consecutiveEmptyLines = 0;

  while (getline(cin, line)) {
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

    vector<string> strs = parseVector(line);
    auto ans = Solution().groupAnagrams(strs);

    cout << "[";
    for (size_t i = 0; i < ans.size(); ++i) {
      cout << "[";
      for (size_t j = 0; j < ans[i].size(); ++j) {
        cout << "\"" << ans[i][j] << "\"";
        if (j < ans[i].size() - 1) cout << ",";
      }
      cout << "]";
      if (i < ans.size() - 1) cout << ",";
    }
    cout << "]" << endl;
  }

  return 0;
}

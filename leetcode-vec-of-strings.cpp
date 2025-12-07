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

vector<string> stringToStringVector(string input) {
  vector<string> res;
  bool inQuotes = false;
  string current;
  for (char c : input) {
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

void printResult(const vector<vector<string>> &result) {
  cout << "[";
  for (size_t i = 0; i < result.size(); ++i) {
    cout << "[";
    for (size_t j = 0; j < result[i].size(); ++j) {
      cout << "\"" << result[i][j] << "\"";
      if (j < result[i].size() - 1)
        cout << ",";
    }
    cout << "]";
    if (i < result.size() - 1)
      cout << ",";
  }
  cout << "]" << endl;
}

int main() {
  string input;
  int empty_lines = 0;
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

    vector<string> strs = stringToStringVector(input);
    auto result = sol.groupAnagrams(strs);

    printResult(result);
  }

  return 0;
}

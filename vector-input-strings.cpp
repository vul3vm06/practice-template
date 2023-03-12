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

int main() {
  vector<string> strs;
  string input;

  // eg: ["eat","tea","tan","ate","nat","bat"]
  getline(cin, input);
  if (input.length() < 2 || input[0] != '[' ||
      input[input.length() - 1] != ']') {
    printf("invalid input: %s", input.c_str());
    return -1;
  }
  input = input.substr(1, input.length() - 2);

  istringstream ss(input);
  string token;
  while (getline(ss, token, ',')) {
    if (token.length() < 2 || token[0] != '"' ||
        token[token.length() - 1] != '"') {
      printf("invalid token: %s", token.c_str());
      return -1;
    }
    strs.push_back(token.substr(1, token.length() - 2));
  }

  auto ans = Solution().groupAnagrams(strs);
  for (auto it = ans.begin(); it != ans.end(); it++) {
    for (auto sub_it = (*it).begin(); sub_it != (*it).end(); sub_it++) {
      cout << *sub_it << " ";
    }
    cout << endl;
  }

  return 0;
}

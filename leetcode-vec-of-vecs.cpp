#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) { return 0; }
};

vector<vector<int>> stringToMatrix(string input) {
  vector<vector<int>> matrix;
  vector<int> row;
  string current_num;
  int depth = 0;

  for (char c : input) {
    if (c == ' ')
      continue;

    if (c == '[') {
      depth++;
    } else if (c == ']' || c == ',') {
      if (depth == 2) {
        if (!current_num.empty()) {
          row.push_back(stoi(current_num));
          current_num.clear();
        }
      } else if (depth == 1) {
        if (!row.empty()) {
          matrix.push_back(row);
          row.clear();
        }
      }

      if (c == ']') {
        depth--;
      }
    } else if (isdigit(c) || c == '-' || c == '+') {
      current_num += c;
    }
  }
  return matrix;
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

    vector<vector<int>> matrix = stringToMatrix(input);

    if (!matrix.empty()) {
      int result = sol.minPathSum(matrix);
      cout << result << endl;
    }
  }
  return 0;
}

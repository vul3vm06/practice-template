#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) { return 0; }
};

vector<vector<int>> stringToVectorOfVectors(string input) {
  vector<vector<int>> result;
  if (input.size() <= 2)
    return result; // Handle empty "[]"
  // Remove the very first and last brackets to avoid edge cases
  // Input: "[[1,2],[3,4]]" -> "[1,2],[3,4]"
  string inner = input.substr(1, input.length() - 2);
  stringstream ss(inner);
  string segment;
  // Split by ']' to isolate each inner vector
  // Segments will look like "[1,2" or ",[3,4"
  while (getline(ss, segment, ']')) {
    // Find where the numbers actually start (after '[')
    size_t start = segment.find('[');
    if (start == string::npos)
      continue;
    // Extract "1,2" and replace commas with spaces for easy parsing
    string rowStr = segment.substr(start + 1);
    replace(rowStr.begin(), rowStr.end(), ',', ' ');
    // Stream the numbers
    stringstream rowSS(rowStr);
    vector<int> row;
    int val;
    while (rowSS >> val) {
      row.push_back(val);
    }
    result.push_back(row);
  }
  return result;
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

    vector<vector<int>> matrix = stringToVectorOfVectors(input);

    if (!matrix.empty()) {
      int result = sol.minPathSum(matrix);
      cout << result << endl;
    }
  }
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool test(vector<vector<int>> &matrix, int target) { return false; }
};

int main(int argc, char **argv) {
  bool DEBUG_INPUT_PARSING = false;
  if (argc == 2 && string(argv[1]) == "debug") {
    DEBUG_INPUT_PARSING = true;
  }

  vector<vector<int>> matrix;
  int target;
  string matrix_string;
  cin >> matrix_string;
  cin >> target;

  DEBUG_INPUT_PARSING &&cout << "matrix_string: " << matrix_string << endl;
  DEBUG_INPUT_PARSING &&cout << "target: " << target << endl;

  auto it = matrix_string.begin();
  string single_number = "";
  int num_strayed_left_bracket = 0;
  vector<int> vec;
  while (it != matrix_string.end()) {
    DEBUG_INPUT_PARSING &&cout << " handling: " << *it << endl;
    if (*it == ' ') {
      it++;
      continue;
    }

    if (*it == '[') {
      num_strayed_left_bracket++;
    } else if (*it == ']' || *it == ',') {
      if (num_strayed_left_bracket == 1) {
        matrix.push_back(vec);
        vec.clear();
      } else if (num_strayed_left_bracket == 2) {
        DEBUG_INPUT_PARSING &&cout << " 2 strayed left bracket "
                                   << single_number << endl;
        vec.push_back(stoi(single_number));
        single_number = "";
      } else {
        DEBUG_INPUT_PARSING &&cout
            << "error: invalid format. #strayed left bracket "
            << num_strayed_left_bracket << " on " << *it << endl;
        return -1;
      }
      if (*it == ']') {
        num_strayed_left_bracket--;
      }
    } else if (isdigit(*it)) {
      DEBUG_INPUT_PARSING &&cout << " isdigit, push " << *it << " to "
                                 << single_number << endl;
      single_number.push_back(*it);
    } else {
      DEBUG_INPUT_PARSING &&cout << "unknown char: " << *it << endl;
    }

    it++;
  }

  if (DEBUG_INPUT_PARSING) {
    for (auto it = matrix.begin(); it != matrix.end(); it++) {
      for (auto sub_it = (*it).begin(); sub_it != (*it).end(); sub_it++) {
        cout << *sub_it << " ";
      }
      cout << endl;
    }
  }

  Solution sol = Solution();
  bool result = sol.test(matrix, target);
  cout << "result: " << result << endl;

  return 0;
}

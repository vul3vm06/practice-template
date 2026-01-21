#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) { return nullptr; }
};

ListNode *stringToList(string input) {
  ListNode *dummy = new ListNode(0);
  ListNode *curr = dummy;

  for (char &c : input) {
    if (c == '[' || c == ']' || c == ',') {
      c = ' ';
    }
  }
  stringstream ss(input);
  int val;
  while (ss >> val) {
    curr->next = new ListNode(val);
    curr = curr->next;
  }

  ListNode *head = dummy->next;
  delete dummy;
  return head;
}

// Helper: Parse "[[1,4,5],[1,3,4],[2,6]]" into vector of lists
vector<ListNode *> stringToVectorOfLists(string input) {
  vector<ListNode *> result;
  if (input.empty() || input == "[]" || input == "[[]]") {
    // Special handling might be needed depending on strictness,
    // but loop below handles empty outer structure nicely usually.
    // If input is "[]", loop won't find sub-arrays.
  }

  // Remove outer brackets
  if (input.size() >= 2 && input.front() == '[' && input.back() == ']') {
    input = input.substr(1, input.size() - 2);
  }

  // Iterate through input to find sub-arrays "[...]"
  int start = 0;
  int bracketCount = 0;
  for (int i = 0; i < input.length(); ++i) {
    if (input[i] == '[') {
      if (bracketCount == 0)
        start = i;
      bracketCount++;
    } else if (input[i] == ']') {
      bracketCount--;
      if (bracketCount == 0) {
        // Found a complete list string: input[start...i]
        string listStr = input.substr(start, i - start + 1);
        result.push_back(stringToList(listStr));
      }
    }
  }

  // Case where input might be like "[[],[]]" -> logic above handles it.
  // Case logic:
  // [] -> empty string after removal -> loop doesn't run -> empty vector.
  // correct.
  // [[]] -> inner is "[]" -> stringToList("[]") returns nullptr -> vector
  // {nullptr}.

  return result;
}

void printList(ListNode *head) {
  cout << "[";
  ListNode *curr = head;
  while (curr) {
    cout << curr->val;
    if (curr->next) {
      cout << ",";
    }
    curr = curr->next;
  }
  cout << "]" << endl;
}

void deleteList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  string input;
  Solution sol;

  // Read line by line.
  // Usually LeetCode style inputs from files might have multiple lines,
  // or sometimes just one large inputs.
  // The prompt implies multiple examples, likely one per line.

  int empty_lines = 0;
  while (getline(cin, input)) {
    // Trim whitespace to check if line is effectively empty
    string trimmed = input;
    size_t first = trimmed.find_first_not_of(" \t\n\r");
    if (first == string::npos) {
      empty_lines++;
      if (empty_lines >= 2)
        break;
      continue;
    }
    empty_lines = 0;

    trimmed.erase(0, first);
    size_t last = trimmed.find_last_not_of(" \t\n\r");
    trimmed.erase(last + 1);

    vector<ListNode *> lists = stringToVectorOfLists(trimmed);

    ListNode *result = sol.mergeKLists(lists);

    printList(result);

    deleteList(result);
  }

  return 0;
}

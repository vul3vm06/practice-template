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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) { return list1; }
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

// Helper to free memory
void deleteList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  string input;
  int empty_lines = 0;
  vector<string> inputs;
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

    inputs.push_back(input);

    if (inputs.size() == 2) {
      ListNode *list1 = stringToList(inputs[0]);
      ListNode *list2 = stringToList(inputs[1]);

      ListNode *result = sol.mergeTwoLists(list1, list2);

      printList(result);

      deleteList(result);
      inputs.clear();
    }
  }
  return 0;
}

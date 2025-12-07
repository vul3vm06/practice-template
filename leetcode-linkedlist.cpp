#include <iostream>
#include <sstream>
#include <string>

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
  ListNode *swapPairs(ListNode *head) { return head; }
};

ListNode *stringToList(string input) {
  if (input.empty())
    return nullptr;
  // Remove brackets if present
  if (input.front() == '[')
    input.erase(0, 1);
  if (!input.empty() && input.back() == ']')
    input.pop_back();

  if (input.empty())
    return nullptr;

  stringstream ss(input);
  string token;
  ListNode *dummy = new ListNode(0);
  ListNode *curr = dummy;

  while (getline(ss, token, ',')) {
    try {
      curr->next = new ListNode(stoi(token));
      curr = curr->next;
    } catch (...) {
      continue;
    }
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
  while (getline(cin, input)) {
    if (input.empty()) {
      empty_lines++;
      if (empty_lines >= 2) {
        break;
      }
      continue;
    }
    empty_lines = 0;

    ListNode *head = stringToList(input);

    Solution sol;
    ListNode *result = sol.swapPairs(head);

    printList(result);

    deleteList(result);
  }
  return 0;
}

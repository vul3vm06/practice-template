#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteAllNodes(ListNode *head) {
  ListNode *temp = nullptr;
  while (head) {
    temp = head->next;
    delete head;
    head = temp;
  }
};

class Solution {
public:
  ListNode *DoRun(ListNode *head) {
    //
    return head;
  }
};

int main() {
  string input;
  getline(cin, input);
  istringstream ss(input);
  string token;

  ListNode *head = nullptr;
  ListNode *temp = nullptr;
  while (getline(ss, token, ',')) {
    if (!head) {
      head = new ListNode(atoi(token.c_str()));
      temp = head;
    } else {
      temp->next = new ListNode(atoi(token.c_str()));
      temp = temp->next;
    }
  }

  ListNode *ans = Solution().DoRun(head);

  cout << "ans: ";
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  deleteAllNodes(head);
  deleteAllNodes(ans);

  return 0;
}

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
  ListNode *DoRun(ListNode *list1, ListNode *list2) {
    //
    return list1;
  }
};

int main() {
  string input;

  int count = 0;
  ListNode *head1 = nullptr;
  ListNode *head2 = nullptr;

  while (getline(cin, input) && count < 2) {
    istringstream ss(input);
    string token;
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    while (getline(ss, token, ',')) {
      if (!head) {
        head = new ListNode(atoi(token.c_str()));
        temp = head;
        if (count == 0) {
          head1 = head;
        } else if (count == 1) {
          head2 = head;
        }
      } else {
        temp->next = new ListNode(atoi(token.c_str()));
        temp = temp->next;
      }
    }

    count++;
  }

  ListNode *ans = Solution().DoRun(head1, head2);

  cout << "ans: ";
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;

  deleteAllNodes(head1);
  deleteAllNodes(head2);
  deleteAllNodes(ans);

  return 0;
}

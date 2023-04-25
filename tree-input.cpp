#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void printTree(const string &prefix, const TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << node->val << endl;

    // enter the next tree level - left and right branch
    printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void printTree(const TreeNode *node) { printTree("", node, false); }

void removeTree(const TreeNode *node) {
  if (node) {
    if (node->left) {
      removeTree(node->left);
    }
    if (node->right) {
      removeTree(node->right);
    }

    delete node;
  }
}

TreeNode *buildTree(vector<string> v) {
  if (v.empty()) {
    return nullptr;
  }

  vector<TreeNode *> pointers;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != "null") {
      int val = -1;
      try {
        val = stoi(v[i]);
      } catch (const exception &ex) {
        cout << "stoi exception: " << ex.what() << " " << v[i] << endl;
      }
      pointers.push_back(new TreeNode(val));
    } else {
      pointers.push_back(nullptr);
    }
  }

  int childIndex = 1;
  for (int i = 0; i < pointers.size(); i++) {
    if (pointers[i] != nullptr) {
      if (childIndex < v.size()) {
        pointers[i]->left = pointers[childIndex];
        childIndex += 1;
      }
      if (childIndex < v.size()) {
        pointers[i]->right = pointers[childIndex];
        childIndex += 1;
      }
    }
  }

  return pointers[0];
}

int main() {
  vector<string> vec;

  string input;

  getline(cin, input);
  istringstream ss(input);
  string token;

  // sample: 1,3,2,5,3,null,9
  // sample: 1,3,2,5,null,null,9,6,null,7
  while (getline(ss, token, ',')) {
    vec.push_back(token);
  }

  TreeNode *root = buildTree(vec);

  printTree(root);

  removeTree(root);
  return 0;
}

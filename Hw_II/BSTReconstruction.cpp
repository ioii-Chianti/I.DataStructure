#include <iostream>
#include <vector>
using namespace std;

class BTNode {
    public:
        BTNode(int data) : data(data), left(nullptr), right(nullptr) {}
        BTNode(int data, BTNode *left, BTNode *right) : data(data), left(left), right(right) {}
        int data;
        BTNode *left;
        BTNode *right;
};

void insertNode(BTNode *node, int data) {
    if (data < node->data) {
        if (node->left)
            insertNode(node->left, data);
        else
            node->left = new BTNode(data);
    } else {
        if (node->right)
            insertNode(node->right, data);
        else
            node->right = new BTNode(data);
    }
}

void preOrder(BTNode *node) {
    if (!node) return;
    cout << node->data << ' ';
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(BTNode *node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->data << ' ';
    inOrder(node->right);
}

void postOrder(BTNode *node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << ' ';
}

int main() {
    BTNode *Root = nullptr;
    int numNode, input;
    cin >> numNode;
    for (int i = 0; i < numNode; i++) {
        cin >> input;
        if (!Root)
            Root = new BTNode(input);
        else
            insertNode(Root, input);
    }
    inOrder(Root);
    cout << '\n';
    postOrder(Root);
    cout << '\n';
}
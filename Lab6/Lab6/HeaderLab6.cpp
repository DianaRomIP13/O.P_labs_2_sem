#include "HeaderLab6.h"

void Tree::AddElement(Node*& node, char symbol) {
    if (!node) {
        node = new Node;
        node->symbol = symbol;
        node->LEFT = 0;
        node->RIGHT = 0;
    }
    else {
        if (symbol < node->symbol) {
            AddElement(node->LEFT, symbol);
        }
        else if (symbol > node->symbol) {
            AddElement(node->RIGHT, symbol);
        }
    }
}

void Tree::AddElement(char s) {
    this->AddElement(this->root, s);
}

void Tree::printLeafs() {
    this->printLeafs(this->root);
}

void Tree::printLeafs(Node* root)
{
    if (root)
    {
        printLeafs(root->LEFT);
        if (!root->LEFT && !root->RIGHT)
            cout << root->symbol << endl;
        printLeafs(root->RIGHT);
    }
}

void Tree::printTree(Node* root, int space) {
    if (root == NULL) return;
    printTree(root->RIGHT, ++space);
    for (int i = 1; i < space; i++) {
        cout << '\t';
    }
    cout << root->symbol << endl;
    printTree(root->LEFT, space);
}

void Tree::printTree() {
    cout << "--------------------------\n";
    int l = this->getLevels(root);
    for (int i = 0; i < l; i++) cout << i << '\t';
    cout << endl;
    for (int i = 0; i < l; i++) cout << "|\t";
    cout << endl << endl;
    printTree(root, 0);
    cout << "--------------------------\n";
}

int Tree::getLevels(Node* root) {
    if (root == NULL) return 0;
    return max(getLevels(root->LEFT), getLevels(root->RIGHT)) + 1;
}
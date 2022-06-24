#include "HeaderLab6.h"

int main() {
    Tree tree;

    int n;
    cout << "Enter amount of tree elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char s;
        cout << "Enter symbol: ";
        cin >> s;
        tree.AddElement(s);
    }

    cout << "Entered tree: " << endl;
    tree.printTree();

    cout << "Its terminal nodes are: " << endl;
    tree.printLeafs();
}
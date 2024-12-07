#include <iostream>
using namespace std;

class Tree {
private:
    struct Node {
        int data; 
        Node* left; 
        Node* right; 
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    Node* root; 
    void add(Node*& current, int value) {
        if (!current) {
            current = new Node(value);
        }
        else if (value < current->data) {
            add(current->left, value);
        }
        else {
            add(current->right, value);
        }
    }
    void printInOrder(Node* current) const {
        if (current) {
            printInOrder(current->left); 
            cout << current->data << " "; 
            printInOrder(current->right); 
        }
    }
public:
    Tree() : root(nullptr) {}
    ~Tree() {
        clear(root);
    }
    void add(int value) {
        add(root, value);
    }
    void print() const {
        if (!root) {
            cout << "Tree is empty." << endl;
        }
        else {
            printInOrder(root);
            cout << endl;
        }
    }
private:
    void clear(Node* current) {
        if (current) {
            clear(current->left);
            clear(current->right);
            delete current;
        }
    }
};

int main() {
    Tree tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(18);

    cout << "Tree elements in order: ";
    tree.print();
    return 0;
}

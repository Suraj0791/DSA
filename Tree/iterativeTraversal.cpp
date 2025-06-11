#include <bits/stdc++.h>
using namespace std;



struct Node {
	int data;
	Node* left;
	Node* right;
};


Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

vector<int> preorder(Node* root) {
    vector<int> result;
    stack<Node*> s;
    if (root) s.push(root);
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        result.push_back(node->data);
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return result;
}

vector<int> inorder(Node* root) {
    vector<int> result;
    stack<Node*> s;
    Node* current = root;
    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        result.push_back(current->data);
        current = current->right;
    }
    return result;
}

vector<int> postorder(Node* root) {
    vector<int> result;
    stack<Node*> s1, s2;
    if (root) s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        result.push_back(s2.top()->data);
        s2.pop();
    }
    return result;
}





int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "Preorder: ";
    vector<int> pre = preorder(root);
    for (int i : pre) {
        cout << i << " ";
    }
    cout << "\nInorder: ";
    vector<int> in = inorder(root);
    for (int i : in) {
        cout << i << " ";
    }
    cout << "\nPostorder: ";
    vector<int> post = postorder(root);
    for (int i : post) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
    




}


#include <bits/stdc++.h>
using namespace std;



struct Node {
	int data;
	Node* left;
	Node* right;
};

void preorder(Node* node){
    if(node == NULL) {
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node == NULL) {
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Node* node){
    if(node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>> levelorder(Node* node){
    vector<vector<int>> result;
    if(node == NULL) {
        return result;
    }
    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            level.push_back(current->data);
            if(current->left != NULL) {
                q.push(current->left);
            }
            if(current->right != NULL) {
                q.push(current->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level order traversal: " << endl;
    vector<vector<int>> levels = levelorder(root);
    for(int i = 0; i < levels.size(); i++) {
        for(int j = 0; j < levels[i].size(); j++) {
            cout << levels[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}



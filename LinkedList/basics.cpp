#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;         // Data stored in the node
        Node* next;       // Pointer to the next node in the linked list
        // Constructors
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
        // Constructor
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
          Node* temp=new Node(arr[i]);
          mover->next=temp;
          mover=temp;
    }
    return head;
}


int main() {
    vector<int> arr = {2, 5, 8, 7};
    // Create a Node 'x' with the first element of the vector and a null next reference
    Node* y=new Node(arr[0],nullptr);
    // Print the memory address of the Node 'x' using the pointer 'y'
    cout << y << '\n';
    //if u need data u shoudl do y->data not y.data
    cout<<y->data<<'\n';

    // if we do Node x= Node(arr[0],nullptr) this is not pointer exctly this creates a object 
    // then now if we do cout<<y it will throw error as its object 
    //corret is cout<<y.data
    //so best is new node only best way to initialize 


    Node* head= convertArr2LL(arr);
    cout<<head->data<<endl;

    Node* temp=head;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;         // Data stored in the node
        Node* next; 
        Node* back;      // Pointer to the next node in the linked list
        // Constructors
        Node(int data1, Node* next1,Node* back1) {
            data = data1;
            next = next1;
            back=back1;
        }
        // Constructor
        Node(int data1) {
            data = data1;
            next = nullptr;
            back=nullptr;
        }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
          Node* temp=new Node(arr[i], nullptr, mover);
          mover->next=temp;
          mover=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* oddevenLL(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=head->next;
    if(head==NULL || head->next==NULL){
        return head;
    }
    //we are doing this even check in loop coz we know one things for sure even index will alwayd be above the odd index as ll starts from od index 1 and next index is even 2 , so if even has not ended i mean even has not touched null its sure odd also hasnt finsihed 
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next= even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}


int main(){
    vector<int> arr={2,5,8,7,9};
    Node* head=convertArr2LL(arr);
    print(head);
    head=oddevenLL(head);
    print(head);
    return 0;
}
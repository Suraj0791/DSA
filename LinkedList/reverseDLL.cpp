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

Node* reverse2Dll(Node* head ){
         if(head==NULL || head->next==NULL){
            return head;
         }
         Node* last=NULL;
         Node* current=head;
         while(current!=NULL){
            last=current->back;
            current->back=current->next;
            current->next=last;
            current=current->back;
         }
         return last->back;
         
}

int main(){
    vector<int> arr={2,5,8,7,9};
    Node* head=convertArr2LL(arr);
    print(head);
     head=reverse2Dll(head);
    print(head);
    return 0;
}
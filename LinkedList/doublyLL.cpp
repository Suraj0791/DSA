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

Node* deletehead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}

Node* deletetail(Node* head){
    if (head == NULL || head->next == NULL) {
        delete head; // Free the single node if it exists
        return NULL; // Return NULL as the list is now empty
    }
     Node* temp=head; 
     while(temp->next->next!=NULL){
         temp=temp->next; 
        } 

         temp->next->back=NULL; 
         temp->next=NULL; 
         delete temp->next;

         return head;

} 


Node* deleteKth(Node* head, int k) {
    if (head == NULL) return NULL;

    // Special case: deleting head
    if (k == 1) {
        Node* toDelete = head;
        head = head->next;
        if (head != NULL) head->back = NULL;
        delete toDelete;
        return head;
    }

    Node* temp = head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (temp->next != NULL)
            temp->next->back = temp;
        delete toDelete;
    }

    return head;
}




int main(){
    vector<int> arr={2,5,8,7,9};
    Node* head=convertArr2LL(arr);
    print(head);
    head=deletetail(head);
    print(head);
    return 0;
}
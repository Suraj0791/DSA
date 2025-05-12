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

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removehead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}

// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}


Node* removeK(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* inserthead(Node* head,int val){
      Node* temp=new Node(val,head);
      return temp; // Return the new head

}

Node* insertlast(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        //stop at the last elem
        //this cond makes us stop at last elem 
        temp=temp->next;
    }
    Node* n=new Node(val,NULL);
    temp->next=n;
    return head;
}

Node* insertatK(Node* head,int val,int k){

    if (k == 1) return inserthead(head, val);
    Node* newNode = new Node(val);

    Node* temp=head;
    for(int i=1;i<k-1&&temp->next!=NULL;i++){
        temp=temp->next;

    }
    //we stop at k-1th elem 
    //now we need to insert at kth posn;
    if (temp == NULL) return head; // invalid k
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}


int main() {
    vector<int> arr = {2, 5, 8, 7};
     Node* head= convertArr2LL(arr);
     print(head);
     head=inserthead(head,100);
     print(head);
     head=insertlast(head,300);
     print(head);

}





//Use temp != NULL when you need to process all nodes in the list.

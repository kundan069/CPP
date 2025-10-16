#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void insertAtHead(Node* &head ,Node* &tail, int data){ 
    // head is pass by reference kyunki original list mein change krna hai
    if(head==NULL){
        //EMPTY node
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node* &head ,Node* &tail, int data){ 
    // head is pass by reference kyunki original list mein change krna hai
    if(head==NULL){
        //EMPTY node
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
    return;
}
void removeDuplicate(Node* head){
    Node* curr = head;
    
    if(curr == NULL){
      
        return ;
    }
    if(curr->next == NULL){
        
        return ;
    }
    Node* temp = NULL;
    while(curr != NULL){
        
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next; 
        }
    }
    
    return;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,4);
    print(head);
    cout<<endl;
    removeDuplicate(head);

    print(head);
    cout<<endl;
    
}

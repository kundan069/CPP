#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(){
       this->data=0;
       this->next=NULL; 
    }
    Node(int data){
        this->data=data;
        this->next=NULL; 
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
int main(){
    // cout<<"printing the Linked List : ";
    Node* head = NULL;
    Node* tail = NULL;
    // insertAtHead(head,tail,25);
    // insertAtHead(head,tail,30);
   cout<<"printing the Linked List from tail : ";
    // print(head);
    // cout<<endl;
    // cout<<"Inserting node at tail! "<<endl;
     insertAtTail(head,tail,220);
   //  insertAtHead(head,tail,2120);
     insertAtTail(head,tail,120);
    print(head);
}

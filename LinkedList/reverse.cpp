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

Node* reverse(Node* &head,Node* &prev,Node* &curr,Node* &nxt){
    //base case
   
    if(nxt == NULL){
        return prev;
    }
    //recursive function
    
    curr->next = NULL ;
    curr->next = prev ;
    reverse(head,curr,nxt,nxt->next);
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    cout<<"printing the LinkedList : ";
    print(head);
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = head->next;

    Node* temp = reverse(head,prev,curr,nxt);
    cout<<endl;
    cout<<"reverse print : ";
    print(temp);
}

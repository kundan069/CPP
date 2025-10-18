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

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = head;
    
    while(curr!=NULL){
        nxt = nxt->next;
        curr->next = NULL;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}


void AddNumber(Node* head1 , Node* head2){
    Node* newHead1 = reverse(head1);
    Node* newHead2 = reverse(head2);
    int carry = 0;
    Node* sum = new Node(0);
    Node* temp = sum;
    while((newHead1 != NULL) && (newHead2 != NULL)){
        sum->data = newHead1->data + newHead2->data + carry + sum->data;
        carry = sum->data/10;
        sum->data = sum->data % 10;
       
        Node* newNode = new Node(0);
        //if((newHead2->next != NULL)&&(newHead1->next != NULL)){
            sum->next = newNode;
            sum = newNode;
        
        
        //     sum->next = newNode;
        //     sum = newNode;
        // }
        
        
        newHead1 = newHead1->next;
        newHead2 = newHead2->next;
    }
    while(newHead1 !=NULL){
        sum->data = newHead1->data  + carry + sum->data;
        carry = sum->data/10;
        sum->data = sum->data % 10;
        Node* newNode = new Node(0);
        //Node* new1 = NULL;
        if(newHead1->next != NULL){
            sum->next = newNode;
        sum = newNode;
        }

        newHead1 = newHead1->next;
    }
    while(newHead2 !=NULL){
        sum->data = newHead2->data  + carry + sum->data;
        carry = sum->data/10;
        sum->data = sum->data % 10;
        
        Node* newNode = new Node(0);
        if(newHead2->next != NULL){
            sum->next = newNode;
            sum = newNode;
        }
        
        newHead2 = newHead2->next;
    }
    while(carry!=0){
        sum->data = carry + sum->data;
        carry = sum->data/10;
        sum->data = sum->data % 10;
        Node* newNode = new Node(0);
        if(carry!=0){
            sum->next = newNode;
        sum = newNode;
        }
        
        
    }
    // print(temp);
    Node* ansNode = reverse(temp);
    print(ansNode);
    return;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(head1,tail1,9);
    insertAtTail(head1,tail1,9);
    insertAtTail(head1,tail1,9);

    insertAtTail(head2,tail2,9);
    insertAtTail(head2,tail2,9);
    insertAtTail(head2,tail2,9);
    
   
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl<<"reverse :"<<endl;
    AddNumber(head1 , head2);
    cout<<endl;
    
}

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
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* Next = curr ->next;
    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
bool checkPalindrome(Node* &head){
    if(head == NULL){
        cout<<"LL is empty! "<<endl;
        return true; 
    }
    if(head -> next == NULL){
        //only one node
        cout<<"only one element "<<endl;
        return true;
    }

    // ek se jayad node 
    //step 1 : finde middle node
    //SLOW and FAST pointer approach

    Node* slow =  head;
    Node* fast = head -> next;
    while(fast != NULL){
        fast = fast-> next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //slow pointer is pointing to middle node;
    //step 2 : Reverse LL from Middle
    Node* reverseKaHead = reverse(slow->next);
    
    Node* temp1 = head;
    Node* temp2 = reverseKaHead;

    while(temp2 != NULL){
        if(temp1 -> data != temp2 -> data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,10);
    print(head);
    cout<<endl;

    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome){
        cout<<"Given LL is Palindrome! "<<endl;
    }
    else {
        cout<<"NOT a palindrome! "<<endl;
    }
}

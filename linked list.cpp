#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this -> data= data;
        this -> next = NULL;
    }
};

void insertathead(Node* &head, int d){
    // create new node 
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
};
void insertattail(Node* &tail, int d){
    // create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<< " ";
        temp= temp->next;
    }
    cout<<endl;
}

void insertatanyposition(Node* head, Node* tail, int position , int d){
    Node*temp = head;
    int count=1;
    if(position == 1){
        insertathead(head,d);
        return;
    }

    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

int main(){
    Node* node1 = new Node(10);
    cout<< node1 -> data<< endl;
    Node* head = node1;
    Node* tail = node1;
    print(head);
    //insertathead(head,12);
    //print(head);
    //insertathead(head,15);
    //print(head);
    insertattail(tail,12);
    print(head);
    insertattail(tail,15);
    print(head);
    insertatanyposition(head,tail,3,22);
    print(head);
    insertatanyposition(head,tail,5,44);
    print(head);

    cout<< "head"<<head ->data <<endl;
    cout<< "tail"<<tail -> data <<endl;
    return 0;
}   
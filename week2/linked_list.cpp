#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data =x;
        next = nullptr;
    }
};

Node* themvaodau(Node *head , int data){
      Node* p = new Node(data);
      p->next = head;
      head =p;
      return head;
} //Do phuc ta O(1)

Node* themvaocuoi(Node*head ,int data){
     Node* p = new Node(data);
     Node* tmp = head;
     if(head == nullptr){
        return p;
     }
     while(tmp -> next != nullptr){
        tmp = tmp ->next;
     }
     tmp -> next =p;
     return head;
} //Do phuc tap O(n)

Node *themvaogiua(Node *head ,int data, int pos){
     Node* p = new Node(data);
     Node* tmp = head;
     int count =0;
     while(count < pos){
       tmp= tmp->next;
       count++; 
     }
     Node* k = tmp->next;
     tmp ->next = p;
     p->next = k;
     return head;
}
//Do phuc tap la O(n)

Node *xoadau(Node*head){
    Node*tmp = head;
    head = head->next;
    delete tmp;
    return head;
}

Node* xoacuoi(Node*head){
    Node*tmp = head;
    while(tmp->next->next !=nullptr){
        tmp = tmp->next;
    }
    Node* k = tmp->next;
    tmp ->next = nullptr;
    delete k;
    return head;
}

Node* xoagiua(Node*head,int pos){
    Node*tmp = head;
    int count =0;
    while(count < pos){
        tmp = tmp ->next; 
    }
    Node*k = tmp->next;
    tmp = tmp->next->next;
    delete k;
    return head;
}

void duyetxuoi(Node*head){
    Node*tmp =head;
    while(tmp !=nullptr){
        cout << tmp->data;
        tmp =tmp ->next; 
    }
}
void duyetnguoc(Node*head ){
    Node *tmp= head;
    if(tmp == nullptr){
        return;
    }
    duyetnguoc(head->next);
    cout << tmp->data<< " ";
}

int main(){
    Node*head = nullptr;
    Node*end =nullptr;
    int n; cin >>n;
    for(int i=0 ; i<n;i++){
        int data; cin >>data;
        Node*p =new Node(data);

        if(head == nullptr){
            head = p;
            end =p;
        }
        else{
            end->next =p;
            end = p;
        }
    }
    return 0;
}



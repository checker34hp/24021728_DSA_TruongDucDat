//doublylinkedlist
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*pre;
    Node(int x){
        data= x;
        next = nullptr;
        pre=nullptr;
    }
};

int main(){
    int n;
    cin>>n;
    Node*head;
    Node*end;
    for(int i=0;i<n;i++){
        int x; cin >>x;
        Node*p =new Node(x);
        if(head == nullptr){
            head =p;
            end =p;
        }
        else{
            end->next = p;
            p->pre = end;
            end =p;
        }
    }
    return 0;
} //doublylinkedlist có tail (end)

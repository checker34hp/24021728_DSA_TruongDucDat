#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node*pre;
    Node(int x){
        data =x;
        next = nullptr;
        pre = nullptr;
    }
};

Node *themdau(Node* head, int x){
    Node*p = new Node(x);
    if(head == nullptr){
        head =p;
        return head;
    }
    p->next = head;
    head ->pre = p;
    head =p;
    return head;
}

Node* xoacuoi(Node* head, Node*& tail) {
    if (tail == nullptr) {
        return head;
    }

    Node* tmp = tail;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->pre;
        tail->next = nullptr;
    }
    delete tmp;
    return head;
}


class queue{
     private:
     Node*head = nullptr;
     Node*tail = nullptr;
     public:
     void enqueue(int x){
        head = themdau(head,x);
     if (tail == nullptr) {
            tail = head;
        }
    }
     void dequeue(){
         cout << tail->data;
         tail = xoacuoi(head,tail);
     }
};

void themcuoi(vector<int> &v,int x){
        v.push_back(x);
}
int xoadau(vector<int> &v){
      int n = sizeof(v);
      int k = v[0];
      for(int i=0;i<n-1;i++){
         v[i]=v[i+1];
      }
      v.pop_back();
    return k;
}

class queu2{
    private:
       vector<int> v;
    public:
        void enqueue(int x){
            themcuoi(v,x);
        }
        int dequeue(){
             return xoadau(v);
        }
};

int main(){
    queue t;
    t.enqueue(4);
    t.enqueue(5);
    t.enqueue(7);
    t.dequeue();

    queu2 t2;
    t2.enqueue(4);
    t2.enqueue(5);
    t2.enqueue(7);
    t2.dequeue();
    return 0;

}

#include<iostream>
#include<vector>
#include<string>
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

Node *themvaodau(Node*head,int x){
    Node *p = new Node(x);
    if(head ==nullptr){
        head =p;
    }
    else{
        p->next = head;
    }
    return p;
}

Node* xoadau(Node*head){
    Node* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}


void themvaocuoi(int x,  vector<int> &V){
    
    V.push_back(x);
}

int xoacuoi(vector<int> &V){
       int n = V.size();
       int k = V[n-1];
       V.pop_back();
       return k;
}




class stack1{
    private:
    Node* head = nullptr;
    public:
    void push(int x){
       head = themvaodau(head,x);
    }
    int pop(){
        int p= head->data;
        head = xoadau(head); 
        return p;
    }
    int top(){
        return head->data;
    }
};

class stack2{
    private:
    vector<int> v;
    public:
    void push(int x){
        themvaocuoi(x,v);
    }
    int pop(){
       return xoacuoi(v);

    }
    int top(){
        return v[v.size()-1];
    }
};

int main() {
   stack1 st;
   st.push(3);
   st.push(20);
   cout << st.pop() << endl;
   cout << st.top() << endl;  
    
   cout << "stack2 bat dau tu day" << endl;
   stack2 st2;
   st2.push(6);
   st2.push(7);
   cout << st2.pop()<<endl;
   cout << st2.top();
    return 0;


    
}

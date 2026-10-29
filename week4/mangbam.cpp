
#include <iostream>
using namespace std;

const int SIZE = 10;

class Node {
public:
    int data;
    int key;
    Node* next;

    Node(int d, int k) {
        data = d;
        key = k;
        next = nullptr;
    }
};

Node* table[SIZE] = {nullptr};

// Ham bam
int hashFunction(int key) {
    return key % SIZE;
}

// Them phan tu
void insert(int data, int key) {
    int index = hashFunction(key);

    Node* p = new Node(data, key);
    p->next = table[index];
    table[index] = p;
}

// Tim kiem theo key
Node* search(int key) {
    int index = hashFunction(key);
    Node* p = table[index];

    while (p != nullptr) {
        if (p->key == key)
            return p;

        p = p->next;
    }

    return nullptr;
}

// In mang bam
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        Node* p = table[i];

        while (p != nullptr) {
            cout << "(data=" << p->data
                 << ", key=" << p->key << ") -> ";

            p = p->next;
        }

        cout << "NULL\n";
    }
}

// Giai phong bo nho
void clearTable() {
    for (int i = 0; i < SIZE; i++) {
        Node* p = table[i];

        while (p != nullptr) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }

        table[i] = nullptr;
    }
}

int main() {
    insert(100, 12);
    insert(200, 22);
    insert(150, 15);
    insert(300, 32);
    insert(70, 7);

    cout << "Mang bam:\n";
    display();

    cout << "\nTim key 22:\n";
    Node* p = search(22);

    if (p != nullptr) {
        cout << "Tim thay: data = " << p->data
             << ", key = " << p->key << '\n';
    } else {
        cout << "Khong tim thay\n";
    }
    clearTable();
    return 0;
}


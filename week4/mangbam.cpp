#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int key;
    Node* next;
};

Node* table[SIZE] = {nullptr};

// Hàm băm
int hashFunction(int key) {
    return key % SIZE;
}

// Thêm phần tử
void insert(int key) {
    int index = hashFunction(key);

    Node* p = new Node;
    p->key = key;
    p->next = table[index];
    table[index] = p;
}

// Tìm kiếm phần tử
bool search(int key) {
    int index = hashFunction(key);
    Node* p = table[index];

    while (p != nullptr) {
        if (p->key == key)
            return true;
        p = p->next;
    }

    return false;
}

// Xóa phần tử
void removeKey(int key) {
    int index = hashFunction(key);
    Node* p = table[index];
    Node* prev = nullptr;

    while (p != nullptr) {
        if (p->key == key) {
            if (prev == nullptr)
                table[index] = p->next;
            else
                prev->next = p->next;

            delete p;
            cout << "Da xoa " << key << '\n';
            return;
        }

        prev = p;
        p = p->next;
    }

    cout << "Khong tim thay " << key << '\n';
}

// In mảng băm
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        Node* p = table[i];

        while (p != nullptr) {
            cout << p->key << " -> ";
            p = p->next;
        }

        cout << "NULL\n";
    }
}

// Giải phóng bộ nhớ
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
    insert(12);
    insert(22);
    insert(15);
    insert(32);
    insert(7);

    cout << "Mang bam:\n";
    display();

    cout << "\nTim 22: ";
    cout << (search(22) ? "Tim thay" : "Khong tim thay");

    cout << "\n\n";
    removeKey(22);

    cout << "\nMang bam sau khi xoa:\n";
    display();

    clearTable();
    return 0;
}

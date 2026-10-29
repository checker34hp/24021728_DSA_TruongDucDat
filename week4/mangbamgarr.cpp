#include <iostream>
using namespace std;

const int SIZE = 10;
int arr[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (arr[index] != -1) {
        index = (index + 1) % SIZE;
    }

    arr[index] = key;
}

bool search(int key) {
    int index = hashFunction(key);

    while (arr[index] != -1) {
        if (arr[index] == key)
            return true;

        index = (index + 1) % SIZE;
    }

    return false;
}

int main() {
    int i = 0;

    while (i < SIZE) {
        arr[i] = -1;
        i++;
    }

    insert(12);
    insert(22);
    insert(32);
    insert(15);
    insert(7);

    i = 0;
    while (i < SIZE) {
        cout << "arr[" << i << "] = "
             << arr[i] << '\n';
        i++;
    }

    int key;
    cout << "Nhap key can tim: ";
    cin >> key;

    if (search(key))
        cout << "Tim thay";
    else
        cout << "Khong tim thay";

    return 0;
}

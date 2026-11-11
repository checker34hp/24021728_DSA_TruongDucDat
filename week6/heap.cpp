#include<iostream>
#include<algorithm>
using namespace std;
class heap{
    public:
       int arr[1000];
       int size;
};


// maxheap
void insert_1(heap &h, int x){
    int i =  h.size;
    h.arr[i] =x;
    h.size++;
    while(i>0){
        int parent = (i-1)/2;
        if(h.arr[i] > h.arr[parent]){
            swap(h.arr[i], h.arr[parent]);
            i = parent;
        }
        else {
            break;
    }
}}
//minheap
void insert_2(heap &h, int x){
    int i =  h.size;
    h.arr[i] =x;
    h.size++;
    while(i>0){
        int parent = (i-1)/2;
        if(h.arr[i] < h.arr[parent]){
            swap(h.arr[i], h.arr[parent]);
        i = parent;
        }
        
        else {
            break;
    }
}
}
\\maxheap
void delete_1(heap &h, int x){
    int pos = -1;
    for(int i = 0; i < h.size; i++){
        if(h.arr[i] == x){
            pos = i;
            break;
        }
    }

    if(pos == -1) return;
    h.arr[pos] = h.arr[h.size - 1];
    h.size--;
    if(pos > 0 && h.arr[pos] > h.arr[(pos-1)/2]){

        while(pos > 0){
            int parent = (pos-1)/2;
            if(h.arr[pos] > h.arr[parent]){
                swap(h.arr[pos], h.arr[parent]);
                pos = parent;
            }
            else break;
        }
    }
    else{
        while(2*pos + 1 < h.size){

            int left = 2*pos + 1;
            int right = 2*pos + 2;

            int largest = left;
            if(right < h.size && h.arr[right] > h.arr[left]){
                largest = right;
            }

            if(h.arr[pos] < h.arr[largest]){
                swap(h.arr[pos], h.arr[largest]);
                pos = largest;
            }
            else break;
        }
    }
}


void delete_2(heap &h, int x){
    int pos = -1;

    for(int i = 0; i < h.size; i++){
        if(h.arr[i] == x){
            pos = i;
            break;
        }
    }

    if(pos == -1) return;

    h.arr[pos] = h.arr[h.size - 1];
    h.size--;

    if(pos > 0 && h.arr[pos] < h.arr[(pos-1)/2]){

        while(pos > 0){
            int parent = (pos-1)/2;

            if(h.arr[pos] < h.arr[parent]){
                swap(h.arr[pos], h.arr[parent]);
                pos = parent;
            }
            else break;
        }
    }
    else{
        while(2*pos + 1 < h.size){

            int left = 2*pos + 1;
            int right = 2*pos + 2;

            int smallest = left;

            if(right < h.size && h.arr[right] < h.arr[left]){
                smallest = right;
            }

            if(h.arr[pos] > h.arr[smallest]){
                swap(h.arr[pos], h.arr[smallest]);
                pos = smallest;
            }
            else break;
        }
    }
}



int main(){
    heap h,h1;
    h.size =0;
    h1.size =0;
    insert_1(h,3);
    insert_1(h,19);
    insert_1(h,4);
    insert_1(h,9);
    for(int i=0;i<h.size;i++){
        cout << h.arr[i] << " ";
    }
    cout <<"\n";
    
    insert_2(h1,3);
    insert_2(h1,19);
    insert_2(h1,4);
    insert_2(h1,9);
    for(int i=0;i<h1.size;i++){
        cout << h1.arr[i] <<" ";
    }
    return 0;
}



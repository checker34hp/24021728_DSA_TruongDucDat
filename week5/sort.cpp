#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
         int min_dex =i;
         for(int j=i+1;j<n;j++){
             if(arr[j]<arr[min_dex]){
                  min_dex = j;
             }
         }
         if(min_dex!=i) swap(arr[min_dex],arr[i]);
    }
}

void bubble_sort(int arr[],int n){
     for(int i=0 ;i <n-1;i++){
         for(int j =0;j<n-i-1;j++){
             if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
         }
     }
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
         int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
 
int partition(int arr[],int left,int right){
        int pivot = arr[(left+right)/2];
        int i=left;
        int j = right;
        while(i<=j){
            while(arr[i] < pivot) i++;
            while(arr[j] >pivot) j--;
            if(i<=j){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        return i;
}
void quick_sort(int arr[],int left,int right){
    if(left >=right) return;
    int p = partition(arr,left,right);
    quick_sort(arr,left,p-1);
    quick_sort(arr,p,right);
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L, R;

    for (int i = l; i <= m; i++)
        L.push_back(a[i]);

    for (int i = m + 1; i <= r; i++)
        R.push_back(a[i]);

    int i = 0, j = 0, k = l;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < L.size())
        a[k++] = L[i++];

    while (j < R.size())
        a[k++] = R[j++];
}

void merge_sort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);

    merge(a, l, m, r);
}

int main(){
  int arr[150];
  int n;
  return 0;
}

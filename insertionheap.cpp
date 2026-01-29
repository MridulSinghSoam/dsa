#include <algorithm>
#include <iostream>
using namespace std;


class Heap{
    public:
    int size=0;
    int arr[1000];
    void print(){
        for (int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int val){
        int index=size;
        arr[index]=val;
        size++;
        if(size >= 1000) return;

        while(index>0){
            int parents=(index-1)/2;
            if(arr[parents]>arr[index]){
                swap(arr[parents],arr[index]);
                index=parents;
            }else{
                break;
            }
        }
    }
    void delection(){
        if(size==0) return ;
        arr[1]=arr[size-1];
        size--;
        //heapify
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            if(left<size && arr[left]<arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if (right<size && arr[right]<arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }else{
                return ;
            }
        }
    }
    void heafify(int arr[], int size, int i){
        int small=i;
        int left=2*i;
        int right=2*i+1;
        if(left<size && arr[left]<arr[small]){
            swap(arr[left],arr[small]);
            small=left;
        }
        else if(right<size && arr[right]<arr[small]){
            swap(arr[right],arr[small]);
            small=right;
        }
        else{
            return ;
        }
        if(small!=i){
            heafify(arr,size,small);
        }
        return ;
    }
};



int main(){
    Heap h;
    h.insert(5);
    h.insert(3);
    h.print();
    h.delection();  
    h.print();
    return 0;
};
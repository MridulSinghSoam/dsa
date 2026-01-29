// question2
#include <iostream>
using namespace std;

int arr[]={-8,-12,15,16,19,19};
int target=19;

int main(){
    int count=0;
    int l=0;
    int r=sizeof(arr)/sizeof(arr[0]);
    int z=1;
    
    while(l<r ||z<r){
        if(arr[l]+arr[r]+arr[z]==target){
            count++;
        }
        l++;
        r--;
        z++;

    }
    cout<<count;
    return count;
}



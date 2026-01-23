//geenrate doubly ll
#include <iostream>
using namespace std;    
#include <vector>

class Node {
    public: 
    int data;
    Node* next;
    Node* prev;
    Node(int data, Node* next = nullptr, Node* prev = nullptr) {
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

int main(){
    vector<int> a={11,2,3,4,4,5,6,7,8,9};
    Node* head=new Node(a[0],nullptr,nullptr);
    Node* current=head;
    for(int i=1;i<a.size();i++){
        Node* newNode=new Node(a[i],nullptr,nullptr);
        current->next=newNode;
        newNode->prev=current;
        current=current->next;
    }
    cout<<head->prev<<endl;
}






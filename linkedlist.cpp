#include <iostream>
using namespace std;
#include <vector>


struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

int main() {
    vector<int> a = {11, 2, 3, 4, 12, 11, 2, 3, 4};
    Node* head = new Node(a[0]);
    Node* current = head;
    for (int i=1;i<a.size();i++){
        current->next=new Node(a[i]);
        current=current->next;
    }
    //delete head of linked list
    Node* new_head = head->next;
    free(head);

    current = new_head;
    while (current != nullptr) {    
        cout << current->data << " ";
        current = current->next;
    }
    //delete the tail of linked list
    if (new_head == nullptr || new_head->next == nullptr) {
        return 0;
    }
    while (new_head->next->next==nullptr){
        new_head=new_head->next;
    }
    free(new_head->next);
    new_head->next=nullptr;
    
}





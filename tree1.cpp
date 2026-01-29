#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
    Node(int x){
        val=x;
        left=right=NULL;
    }
};

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<Node*> q;
    q.push(root);
    bool checker=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            int index=checker?i:size-1-i;
            level[index]=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(level);
        checker!=checker;
    }
    return result;
};




int main(){
    Node root=Node(12);
    Node root->left=Node(15);
    Node right=Node(16);
    Node right=Node(17);
    Node right=Node(19);
    Node right=Node(20);
    zigzag(root);
}


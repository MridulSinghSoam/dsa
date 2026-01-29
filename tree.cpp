Nice 👍
Here’s a **small, clean, interview-ready TREE cheat sheet** with **height, width, traversal, diameter, leaf count, etc.**
All codes are **short + easy to remember**.

---

## 🌳 Basic Tree Node (Binary Tree)

```cpp
struct Node {
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};
```

---

## 1️⃣ Height of Binary Tree

```cpp
int height(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

## 2️⃣ Size of Tree (Total Nodes)

```cpp
int size(Node* root) {
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
```

---

## 3️⃣ Count Leaf Nodes

```cpp
int leafCount(Node* root) {
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}
```

---

## 4️⃣ Width of Binary Tree (Max nodes at any level)

```cpp
int width(Node* root) {
    if(root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int ans = 0;

    while(!q.empty()) {
        int sz = q.size();
        ans = max(ans, sz);

        while(sz--) {
            Node* cur = q.front(); q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return ans;
}
```

---

## 5️⃣ Diameter of Tree (Longest Path)

```cpp
int diameter(Node* root, int &ans) {
    if(root == NULL) return 0;

    int lh = diameter(root->left, ans);
    int rh = diameter(root->right, ans);

    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}
```

### Call:

```cpp
int ans = 0;
diameter(root, ans);
```

---

## 6️⃣ Level Order Traversal (BFS)

```cpp
void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}
```

---

## 7️⃣ Tree Traversals (DFS)

### Inorder (L Root R)

```cpp
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

### Preorder (Root L R)

```cpp
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

### Postorder (L R Root)

```cpp
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

---

## 8️⃣ Check if Tree is Balanced

```cpp
int check(Node* root) {
    if(root == NULL) return 0;

    int lh = check(root->left);
    if(lh == -1) return -1;

    int rh = check(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return check(root) != -1;
}
```

---

## 9️⃣ Mirror (Invert) Binary Tree

```cpp
Node* mirror(Node* root) {
    if(root == NULL) return NULL;

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);

    return root;
}
```

---

## 🔟 Maximum Depth = Height


Got you 👍
Here’s **clean, small, beginner-friendly graph code** covering **DFS, BFS, and basics** (perfect for DSA + interviews).

I’ll use **C++**, **adjacency list**, and **0-based indexing**.

---

## 🔹 Basic Graph Representation (Adjacency List)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;   // n = nodes, m = edges
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this for directed graph
    }
}
```

---

## 🔹 DFS (Depth First Search)

### 🔸 Recursive DFS

```cpp
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";

    for(int neigh : adj[node]) {
        if(!vis[neigh]) {
            dfs(neigh, adj, vis);
        }
    }
}
```

### 🔸 Call DFS

```cpp
vector<int> vis(n, 0);
dfs(0, adj, vis);   // start DFS from node 0
```

---

## 🔹 BFS (Breadth First Search)

```cpp
void bfs(int start, vector<vector<int>> &adj, vector<int> &vis) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neigh : adj[node]) {
            if(!vis[neigh]) {
                vis[neigh] = 1;
                q.push(neigh);
            }
        }
    }
}
```

### 🔸 Call BFS

```cpp
vector<int> vis(n, 0);
bfs(0, adj, vis);
```

---

## 🔹 DFS using Stack (Iterative)

```cpp
void dfs_stack(int start, vector<vector<int>> &adj) {
    vector<int> vis(adj.size(), 0);
    stack<int> st;

    st.push(start);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(vis[node]) continue;

        vis[node] = 1;
        cout << node << " ";

        for(int neigh : adj[node]) {
            if(!vis[neigh]) {
                st.push(neigh);
            }
        }
    }
}
```

---

## 🔹 BFS vs DFS (Quick)

| BFS                        | DFS                        |
| -------------------------- | -------------------------- |
| Uses **Queue**             | Uses **Stack / Recursion** |
| Level by level             | Goes deep first            |
| Shortest path (unweighted) | No shortest guarantee      |

---

## 🔹 Handle Disconnected Graph

```cpp
vector<int> vis(n, 0);
for(int i = 0; i < n; i++) {
    if(!vis[i]) {
        dfs(i, adj, vis);   // or bfs(i, adj, vis)
    }
}
```

---

## 🔹 Input Example

```
5 4
0 1
0 2
1 3
3 4
```

**DFS Output:** `0 1 3 4 2`
**BFS Output:** `0 1 2 3 4`

---

If you want next:

* 🔸 **Cycle detection**
* 🔸 **Connected components**
* 🔸 **Topological sort**
* 🔸 **Graph questions for interviews**

Just say the word 🚀
Perfect 👍
Here are **MOST IMPORTANT GRAPH QUESTIONS with SHORT & CLEAN C++ CODE**
(Interview + exam ready)

---

# 1️⃣ DFS Traversal

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for(int v : adj[node]) {
        if(!vis[v])
            dfs(v, adj, vis);
    }
}
```

---

# 2️⃣ BFS Traversal

```cpp
void bfs(int start, vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int v : adj[node]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
```

---

# 3️⃣ Count Connected Components

```cpp
int countComponents(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            cnt++;
        }
    }
    return cnt;
}
```

---

# 4️⃣ Cycle Detection (Undirected Graph)

```cpp
bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for(int v : adj[node]) {
        if(!vis[v]) {
            if(dfsCycle(v, node, adj, vis))
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}
```

---

# 5️⃣ Cycle Detection (Directed Graph)

```cpp
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path) {
    vis[node] = 1;
    path[node] = 1;

    for(int v : adj[node]) {
        if(!vis[v] && dfs(v, adj, vis, path))
            return true;
        else if(path[v])
            return true;
    }

    path[node] = 0;
    return false;
}
```

---

# 6️⃣ Topological Sort (DFS)

```cpp
void topoDFS(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for(int v : adj[node]) {
        if(!vis[v])
            topoDFS(v, adj, vis, st);
    }
    st.push(node);
}
```

---

# 7️⃣ Topological Sort (BFS – Kahn’s Algorithm)

```cpp
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0), ans;
    queue<int> q;

    for(int i = 0; i < n; i++)
        for(int v : adj[i])
            indeg[v]++;

    for(int i = 0; i < n; i++)
        if(indeg[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);

        for(int v : adj[node]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
    }
    return ans;
}
```

---

# 8️⃣ Shortest Path (Unweighted Graph)

```cpp
vector<int> shortestPath(int n, vector<vector<int>>& adj, int src) {
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int v : adj[node]) {
            if(dist[v] == -1) {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
```

---

# 9️⃣ Bipartite Graph Check

```cpp
bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int node = q.front(); q.pop();

                for(int v : adj[node]) {
                    if(color[v] == -1) {
                        color[v] = !color[node];
                        q.push(v);
                    }
                    else if(color[v] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
}
```

---

# 🔥 MUST-REMEMBER PATTERNS

| Problem                    | Technique        |
| -------------------------- | ---------------- |
| Traversal                  | DFS / BFS        |
| Shortest path (unweighted) | BFS              |
| Cycle (undirected)         | DFS + parent     |
| Cycle (directed)           | DFS + path array |
| Course Schedule            | Topological Sort |
| Islands / Grid             | BFS / DFS        |

---

If you want next:

* 🔹 **LeetCode graph questions list**
* 🔹 **Grid problems with code**
* 🔹 **MST (Prim + Kruskal)**
* 🔹 **One-page Graph Cheat Sheet**

Just tell me 🚀

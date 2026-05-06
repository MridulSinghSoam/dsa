class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topo sort as khans alog
        vector<vector<int>> adj(numCourses);
        for (auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> indgree(numCourses,0);
        for (int i=0;i<numCourses;i++){
            for (auto it:adj[i]){
                indgree[it]++;
            }
        }

        queue<int>q;
        for (int i=0;i<numCourses;i++){
            if(indgree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();

            for (auto it:adj[node]){
                indgree[it]--;
                if(indgree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses){
            return topo;
        }else{
            return {};
        }
    }
};
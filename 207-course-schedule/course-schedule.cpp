class Solution {

    bool dfs(int node,vector<vector<int>>&adj,vector<int> &vis,stack<int> &st,vector<int> &pathVis){
            vis[node]=1;
            pathVis[node]=1;
            for (auto it:adj[node]){
                if (!vis[it]){
                    if(dfs(it,adj,vis,st,pathVis)){
                        return true;
                    }
                }
                else if(pathVis[it]){
                    return true;
                }
            }
            pathVis[node]=0;
            return false;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        //make graph from the prerequestis :
        vector<vector<int>>adj(numCourses);
        for (auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses,0);
        stack<int> st;
        vector<int> pathVis(numCourses,0);
        for (int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,st,pathVis)){
                    return false;
                }
            }
        }
        return true;
        // check if the size of array is equla ot hte size of original array then answer 
    }
};
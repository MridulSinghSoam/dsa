class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int time=0;
        //size of grid:
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({{i,j},time});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int> disr={-1,0,1,0};
        vector<int> disc={0,1,0,-1};
        while (!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(t,time);
            for (int i=0;i<4;i++){
                int newr=r+disr[i];
                int newc=c+disc[i];
                if (newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                    q.push({{newr,newc},t+1});
                    vis[newr][newc] = 1;
                    grid[newr][newc] = 2;
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};
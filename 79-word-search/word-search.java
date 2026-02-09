class Solution {
    public boolean exist(char[][] board, String word) {
        int m=board.length;
        int n=board[0].length;
        boolean[][] vis=new boolean[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch=board[i][j];
                if(ch==word.charAt(0))
                {
                    if(dfs(i,j,board,vis,word,1)==true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public boolean dfs(int row,int col,char[][] board,boolean[][] vis,String word,int idx)
    {
        if(idx==word.length())
        {
            return true;
        }
        vis[row][col]=true;
        int m=board.length;
        int n=board[0].length;
        int[] di={-1,0,1,0};
        int[] dj={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+di[i];
            int ncol=col+dj[i];
            if(nrow<m&&nrow>=0&&ncol<n&&ncol>=0&&!vis[nrow][ncol]&&board[nrow][ncol]==word.charAt(idx))
            {
                if(dfs(nrow,ncol,board,vis,word,idx+1))
                {
                    return true;
                }
            }
        }
        vis[row][col] = false;

        return false;
    }
}
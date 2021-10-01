class Solution {
public:
    int x[4] = {0, 1, 0, -1};
    int y[4] = {-1, 0, 1, 0};
    
    bool isValid(int i, int j, int n, int m)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        
        int ans = 0;
        vector<vector<int>> level(n,vector<int> (m,0));
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            ans = max(ans,level[i][j]);
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int xx = x[k] + i;
                int yy = y[k] + j;
                
                if(isValid(xx,yy,n,m) && grid[xx][yy]==1 && !level[xx][yy])
                    level[xx][yy] = level[i][j]+1,
                    grid[xx][yy] = 2,
                    q.push({xx,yy});
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)
                    return -1;
        
        return ans;
    }
};

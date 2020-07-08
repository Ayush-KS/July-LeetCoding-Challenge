// Island Perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m)
            return 0;
        int n = grid[0].size();
    
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    if(!i || !grid[i - 1][j])
                        ans++;
                    if(!j || !grid[i][j - 1])
                        ans++;
                    if(i == m - 1 || !grid[i + 1][j])
                        ans++;
                    if(j == n - 1 || !grid[i][j + 1])
                        ans++;
                }
            }
        }
        
        return ans;
    }
};
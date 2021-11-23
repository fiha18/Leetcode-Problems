 /*
    Using DFS Approach Recursively:
        if (i,j) is current position then possible movement:
            (i-1,j), (i+1,j) - Horizontally
            (i,j-1), (i,j+1) = Vertically
    Time Complexity - O(n) - n is the no of 1s
    Space Comlexity - (row*col*(auxilary stack memory)) - if all the element is 1 then recursion for all the element 
    Actually Recursion is using Auxilary Stack
 */
 void mark_island(int i,int j, int row, int col, vector<vector<char>>& grid)
    {

        if(i<0|| j<0|| i>=row|| j>=col|| grid[i][j]!='1')
        {
            return;
        }
        grid[i][j] = '2';
        
        
        mark_island(i+1,j,row,col,grid);
        mark_island(i,j+1,row,col,grid);
        mark_island(i-1,j,row,col,grid);
        mark_island(i,j-1,row,col,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int no_of_islands = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == '1')
                {
                    mark_island(i,j,row,col,grid);
                    no_of_islands+=1;
                }
            }
        }
        return no_of_islands;
    }
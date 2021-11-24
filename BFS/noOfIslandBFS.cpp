/*
Using BFS Approach:
    1 - Traversed to each element and checked if it is 1, then
    2 - Doing BFS for each element which can move horizontally(x+1 or x-1) or vertically(y+1 or y-1)
    Time Complexity for the BFS part will be O(n) - n is the no of element with 1
    Space Complexity for BFS will be using queue O(m) - m is the maximum no of 1s in 1 island 
*/

 int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int islands = 0;
        int xA[4] ={1,0,-1,0}; 
        int yA[4] ={0,1,0,-1};
        for(int i= 0; i< row; i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == '1')
                {
                islands++;
                grid[i][j] = '2';
                queue<pair<int,int>> q;
                q.push(pair<int,int>(i,j));
                while(!q.empty())
                {
                       pair<int,int> temp = q.front();
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                             int x = temp.first + xA[k];
                             int y = temp.second + yA[k];
                             if(x>=0 && x<row && y>=0 && y< col && grid[x][y] == '1')
                             {
                                grid[x][y] = '2';
                                q.push(pair<int,int>(x,y));
                             }
                        }
                }
            }
        }
    }
return islands;
}
 int orangesRotting(vector<vector<int>>& grid) {
        int r,c, time =0,cntCheck = 0;
     int m = grid.size(),n = grid[0].size();
     for (int i = 0; i < m; ++i)
     {
         /* code */
        for (int j = 0; j < n; ++j)
        {
            if(grid[i][j] != 1)
            {
                cntCheck++;
            }
        }
     }
    if(cntCheck == m*n)
    {
        return 0;
    }
    queue<vector<int>> q;
    for (int i = 0; i < m; ++i)
     {
         /* code */
        for (int j = 0; j < n; ++j)
        {
            if(grid[i][j] == 2)
            {
            vector<int> root(2);
            root[0] = i, root[1] = j;
            q.push(root);
            }
            /* code */
        }
     }
 
     while(!q.empty())
     {
        int qLen = q.size();
        time+=1;
        for (int k = 0; k < qLen; ++k)
        {
            /* code */
            vector<int> temp(2);
            temp = q.front();
            int i = temp[0], j =temp[1];
            q.pop();
            if(grid[i][j] == 2)
            {
                if((i-1) >= 0)
                {
                    if(grid[i-1][j] == 1)
                    {
                     grid[i-1][j] = 2;
                     vector<int> t(2);
                     t[0] = i -1;
                     t[1] = j;
                     q.push(t);   
                    }
                }
                if((j-1) >= 0)
                {
                    if(grid[i][j-1] == 1)
                    {
                     grid[i][j-1] = 2;
                     vector<int> t(2);
                     t[0] = i;
                     t[1] = j-1;
                     q.push(t);   
                    }
                }
                if((i+1) < m)
                {
                    if(grid[i+1][j] == 1)
                    {
                     grid[i+1][j] = 2;
                     vector<int> t(2);
                     t[0] = i+1;
                     t[1] = j;
                     q.push(t);   
                    }
                }
                if((j+1) < n)
                {
                    if(grid[i][j+1] == 1)
                    {
                     grid[i][j+1] = 2;
                     vector<int> t(2);
                     t[0] = i;
                     t[1] = j+1;
                     q.push(t);   
                    }
                }
            }
        }
     }
      for (int i = 0; i < m; ++i)
     {
        for (int j = 0; j < n; ++j)
        {
            if(grid[i][j] == 1)
            {
                return -1;
            }
            /* code */
        }
     }
     return time-1;
    }
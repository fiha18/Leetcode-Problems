 int row = grid.size();
        int col = grid[0].size();
        //Visited array to store maximum value of k while passing to particular cell
        vector<vector<int>> visited(row,vector<int>(col,-1));
        //BFS approach and use of queue
        // Queue to store x,y, length of the shortest path till x y from 0 0 and value of k at particular cell
        queue<vector<int>> q;
        q.push({0,0,0,k});  
        while(!q.empty())
        {
            vector<int> temp(4);
            temp = q.front();
            q.pop();
            // poping x and y
            int x = temp[0], y = temp[1];
            // if cell index is out of grid then continue to next iteration 
            if(x<0|| y<0 || x>=row || y>=col)
                continue;

            // if bottom right corner is reached - return value of shortest path till now
            if(x==row-1 && y == col-1)
                return temp[2];

            // if cell has obstacle then check for value of k if we can eleminate obstacle or not
            if(grid[x][y] == 1)
            {
                if(temp[3] > 0)
                    temp[3]--;
                else
                    continue;
            }

            // if visited and it has elimination value more than or equal to current
            // then more effiicient path is there no need to move forward will this cell 
            if(visited[x][y] != -1 && visited[x][y] >=temp[3])
            {
                continue;
            }

            // No efficient path present then store current value of elimination possible
            visited[x][y] = temp[3];
            
            // pushing all the 4 possible movement
            q.push({x-1,y,temp[2]+1,temp[3]});
            q.push({x,y-1,temp[2]+1,temp[3]});
            q.push({x+1,y,temp[2]+1,temp[3]});
            q.push({x,y+1,temp[2]+1,temp[3]});
        }
        
        return -1;
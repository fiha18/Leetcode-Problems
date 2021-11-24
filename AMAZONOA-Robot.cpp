#include <bits/stdc++.h>

using namespace std;

/*
			int qLen = q.size();
			for (int k = 0; k < qLen ; ++k)
			{
				int x[4] = {-1,0,1,0};
				int y[4] = {0,-1,0,1};
				vector<int> temp(2);
				temp = q.front();
				int xTemp = temp[0],yTemp = temp[1];
				for (int j = 0; j < 4; ++j)
				{
					int xd = xTemp + x[j];
					int yd = yTemp + y[j];
					if(xd >= 0 && xd < m && yd >= 0 && yd < n && maze[xd][yd] == 0)
					{
						vector<int> qPart(2);
						qPart[0] = xd, qPart[1] = yd;
						q.push(qPart);
						time+=1;
					}
				}
			}
*/

bool isValid(int x, int y, int row, int col, vector<vector<int>> arr, vector<vector<bool>> visited)
{
	if(x>=0 && x<row && y>=0 && y<col && visited[x][y] == false && arr[x][y]!=0)
		return true;
	else
		return false;
}
int minSteps(vector<vector<int>> arr)
{
	int row = arr.size(), col = arr[0].size();
	int flag = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if(arr[i][j] == 9)
				flag = 1;
		}
	}
	if(flag == 0)
		return -1;
	vector<vector<bool>> visited(row, vector<bool> (col,false));	
	queue<vector<int>> q;
	vector<int> id(3);
	id[0] = 0, id[1] = 0,id[2] = 0;
	vector<vector<int>> distance_matrix(row, vector<int> (col,1000));
	q.push(id);
	vector<int> temp;
	while(!q.empty())
	{
		vector<int> temp;
		temp = q.front();
		q.pop();
		int x=temp[0],y=temp[1],distance=temp[2];
		distance_matrix[x][y] = distance;
		visited[x][y] = true;
		if(arr[x][y] == 9)
			return distance;
		int new_dist = distance + 1;
		if(isValid(x+1,y,row,col,arr,visited))
			{
				vector<int> p(3);
				p[0]=x+1,p[1]=y,p[2]=new_dist;
				q.push(p);
			}
		if(isValid(x,y+1,row,col,arr,visited))
			{
				vector<int> p(3);
				p[0]=x,p[1]=y+1,p[2]=new_dist;
				q.push(p);
			}
		if(isValid(x-1,y,row,col,arr,visited))
			{
				vector<int> p(3);
				p[0]=x-1,p[1]=y,p[2]=new_dist;
				q.push(p);
			}
		if(isValid(x,y-1,row,col,arr,visited))
			{
				vector<int> p(3);
				p[0]=x,p[1]=y-1,p[2]=new_dist;
				q.push(p);
			}
	}
	return -1;
}


int main()
{
	int row,col;
	cin >> row >> col;
	cout << endl;
	vector<vector<int>> arr;
	for (int i = 0; i < row; ++i)
	{
		vector<int> r;
		for (int j = 0; j < col; ++j)
		{
			int x;
			cin >> x;
			r.push_back(x);
		}
		arr.push_back(r);
	}
	int minSt;
	minSt = minSteps(arr);
	cout << minSt << endl;
	return 0;
}

/*
 int row = grid.size(), col = grid[0].size();
    int islands = 0;
    for(int i= 0; i< row; i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j] == '1')
            {
            islands++;
            grid[i][j] = '0';
            queue<vector<int>> q;
            vector<int> root(2);
            root[0] = i;
            root[1] = j;
            q.push(root);
            while(!q.empty())
            {
                    vector<int> temp;
                    temp = q.front();
                    q.pop();
                    int x = temp[0],y = temp[1];
                    //visited[temp[0]][temp[1]] = true;
                    if(x>=0 && x< row && y+1>=0 && y+1< col && grid[x][y+1] == '1')
                    {
                            //visited[x-1][y] = true;
                            grid[x][y+1] = '0';
                            vector<int> out(2);
                            out[0] = x;
                            out[1] = y+1;
                            q.push(out);
                    }
                    if(x+1>=0 && x+1< row && y>=0 && y< col && grid[x+1][y] == '1')
                    {
                            //visited[x][y-1] = true;
                            grid[x+1][y] = '0';
                            vector<int> out(2);
                            out[0] = x+1;
                            out[1] = y;
                            q.push(out);
                    }
                    if(x>=0 && x< row && y-1>=0 && y-1< col && grid[x][y-1] == '1')
                    {
                            //visited[x+1][y] = true;
                            grid[x][y-1] = '0';
                            vector<int> out(2);
                            out[0] = x;
                            out[1] = y-1;
                            q.push(out);
                    }
                    if(x-1>=0 && x-1< row && y>=0 && y< col && grid[x][y-1] == '1')
                    {
                            //visited[x][y+1] = true;
                            grid[x-1][y] = '0';
                            vector<int> out(2);
                            out[0] = x-1;
                            out[1] = y;
                            q.push(out);
                    }   
                }
            }
        }
    }
    
    
    return islands;
    }
*/

/*
int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
*/
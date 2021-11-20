#include <bits/stdc++.h>
using namespace std;

int mazeRunner(vector<vector<int>> maze,int m,int n,int x ,int y)
{
	vector<vector<int>> gold;
	vector<int> root(2);
	root = {0,0};
	gold.push_back(root);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(maze[i][j] == 2)
			{
				vector<int> g(2);
				g[0] = i,g[1] = j;
				gold.push_back(g);
			}
		}
	}
	vector<int> des(2);
	des[0] = x, des[1] = y;
	gold.push_back(des);
	queue<vector<int>> q;
	int time = 0;
	for (int i = 0; i < gold.size(); ++i)
	{
		q.push(gold[i]);
		while(!q.empty())
		{
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
		}
	}
	return time;

}

int main()
{
	int m,n;
	cout << "Provide m,n" << endl;
	cin >> m >> n;
	vector<vector<int>> maze;
	cout << "Maze matrix" << endl;
	for (int i = 0; i < m; ++i)
	{
		vector<int> v(n);
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		maze.push_back(v);
	}
	cout << "Provide x , y" << endl;
	int x,y;
	cin >> x >> y;
	int result = mazeRunner(maze,m,n,x,y);
	cout << result;
	return 0;
}
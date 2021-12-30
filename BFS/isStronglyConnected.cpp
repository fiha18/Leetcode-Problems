#include <bits/stdc++.h>
using namespace std;

void BFS(int root, vector<vector<int>> adjList, vector<int> &visited)
{
	queue<int> q;
	q.push(root);
	visited[root]  = 1;
	while(!q.empty())
	{
		int qLen = q.size();
		for (int i = 0; i < qLen; ++i)
		{
			/* code */
			int node = q.front();
			q.pop();
			int adjLen = adjList[node].size();
			for (int j = 0; j < adjLen ; ++j)
			{
				/* code */
				int temp = adjList[node][j];
				if(!visited[temp])
				{
					visited[temp] = 1;
					q.push(temp);
				}
			}
		}
	}
}

bool isStronglyConnected(int N, vector<vector<int>> adjList)
{
	for(int i = 0; i< N ; i++)
	{
		vector<int> visited(N,0);
		BFS(i,adjList,visited);
		for (int j = 0; j < N; ++j)
		{
			/* code */
			if(!visited[j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	
	int n;
	cin >> n;

	vector<vector<int>> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };

    vector<vector<int>> adjList(n);
    for(int i = 0 ; i < edges.size(); i++)
    {
    	int src = edges[i][0];
    	int des = edges[i][1];
    	adjList[src].push_back(des);
    }
    if(isStronglyConnected(n,adjList))
    	cout << "true";
    else
    	cout << "false";

	return 0;
}
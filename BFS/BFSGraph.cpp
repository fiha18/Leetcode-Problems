vector<int> BFS(int Vertex, vector<int> adj[]){

	vector<int> bfsResult;

	vector<int> visited(Vertex+1,0);

	for (int i = 1; i <= Vertex; ++i)
	{
		/* code */
		if(visited[i])
		{
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				bfsResult.push_back(node);

				for (int it : adj[node])
				{
					/* code */
					if(!visited[it])
					{
						q.push(it);
						visited[it] = 1;
					}
				}
			}
		}
	}
	return bfsResult;
}
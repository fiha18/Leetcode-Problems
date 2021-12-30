// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfsIterative(int i, int V, vector<int> adj[], vector<int> &visited, vector<int> &storeDFS)
    {
        stack<int> st;
        st.push(i);
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!visited[node])
            {
                storeDFS.push_back(node);
                visited[node] = 1;
            }
            for(auto ad : adj[node])
            {
                if(!visited[ad])
                {
                st.push(ad);
                }
            }
        }
    }

     void dfsRecursive(int i, int V, vector<int> adj[], vector<int> &visited, vector<int> &storeDFS)
    {
         storeDFS.push_back(i);
        visited[i] = 1;
        for(auto ad : adj[i])
        {
            if(!visited[ad])
            {
                dfsRecursive(ad,V,adj,visited,storeDFS);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> storeDFS;
        vector<int> visited(V,0);
        for(int i=0; i < V ; i++)
        {
            if(!visited[i])
            {
                dfsRecursive(i,V,adj,visited,storeDFS);
            }
        }
        return storeDFS;   
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
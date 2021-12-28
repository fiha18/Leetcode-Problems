// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    bool BFS(int N,int i,int j , vector<vector<int>> graph)
    {
        vector<int> visited(N,0);
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int qLen = q.size();
            for(int k = 0; k<qLen; k++)
            {
                int node = q.front();
                q.pop();
                if(node == j)
                {
                    return true;
                }
                for(int j = 0; j < N ; j++)
                {
                    if(!visited[j] && graph[node][j] && j != i)
                    {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
        return false;
        
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>>result(N, vector<int>(N,0));
        
        
        for(int i = 0; i<N ; i++)
        {
            for(int j = 0 ; j < N; j++)
            {
                if(graph[i][j])
                {
                    result[i][j] = 1;
                }
                else
                {
                    if(BFS(N,i,j,graph))
                    {
                        result[i][j] = 1;
                    }
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends
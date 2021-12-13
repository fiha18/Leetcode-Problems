#include<bits/stdc++.h>
using namespace std;


int check(int A, int B)
{
    int cnt = 0;
    while(A!=B)
    {
        A=A>>1;
        B=B>>1;
        cnt++;
    }
    return (62 - cnt);
}
vector<int> dfs(vector<int> adj[], vector<bool> visited,int node,int root)
{
    vector<int> ancestor;
    ancestor.push_back(node);
    for(int i: adj[node])
    {
        cout << i << " ";
        if(i == root)
        {
            return;
        }
        if(visited[i] == false)
        {
            visited[i] = true;
            dfs(adj,ancestor,visited,i,root);
        }
        continue;
    }
}
vector<int> solve (int N, vector<int> A, vector<vector<int> > edges, int V, int X) {
   // Write your code here
   vector<int> adj[N];
   vector<bool> visited(N,false);
   int e = edges.size();
   //cout << e;
   for(int i =0;i<e;i++)
   {
       int u = edges[i][0];
       int v = edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   
   vector<int> output;
   
       vector<int> ancestor;
       dfs(adj,ancestor,visited,X,1);
       for (int i = 0; i < ancestor.size(); ++i)
       {
        cout << ancestor[i];
       }
       int longest_prefix = 0;
       for(int j=0;j<ancestor.size();j++)
       {
            longest_prefix = max(longest_prefix,check(V,A[ancestor[j]-1]));
       }
       output.push_back(longest_prefix);
   return output;
}

int main() {

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
        cin >> A[i_A];
    }
    vector<vector<int> > edges(N-1, vector<int>(2));
    for (int i_edges = 0; i_edges < N-1; i_edges++)
    {
        for(int j_edges = 0; j_edges < 2; j_edges++)
        {
        	cin >> edges[i_edges][j_edges];
        }
    }
    //cout << edges.size();
    int V,X;
    cin >> V >> X;
    vector<int> out;
    out = solve(N, A, edges,V,X);
    cout << endl;
    for(int i= 0; i < out.size(); i++)
    {
        cout << " " << out[i];
    }
        cout << "\n";
}

/*

Input

1
10
88 78 46 95 84 98 55 3 68 42
3 7
8 7
7 5
4 6
7 9
10 1
1 7
2 7
1 4
6
26 9
50 7
79 10
40 1
77 5
50 3

output - 56 59 57 55 57 59 

Input

1
10
34 48 8 72 67 90 15 85 7 90
4 9
10 1
1 7
5 1
9 1
1 8
3 1
2 1
6 1
9
61 5
85 7
55 3
80 1
34 4
86 7
88 3
43 1
79 8

output
57 55 57 55 62 55 55 58 57 
*/

#include<bits/stdc++.h>
using namespace std;
int BFS(int A, int B, vector<int> Arr)
{
if(A==B)
   { 
      return 0;  
   }
   queue<int> q;
   q.push(A);
   q.push(B);
   int steps = 0;
   set<vector<vector<int>>> s;
   while(!q.empty())
   { 
      int temp1 = q.front();
      q.pop();
      int temp2 = q.front();
      q.pop();
      if(temp1 == temp2)
      {
         return steps;
      }
      int next1 = Arr[temp1-1];
      int next2 = Arr[temp2-1];
      vector<vector<int>> p(2);
      vector<int> p1(2);
      p1[0] = temp1;
      p1[1] = temp2;
      vector<int> p2(2);
      p2[0] = next1;
      p2[1] = next2;
      p[0] = p1;
      p[1] = p2;
      if(s.find(p)!=s.end())
      {
         return -1;
      }
      s.insert(p);
      steps+=1;
      q.push(next1);
      q.push(next2);
   }

}
vector<int> collision_time (int N, int Q, vector<int> Arr, vector<vector<int> > AB) {
   // Write your code here
   
   vector<int> res;
   for(int i=0;i<Q;i++){
   
   int A = AB[i][0];
   int B = AB[i][1];
   int x = BFS(A,B,Arr);
   res.push_back(x);
   }
   return res;
}

int main() {

    string number = "12345";
    number[2] = '0'+6;
    cout << number;
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> Arr(N);
    for(int i_Arr = 0; i_Arr < N; i_Arr++)
    {
    	cin >> Arr[i_Arr];
    }
    vector<vector<int> > AB(Q, vector<int>(2));
    for (int i_AB = 0; i_AB < Q; i_AB++)
    {
    	for(int j_AB = 0; j_AB < 2; j_AB++)
    	{
    		cin >> AB[i_AB][j_AB];
    	}
    }

    vector<int> out_;
    out_ = collision_time(N, Q, Arr, AB);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << "\n" << out_[i_out_];
    }
}

/*



7 4
2 3 3 5 4 4 3
1 7
4 5
7 6
2 2

output 
2
-1
-1
0


9 10
2 3 4 5 6 4 3 9 9
4 1
5 7
2 7
1 9
2 4
7 4
6 3
9 8
5 5
1 6


output
3
2
1
-1
-1
-1
1
1
0
-1
*/
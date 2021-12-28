#include <bits/stdc++.h>
using namespace std;
void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        for(int i =0; i < n ; i++)
        {
            for(int j = 0; j< m ; j++)
            {
                int cnt = 0;
                // Checking if neighbour is live or not
                if(  ((i - 1) >=0 && (i-1)<n) && board[i-1][j]%10 == 1)
                {
                    cnt++;
                }
                if(  ((i + 1) < n && (i+1)>=0) && board[i+1][j]%10 == 1)
                {
                    cnt++;
                }
                if(  ((j - 1) >=0 && (j-1) < m) && board[i][j-1]%10 == 1)
                {
                    cnt++;
                }
                if(  ((j+1) >=0 && (j + 1) < m) && board[i][j+1]%10 == 1)
                {
                    cnt++;
                }
                if(  ((i - 1) >=0 && (j-1) >=0 && (i-1) <n && (j-1) < m) && board[i-1][j-1]%10 == 1)
                {
                    cnt++;
                }
                if(  ((i - 1) >=0 && (i-1) <n && (j+1) >=0 && (j+1) < m) && board[i-1][j+1]%10 == 1)
                {
                    cnt++;
                }
                if(  ((i+1)>=0 && (i + 1) < n && (j-1) >=0 &&(j-1) < m) && board[i+1][j-1]%10 == 1)
                {
                    cnt++;
                }
                if(  ((i+1) >=0 && (i + 1) <n && (j+1) >= 0 && (j + 1) < m) && board[i+1][j+1]%10 == 1)
                {
                    cnt++;
                }
                // updating the board value to keep track of live neighbours
                int s = cnt*10 + board[i][j];
                board[i][j] = s;
            }
        }
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                // Here count is the no of live neighbours
                int cnt = board[i][j]/10;
                // Here val is the original value of the cell
                int val = board[i][j]%10;

                // Checking according to the condition provided and updating the cell with final value

                if(val ==1 && cnt < 2)
                {
                    board[i][j] = 0;
                    continue;
                }
                if(val == 1 && (cnt == 2 || cnt == 3))
                {
                    board[i][j] = 1;
                    continue;
                }
                if(val == 1 && cnt > 3)
                {
                    board[i][j] = 0;
                    continue;
                }
                if( val == 0 && cnt !=3)
                {
                    board[i][j] = 0;
                    continue;
                }
                if(val == 0 && cnt == 3)
                {
                    board[i][j] = 1;
                    continue;
                }
            }
        }  
    }

int main()
{
    int n;
    cin >> n;
    int m ;
    cin >> m;


    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    gameOfLife(matrix);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
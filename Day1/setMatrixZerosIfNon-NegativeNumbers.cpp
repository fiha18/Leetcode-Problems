#include <bits/stdc++.h>
using namespace std;



void verticalUp(vector<vector<int>>& matrix, int i, int j, int n ,int m)
    {
    	if(j >=0 && j < m)
        {	if(matrix[i][j] != 0 && matrix[i][j] != -1)
                {   //cout << matrix[i][j] << i << j << endl; 
                	matrix[i][j] = 0;}         
            verticalUp(matrix,i,j-1,n,m);}
        else
        	return;

                    
    }

 void verticalDown(vector<vector<int>>& matrix, int i, int j, int n ,int m)
    {
    	if(j >=0 && j < m)
        {	if(matrix[i][j] != 0 && matrix[i][j] != -1)
                {   //cout << matrix[i][j] << i << j << endl; 
                	matrix[i][j] = 0;}
            verticalDown(matrix,i,j+1,n,m);}
        else
        	return;

                    
    }
void horizontalLeft(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        if(i >=0 && i <n)
       { if(matrix[i][j]!=0 && matrix[i][j] != -1)
                {   //cout << matrix[i][j]<< i << j << endl;
                	matrix[i][j] = 0;
                }
         horizontalLeft(matrix,i-1,j,n,m);}
        else
        	return;
    }

void horizontalRight(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        if(i >=0 && i <n)
       { if(matrix[i][j]!=0 && matrix[i][j] != -1)
                {   //cout << matrix[i][j]<< i << j << endl;
                	matrix[i][j] = 0;
                }
         horizontalRight(matrix,i+1,j,n,m);}
        else
        	return;
    }
void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i =0 ; i<n ;i++)
        {
            for(int j = 0; j < m ; j++)
            {
               if(matrix[i][j] == 0)
               {
                    matrix[i][j] = -1;
               }
            }
        }
        for(int i =0 ; i<n ;i++)
        {
            for(int j = 0; j < m ; j++)
            {
               if(matrix[i][j] == -1)
               {
               		verticalUp(matrix,i,j,n,m);
                    verticalDown(matrix,i,j,n,m);
                    horizontalLeft(matrix,i,j,n,m);
                    horizontalRight(matrix,i,j,n,m);
                    matrix[i][j] = 0;
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

	setZeroes(matrix);

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
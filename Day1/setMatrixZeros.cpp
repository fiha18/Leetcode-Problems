#include <bits/stdc++.h>
using namespace std;

// Time Complexity  - O(n*m) and Space Complexity - O(1)
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Keeping Track if any of the first row or first column have 0    
        bool firstRow = false;
        bool firstColumn = false;
        
        for(int i = 0; i< n;i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i==0)firstRow = true;
                    if(j==0)firstColumn=true;

                    // making its corresponding 1st row and 1st column value 0 this will optimize the work
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i< n;i++)
        {
            for(int j = 1; j<m; j++)
            {
                // If any of the corresponding 1st row or 1st column is 0 then this element will update to 0
                if(!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Now if there is any first row element was 0 then First row will become 0 
        if(firstRow)
        {
            for(int i=0; i< m; i++)
            {
                matrix[0][i] = 0;
            }
        }

        // Now if there is any first column element was 0 then First column will become 0
        if(firstColumn)
        {
            for(int i = 0; i<n ;i++)
            {
                matrix[i][0] = 0;
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
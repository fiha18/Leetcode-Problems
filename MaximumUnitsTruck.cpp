/*
Greedy approach : We need to sort the 2D vector in according to 2nd element in each vector of 2D vector.
                  Taking maximum boxUnits boxType first and consecutivly decreasing the truckSize untill it becomes 0


Time Complexity - O(nlogn)
*/


int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){return a[1]>b[1];});
        int ans =0;
        for(int i=0;i<boxTypes.size();i++)
        {
            int x = min(boxTypes[i][0],truckSize);
            ans+=x*boxTypes[i][1];
            truckSize-=x;
            if(truckSize==0)
                break;
        }
        return ans;
    }
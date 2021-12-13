/*
Approach :
    store frequency of elements in lookup 
    then storing the frequency in multiset - it will be sorted automatically in the multiset
    comparing value in the multiset with k and decreasing value of k and removing element from multiset
    After if the value of k == 0 then break
    The required least unique integer count will be size of multiset remaining.


Time Complexity - O(NlogN)
Space Complexity - O(2N) - for lookup and multiset

*/


int findLeastNumOfUniqueInts(vector<int>& arr, int k) {lookup<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i])!=m.end())
            {
                m[arr[i]]++;
            }
            else
                m[arr[i]]=1;
        }
        multiset<int> s;
        lookup<int,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            s.insert(itr->second);
        }
        multiset<int>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            if(k==0)break;
            if(*it<=k)
            {
                k-=*it;
                s.erase(it);
            }
           
        }
        return s.size();
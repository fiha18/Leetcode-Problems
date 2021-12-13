 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map for look up for the num1
        map<int,int> map;
        int n = nums2.size();

        // Stack is the efficient Data structure 
        stack<int> s;
        // Pushing the last element
        s.push(nums2[n-1]);

        // We will iterate in reverse order
        for(int i = n-1 ; i >= 0;i--)
        {
            // Checking if stack top is less then we will pop till element is not less
            if(s.top()<nums2[i])
            {
                while(!s.empty() && s.top() < nums2[i])
                {
                    s.pop();
                }
            }
            // If stack top is greater then the element then it is the nextGreaterElement
            if(!s.empty() && s.top() > nums2[i])
            {
                map.insert(pair<int,int>(nums2[i],s.top()));
                s.push(nums2[i]);
            }
            // If no next greater element
            else
            {
                map.insert(pair<int,int>(nums2[i],-1));
                s.push(nums2[i]);
            }
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(map[nums1[i]]);
        }
        
        return res;
    }
class Solution {
public:
unordered_map<int,int> lookup;   
    // n*(2*(2*n))*(2*n)*(2*n) = n^3*2^(2*n)
    int dp(int a, int mask, vector<int>& nums, int m){
        if(mask==0) return 0;
        // for creating a unique key we can do mask*10
        int key=a+mask*10;
        if(lookup.find(key)==lookup.end()){
            int maxVal=0;
            for(int i=0;i<m;i++){
                // i is present in the mask then (1<<i) & mask will be true 
                // if mask is 31 (11111) and i = 3 then (1<<i) is 00100 then (11111)&(00100) is true
                if(mask&(1<<i)){
                    for(int j=i+1;j<m;j++){
                        // same checking if jth element is not yet removed from mask
                        if(mask&(1<<j)){
                            // comparing maxVal till now for ith element with next iteration as a represent iteration
                            // using inbuilt gcd function of c++
                            maxVal=max(maxVal,a*__gcd(nums[i],nums[j])+dp(a+1,mask^(1<<i)^(1<<j),nums,m));;
                        }
                    }
                }
            }
            
            lookup[key]=maxVal;
        }
        return lookup[key];
    }
    int maxScore(vector<int>& nums) {
         // Using bit masking we can check for 2^n possibilities
        // where if 1 is in bit representaion then that index element is there in the sub array
        // (a,mask) = max((a,mask),a*gcd(i,j)+(a+1,submask))
        //  n*2^(2*n)*(2*n)*(2*n) =(n^3)*(2^(2*n))
        int m=nums.size();
        // initial mask = 2^n - 1
        return dp(1,(1<<m)-1,nums,m);
    }
};
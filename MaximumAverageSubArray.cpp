double findMaxAverage(vector<int>& nums, int k) {
        int sum_K=0;
        for(int i=0; i< k; i++)
        {
            sum_K+=nums[i];
        }
        double max_avg = double(sum_K)/double(k);
        int n = nums.size();
        for(int i = 1; i < n - k + 1; i++)
        {
            sum_K = sum_K - nums[i-1] + nums[k+i-1];
            double avg = double(sum_K)/double(k);
            if(avg > max_avg)
            {
                max_avg = avg;
            }
        }
        return max_avg;
    }
void sortColors(vector<int>& nums) {
        int low = 0, mid = 0,high = nums.size()-1;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                { 
                    int temp;
                    temp = nums[low];
                    nums[low] = nums[mid];
                    nums[mid] = temp;
                    low++;
                    mid++;
                    break;
                }
                case 1:
                {
                    mid++;
                    break;
                }
                case 2:
                    {
                    int temp;
                    temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                    high--; // won't increase mid here becoz we willstop mid at the end of 1.
                    break;
                    }
            }

    }
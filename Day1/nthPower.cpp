 int myPow(int x, int n) {
       
       int pow = 1;
        // If n is negative then 1st exp will be reverse and can continue 
        if(n < 0)
           x = 1/x;
       while(n!=0)
       {
       		// When bit is 1 i.e. division with 2 gives remainder
            if(n%2 != 0)
            {
                pow*=x;
            }
            // updating x at each iteration with powers of 2, 4, 8, and so on
            x = x* x;

            // Dividing n with 2 to create it equivalent to bits
            n = n/2;
       }
        return pow;
    }
    int mySqrt(int x) {
        if(x == 1 || x == 0)return x;
        int low = 1;
        int high = x/2;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(pow(mid,2) == x)
                return mid;
            else if(pow(mid,2) < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low-1;
    }


    int nthRoot(int x,int n) {
        if(x == 1 || x == 0)return x;
        int low = 1;
        int high = x/2;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(pow(mid,n) == x)
                return mid;
            else if(pow(mid,n) < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low-1;
    }
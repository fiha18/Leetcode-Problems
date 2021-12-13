/*
Second Approach
In order to improve efficiency we will opt for Binary Exponentiation using which we can calculate xn using O log2(N) multiplications.

Basic Idea is to divide the work using binary representation of exponents
i.e. is to keep multiplying pow with x, if the bit is odd, and multiplying x with itself until we get 0
We will use very 1st example of 1st Approach i.e.
x = 7, n = 11 and pow = 1
Here, we have to calculate 711
Binary of n i.e. (11)1 is (1011)

1    0    1    1
2^3  2^2  2^1  2^0   <-- Corresponding place values of each bit


OR we can also write this as
1 0 1 1
8 4 2 1 <-- Corresponding place values of each bit

Bit is 1 if after dividing by 2 there is remainder So -----> if (n%2) then multiply


Now, 7^8 × 7^2 × 7^1 == 7^11 as 7(8 + 2 + 1) == 711
NOTE: We have not considered 74 in this case as the 4th place bit is OFF

So, 78 × 72 × 71 == 5764801 × 49 × 7 == 1977326743 <-- Desired Output
Now, applying logic keeping this concept in mind
*/



double myPow(double x, int n) {
       
       double pow = 1;
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
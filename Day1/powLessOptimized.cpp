
/*
Binary Exponentiation

Time Complexity - O(log2(n))

Space Complexty - O(log2(n))

Have to write too much of code
*/

void setMap(map<int,double>& map,int m,int flag)
    {
        for(int i =2 ; i <= m ; i++)
        {
            int indx = (i - 1)*flag;
            map.insert(pair<int,double>(i*flag,map[indx]*map[indx]));
        }
    }
        
    vector<int> bitRep(int n)
    {
        vector<int> out;
        while(n!=0)
        {
            if(n%2)
            {
                out.push_back(1);
                n= n/2;
            }
            else
            {
                out.push_back(0);
                n = n/2;
            }
        }
        return out;
    }
    double myPow(double x, int n) {
        map<int,double> map;
        int flag;
        if(n == 0 || x == 1.0)
            return 1;
        if( x == -1 && (n%2))
            return -1;
        if( x == -1 && !(n%2))
            return 1;
        if(n>0)
        {
            map.insert(pair<int,double>(1,x));
            flag = 1;
        }
        else
        {
            double invert_x = 1/x;
            map.insert(pair<int,double>(-1,invert_x));
            flag = -1;
        }
        int m;
        if(n == -2147483648)
            m = 31;
        else
            m = log2(abs(n))+1;
        setMap(map,m,flag);
        vector<int> bits;
        bits = bitRep(n);
        double res = 1.0;
        
        for(int i = 0 ; i<bits.size();i++)
        {
            if(bits[i])
            {res*=bits[i]*map[(i+1)*flag];}
        }
        return res;
    }
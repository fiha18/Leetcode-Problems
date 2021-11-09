int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++)
        {
            while(charSet.find(s[r]) != charSet.end())
            {
                charSet.erase(charSet.find(s[l]));
                l+=1;
            }
            charSet.insert(s[r]);
            if(res < (r - l + 1))
            {
                res = r - l + 1;
            }
        }
        return res;
    }
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, biggest = 0;

        string result = "";
        while(i < s.size()){
            auto it = find(result.begin(), result.end(), s[i]);
            
            
            if(it != result.end())
                result.erase(0, it - result.begin() + 1);
            
            result += s[i];
            i++;

            biggest = max(biggest, (int)result.size());
        }

        return biggest;
    }
};
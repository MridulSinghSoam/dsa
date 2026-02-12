class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int leng=0;
        int maxLen=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                    mp[s[l]]--;
                    l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<int,int> mp;
        while(r<s.length()){
            while(mp[s[r]]>0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]+=1;
            maxi=max(r-l+1,maxi);
            r++;
        }
        return maxi;
    }
};
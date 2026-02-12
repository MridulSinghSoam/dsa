class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leng=0;
        int maxi=0;
        for (int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            for (int j=i;j<s.size();j++){
                if(mp[s[j]]==1)break;
                mp[s[j]]+=1;
                leng=j-i+1;
                maxi=max(maxi,leng);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int sub[256];
        int size=s.size();
        int maxlen=0;
        fill(sub,sub+256,-1);
        while(r<size){
            if(sub[s[r]]!=-1){
                if(sub[s[r]]>=l){
                    l=sub[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            sub[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};

from operator import itemgetter
class Solution:
    def frequencySort(self, s: str) -> str:
        #map of frequency , arranbe then print thimes into the times ir appers
        d={}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        ans=""
        sorted_chars = sorted(d.items(), key=itemgetter(1), reverse=True)
        for key,val in sorted_chars:
            ans+=key*val
        return(ans)
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans=[]
        bal=0
        for i in s:
            if i=='(' :
                if bal>0:
                    ans.append(i)
                bal+=1
            else:
                bal-=1
                if(bal>0):
                    ans.append(i)

        return "".join(ans)
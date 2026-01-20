class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arra;
        int open=0;
        int close=0;
        string current = "";
        parenthesis(arra,"",open,close,n);
        return arra;
    }
    void parenthesis(vector<string>& arra,string current,int open,int close,int n){
        if (open+close==2*n){
            arra.push_back(current);
            return;
        }
        if(open<n){
            parenthesis(arra,current+'(',open+1,close,n);
        }
        if (open>close){
            parenthesis(arra,current+')',open,close+1,n);
        }
    }
};
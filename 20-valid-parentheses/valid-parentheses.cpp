class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char a:s){
            if(a=='{' || a=='(' || a=='['){
                st.push(a);
            }else{
                //agar closing nhi h
                if(st.empty()){
                    return false;
                }
                char b=st.top();
                st.pop();
                if((b=='(' && a!=')')
                ||(b=='{' && a!='}')
                ||(b=='[' && a!=']')
                ){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
#include <iostream>
#include <vector>
using namespace std;

void genallstr(int n,string curr, vector<string> &result){
    if (curr.length()==n){
        result.push_back(curr);
        return;
    }
    genallstr(n,curr+'0',result);
    if (curr.length()==0 || curr.back()!='1'){
        genallstr(n,curr+'1',result);
    }
}


int main(){
    int n=4;
    vector<string> result;
    genallstr(n,"",result);
    cout<<"All valid binary strings of length "<<n<<":"<<endl;
    for (const string &s : result){
        cout<<s<<endl;
    }
    return 0;
}


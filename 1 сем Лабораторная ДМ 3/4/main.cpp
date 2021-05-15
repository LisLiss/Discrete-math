#include <bits/stdc++.h>

using namespace std;
ifstream f1("chaincode.in");
ofstream f2("chaincode.out");

int n;
vector <int> help;

int toInt(string s){
    int ans=0;
    for (int i=n-1; i>-1; i--){
        ans+=pow(2,n-1-i)*(s[i]-'0');
    }
    return ans;
}

int main(){
    f1>>n;
    help.resize(pow(2,n), 0);
    string s="";
    for (int i=0; i<n; i++){
        s.push_back('0');
    }
    f2<<s<<endl;
    help[0]=1;
    while (true){
        string ns=s.substr(1,n-1)+"1";
        int x=toInt(ns);
        if (help[x]==1){
            ns[n-1]='0';
            x-=1;
            if (help[x]==1){
                break;
            }
            help[x]=1;
            f2<<ns<<endl;
            s=ns;
        }
        else{
            help[x]=1;
            f2<<ns<<endl;
            s=ns;
        }
    }
    f1.close();
    f2.close();
    return 0;
}

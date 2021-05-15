#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ifstream f1("nextvector.in");
ofstream f2("nextvector.out");
string inc(){
    string ss=s;
    ll i=ss.size()-1;
    while (ss[i]!='0'){
        ss[i]='0';
        i--;
    }
    ss[i]='1';
    return ss;
}

string dec(){
    string ss=s;
    ll i=ss.size()-1;
    while (ss[i]!='1'){
        ss[i]='1';
        i--;
    }
    ss[i]='0';
    return ss;
}

int main()
{
    f1>>s;
    bool f1=false, f0=false;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='1') f1=true;
        if (s[i]=='0') f0=true;
    }
    if (f1 && f0){
        f2<<dec()<<endl<<inc();
    } else{
        if (f1){
            f2<<dec()<<endl<<"-";
        } else{
            f2<<"-"<<endl<<inc();
        }
    }
    return 0;
}

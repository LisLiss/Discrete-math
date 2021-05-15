#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;
int k, flag;
vector <ll> first, c, a, b, res;

void mul(){
    int na=a.size();
    int nb = b.size();
    vector <ll> ans(na+nb, 0);
    flag=0;
    for (int i=0; i<na; i++){
        for (int j=0; j<nb; j++){
            ans[i+j]+=a[i]*b[j];
            ans[i+j]%=MOD;
        }
    }
    for (int i=0; i<k; i++){
        res.push_back(ans[i]);
        if (ans[i]!=0) flag=i;
    }
}

void Q(){
    //q in a
    a.resize(k+1);
    a[0]=1;
    //cout<<k+1<<endl;
    //cout<<1<<" ";
    for (int i=0; i<k; i++){
        a[i+1]=-c[i];
    //    cout<<-c[i]<<" ";
    }
    //cout<<endl;
}
void P(){
    //p in res
    b=first;
    mul();
}
int main(){
    //2 line is first
    //3 line is c
    cin>>k;
    first.resize(k);
    c.resize(k);
    for (int i=0; i<k; i++){
        cin>>first[i];
    }
    for (int i=0; i<k; i++){
        cin>>c[i];
    }
    Q();
    P();
    cout<<flag<<endl;
    for (int i=0; i<=flag; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl<<a.size()-1<<endl;
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

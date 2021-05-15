#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream f1("num2choose.in");
ofstream f2("num2choose.out");
ll n, m, k;
vector <ll> ans;
vector <bool> num;

ll factor(ll nn, ll kk){
    if (nn-kk>kk){
        kk=nn-kk;
    }
    ll ans1=1;
    for (ll i=1; i<nn-kk+1; i++){
        ans1*=i;
    }
    ll ans2=1;
    for (ll i=kk+1; i<nn+1; i++){
        ans2*=i;
    }
    return ans2/ans1;
}

void numChoose(){
    for (ll i=0; i<k; i++){
        for (ll j=0; j<n; j++){
            if (num[j]) continue;
            if (i>0 && ans[i-1]>j) continue;
            ll help=factor(n-j-1, k-i-1);
            if (help<=m) m-=help;
            else {ans[i]=j; num[j]=true; break;}
        }
    }
}

void print(){
    for (ll i=0; i<k; i++){
        f2<<ans[i]+1<<" ";
    }
    f2<<endl;
}

int main(){
    f1>>n>>k>>m;
    ans.resize(k, 0);
    num.resize(n, false);
    numChoose();
    print();
    return 0;
}

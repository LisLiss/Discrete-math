#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f1("num2perm.in");
ofstream f2("num2perm.out");
vector <bool> was;
vector <int> ans;
ll n, k;
ll factorial(ll x){
    ll ans=1;
    for (ll i=1; i<x+1; i++){
        ans*=i;
    }
    return ans;
}
void print(){
    for (int i=0; i<n; i++){
        f2<<ans[i]+1<<" ";
    }
    f2<<endl;
}

void fromNum(ll k, ll i){
    for (ll j=0; j<n; j++){
        if (was[j]){
            continue;
        }
        if (k<factorial(n-i-1)){
            ans[i]=j;
            was[j]=true;
            fromNum(k, i+1);
        } else{
            k-=factorial(n-i-1);
        }
    }
}


int main()
{
    f1>>n>>k;
    was.resize(n, false);
    ans.resize(n, 0);
    fromNum(k,0);
    print();
    return 0;
}

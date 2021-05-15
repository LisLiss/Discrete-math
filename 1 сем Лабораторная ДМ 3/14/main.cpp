#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f1("perm2num.in");
ofstream f2("perm2num.out");
vector <bool> was;
vector <int> ans;
int n;
ll factorial(ll x){
    ll ans=1;
    for (ll i=1; i<x+1; i++){
        ans*=i;
    }
    return ans;
}

ll fromPer(){
    ll answer=0;
    for (int i=0; i<n; i++){
        for (int j=1; j<n+1; j++){
            if (j >= ans[i]) break;
            if (was[j]) continue;
            answer+=factorial(n-i-1);
        }
        was[ans[i]]=true;
    }
    return answer;
}


int main()
{
    cin>>n;
    ans.resize(n);
    for (int i=0; i<n; i++){
        cin>>ans[i];
    }
    was.resize(n, false);
    cout<<fromPer();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll k, m, MOD=1e9+7;
    cin>>k>>m;
    vector <ll> c(k);
    for (int i=0; i<k; i++){
        cin>>c[i];
    }
    vector <ll> ans(m+1), help(m+1);
    ans[0]=1;
    help[0]=1;
    for (int i=1; i<m+1; i++){
        for (int j=0; j<k; j++){
            ll cc=c[j];
            if (cc>i) continue;
            ans[i]+=help[i-cc];
            ans[i]%=MOD;
        }
        help[i]=0;
        for (int l=0; l<=i; l++){
            help[i]+=ans[l]*ans[i-l];
            help[i]%=MOD;
        }
    }
    for (int i=1; i<m+1; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

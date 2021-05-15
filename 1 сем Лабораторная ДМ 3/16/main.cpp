#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("choose2num.in");
ofstream f2("choose2num.out");
vector <ll> ans;
vector <bool> was;

ll n, k;

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

ll chooseNum(){
    ll answer=0;
    for (int i=0; i<k; i++){
        for (int j=0; j<ans[i]; j++){
            if (i>0 && ans[i-1]>j) continue;
            if (was[j]) continue;
            answer+=factor(n-j-1, k-i-1);
        }
        was[ans[i]]=true;
    }
    return answer;
}
int main()
{
    f1>>n>>k;
    ans.resize(k);
    was.resize(n,false);
    for (ll i=0; i<k; i++){
        f1>>ans[i];
        ans[i]--;
    }
    f2<<chooseNum();
    return 0;
}

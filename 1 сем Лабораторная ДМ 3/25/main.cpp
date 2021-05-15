#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector <ll> ans;
ll n, k;

ifstream f1("nextchoose.in");
ofstream f2("nextchoose.out");

void nexti(){
    ll maxi=n;
    for (ll i=k-1; i>-1; i--){
        if (ans[i]==maxi){
            maxi--;
            continue;
        }
        ans[i]++;
        maxi=ans[i];
        for (ll j=i+1; j<k; j++){
            maxi++;
            ans[j]=maxi;
        }
        for (ll j=0; j<k; j++){
            f2<<ans[j]<<" ";
        }
        return;
    }
    f2<<-1;
    return;
}

int main()
{
    f1>>n>>k;
    ans.resize(k);
    for (ll i=0; i<k; i++){
        f1>>ans[i];
    }
    nexti();
    return 0;
}

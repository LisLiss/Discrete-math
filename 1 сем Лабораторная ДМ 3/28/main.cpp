#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f1("nextmultiperm.in");
ofstream f2("nextmultiperm.out");
ll n;
vector <ll> ans, nexti;

void nextip(){
    for (ll i=n-1; i>0; i--){
        if (nexti[i-1]<nexti[i]){
            ll maxi=i;
            for (ll j=i+1; j<n; j++){
                if (nexti[j]<nexti[maxi] && (nexti[j]>nexti[i-1])){
                    maxi=j;
                }
            }
            swap(nexti[i-1],nexti[maxi]);
            vector <ll> help;
            for (ll k=i; k<n; k++) help.push_back(nexti[k]);
            sort(help.begin(), help.end());
            ll m=0;
            for (ll k=i; k<n; k++){
                nexti[k]=help[m];
                m++;
            }
            for (ll k=0; k<n; k++){
                f2<<nexti[k]<<" ";
            }
            f2<<endl;
            return;
        }
    }
    for (ll k=0; k<n; k++){
        f2<<"0 ";
    }
    f2<<endl;
}

int main()
{
    f1>>n;
    ans.resize(n);
    nexti.resize(n);
    for (ll i=0; i<n; i++){
        f1>>ans[i];
        nexti[i]=ans[i];
    }
    nextip();
    return 0;
}

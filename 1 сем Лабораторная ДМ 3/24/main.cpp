#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f1("nextperm.in");
ofstream f2("nextperm.out");
ll n;
vector <ll> ans, previ, nexti;

void previious(){
    for (ll i=n-1; i>0; i--){
        if (previ[i-1]>previ[i]){
            ll maxi=i;
            for (ll j=i+1; j<n; j++){
                if (previ[j]>previ[maxi] && (previ[j]<previ[i-1])){
                    maxi=j;
                }
            }
            swap(previ[i-1],previ[maxi]);
            for (ll k=0; k<(n-i)/2; k++){
                swap(previ[k+i],previ[n-k-1]);
            }
            for (ll k=0; k<n; k++){
                f2<<previ[k]<<" ";
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
            for (ll k=0; k<(n-i)/2; k++){
                swap(nexti[k+i],nexti[n-k-1]);
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
    previ.resize(n);
    nexti.resize(n);
    for (ll i=0; i<n; i++){
        f1>>ans[i];
        previ[i]=ans[i];
        nexti[i]=ans[i];
    }
    previious();
    nextip();
    return 0;
}

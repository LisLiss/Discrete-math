#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MOD=998244353;

vector <vector <ll> > pif;
ll k, n;
vector<ll> a,b;

void makePif(){
    pif.resize(k, vector <ll> (k, 0));
    pif[0][0]=1;
    for (int i=1; i<k; i++){
        for (int j=0; j<k; j++){
            if (i<j) continue;
            if (j==0) {
                pif[i][j]=pif[i-1][j];
            }
            else pif[i][j]=pif[i-1][j-1]+pif[i-1][j];
            pif[i][j]%=MOD;
        }
    }
}

void makeP(){
    for (int i=0; i<k; i++){
        if (i>k-2-i) break;
        a.push_back(pif[k-2-i][i]%MOD);
        if (i%2==1) a[i]*=-1;
        if (a[i]<0) a[i]+=MOD;
    }
}
void makeQ(){
    for (int i=0; i<k; i++){
        if (i>k-1-i) break;
        b.push_back(pif[k-1-i][i]%MOD);
        if (i%2==1) b[i]*=-1;
        if (b[i]<0) b[i]+=MOD;
    }
}

void div(){
    vector <ll> ans(n, 0);
    ll na=a.size();
    ll nb=b.size();

    for (int i=0; i<n; i++){
        ll help=0;
        for (int j=0; j<i; j++){
            if (i-j<nb){
                help+=(ans[j]*b[i-j])%MOD;
                help%=MOD;
            }
        }
        if (i<na){
            ans[i]=(a[i]-help)/b[0];
            ans[i]%=MOD;
        } else{
            ans[i]=(0-help)/b[0];
            ans[i]%=MOD;
        }
    }
    for (int i=0; i<n; i++){
        if (ans[i]<0){
            cout<<ans[i]+MOD<<endl;
        }
        else cout<<ans[i]<<endl;
    }
}

int main(){
    cin>>k>>n;
    makePif();
    makeP();
    makeQ();
    /*for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    div();
    return 0;
}

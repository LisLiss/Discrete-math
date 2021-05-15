#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;
int n, m;
vector <ll> a, b, p, res;
vector <vector <ll> > power;

ll gcd(ll a, ll b, ll&x, ll& y){
    if (a==0){
        x=0; y=1;
        return b;
    }
    ll x1, y1;
    ll d= gcd(b%a, a, x1, y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

ll rec(ll a){
    ll x, y;
    ll d=gcd(a, MOD, x, y);
    return (x%MOD + MOD)%MOD;
}

void mul(){
    int na=a.size();
    int nb = b.size();
    vector <ll> ans(na+nb, 0);
    int flag=0;
    for (int i=0; i<na; i++){
        for (int j=0; j<nb; j++){
            ans[i+j]+=a[i]*b[j];
            ans[i+j]%=MOD;
        }
    }
    res.resize(m, 0);
    int help1=ans.size();
    help1=min(help1, m);
    for (int i=0; i<help1; i++){
        res[i]=ans[i];
    }
}

void makePowers(){
    power.resize(m+1);
    power[0].resize(m, 0);
    power[1]=p;
    for (int i=2; i<m ; i++){
        a=power[i-1];
        b=p;
        mul();
        power[i]=res;
    }
}

void sqrtPlus(){
    vector <vector <ll> > power2 = power;
    ll coef=1;
    for (int i=1; i<m; i++){
        ll help1=(MOD-2*i+3)%MOD;
        ll help2=(rec(i*2))%MOD;
        coef*=help1;
        coef%=MOD;
        coef*=help2;
        coef%=MOD;
        if (coef<0) coef+=MOD;
        for (int j=0; j<m; j++){
            power2[i][j]*=coef;
            power2[i][j]%=MOD;
        }
    }
    vector <ll> ans(m, 0);
    for (int i=1; i<m; i++){
        for (int j=0; j<m; j++){
            ans[j]+=power2[i][j];
            ans[j]%=MOD;
        }
    }
    ans[0]=1;
    for (int i=0; i<m; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void exp(){
    vector <vector <ll> > power2 = power;
    ll coef=1;
    for (int i=1; i<m; i++){
        coef*=i;
        coef%=MOD;
        if (coef<0) coef+=MOD;
        for (int j=0; j<m; j++){
            power2[i][j]*=rec(coef);
            power2[i][j]%=MOD;
        }
    }
    vector <ll> ans(m, 0);
    for (int i=1; i<m; i++){
        for (int j=0; j<m; j++){
            ans[j]+=power2[i][j];
            ans[j]%=MOD;
        }
    }
    ans[0]=1;
    for (int i=0; i<m; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void lnPlus(){
    vector <vector <ll> > power2 = power;
    ll coef=1;
    for (int i=1; i<m; i++){
        coef=i;
        if (i%2==0) coef*=-1;
        coef%=MOD;
        if (coef<0) coef+=MOD;
        for (int j=0; j<m; j++){
            power2[i][j]*=rec(coef);
            power2[i][j]%=MOD;
        }
    }
    vector <ll> ans(m, 0);
    for (int i=1; i<m; i++){
        for (int j=0; j<m; j++){
            ans[j]+=power2[i][j];
            ans[j]%=MOD;
        }
    }
    for (int i=0; i<m; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>m;
    n++;
    p.resize(n);
    for (int i=0; i<n; i++){
        cin>>p[i];
    }
    for (int i=n; i<m; i++) p.push_back(0);
    makePowers();
    sqrtPlus();
    exp();
    lnPlus();
    return 0;
}

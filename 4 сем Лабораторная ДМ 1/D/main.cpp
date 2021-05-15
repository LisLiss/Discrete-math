#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll r, k, divv;
vector <ll> p;

void make_div(){
    ll kfact=1;
    ll rk=1;
    for (int i=1; i<=k; i++){
        kfact*=i;
        rk*=r;
    }
    divv=rk*kfact;
}

ll gcd(ll a, ll b){
    if (a==0){
        return b;
    }
    ll d= gcd(b%a, a);
    return d;
}

vector <ll>  mul(vector <ll> &a, vector <ll> &b){
    int na=a.size();
    int nb = b.size();
    vector <ll> ans(na+nb, 0);
    int flag=0;
    for (int i=0; i<na; i++){
        for (int j=0; j<nb; j++){
            ans[i+j]+=a[i]*b[j];
        }
    }
    vector <ll> res(12, 0);
    int help1=ans.size();
    help1=min(help1, 12);
    for (int i=0; i<help1; i++){
        res[i]=ans[i];
    }
    return res;
}

vector <ll> make_fact(ll i){
    vector <ll> help(12, 0), help2;
    help[0]=1-i; help[1]=1;
    for (int j=2; j<k+1; j++){
        help2.resize(0);
        help2.resize(12, 0);
        help2[0]=j-i; help2[1]=1;
        help=mul(help, help2);
    }
    return help;
}


vector <ll> make_ans(){
    vector <ll> ans(20, 0);
    ll help=1;
    vector <ll> fact;
    for (int i=0; i<k+1; i++){
        help=p[i]*pow(r, k-i);
        fact=make_fact(i);
        //cout<<help<<endl;
        for (int j=0; j<12; j++){
          //  cout<<fact[j]<<" ";
            ans[j]+=help*fact[j];
        }
        //cout<<endl;
    }
    return ans;
}

int main(){
    cin>>r>>k;
    p.resize(k+1);
    for (int i=0; i<k+1; i++){
        cin>>p[i];
    }
    make_div();
    vector <ll> answer=make_ans();
    for (int i=0; i<k+1; i++){
        ll gcdNum=gcd(abs(divv), abs(answer[i]));
        cout<<answer[i]/gcdNum<<"/"<<divv/gcdNum<<" ";
    }
    return 0;
}

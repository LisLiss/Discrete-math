#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll r, d;
vector <ll> pp;

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
    vector <ll> res(200, 0);
    int help1=ans.size();
    help1=min(help1, 200);
    for (int i=0; i<help1; i++){
        res[i]=ans[i];
    }
    return res;
}

vector <ll> make_fact(){
    vector <ll> help(200, 0), help2;
    help[0]=1; help[1]=-r;
    help2.resize(0);
    help2.resize(200, 0);
    help2[0]=1; help2[1]=-r;
    for (int j=0; j<d; j++){
        help=mul(help, help2);
    }
    return help;
}

int main(){
    cin>>r>>d;
    pp.resize(d+1);
    for (int i=0; i<d+1; i++){
        cin>>pp[i];
    }
    int flag=0;
    vector <ll> q = make_fact();
    vector <ll> help;
    ll powr=pow(r, 0);
    for (ll i=0; i<d+1; i++){
        ll qqq=0;
        ll powi=pow(i, 0);
        for (ll j=0; j<d+1; j++){
            qqq+=pp[j]*powi;
            powi*=i;
        }
        //cout<<endl<<qqq<<" ";
        help.push_back(qqq*powr);
        powr*=r;
        //cout<<help[i]<<" ";
    }
    //cout<<endl;
    vector <ll> p=mul(help, q);
    for (int i=0; i<p.size(); i++){
        if (p[i]!=0) flag=i;
    }
    cout<<min(flag, (int) d)<<endl;
    for (int i=0; i<min(flag, (int) d) + 1; i++){
        cout<<p[i]<<" ";
    }
    flag=0;
    for (int i=0; i<q.size(); i++){
        if (q[i]!=0) flag=i;
    }
    cout<<endl<<flag<<endl;
    for (int i=0; i<flag+1; i++){
        cout<<q[i]<<" ";
    }
    return 0;
}

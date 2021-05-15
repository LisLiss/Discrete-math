#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m,k;
vector <vector <ll> > matrix, revmatrix;
vector <ll> cango, dp, term, numcan;
void check(ll v){
    queue<ll> q;
    q.push(v);
    cango[v]++;
    while (!q.empty()){
        v=q.front(); q.pop();
        for (ll i=0; i<matrix[v].size(); i++){
            if (cango[matrix[v][i]]==-1){
                q.push(matrix[v][i]);
                cango[matrix[v][i]]++;
            }
        }
    }
}
void revcheck(ll v){
    if (cango[v]==-1) return;
    queue<ll> q;
    q.push(v);
    cango[v]=1;
    while (!q.empty()){
        v=q.front(); q.pop();
        for (ll i=0; i<revmatrix[v].size(); i++){
            if (cango[revmatrix[v][i]]==0){
                q.push(revmatrix[v][i]);
                cango[revmatrix[v][i]]=1;
            }
        }
    }
}
void delcantGo(){
    for (ll i=0; i<n; i++){
        if (cango[i]!=1){
            //matrix[i].clear();
            //revmatrix[i].clear();
            numcan[i]=-1;
            for (ll j=0; j<matrix[i].size(); j++) numcan[matrix[i][j]]--;
        } else{
            numcan[i]+=revmatrix[i].size();
        }
    }
}
void makeans(){
    queue <ll> q;
    ll v=0;
    for (ll i=0; i<matrix[v].size(); i++){
        if (cango[matrix[v][i]]==1) q.push(matrix[v][i]);
    }
    while (!q.empty()){
        v=q.front(); q.pop();
        //f2<<v+1<<endl;
        numcan[v]--;
        if (numcan[v]==0){
          //  f2<<"was"<<endl;
            for (ll i=0; i<revmatrix[v].size(); i++){
                if (cango[revmatrix[v][i]]==-1) continue;
                if (dp[revmatrix[v][i]]==0) dp[v]++;
                else dp[v]+=dp[revmatrix[v][i]];
            }
            for (ll i=0; i<matrix[v].size(); i++){
                if (numcan[matrix[v][i]]!=-1) q.push(matrix[v][i]);
            }
        }
    }
}
ll getans(){
    ll ans=0;
    for (ll i=0; i<k; i++){
        if (cango[term[i]]!=-1) ans+=dp[term[i]];
    }
    return ans;
}


int main(){
    ifstream f1("problem3.in");
    ofstream f2("problem3.out");
    f1>>n>>m>>k;
    matrix.resize(n);
    revmatrix.resize(n);
    cango.resize(n, -1);
    numcan.resize(n, 0);
    dp.resize(n, 0);
    term.resize(k);
    for (ll i=0; i<k; i++) {f1>>term[i]; term[i]--;}
    ll x,y;
    char c;
    for (ll i=0; i<m; i++){
        f1>>x>>y;
        f1>>c;
        x--; y--;
        matrix[x].push_back(y);
        revmatrix[y].push_back(x);
    }
    check(0);
    for (ll i=0; i<k; i++) revcheck(term[i]);
    if (cango[0]!=1){
        f2<<"0";
        return 0;
    }
    if (revmatrix[0].size()!=0){
        f2<<"-1";
        return 0;
    }
    delcantGo();
    makeans();
    for (ll i=0; i<n; i++){
        //f2<<numcan[i]<<" ";
        if (numcan[i]>0){
            f2<<"-1";
            return 0;
        }
    }
    dp[0]=1;
    f2<<getans();
    return 0;
}

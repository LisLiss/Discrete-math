#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f1("brackets2num.in");
ofstream f2("brackets2num.out");
vector <vector <ll> > dp;
vector <char> ans;
ll n;

void makeDP(){
    for (ll i=0; i<2*n; i++){
        for (ll j=0; j<n+1; j++){
            if (i==0){
                if (j==0){
                    dp[i][j]=1;
                } else{
                    dp[i][j]=0;
                }
            } else{
                if (j==0){
                    dp[i][j]=dp[i-1][j+1];
                } else{
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
                }
            }
        }
    }
}
ll bracketsNum(){
    ll l=0;
    ll answer=0;
    for (ll i=0; i<2*n; i++){
        if (ans[i]=='('){
            l++;
        } else{
            answer+=dp[2*n-(i+1)][l+1];
            l--;
        }
    }
    return answer;
}

int main()
{
    string st;
    f1>>st;
    n=st.size()/2;
    dp.resize(2*n+1, vector< ll> (n+2, 0));
    dp[0][0]=1;
    ans.resize(2*n);
    for (ll i=0; i<2*n; i++){
        ans[i]=st[i];
    }
    makeDP();
    f2<<bracketsNum();
    return 0;
}

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f1("num2brackets.in");
ofstream f2("num2brackets.out");
vector <vector <ll> > dp;
ll k,n;
string ans;

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
void numBrackets(){
    ll l=0;
    for (ll i=0; i<2*n; i++){
        if (dp[2*n-(i+1)][l+1]>=k){
            ans+='(';
            l++;
        } else{
            k-=dp[2*n-(i+1)][l+1];
            ans+=')';
            l--;
        }
    }
}

int main()
{
    f1>>n>>k;
    dp.resize(2*n+1, vector< ll> (n+2, 0));
    dp[0][0]=1;
    ans="";
    k++;
    makeDP();
    numBrackets();
    f2<<ans;
    return 0;
}

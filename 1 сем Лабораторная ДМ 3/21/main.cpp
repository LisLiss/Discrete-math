#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector <vector <ll> > dp;
vector <ll> ans;
ll n, k;
ifstream f1("num2part.in");
ofstream f2("num2part.out");

void DP(){ //i слагаемых >=j
    for (ll i=0; i<n+1; i++){
        for (ll j=n; j>-1; j--){
            if (i==j) dp[i][j]=1;
            if (i<j) dp[i][j]=0;
            if (i>j) dp[i][j]=dp[i][j+1]+dp[i-j][j];
        }
    }
}

void numPart(){
    ll sum=0;
    for (ll j=1; j<n+1; j++){
        if (k==0 && dp[n-j][j]==0 && sum+j==n){
            ans.push_back(j);
            break;
        }
        if (k>=dp[n-j][j]){
            k-=dp[n-j][j];
        } else{
            ans.push_back(j);
            break;
        }
    }
    sum+=ans[0];
    for (ll i=1; i<n+1; i++){
        if(sum==n) break;
        for (ll j=ans[i-1]; j<n+1; j++){
            if (sum+j==n){
                ans.push_back(j);
                sum+=j;
                break;
            }
            if (k>=dp[n-sum-j][j]){
                k-=dp[n-sum-j][j];
            } else{
                ans.push_back(j);
                sum+=j;
                break;
            }
        }
    }
}

void print(){
    for (ll i=0; i<ans.size()-1; i++){
        f2<<ans[i]<<"+";
    }
    f2<<ans[ans.size()-1];

}
int main()
{
    f1>>n>>k;
    dp.resize(n+1, vector<ll> (n+1));
    DP();
    numPart();
    print();
    return 0;
}

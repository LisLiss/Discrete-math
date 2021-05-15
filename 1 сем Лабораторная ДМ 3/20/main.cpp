#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f1("brackets2num2.in");
ofstream f2("brackets2num2.out");
vector <vector <ll> > dp;
vector <char> ans;
ll n;

void makeDP(){
    for (ll i=0; i<2*n; i++){
        for (ll j=0; j<2*n; j++){
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
    unsigned long long answer=0;
    vector <char> lastOpen;
    for (ll i=0; i<2*n; i++){
        if (ans[i]=='('){
            l++;
            lastOpen.push_back('(');
        } else{
            answer+=dp[2*n-(i+1)][l+1]*(1ull<<((2*n-(i+1)-(l+1))/2));
            if (ans[i]==')'){
                l--;
                lastOpen.pop_back();
            } else{
                if (lastOpen.size()!=0 && lastOpen[lastOpen.size()-1]=='('){
                    answer+=dp[2*n-(i+1)][l-1]*(1ull<<((2*n-(i+1)-(l-1))/2));
                }
                if (ans[i]=='['){
                    l++;
                    lastOpen.push_back('[');
                } else{
                    answer+=dp[2*n-(i+1)][l+1]*(1ull<<((2*n-(i+1)-(l+1))/2));
                    l--;
                    lastOpen.pop_back();
                }
            }
        }
    }
    return answer;
}

int main()
{
    string st;
    f1>>st;
    n=st.size()/2;
    dp.resize(2*n+1, vector< ll> (2*n+1, 0));
    dp[0][0]=1;
    ans.resize(2*n);
    for (ll i=0; i<2*n; i++){
        ans[i]=st[i];
    }
    makeDP();
    f2<<bracketsNum();
    return 0;
}

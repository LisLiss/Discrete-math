#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector <vector <ll> > dp;
vector <ll> ans;
ll n;
ifstream f1("part2num.in");
ofstream f2("part2num.out");

void DP(){ //i слагаемых >=j
    for (ll i=0; i<n+1; i++){
        for (ll j=n; j>-1; j--){
            if (i==j) dp[i][j]=1;
            if (i<j) dp[i][j]=0;
            if (i>j) dp[i][j]=dp[i][j+1]+dp[i-j][j];
        }
    }
}

ll numPart(){
    ll answer=0, sum;
    for (ll j=1; j<ans[0]; j++){
        answer+=dp[n-j][j];
    }
    sum=ans[0];
    for (ll i=1; i<ans.size(); i++){
        for (ll j=ans[i-1]; j<ans[i]; j++){
            answer+=dp[n-sum-j][j];
        }
        sum+=ans[i];
    }
    return answer;
}

ll parse(string s){
    ll k=1, answer=0;
    for (ll i=s.size()-1; i>-1; i--){
        answer+=k*(s[i]-'0');
        k*=10;
    }
    return answer;
}
int main()
{
    string s, help="";
    ll k=0;
    n=0;
    cin>>s;
    for (ll i=0; i<s.size(); i++){
        if (s[i]=='+'){
            ans.push_back(parse(help));
            help="";
            n+=ans[k];
            k++;
        } else{
            help+=s[i];
        }
    }
    ans.push_back(parse(help));
    n+=ans[k];
    k++;
    dp.resize(n+1, vector<ll> (n+1));
    DP();
    for (ll i=0; i<n+1; i++){
        for (ll j=0; j<n+1; j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    cout<<numPart();
    return 0;
}

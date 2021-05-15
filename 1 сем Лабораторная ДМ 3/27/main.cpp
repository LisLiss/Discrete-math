#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s;
ll n;

ifstream f1("nextbrackets.in");
ofstream f2("nextbrackets.out");

string NextBrac(){
    string ans=s;
    ll l=0, k=0;
    for (ll i=ans.size()-1; i>-1; i--){
        k++;
        if (ans[i]=='('){
            l--;
            if (l>0){
                ans[i]=')';
                for (ll j=0; j<(ans.size()-i-l)/2; j++){
                    ans[j+i+1]='(';
                }
                for (ll j=(ans.size()-i-l)/2+i+1; j<ans.size(); j++){
                    ans[j]=')';
                }
                return ans;
            }
        } else{
            l++;
        }
    }
    return "-";
}
int main()
{
    f1>>s;
    f2<<NextBrac();
    return 0;
}

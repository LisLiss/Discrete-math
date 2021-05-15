#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector <ll> ans;
ll n, k;

ifstream f1("nextpartition.in");
ofstream f2("nextpartition.out");
ll parse(string s){
    ll k=1, answer=0;
    for (ll i=s.size()-1; i>-1; i--){
        answer+=k*(s[i]-'0');
        k*=10;
    }
    return answer;
}
void print(){
    cout<<n<<"=";
    for (ll i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<"+";
    }
    cout<<ans[ans.size()-1];

}
void nextPar(){
    if (ans[ans.size()-2]>=ans[ans.size()-1]-1){
        ans[ans.size()-2]+=ans[ans.size()-1];
        ans.pop_back();
        return;
    }
    ans[ans.size()-2]++;
    ans[ans.size()-1]--;
    while (ans[ans.size()-2]*2<=ans[ans.size()-1]){
        ans.push_back(ans[ans.size()-1]-ans[ans.size()-2]);
        ans[ans.size()-2]=ans[ans.size()-3];
    }
}
int main(){
    string s;
    cin>>s;
    string help="";
    ll i=0;
    while (s[i]!='='){
        help+=s[i];
    i++;
    }
    n=parse(help);
    help="";
    for (ll j=i+1; j<s.size(); j++){
        if (s[j]=='+'){
            ans.push_back(parse(help));
            help="";
            k++;
        } else{
            help+=s[j];
        }
    }
    ans.push_back(parse(help));
    if (ans.size()==1){
        cout<<"No solution";
    } else{
        nextPar();
        print();
    }
    return 0;
}

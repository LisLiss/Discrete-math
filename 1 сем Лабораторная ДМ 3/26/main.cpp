#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, k;
vector  <vector <int> >  ans;
set <int> sorted;

ifstream f1("nextsetpartition.in");
ofstream f2("nextsetpartition.out");

ll parse(string s){
    ll kk=1, answer=0;
    for (ll i=s.size()-1; i>-1; i--){
        answer+=kk*(s[i]-'0');
        kk*=10;
    }
    return answer;
}
void print(){
    f2<<n<<" ";
    k=0;
    for (ll i=0; i<ans.size(); i++){
        if (ans[i].size()==0) continue;
        k++;
    }
    f2<<k+sorted.size()<<endl;
    for (ll i=0; i<ans.size(); i++){
        if (ans[i].size()==0) continue;
        for (ll j=0; j<ans[i].size(); j++){
            f2<<ans[i][j]<<" ";
        }
        f2<<endl;
    }
    for (set<int>::iterator it = sorted.begin(); it != sorted.end(); ++it){
        f2<<*it<<endl;
    }
    f2<<endl;
    sorted.clear();

}
bool push(int i){
    if (!sorted.empty()){
        if (sorted.upper_bound(ans[i][ans[i].size()-1])==sorted.end()){
            return false;
        }
        int x=*(sorted.upper_bound(ans[i][ans[i].size()-1]));
        ans[i].push_back(x);
        sorted.erase(x);
        return true;
    }
    return false;
}

bool add(int i, int j){
    if (!sorted.empty()){
        if (sorted.upper_bound(ans[i][j])==sorted.end()){
            return false;
        }
        int x=*(sorted.upper_bound(ans[i][j]));
        sorted.insert(ans[i][j]);
        ans[i][j]=x;
        sorted.erase(x);
        return true;
    }
    return false;
}
void nextSet(){
    for (ll i=ans.size()-1; i>-1; i--){
        if (push(i)) return;
        for (ll j=ans[i].size()-1; j>0; j--){
            if (add(i, j)) return;
            sorted.insert(ans[i][j]);
            ans[i].pop_back();
        }
        sorted.insert(ans[i][0]);
        ans[i].pop_back();
    }
}
int main()
{
    while (true){
        f1>>n>>k;
        if (n==0 && k==0) return 0;
        ans.clear();
        ans.resize(k);
        string s;
        getline(f1, s);
        for (ll i=0; i<k; i++){
            getline(f1, s);
            string help="";
            for (ll j=0; j<s.size(); j++){
                if (s[j]==' '){
                    if (help!=""){
                        ans[i].push_back(parse(help));
                        help="";
                    }
                } else{
                    help+=s[j];
                }
            }
            if (help!=""){
                ans[i].push_back(parse(help));
                help="";
            }
        }
        nextSet();
        print();
    }
    return 0;
}

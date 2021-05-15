#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > rulesP[110*110];
vector <string> rules[30];
int dp [110*110][110][110];
int curNoTerm=26;
string word;

int conv(char c){
    if (c>='A' && c<='Z') return c-'A';
    if (c>='a' && c<='z') return 'a'-c-2;
    return -1;
}
char reConv(int c){
    return 'a'-c-2;
}

void veryLong(){
    for (int i=0; i<26; i++){
        for (string s:rules[i]){
            int cur=i;
            for (int j=0; j<(int)s.size()-2; j++){
                rulesP[cur].push_back(make_pair(conv(s[j]), curNoTerm));
                cur=curNoTerm; curNoTerm++;
            }
            if (s.size()>=2) rulesP[cur].push_back(make_pair(conv(s[s.size()-2]), conv(s[s.size()-1])));
            else{
                if (s.size()==0) rulesP[cur].push_back(make_pair(-1, -1));
                else rulesP[cur].push_back(make_pair(conv(s[s.size()-1]), -1));
            }
        }
    }
}
 int makeDp(int state, int st, int en){
    if (dp[state][st][en]!=-1) return dp[state][st][en];
    dp[state][st][en]=0;
    if (st==en){
        for (pair <int, int> x: rulesP[state]){
            if (x.second!=-1 && x.first<-1 && word[st]==reConv(x.first)){
                dp[state][st][st]=1;
                return 1;
            }
        }
    }
    int i=state, len=en-st+1;
    for (int k=st-1; k<=en; k++){
        for (pair <int, int> x: rulesP[i]){
            if (x.second==-1 && x.first>=0) dp[i][st][en] |=makeDp(x.first, st, en);
            if (x.second < -1 && x.first < -1 && len == 2 && reConv(x.first) == word[st] && reConv(x.second) == word[en]) dp[i][st][en] = 1;
            if (x.second >= 0 && x.first < -1 && reConv(x.first) == word[st]) dp[i][st][en] |= makeDp(x.second, st + 1, en);
            if (x.second < -1 && x.first >= 0 && reConv(x.second) == word[en]) dp[i][st][en] |= makeDp(x.first, st, en - 1);
            if (x.second >= 0 && x.first >= 0) dp[i][st][en] |= (makeDp(x.first, st, k) & makeDp(x.second, k + 1, en));
            if (len == 0 && x.first == -1) dp[i][st][en] = 1;
        }
    }
    return dp[i][st][en];
 }

int main()
{
   // ifstream f1("cf.in");
    //ofstream f2("cf.out");
    memset(dp, -1, sizeof(dp));
    int n;
    string now;
    int start;
    cin>>n>>now;
    start=now[0]-'A';
    getline(cin, now);
    for (int i=0; i<n; i++){
        getline(cin, now);
        string help="";
        for (int j=5; j<(int)now.size(); j++) help+=now[j];
        rules[now[0]-'A'].push_back(help);
    }
    cin>>word;
    veryLong();
    if (makeDp(start, 0, (int)word.size()-1)) cout<<"yes";
    else cout<<"no";
    return 0;
}

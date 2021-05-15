#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("nfc.in");
    ofstream f2("nfc.out");
    int n;
    string now, word, start;
    cin>>n>>start;
    vector <string> rules;
    getline(cin, now);
    for (int i=0; i<n; i++){
        getline(cin, now);
        rules.push_back(now);
    }
    cin>>word;
    int dp[26][201][201];
    for (int i=0; i<26; i++){
        for (int j=0; j<201; j++){
            for (int k=0; k<201; k++) dp[i][j][k]=0;
        }
    }
    //vector <vector <vector <int> > > dp(26, vector <vector <int> > (201, vector <int> (201, 0)));
    for (int i=0; i<26; i++){
        for (int j=0; j<word.size(); j++){
            for (int k=0; k<n; k++){
                if (i+'A'==rules[k][0] && word[j]==rules[k][5]) dp[i][j][j]=1;
            }
        }
    }
    for (int i=word.size()-1; i>-1; i--){
        for (int j= i+1; j<word.size(); j++){
            for (int k=0; k<26; k++){
                for (int l=0; l<n; l++){
                    if (rules[l][0]==k+'A' && rules[l].size()>=7){
                        for (int m=i; m<j; m++){
                            dp[k][i][j]=(dp[k][i][j]+(dp[rules[l][5]-'A'][i][m]*dp[rules[l][6]-'A'][m+1][j])%1000000007)%1000000007;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[start[0]-'A'][0][word.size()-1]<<endl;
    return 0;
}

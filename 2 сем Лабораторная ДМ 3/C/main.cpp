#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("useless.in");
    ofstream f2("useless.out");
    vector <bool> isEpsilon(26, false), was(26, false), canGo(26, false), canFrom(26, false);
    vector <string> rules, goodRules;
    int n, numRule=5;
    string now;
    f1>>n>>now;
    canGo[now[0]-'A']=true;
    was[now[0]-'A']=true;
    getline(f1, now);
    for (int i=0; i<n; i++){
        getline(f1, now);
        for (int j=0; j<now.size(); j++){
            if (now[j]>='A' && now[j]<='Z') was[now[j]-'A']=true;
        }
        rules.push_back(now);
    }
    bool f=true;
    while (f){
        f=false;
        for (int i=0; i<rules.size(); i++){
            bool f2=true;
            for (int j=numRule; j<rules[i].size(); j++){
                if (rules[i][j]>='a' && rules[i][j]<='z') continue;
                if (!isEpsilon[rules[i][j]-'A']) f2=false;
            }
            if (f2 && !isEpsilon[rules[i][0]-'A']) {isEpsilon[rules[i][0]-'A']=true; f=true;}
        }
    }
    for (int i=0; i<rules.size(); i++){
        bool f2=true;
        for (int j=numRule; j<rules[i].size(); j++){
            if (rules[i][j]>='a' && rules[i][j]<='z') continue;
            if (!isEpsilon[rules[i][j]-'A']) {f2=false; break;}
        }
        if (f2) goodRules.push_back(rules[i]);
    }
    f=true;
    while (f){
        f=false;
        for (int i=0; i<goodRules.size(); i++){
            if (!canGo[goodRules[i][0]-'A']) continue;
            for (int j=numRule; j<goodRules[i].size(); j++){
                if (goodRules[i][j]>='a' && goodRules[i][j]<='z') continue;
                if (!canGo[goodRules[i][j]-'A']) {
                    f=true;
                    canGo[goodRules[i][j]-'A']=true;
                }
            }
        }
    }
    for (int i=0; i<goodRules.size(); i++){
        if (canGo[goodRules[i][0]-'A']) canFrom[goodRules[i][0]-'A']=true;
    }
    for (int i=0; i<26; i++){
        if (!canFrom[i] && was[i]) f2<<char('A'+i)<<" ";
    }
    return 0;
}

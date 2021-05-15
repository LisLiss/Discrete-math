#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("epsilon.in");
    ofstream f2("epsilon.out");

    vector <bool> isEpsilon(26, false);
    vector <string> rules;
    int n, numRule=5;
    string now;
    f1>>n>>now;
    for (int i=0; i<n+1; i++){
        getline(f1, now);
        if (now.size()==0) continue;
        if (now.size()==4) isEpsilon[now[0]-'A']=true;
        else rules.push_back(now);
    }
    bool f=true;
    while (f){
        f=false;
        for (int i=0; i<rules.size(); i++){
            bool f2=true;
            for (int j=numRule; j<rules[i].size(); j++){
                if (rules[i][j]>='a' && rules[i][j]<='z'){
                    f2=false;
                    break;
                }
                if (!isEpsilon[rules[i][j]-'A']) f2=false;
            }
            if (f2 && !isEpsilon[rules[i][0]-'A']) {isEpsilon[rules[i][0]-'A']=true; f=true;}
        }
    }
    for (int i=0; i<26; i++){
        if (isEpsilon[i]) f2<< char('A'+i)<<" ";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("automaton.in");
    ofstream f2("automaton.out");

    vector <vector <vector <int> > > matrix(28, vector <vector <int> > (26));
    string s, now; char c;
    int n, m;
    f1>>n>>now;
    for (int i=0; i<n; i++){
        f1>>c>>s; f1>>s;
        if (s.size()==1) matrix[c-'A'][s[0]-'a'].push_back(26);
        else matrix[c-'A'][s[0]-'a'].push_back(s[1]-'A');
    }
    f1>>m;
    vector <int> lastV, nowV;
    for (int i=0; i<m; i++){
        f1>>s;
        lastV.clear();
        nowV.clear();
        nowV.push_back(now[0]-'A');
        for (int j=0; j<s.size(); j++){
            lastV=nowV;
            nowV.clear();
            for (int k=0; k<lastV.size(); k++){
                for (int l=0; l<matrix[lastV[k]][s[j]-'a'].size(); l++){
                    nowV.push_back(matrix[lastV[k]][s[j]-'a'][l]);
                }
            }
        }
        bool f=false;
        for (int j=0; j<nowV.size(); j++){
            if (nowV[j]==26){
                f=true;
                f2<<"yes"<<endl;
                break;
            }
        }
        if (!f) f2<<"no"<<endl;
    }
    return 0;
}

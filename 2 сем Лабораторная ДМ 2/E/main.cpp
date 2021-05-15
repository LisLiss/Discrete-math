#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("problem5.in");
    ofstream f2("problem5.out");
    int n,m,k,l, x, y;
    char c;
    f1>>n>>m>>k>>l;
    vector<int> prinim(k), termDka;
    for (int i=0; i<k; i++) {f1>>prinim[i]; prinim[i]--;}
    vector <vector <vector <int> > > matrix (n, vector <vector <int> >(26));
    for (int i=0; i<m; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix[x][int(c)-int('a')].push_back(y);
    }

    vector <vector <int> > dka(101);
    queue <set<int> > q;
    map<set <int>, int> allSetWithNum;
    set<int> now;
    int numSet=0;
    now.insert(0);
    q.push(now);
    allSetWithNum.insert(make_pair(now, numSet));
    while (!q.empty()){
        now=q.front(); q.pop();
        bool f=false;
        for (set<int>::iterator j=now.begin(); j!=now.end(); j++){
            for (int i=0; i<k; i++){
                if (prinim[i]==*j){
                    termDka.push_back(allSetWithNum.find(now)->second);
                    f=true;
                    break;
                }
            }
            if (f) break;
        }
        for (int i=0; i<26; i++){
            set <int> help;
            for (set<int>::iterator j=now.begin(); j!=now.end(); j++){
                for (int kk=0; kk<matrix[*j][i].size(); kk++) help.insert(matrix[*j][i][kk]);
            }
            if (allSetWithNum.find(help)==allSetWithNum.end()) {
                if (!help.empty()){
                    numSet++;
                    allSetWithNum.insert(make_pair(help, numSet));
                    q.push(help);
                    dka[allSetWithNum.find(now)->second].push_back(numSet);
                }
            } else{
                dka[allSetWithNum.find(now)->second].push_back(allSetWithNum.find(help)->second);
            }
        }
    }

    int now2;
    vector<int> ans(101, 0), anshelp(101, 0);
    set<int> stek1, stek2;
    stek1.insert(0);
    for (int ll=0; ll<l; ll++){
        for (set<int>::iterator j=stek1.begin(); j!=stek1.end(); j++){
            now2=*j;
            for (int t=0; t<dka[now2].size(); t++) {
                stek2.insert(dka[now2][t]);
                anshelp[dka[now2][t]]+=ans[now2];
                if (ans[now2]==0) anshelp[dka[now2][t]]++;
                anshelp[dka[now2][t]]=anshelp[dka[now2][t]]%(1000000007);
            }
        }
        stek1=stek2;
        stek2.clear();
        for (int j=0; j<101; j++) {ans[j]=anshelp[j]; anshelp[j]=0;}
    }
    int answer=0;
    for (int i=0; i<termDka.size(); i++){
        for (int j=0; j<101; j++){
            if (termDka[i]==j){
                answer+=ans[j];
                answer%=1000000007;
            }
        }
    }
    f2<<answer;
    return 0;
}

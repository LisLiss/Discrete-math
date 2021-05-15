#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("problem2.in");
    ofstream f2("problem2.out");
    string s;
    f1>>s;
    int n, m, k;
    f1>>n>>m>>k;
    vector <vector<vector <int> > > matrix (n, vector <vector <int> >(26, vector <int>(0)));
    int x, y;
    char c;
    vector<int> prinim(k);
    set<int> stek1, stek2;
    for (int i=0; i<k; i++) {f1>>prinim[i]; prinim[i]--;}
    for (int i=0; i<m; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix[x][int(c)-int('a')].push_back(y);
    }
    int now;
    stek1.insert(0);
    for (int i=0; i<s.size(); i++){
        x=int(s[i])-int('a');
        for (set<int>::iterator j=stek1.begin(); j!=stek1.end(); j++){
            now=*j;
            for (int t=0; t<matrix[now][x].size(); t++) stek2.insert(matrix[now][x][t]);
        }
        if (stek2.empty()){
            f2<<"Rejects";
            return 0;
        }
        stek1=stek2;
        stek2.clear();
    }
    for (int i=0; i<k; i++){
        for (set<int>::iterator j=stek1.begin(); j!=stek1.end(); j++){
            now=*j;
            if (prinim[i]==now){
                f2<<"Accepts";
                return 0;
            }
        }
    }
    f2<<"Rejects";
    return 0;
}

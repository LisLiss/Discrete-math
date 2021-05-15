#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("problem1.in");
    ofstream f2("problem1.out");

    string s;
    f1>>s;
    int n, m, k;
    f1>>n>>m>>k;
    vector <vector <int> > matrix (n, vector <int>(26, -1));
    int x, y;
    char c;
    vector<int> prinim(k);
    for (int i=0; i<k; i++) {f1>>prinim[i]; prinim[i]--;}
    for (int i=0; i<m; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix[x][int(c)-int('a')]=y;
    }

    int now=0;
    for (int i=0; i<s.size(); i++){
        x=int(s[i])-int('a');
        if (matrix[now][x]==-1){
            f2<<"Rejects";
            return 0;
        }
        now=matrix[now][x];
    }
    for (int i=0; i<k; i++){
        if (prinim[i]==now){
            f2<<"Accepts";
            return 0;
        }
    }
    f2<<"Rejects";
    return 0;
}

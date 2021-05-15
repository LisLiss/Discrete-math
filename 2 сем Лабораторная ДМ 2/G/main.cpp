#include <bits/stdc++.h>

using namespace std;
int n1,m1,k1,n2, m2, k2, x, y;
vector <vector <bool> > visit;
vector<int> prinim1;
vector <vector <int> > matrix1;
vector<int> prinim2;
vector <vector <int> > matrix2;

bool checkEquivalence(){
    queue <pair <int, int> > q;
    q.push(make_pair(1, 1));
    pair <int, int> now;
    while (!q.empty()){
        now=q.front(); q.pop();
        bool term1=false, term2=false;
        for (int i=0; i<k1; i++){
            if (now.first==prinim1[i]) term1=true;
        }
        for (int i=0; i<k2; i++){
            if (now.second==prinim2[i]) term2=true;
        }
        if (term1!=term2) return false;
        visit[now.first][now.second]=true;
        //bool flag=false;
        for (int i=0; i<26; i++){
            //if (matrix1[now.first][i]==-1 || matrix2[now.second][i]==-1) {
            //    if (matrix1[now.first][i]!=matrix2[now.second][i]==-1) flag=true;
            //    continue;
            //}
            //if (matrix1[now.first][i]==-1 && matrix2[now.second][i]!=-1) return false;
            //if (matrix1[now.first][i]!=-1 && matrix2[now.second][i]==-1) return false;
            if (!visit[matrix1[now.first][i]][matrix2[now.second][i]]){
                q.push(make_pair(matrix1[now.first][i], matrix2[now.second][i]));
            }
        }
        //if (flag && q.empty()) return false;
    }
    return true;
}
int main()
{
    ifstream f1("equivalence.in");
    ofstream f2("equivalence.out");
    char c;
    f1>>n1>>m1>>k1;
    prinim1.resize(k1);
    for (int i=0; i<k1; i++) {f1>>prinim1[i];}// prinim1[i]--;}
    matrix1.resize(n1+1, vector <int >(26, 0));
    for (int i=0; i<m1; i++){
        f1>>x>>y>>c;
       // x--; y--;
        matrix1[x][int(c)-int('a')]=y;
    }
    f1>>n2>>m2>>k2;
    prinim2.resize(k2);
    visit.resize(n1+1, vector <bool> (n2+1, false));
    for (int i=0; i<k2; i++) {f1>>prinim2[i];}// prinim2[i]--;}
    matrix2.resize(n2+1, vector<int>(26, 0));
    for (int i=0; i<m2; i++){
        f1>>x>>y>>c;
        //x--; y--;
        matrix2[x][int(c)-int('a')]=y;
    }
    if (checkEquivalence()) f2<<"YES";
    else f2<<"NO";
    return 0;
}

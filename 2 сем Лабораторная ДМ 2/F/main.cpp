#include <bits/stdc++.h>

using namespace std;
int n1,m1,k1,n2, m2, k2, x, y;
vector <int> visit;
vector<int> prinim1;
vector <vector <int> > matrix1;
vector<int> prinim2;
vector <vector <int> > matrix2;


bool checkIsomorfism(int a, int b){
    visit[a]=true;
    bool term1=false, term2=false;
    for (int i=0; i<k1; i++){
        if (a==prinim1[i]) term1=true;
    }
    for (int i=0; i<k2; i++){
        if (b==prinim2[i]) term2=true;
    }
    if (term1!=term2) return false;
    for (int i=0; i<26; i++){
        if (matrix1[a][i]!=-1 && matrix2[b][i]==-1) return false;
        if (matrix1[a][i]==-1 && matrix2[b][i]!=-1) return false;
        if (!visit[matrix1[a][i]]){
            return checkIsomorfism(matrix1[a][i], matrix2[b][i]);
        }
    }
    return true;
}
int main()
{
    ifstream f1("isomorphism.in");
    ofstream f2("isomorphism.out");
    char c;
    f1>>n1>>m1>>k1;
    prinim1.resize(k1);
    visit.resize(n1, false);
    for (int i=0; i<k1; i++) {f1>>prinim1[i]; prinim1[i]--;}
    matrix1.resize(n1, vector <int >(26, -1));
    for (int i=0; i<m1; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix1[x][int(c)-int('a')]=y;
    }
    f1>>n2>>m2>>k2;
    prinim2.resize(k2);
    for (int i=0; i<k2; i++) {f1>>prinim2[i]; prinim2[i]--;}
    matrix2.resize(n2, vector<int>(26, -1));
    for (int i=0; i<m2; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix2[x][int(c)-int('a')]=y;
    }
    if (n1!=n2 || m1!=m2 || k1!=k2){
        f2<<"NO";
        return 0;
    }
    if (checkIsomorfism(0, 0)) f2<<"YES";
    else f2<<"NO";
    return 0;
}

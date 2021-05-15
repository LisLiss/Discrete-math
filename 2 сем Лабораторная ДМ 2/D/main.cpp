#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("problem4.in");
    ofstream f2("problem4.out");
    int n, m, k, l;
    f1>>n>>m>>k>>l;
    vector <vector <int> > matrix (n);
    int x, y;
    char c;
    vector<int> prinim(k), ans(n, 0), anshelp(n, 0);
    set<int> stek1, stek2;
    for (int i=0; i<k; i++) {f1>>prinim[i]; prinim[i]--;}
    for (int i=0; i<m; i++){
        f1>>x>>y>>c;
        x--; y--;
        matrix[x].push_back(y);
    }
    int now;
    stek1.insert(0);
    for (int ll=0; ll<l; ll++){
        for (set<int>::iterator j=stek1.begin(); j!=stek1.end(); j++){
            now=*j;
            for (int t=0; t<matrix[now].size(); t++) {
                stek2.insert(matrix[now][t]);
                anshelp[matrix[now][t]]+=ans[now];
                anshelp[matrix[now][t]]=anshelp[matrix[now][t]]%(1000000007);
                if (ans[now]==0) anshelp[matrix[now][t]]++;
            }
        }
        stek1=stek2;
        stek2.clear();
        for (int j=0; j<n; j++) {ans[j]=anshelp[j]; anshelp[j]=0;}
    }
    int answer=0;
    for (int i=0; i<k; i++){
        for (int j=0; j<n; j++){
            if (prinim[i]==j){
                answer+=ans[j];
                answer%=1000000007;
            }
        }
    }
    f2<<answer;
    return 0;
}

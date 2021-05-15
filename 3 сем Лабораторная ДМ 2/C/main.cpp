#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector <int> > matrix;
vector <int> ans;
vector <bool> was;

int dfs(int v){
    if (was[v]==false){
        was[v]=true;
        for (int i=0; i<matrix[v].size(); i++){
            if ((ans[matrix[v][i]]==-1) || (dfs(ans[matrix[v][i]])==1)){
                ans[matrix[v][i]]=v;
                return 1;
            }
        }
    }
    return -1;
}

bool cmp (pair<int, int> x, pair <int, int> y){
    if (x.first>y.first) return true;
    return false;
}
int main()
{
    ifstream f1("matching.in");
    ofstream f2 ("matching.out");
    f1>>n;
    matrix.resize(n);
    vector <pair <int, int> > leftD;
    for (int i=0; i<n; i++){
        int w;
        f1>>w;
        leftD.push_back(make_pair(w, i));
    }
    sort(leftD.begin(), leftD.end(), cmp);
    for (int i=0; i<n; i++){
        int m;
        f1>>m;
        for (int j=0; j<m; j++){
            int y;
            f1>>y;
            y--;
            matrix[i].push_back(y);
        }
    }
    ans.resize(n, -1);
    was.resize(n, false);
    for (int i=0; i<n; i++){
        was.clear();
        was.resize(n,false);
        //cout<<leftD[i].first<<" "<<leftD[i].second<<endl;
        dfs(leftD[i].second);
    }
    vector <int> answer(n, 0);
    for (int i=0; i<n; i++) {
        if (ans[i]!=-1) answer[ans[i]]=i+1;
    }
    for (int i=0; i<n; i++) f2<<answer[i]<<" ";
    return 0;
}

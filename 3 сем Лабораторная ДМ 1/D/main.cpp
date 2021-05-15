#include <bits/stdc++.h>

using namespace std;

int n;
vector <vector <int> > matrix;

bool cmp(int x, int y){
    return matrix[x][y]==1;
}

bool check (vector <int> &ans){
    for (int i=0; i<n-1; i++){
        if (cmp(ans[i], ans[i+1])==false) return false;
    }
    if (cmp(ans[n-1], ans[0])==false) return false;
    return true;
}
int main(){
    ifstream f1("guyaury.in");
    ofstream f2("guyaury.out");
    f1>>n;
    matrix.resize(n, vector <int> (n, 0));
    string s;
    getline(f1, s);
    getline(f1, s);
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            char c;
            f1>>c;
            if (c=='1'){
                matrix[i][j]=1;
            } else{
                matrix[j][i]=1;
            }
        }
    }
    vector <int> ans(n);
    for (int i=0; i<n; i++) ans[i]=i;
    while (!check(ans)){
        random_shuffle(ans.begin(), ans.end());
        stable_sort(ans.begin(), ans.end(), cmp);
    }
    for (int i=0; i<n; i++) f2<<ans[i]+1<<" ";
    return 0;
}

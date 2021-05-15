#include <bits/stdc++.h>

using namespace std;

ifstream f1("gray.in");
ofstream f2("gray.out");
int nn;

vector <vector<int> > ans;

void rec(int n){
    if (n>nn) return;
    if (n==1){
        ans[0][0]=0;
        ans[1][0]=1;
    } else{
        int k=pow(2,n);
        for (int i=k/2; i<k; i++){
            for (int j=0; j<n; j++){
                ans[i][j]=ans[k-i-1][j];
            }
        }
        int j=n-1;
        for (int i=0; i<k/2; i++){
            ans[i][j]=0;
        }
        for (int i=k/2; i<k; i++){
            ans[i][j]=1;
        }
    }
    rec(n+1);
}
int main(){
    f1>>nn;
    ans.resize(pow(2,nn), vector<int>(nn, 3));
    rec(1);
    for (int i=0; i<ans.size(); i++){
        for (int j=ans[i].size()-1; j>-1; j--){
            f2<<ans[i][j];
        }
        f2<<endl;
    }
    return 0;
}

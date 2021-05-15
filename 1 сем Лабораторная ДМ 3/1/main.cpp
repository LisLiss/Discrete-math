#include <bits/stdc++.h>

using namespace std;

ifstream f1("allvectors.in");
ofstream f2("allvectors.out");

void print(int x, int n){
    vector<int> ans;
    for (int i=0; i<n; i++){
        ans.push_back(x%2);
        x/=2;
    }
    for (int i=ans.size()-1; i>=0; i--){
        f2<<ans[i];
    }
    f2<<endl;
}
int main()
{
    int n;
    f1>>n;
    int nn=pow(2,n);
    for (int i=0; i<nn; i++){
        print(i, n);
    }
    return 0;
}

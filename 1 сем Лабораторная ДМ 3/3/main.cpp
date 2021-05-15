#include <bits/stdc++.h>

using namespace std;
ifstream f1("antigray.in");
ofstream f2("antigray.out");
int n;

void print(int x){
    vector <int> ans;
    for (int i=0; i<n; i++){
        ans.push_back(x%3);
        x=x/3;
    }
    for (int i=n-1; i>-1; i--){
        f2<<ans[i];
    }
    f2<<endl;

    for (int i=n-1; i>-1; i--){
        f2<<(ans[i]+1)%3;
    }
    f2<<endl;
    for (int i=n-1; i>-1; i--){
        f2<<(ans[i]+2)%3;
    }
    f2<<endl;
}
int main()
{
    f1>>n;
    for (int i=0; i<pow(3,n-1); i++){
        print(i);
    }
    return 0;
}

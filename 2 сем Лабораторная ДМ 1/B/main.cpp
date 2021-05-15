#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("shooter.in");
    ofstream f2("shooter.out");
    int n, m, k;
    double p, ans=0, ans1;
    f1>>n>>m>>k;
    k--;
    for (int i=0; i<n; i++){
        f1>>p;
        p=1-p;
        ans+=pow(p, m);
        if (i==k) ans1=pow(p, m);
    }
    f2<<fixed<<setprecision(15);
    f2<<ans1/ans;
    f1.close();
    f2.close();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("exam.in");
    ofstream f2("exam.out");
    int k, n, p, m;
    f1>>k>>n;
    f2<<fixed<<setprecision(10);
    double ans=0;
    for (int i=0; i<k; i++){
        f1>>p>>m;
        ans+=p*m;
    }
    f2<<ans/n/100;
    f1.close();
    f2.close();
    return 0;
}

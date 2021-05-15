#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("lottery.in");
    ofstream f2("lottery.out");
    double n,m,a,b, bs=0;
    f1>>n>>m;
    double vergo=1;
    double mato=0;
    for (int i=0; i< m; i++){
        f1>>a>>b;
        mato+=(a-1)*bs/(a*vergo);
        vergo*=a;
        bs=b;
    }
    mato+=b/vergo;
    f2<<fixed<<setprecision(10);
    f2<<n-mato;
    f1.close();
    f2.close();
    return 0;
}



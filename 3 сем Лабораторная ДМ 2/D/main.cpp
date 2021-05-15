#include <bits/stdc++.h>

using namespace std;

vector <int> matrix, c;
vector <bool> was;
int n, m, n2;

bool checkFirst(){
    return was[0];
}

bool checkSecond(){
    vector <bool> used (n2, false);
    for (int i=0; i<n2; i++){
        if (was[i]){
            used[i]=true;
            for (int j=0; j<n; j++){
                if (used[i & (~(1<<j))] ==false) used[i]=false;
            }
        }
        if (was[i]!=used[i]) return false;
    }
    return true;
}

bool checkThird(){
    for (int i=0; i<n2; i++){
        for (int j=0; j<n2; j++){
            if (was[i]==true && was[j]==true && c[i]>c[j]){
                bool f=false;
                for (int k=0; k<n; k++){
                    if ((((1<<k)&i)!=0) && (((1<<k)&j)==0) && was[(1<<k)|j]==true){
                            f=true;
                    }
                }
                if (f==false) return false;
            }
        }
    }
    return true;
}
int main()
{
    ifstream f1("check.in");
    ofstream f2 ("check.out");

    f1>>n>>m;
    n2=1<<n;
    was.resize(n2, false);
    c.resize(n2);
    for (int i=0; i<m; i++){
        int m2, k, help=0;
        f1>>m2;
        for (int j=0; j<m2; j++){
            f1>>k; k--;
            help = help | (1<<k);
        }
        was[help]=true;
        c[help]=m2;
    }
    //cout<<checkFirst()<<" "<<checkSecond()<<" "<<checkThird()<<endl;
    if (checkFirst() && checkSecond() && checkThird()) f2<<"YES";
    else f2<<"NO";
    return 0;
}

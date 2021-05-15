#include <bits/stdc++.h>

using namespace std;

vector <pair <long long, long long> > w;
vector <bool> was;
vector<long long> c;
long long n, m, n2;

long long BaseMax(){
    long long ans=0, now=0;
    for (long long i=0; i<n; i++){
        if (was[now|(1<<w[i].second)]==false){
            ans+=w[i].first;
            now=now|(1<<w[i].second);
        }
    }
    return ans;
}

bool cmp(pair <long long, long long> x, pair <long long, long long> y){
    if (x.first>y.first) return true;
    return false;
}
int main(){
    ifstream f1("cycles.in");
    ofstream f2 ("cycles.out");

    f1>>n>>m;
    n2=1<<n;
    was.resize(n2, false);
    for (long long i=0; i<n; i++){
        long long w1;
        f1>>w1;
        w.push_back(make_pair(w1, i));
    }
    sort(w.begin(), w.end(), cmp);
    for (long long i=0; i<m; i++){
        long long m2, k, help=0;
        f1>>m2;
        for (long long j=0; j<m2; j++){
            f1>>k; k--;
            help = help | (1<<k);
        }
        was[help]=true;
        c.push_back(help);
    }
    while (c.size()!=0){
        long long help=c[c.size()-1];
        c.pop_back();
        for (long long i=0; i<n; i++){
            if (was[help | (1<<i)]==false) c.push_back(help|(1<<i));
            was[help|(1<<i)]=true;
        }
    }
    f2<<BaseMax();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<long long, long long> x, pair<long long, long long> y){
    if (x.second>y.second) return true;
    if (x.second<y.second) return false;
    return x.first<y.first;
}

int main()
{
    ifstream f1("schedule.in");
    ofstream f2("schedule.out");
    long long n;
    f1>>n;
    vector <pair <long long, long long> > a(n);
    set <long long> was;
    for (long long i=0; i<n; i++){
        f1>>a[i].first>>a[i].second;
        was.insert(i+1);
    }
    sort(a.begin(), a.end(), cmp);
    long long ans=0, now=0;
    for (long long i=0; i<n; i++){
        //cout<<a[i].first<<" "<<a[i].second<<endl;
        auto help=was.lower_bound(a[i].first);
        if (*help==a[i].first){
            was.erase(help);
        } else{
            if (help==was.begin()) ans+=a[i].second;
            else was.erase(--help);
        }
    }
    f2<<ans;
    return 0;
}

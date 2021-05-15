#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;
int n, m;
vector <ll> a, b;

void sum(){
    vector <ll> ans;
    int flag=0;
    for (int i=0; i<max(n, m); i++){
        ans.push_back((a[i]+b[i])%MOD);
        if (ans[i]!=0) flag=i;
    }
    cout<<flag<<endl;
    for (int i=0; i<flag+1; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void mul(){
    vector <ll> ans(n+m, 0);
    int flag=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ans[i+j]+=a[i]*b[j];
            ans[i+j]%=MOD;
            if (ans[i+j]!=0) flag=max(flag, i+j);
        }
    }
    cout<<flag<<endl;
    for (int i=0; i<flag+1; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void div(){
    vector <ll> ans(1000, 0);
    for (int i=0; i<1000; i++){
        ll help=0;
        for (int j=0; j<i; j++){
            if (i-j<m){
                help+=(ans[j]*b[i-j])%MOD;
                help%=MOD;
            }
        }
        if (i<n){
            ans[i]=(a[i]-help)/b[0];
            ans[i]%=MOD;
        } else{
            ans[i]=(0-help)/b[0];
            ans[i]%=MOD;
        }
    }
    for (int i=0; i<1000; i++){
        if (ans[i]<0){
            cout<<ans[i]+MOD<<" ";
        }
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>m;
    n++; m++;
    a.resize(max(n, m), 0);
    b.resize(max(n, m), 0);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<m; i++){
        cin>>b[i];
    }
    sum();
    mul();
    div();
    return 0;
}

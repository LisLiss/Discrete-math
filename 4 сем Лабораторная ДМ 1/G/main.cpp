#include <bits/stdc++.h>

using namespace std;
#define ll long long

string komb;
ll pos;

vector <ll> seq(vector <ll> &a){
    vector <ll> ans(7, 0);
    ans[0]=1;
    for (int i=1; i<7; i++){
        for (int j=1; j<i+1; j++){
            ans[i]+=ans[i-j]*a[j];
        }
    }
    return ans;
}

vector <ll> mset(vector <ll> &a){
    vector <ll> ans(7, 0);
    ans[0]=1;
    vector <vector <ll> > m(7, vector <ll> (7, 0));
    for (int i=0; i<7; i++){
        m[0][i]=1;
    }
    for (int i=1; i<7; i++){
        for (int j=1; j<7; j++){
            ll binom=1;
            m[i][j]+=m[i][j-1];
            for (int k=1; k<=i/j; k++){
                if (a[j]+k-1>0){
                    binom*=a[j]+k-1;
                    binom/=k;
                    m[i][j]+=binom*m[i-k*j][j-1];
                }
            }
        }
        ans[i]=m[i][i];
    }
    return ans;
}

vector <ll> pairtwo(vector <ll> &a, vector <ll> &b){
    vector <ll> ans(7, 0);
    for (int i=0; i<7; i++){
        for (int j=0; j<i+1; j++){
            ans[i]+=a[j]*b[i-j];
        }
    }
    return ans;
}

vector <ll> make_ans(){
    vector <ll> ans(7, 0);
    vector <ll> a, b;
    if (komb[pos]=='L'){
        pos+=2;
        a=make_ans();
        ans=seq(a);
        pos++;
    } else{
        if (komb[pos]=='S'){
            pos+=2;
            a=make_ans();
            ans=mset(a);
            pos++;
        } else{
            if (komb[pos]=='P'){
                pos+=2;
                a=make_ans();
                pos++;
                b=make_ans();
                ans=pairtwo(a, b);
                pos++;
            } else{
                if (komb[pos]=='B'){
                    ans[1]=1;
                    pos++;
                }
            }
        }
    }
    return ans;
}

int main(){
    //L = seq
    //S = mset
    //P = pair
    cin>>komb;
    pos=0;
    vector<ll> ans=make_ans();
    for (int i=0; i<7; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

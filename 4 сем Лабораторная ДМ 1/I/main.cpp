#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector <ll> a, c, q, nq, mulq;
ll k, n;
const ll MOD = 104857601;

int main(){
    cin>>k>>n;
    n--;
    a.resize(2*k+1);
    c.resize(k);
    q.resize(k+1);
    nq.resize(k+1);
    mulq.resize(k+1);
    for (int i=0; i<k; i++){
        cin>>a[i];
    }
    for (int i=0; i<k; i++){
        cin>>c[i];
        q[i+1]=(MOD - c[i])%MOD;
    }
    q[0]=1;
    if (n<k){
        cout<<a[n];
        return 0;
    }
    while (n>=k){
        for (int i=0; i<k+1; i++){
            a[i+k]=0;
            for (int j=0; j<k; j++){
                //cout<<q[j+1]<<endl;
                a[k+i]+=((MOD-q[j+1])*a[k+i-j-1])%MOD;
                a[k+i]%=MOD;
            }
        }
        /*for (int i=0; i<2*k; i++){
            cout<<a[i]<<" ";
        } cout<<endl;
        */
        for (int i=0; i<k+1; i++){
            if (i%2==0) nq[i]=q[i];
            else nq[i]=(MOD-q[i])%MOD;
        }
        for (int i=0; i<=2*k; i+=2){
            ll help =0;
            for (int j=0; j<i+1; j++){
                if (j<=k){
                    if (i-j<=k){
                        help+=q[j]*nq[i-j];
                        help%=MOD;
                    }
                }
            }
            mulq[i/2]=help;
        }
        q.resize(0);
        for (int i=0; i<k+1; i++){
            q.push_back(mulq[i]);
        }
        ll help=0;
        if (n%2==0){
            for (int i=0; i<2*k; i+=2){
                a[help]=a[i];
                help++;
            }
        } else{
            for (int i=1; i<2*k; i+=2){
                a[help]=a[i];
                help++;
            }
        }
        n/=2;
    }
    cout<<a[n];
    return 0;
}

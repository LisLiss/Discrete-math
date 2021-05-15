#include <bits/stdc++.h>

using namespace std;

ifstream f1("telemetry.in");
ofstream f2("telemetry.out");
int nn, sis;

vector <vector<int> > ans;

void rec(int n){
    if (n>nn) return;
    if (n==1){
        for (int i=0; i<sis; i++){
            ans[i][0]=i;
        }
    } else{
        int k=pow(2,n);
        int where=0;
        for (int i=0; i<sis; i++){
            for (int j=0; j<pow(sis,n-1); j++){
                ans[where][n-1]=i;
                where++;
            }
        }
        bool f=true;
        where=pow(sis,n-1);
        int help1=where-1;
        int help2=0;
        for(int i=1; i<sis; i++){
            if (f){
                for (int j=0; j<pow(sis,n-1); j++){
                    for (int k=0; k<n-1; k++){
                        ans[where][k]=ans[help1][k];
                    }
                    where++;
                    help1--;
                }
                f=false;
                help1=pow(sis, n-1)-1;
            } else{
                for (int j=0; j<pow(sis,n-1); j++){
                    for (int k=0; k<n-1; k++){
                        ans[where][k]=ans[help2][k];
                    }
                    where++;
                    help2++;
                }
                f=true;
                help2=0;
            }
        }
    }
    rec(n+1);
}
int main(){
    f1>>nn>>sis;
    ans.resize(pow(sis,nn), vector<int>(nn, 0));
    rec(1);
    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            f2<<ans[i][j];
        }
        f2<<endl;
    }
    return 0;
}

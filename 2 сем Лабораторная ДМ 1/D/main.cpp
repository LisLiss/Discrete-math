#include <bits/stdc++.h>

using namespace std;
vector <vector<double> > ans, help;
int n;
const double e=1e-5;
void swp(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans[i][j]=help[i][j];
            help[i][j]=0;
        }
    }
}


bool check(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (abs(ans[i][j]-help[i][j])>e) return false;
        }
    }
    return true;
}

void mul(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                help[i][k]+=ans[i][j]*ans[j][k];
            }
        }
    }
    if (check()) return;
    swp();
    mul();
}

int main()
{
    ifstream f1("markchain.in");
    ofstream f2("markchain.out");
    f1>>n;
    ans.resize(n, vector <double> (n));
    help.resize(n, vector <double> (n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            f1>>ans[i][j];
        }
    }
    mul();
    f2<<fixed<<setprecision(10);
    for (int i=0; i<n; i++) f2<<ans[0][i]<<endl;
    f1.close();
    f2.close();
    return 0;
}

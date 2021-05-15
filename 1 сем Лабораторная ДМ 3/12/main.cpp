#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, kk;
vector <vector <vector <string> > > ans;

ifstream f1("part2sets.in");
ofstream f2("part2sets.out");

void Build(){
    vector <string> h;
    string help;
    help+=char (int('0')+0);
    h.push_back(help);
    ans[0].push_back(h);
    for (int i=1; i<n; i++){//разбиение для чисел <=i
        for (int j=0; j<ans[i-1].size(); j++){ //идем по всем разбиения прошлым
            for (int k=0; k<ans[i-1][j].size(); k++){//идем по элементам в разбиении
                ans[i].push_back(ans[i-1][j]);
                ans[i][ans[i].size()-1][k]+=char (int('0')+i);
            }
            ans[i].push_back(ans[i-1][j]);
            help="";
            help+=char (int('0')+i);
            h[0]=help;
            ans[i][ans[i].size()-1].push_back(help);
        }
    }
}

void print(){
    int i=n-1;
    for (int j=0; j<ans[i].size(); j++){
        if (ans[i][j].size()!=kk) continue;
        for (int k=0; k<ans[i][j].size(); k++){
            for (int m=0; m<ans[i][j][k].size(); m++){
                char ch=ans[i][j][k][m];
                f2<<int(ch)-int('0')+1<<" ";
            }
            f2<<endl;
        }
        f2<<endl;
    }
}

int main()
{
    f1>>n>>kk;
    ans.resize(n);
    Build();
    print();
    return 0;
}

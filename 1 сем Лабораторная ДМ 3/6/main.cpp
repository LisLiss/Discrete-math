#include <bits/stdc++.h>

using namespace std;
ifstream f1("vectors.in");
ofstream f2("vectors.out");

vector <vector<int> > help;
int n;

void print(int x){
    vector<int> ans;
    for (int i=0; i<n; i++){
        ans.push_back(x%2);
        x/=2;
    }
    help.push_back(ans);
}
int main()
{
    f1>>n;
    int k=pow(2,n);
    for (int i=0; i<k; i++){
        print(i);
    }
    bool f=false;
    int ans=0;
    vector <vector<int> > answer;

    for(int i=0; i<k; i++){
        for (int j=1; j<n; j++){
            if(help[i][j]==help[i][j-1]){
                if (help[i][j]==1){
                    f=true;
                    break;
                }
            }
        }
        if (f==true){
            f=false;
        } else{
            ans++;
            answer.push_back(help[i]);
        }
    }
    f2<<ans<<endl;
    for (int i=0; i<answer.size(); i++){
        for (int j=answer[i].size()-1; j>-1; j--){
            f2<<answer[i][j];
        }
        f2<<endl;
    }
    return 0;
}

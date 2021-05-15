#include <bits/stdc++.h>

using namespace std;
ifstream f1("choose.in");
ofstream f2("choose.out");

int n, k;
bool isKomb(vector<int> s){
    if (s.size()<k) return false;
    return true;
}

void print(vector <int> s){
    for (int i=0; i<s.size(); i++){
        f2<<s[i]<<" ";
    }
    f2<<endl;
}

void generate(vector <int> x){
    if (isKomb(x)){
        print(x);
    } else{
        for (int i=x[x.size()-1]+1; i<n+1; i++){
            vector <int> s =x;
            s.push_back(i);
            generate(s);
        }
    }
}
int main()
{
    f1>>n>>k;
    for (int i=1; i<n+1; i++){
        vector<int> s;
        s.push_back(i);
        generate(s);
    }
    return 0;
}

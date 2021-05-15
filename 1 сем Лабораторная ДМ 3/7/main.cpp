#include <bits/stdc++.h>

using namespace std;
ifstream f1("permutations.in");
ofstream f2("permutations.out");

int n;
bool isKomb(vector<int> s){
    vector<bool> num(n, false);
    for (int i=0; i<s.size(); i++){
        if (num[s[i]-1]==true) return false;
        num[s[i]-1]=true;
    }
    return true;
}

void print(vector <int> s){
    for (int i=0; i<s.size(); i++){
        f2<<s[i]<<" ";
    }
    f2<<endl;
}

void generate(vector <int> x){
    if (isKomb(x) && x.size()==n){
        print(x);
    } else{
        for (int i=1; i<n+1; i++){
            vector <int> s = x;
            s.push_back(i);
            if (isKomb(s)) generate(s);
        }
    }
}
int main()
{
    f1>>n;
    for (int i=1; i<n+1; i++){
        vector<int> s;
        s.push_back(i);
        generate(s);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
ifstream f1("partition.in");
ofstream f2("partition.out");

int n;
bool isKomb(vector<int> s){
    int ans=0;
    for (int i=0; i<s.size(); i++){
        ans+=s[i];
        if (ans>n) return false;
    }
    return true;
}

void print(vector <int> s){
    for (int i=0; i<s.size()-1; i++){
        cout<<s[i]<<"+";
    }
    cout<<s[s.size()-1]<<endl;
}
bool isKombPoln(vector<int> s){
    int ans=0;
    for (int i=0; i<s.size(); i++){
        ans+=s[i];
        if (ans>n) return false;
    }
    if (ans!=n) return false;
    return true;
}

void generate(vector <int> x){
    if (isKombPoln(x)){
        print(x);
    } else{
        for (int i=x[x.size()-1]; i<n+1; i++){
            vector <int> s = x;
            s.push_back(i);
            if (isKomb(s)) generate(s);
        }
    }
}
int main()
{
    cin>>n;
    vector<int> s;
    for (int i=1; i<n+1; i++){
        vector<int> s;
        s.push_back(i);
        generate(s);
    }
    return 0;
}

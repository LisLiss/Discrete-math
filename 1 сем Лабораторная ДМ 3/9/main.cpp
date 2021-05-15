#include <bits/stdc++.h>

using namespace std;
ifstream f1("brackets.in");
ofstream f2("brackets.out");

int n;
bool isKomb(vector<char> s){
    if (s.size()>2*n) return false;
    int ans=0;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='(') ans++;
        else{
            if (ans-1<0) return false;
            ans--;
        }
    }
    return true;
}

bool isKombPoln(vector<char> s){
    int ans=0;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='(') ans++;
        else{
            if (ans-1<0) return false;
            ans--;
        }
    }
    if (ans!=0) return false;
    return true;
}
void print(vector <char> s){
    for (int i=0; i<s.size(); i++){
        f2<<s[i];
    }
    f2<<endl;
}

void generate(vector <char> x){
    if (isKombPoln(x) && x.size()==2*n){
        print(x);
    } else{
        for (int i=0; i<2; i++){
            vector <char> s = x;
            if (i==0){
                s.push_back('(');
            } else{
            s.push_back(')');
            }
            if (isKomb(s)) generate(s);
        }
    }
}
int main()
{
    f1>>n;
    vector<char> s;
    s.push_back('(');
    generate(s);
    return 0;
}

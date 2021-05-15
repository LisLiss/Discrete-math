#include <bits/stdc++.h>

using namespace std;


bool cmp(int x, int y){
    cout<<"1 "<<x<<" "<<y<<endl;
    string s;
    cin>>s;
    return s=="YES";
}
int main(){
    int n;
    cin>>n;
    vector <int> matrix(n);
    for (int i=0; i<n; i++) matrix[i]=i+1;
    stable_sort(matrix.begin(), matrix.end(), cmp);
    cout<<"0 ";
    for (int i=0; i<n; i++) cout<<matrix[i]<<" ";
    return 0;
}

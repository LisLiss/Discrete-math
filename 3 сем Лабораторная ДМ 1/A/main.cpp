#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f1("fullham.in");
    ofstream f2("fullham.out");
    int n, left=0, right=n;
    f1>>n;
    vector <vector <int> > matrix(n, vector <int> (n, 0));
    string s;
    getline(f1, s);
    getline(f1, s);
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            char c;
            f1>>c;
            if (c=='1'){
                matrix[i][j]=1;
                matrix[j][i]=1;
            }
        }
    }
    vector <int> vertex;
    for (int i=0; i<n; i++) vertex.push_back(i);
    for (int k=0; k<n*(n-1); k++){
        if (matrix[vertex[0+left]][vertex[1+left]]==0){
            int help=2;
            while ((matrix[vertex[0+left]][vertex[help+left]]==0) || (matrix[vertex[help+1+left]][vertex[1+left]]==0)) help++;
            reverse(&vertex[1+left], &vertex[help+1+left]);
        }
        vertex.push_back(vertex[left]);
        left++; right++;
    }
    for (int i=left; i<left+n; i++) f2<<vertex[i]+1<<" ";
    return 0;
}

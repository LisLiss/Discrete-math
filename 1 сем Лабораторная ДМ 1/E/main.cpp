#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> tableIstin;
vector <vector <bool> > graf;
vector <vector <int> > tableGraf;
vector <int> numList;
int dfs(int v, int ans){
    int help = ans;
    for (int i=0; i<n; i++){
        if (tableGraf[i].size()==0) continue;
        if (graf[v][i]==true) {
            help = max(help, dfs(i, ans+1));
        }
    }
    return help;
}


int answer(int v){
    if (tableGraf[v].size()==0) return tableIstin[numList[v]];
    int nn=1;
    int number=0;
    for (int i=n-1; i>-1; i--){
        if (graf[v][i]==false) continue;
        number+=answer(i)*nn;
        nn*=2;
    }
    return tableGraf[v][number];
}
void inc(){
    int x=tableIstin.size()-1;
    while(tableIstin[x]==1 && x>-1) {
        tableIstin[x]=0;
        x--;
    }
    if (x>-1) tableIstin[x]=1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    graf.resize(n, vector <bool> (n, false));
    tableGraf.resize(n);
    numList.resize(n, 0);
    int m, kolList=0;;
    for (int i =0; i< n; i++){
        cin>>m;
        if (m==0){
            numList[i]=kolList;
            kolList++;
        }
        else{
            int x;
            for (int j=0; j<m; j++){
                cin>>x;
                graf[i][x-1]=true;
            }
            for (int j=0; j<pow(2, m); j++){
                cin>>x;
                tableGraf[i].push_back(x);
            }
        }
    }
    int ans = dfs(n-1, 1);
    int nn = pow(2, kolList);
    tableIstin.resize(kolList, 0);
    cout<<ans<<endl;
    for (int i=0; i<nn; i++){
        cout<<answer(n-1);
        inc();
    }

    return 0;
}

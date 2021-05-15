#include <bits/stdc++.h>

using namespace std;
int n,m,k, x, y;
vector<int> prinim, prinimNew, prinimAns;
vector <vector <int> > matrix, matrixNew, matrixAns;
vector <vector <vector <int> > > revmatrix, revmatrixNew;

void goFromStart(vector <bool> &was, vector <bool> &canGoFromStart, int x){
    if (!was[x]){
        was[x]=true;
        canGoFromStart[x]=true;
        for (int i=0; i<26; i++){
            if (matrix[x][i]!=-1) goFromStart(was, canGoFromStart, matrix[x][i]);
        }
    }
}

void goFromTerm(vector <bool> &was, vector <bool> &canGoFromTerm, int x){
    if (!was[x]){
        was[x]=true;
        canGoFromTerm[x]=true;
        for (int i=0; i<26; i++){
            for (int j=0; j<revmatrix[x][i].size(); j++){
                goFromTerm(was, canGoFromTerm, revmatrix[x][i][j]);
            }
        }
    }
}


int main()
{
    ifstream f1("minimization.in");
    ofstream f2("minimization.out");
    char c;
    f1>>n>>m>>k;
    prinim.resize(k+1);
    for (int i=0; i<k; i++) {f1>>prinim[i];}
    matrix.resize(n+1, vector <int >(26, -1));
    revmatrix.resize(n+1, vector <vector <int> >(26));
    for (int i=0; i<m; i++){
        f1>>x>>y>>c;
        matrix[x][int(c)-int('a')]=y;
        revmatrix[y][int(c)-int('a')].push_back(x);
    }
    vector <bool> was(n+1, false);
    vector <bool> canGoFromTerm(n+1, false);
    vector <bool> canGoFromStart(n+1, false);
    goFromStart(was, canGoFromStart, 1);
    was.clear();
    was.resize(n+1, false);
    for (int i=0; i<k; i++){
        goFromTerm(was, canGoFromTerm, prinim[i]);
    }
    int numGood=1;
    vector <int> good(n+1, -1);
    for (int i=1; i<=n; i++){
        if (canGoFromStart[i] && canGoFromTerm[i]){
            good[i]=numGood;
            numGood++;
        }
    }


    matrixNew.resize(numGood, vector <int >(26, 0));
    revmatrixNew.resize(numGood, vector <vector <int> >(26));
    int helpnum=1;

    for (int i=1; i<=n; i++){
        if (good[i]==-1) continue;
        for (int j=0; j<26; j++){
            if (matrix[i][j]==-1) continue;
            if (good[matrix[i][j]]!=-1){
                matrixNew[helpnum][j]=good[matrix[i][j]];
                revmatrixNew[good[matrix[i][j]]][j].push_back(helpnum);
            }
        }
        helpnum++;
    }
    for (int i=0; i<k; i++){
        if (good[prinim[i]]!=-1){
            prinimNew.push_back(good[prinim[i]]);
        }
    }
    n=numGood;
    k=prinimNew.size();

    vector <unordered_set <int> > p;
    vector <int> numClass(n);
    queue <pair <int, int> > q;
    unordered_set <int> firstClass, secondClass;
    unordered_map <int, vector<int> > involved;
    for (int i=0; i<k; i++){
        numClass[prinimNew[i]]=0;
        firstClass.insert(prinimNew[i]);
    }
    if (!firstClass.empty()) p.push_back(firstClass);
    for (int i=1; i<n; i++){
        if (firstClass.find(i)==firstClass.end()) {
            secondClass.insert(i);
            numClass[i]=1;
        }
    }
    if (!secondClass.empty()) p.push_back(secondClass);
    for (int i=0; i<26; i++){
        if (!firstClass.empty()) q.push(make_pair(0, i));
        if (!secondClass.empty()) q.push(make_pair(1, i));
    }
    for (int i=0; i<p.size(); i++){
        for (unordered_set<int>::iterator kk=p[i].begin(); kk!=p[i].end(); kk++){
            numClass[*kk]=i;
        }
    }
    pair<int, int> now;
    while (!q.empty()){
        now=q.front(); q.pop();
        unordered_map<int, vector<int>> involved;
        for (unordered_set<int>::iterator qq=p[now.first].begin(); qq!=p[now.first].end(); qq++) {
            for (int r=0; r<revmatrixNew[*qq][now.second].size(); r++) {
                int i = numClass[revmatrixNew[*qq][now.second][r]];
                if (involved.find(i) == involved.end()) {
                    involved.insert(make_pair(i, vector<int>()));
                }
                (*(involved.find(i))).second.push_back(revmatrixNew[*qq][now.second][r]);
            }
        }
        for (unordered_map<int, vector<int> >::iterator ppp=involved.begin(); ppp!=involved.end(); ppp++) {
            pair<int, vector<int> > helpNow=*ppp;
            if (helpNow.second.size() < p[helpNow.first].size()) {
                p.push_back(unordered_set<int>());
                for (int r=0; r<helpNow.second.size(); r++) {
                    p[helpNow.first].erase(helpNow.second[r]);
                    p[p.size() - 1].insert(helpNow.second[r]);
                }
                if (p[p.size() - 1].size() > p[helpNow.first].size()) {
                    swap(p[p.size() - 1], p[helpNow.first]);
                }
                for (unordered_set<int>::iterator r=p[p.size() - 1].begin(); r!=p[p.size() - 1].end(); r++) {
                    numClass[*r] = p.size() - 1;
                }
                for (int i = 0; i < 26; ++i) {
                    q.push(pair<int, int>(p.size() - 1, i));
                }
            }
        }
    }
    for (int i=0; i<p.size(); i++){
        for(int t : p[i]) {
            numClass[t] = i;
        }
    }
    if (numClass[1]!=0){
        int helpNum=numClass[1];
        for (unordered_set<int>::iterator kk=p[0].begin(); kk!=p[0].end(); kk++) numClass[*kk]=helpNum;
        for (unordered_set<int>::iterator kk=p[numClass[1]].begin(); kk!=p[numClass[1]].end(); kk++) numClass[*kk]=0;
        swap(p[0],p[helpNum]);
    }
    n=p.size();
    for (int i=0; i<n; i++){
        bool f=false;
        for (unordered_set<int>::iterator kk=p[i].begin(); kk!=p[i].end(); kk++){
            for (int j=0; j<k; j++){
                if (prinimNew[j]==*kk) {
                    prinimAns.push_back(i);
                    f=true;
                    break;
                }
            }
            if (f==true) break;
        }
    }
    k=prinimAns.size();
    m=0;
    matrixAns.resize(n, vector<int> (26, -1));
    for (int i=0; i<n; i++){
        for (unordered_set<int>::iterator kk=p[i].begin(); kk!=p[i].end(); kk++){
            for (int j=0; j<26; j++){
                if (matrixNew[*kk][j]!=0) {
                    matrixAns[i][j]=numClass[matrixNew[*kk][j]];
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<26; j++){
            if (matrixAns[i][j]!=-1) m++;
        }
    }
    f2<<n<<" "<<m<<" "<<k<<endl;
    for (int i=0; i<k; i++) f2<<prinimAns[i]+1<<" ";
    f2<<endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<26; j++){
            if (matrixAns[i][j]!=-1) f2<<i+1<<" "<<matrixAns[i][j]+1<<" "<<(char)(int('a')+j)<<endl;
        }
    }

    return 0;
}

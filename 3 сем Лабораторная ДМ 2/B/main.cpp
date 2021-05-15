    #include <bits/stdc++.h>

    using namespace std;
    struct edge{
        int x,y,i;
        long long w;
    };
    vector <int> p;
    vector <edge> matrix;
    int n, m;
    vector <bool> ans;
    int get(int v){
        return (v == p[v]) ? v : (p[v] = get (p[v]));
        //if (v == p[v]) return v;
        //p[v]=get(p[v]);
        //return p[v];
    }

    int unite (int x, int y){
        x = get(x);
        y = get(y);
        if (x!=y) p[x]=y;
    }

    void kruskal(){
        for (int i=0; i<m; i++){
            int x = matrix[i].x;
            int y = matrix[i].y;
            long long w = matrix[i].w;
            if (get(x)!=get(y)){
                ans[matrix[i].i]=true;
                unite(x, y);
            }
        }
    }

    bool cmp(edge x, edge y){
        return x.w > y.w;
    }
    int main(){
        ifstream f1("destroy.in");
    ofstream f2("destroy.out");

        long long s, sum=0;
        f1>>n>>m>>s;
        p.resize(n);
        for (int i=0; i<n; i++) p[i]=i;
        for (int i=0; i<m; i++){
            int x, y;
            long long w;
            f1>>x>>y>>w;
            x--; y--;
            edge help; help.x=x; help.y=y; help.w=w; help.i=i;
            matrix.push_back(help);
        }
        ans.resize(m,false);
        sort (matrix.begin(), matrix.end(), cmp);
        kruskal();
        vector <int> answer;
        for (int i=m-1; i>-1; i--){
            if ((ans[matrix[i].i]==false) && (sum+matrix[i].w<=s)){
                answer.push_back(matrix[i].i);
                sum+=matrix[i].w;
            }
        }
        f2<<answer.size()<<endl;
        sort(answer.begin(), answer.end());
        for (int i=0; i<answer.size(); i++){
            f2<<answer[i]+1<<" ";
        }
        return 0;
    }

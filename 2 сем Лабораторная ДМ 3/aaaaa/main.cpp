#include <bits/stdc++.h>

using namespace std;
const int N = 110;

int start;
vector< pair<int, int> > g[N*10];
vector<string> gg[30];
int dp[N*10][N][N];
string sword;
int n;
int cur_nterm = 26;

int conv(char c) {
    if (c >= 'a' && c <= 'z') {
        return -(c - 'a' + 2);
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    return -1;
}

char chr(int x) {
    return (-x - 2) + 'a';
}

void veryLong() {
    for (int i = 0; i < 26; i++) {
        for (string to: gg[i]) {
            int cur = i;
            for (int j = 0; j < (int)to.size() - 2; j++) {
                g[cur].push_back(make_pair(conv(to[j]), cur_nterm));
                cur = cur_nterm;
                cur_nterm++;
            }
            if (to.size() >= 2) {
                g[cur].push_back(make_pair(conv(to[to.size() - 2]), conv(to[to.size() - 1])));
            } else {
                if (to.size() == 1) g[cur].push_back(make_pair(conv(to[to.size() - 1]), -1));
                else g[cur].push_back(make_pair(-1, -1));
            }
        }
    }
}

int makeDp(int state, int st, int en) {
    if (dp[state][st][en] != -1) return dp[state][st][en];
    dp[state][st][en] = 0;
    if (st == en) {
        for (pair<int, int> x: g[state]) {
            if (x.second == -1 && x.first < -1 && (sword[st] == chr(x.first))) {
                dp[state][st][st] = 1;
                return dp[state][st][st];
            }
        }
    }
    int i = state;
    int len = en - st + 1;
    for (int k = st - 1; k <= en; k++) {
        for (pair<int, int> x: g[i]) {
            if (x.second == -1 && x.first >= 0) {
                dp[i][st][en] |= makeDp(x.first, st, en);
            }
            if (x.second < -1 && x.first < -1 && len == 2 && chr(x.first) == sword[st] && chr(x.second) == sword[en]) {
                dp[i][st][en] = 1;
            }
            if (x.second >= 0 && x.first < -1 && chr(x.first) == sword[st]) {
                dp[i][st][en] |= makeDp(x.second, st + 1, en);
            }
            if (x.second < -1 && x.first >= 0 && chr(x.second) == sword[en]) {
                dp[i][st][en] |= makeDp(x.first, st, en - 1);
            }
            if (x.second >= 0 && x.first >= 0) {
                dp[i][st][en] |= (makeDp(x.first, st, k) & makeDp(x.second, k + 1, en));
            }
            if (len == 0 && x.first == -1) {
                dp[i][st][en] = 1;
            }
        }
    }
    return dp[i][st][en];
}

void init() {
    for (int i = 0; i < N * 10; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
}

int main() {
    ifstream f1("cf.in");
    ofstream f2("cf.out");

    init();
    char d;
    f1 >> n >> d;
    start = d - 'A';
    getline(f1, sword);
    for (int i = 0; i < n; i++) {
        getline(f1, sword);
        int from = sword[0] - 'A';
        string to = "";
        for (int j = 5; j < (int)sword.size(); j++) {
            to += sword[j];
        }
        gg[from].push_back(to);
    }
    getline(f1, sword);
    veryLong();
    if (makeDp(start, 0, (int)sword.size() - 1)) f2 << "yes" << endl;
    else f2 << "no" << endl;

    return 0;
}

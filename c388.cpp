#include <bits/stdc++.h>
using namespace std;

#define forn(i, e) for (int i = 0; i < e; i++)

void solve() {
    int a, c = 0;
    cin >> a;
    int fs = 0, sc = 0;

    vector<vector<int>> vs(a);

    forn(i, a) {
        int cs;
        cin >> cs;
        c += cs;
        vs[i].resize(cs);
        forn(j, cs)
            cin >> vs[i][j];
    }

    for (int i = 0; i < c; i++) {
        int maxx = 0, cp = -1;

        if (i % 2 != 0) {
            for (int j = 0; j < a; j++) {
                if (!vs[j].empty() && vs[j].back() > maxx) {
                    maxx = vs[j].back();
                    cp = j;
                }
            }
            if (cp != -1) {
                fs += vs[cp].back();
                vs[cp].pop_back();
            }
        } else {
            for (int j = 0; j < a; j++) {
                if (!vs[j].empty() && vs[j].front() > maxx) {
                    maxx = vs[j].front();
                    cp = j;
                }
            }
            if (cp != -1) {
                sc += vs[cp].front();
                vs[cp].erase(vs[cp].begin());
            }
        }
    }

    cout << sc << " " << fs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

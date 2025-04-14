#include <bits/stdc++.h>
using namespace std;

#define forn(i, e) for (int i = 0; i < e; i++)
#define ln "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int l;
    cin >> l;

    vector<int> vs(l);  // ✅ Fixed: Allocate correct size
    forn(i, l) cin >> vs[i];

    int s = -1, e = -1, cou = 0;
    bool found = false;

    // ✅ Find the first decreasing point
    for (int i = 0; i < l - 1; i++) {
        if (vs[i] > vs[i + 1]) {
            if (!found) {
                s = i;  // Start of the segment
                found = true;
            }
            e = i + 1;  // Extend the segment
        }
    }

    // ✅ If there is no decreasing segment, array is already sorted
    if (!found) {
        cout << "yes\n1 1\n";
        return;
    }

    // ✅ Reverse the segment and check if sorted
    reverse(vs.begin() + s, vs.begin() + e + 1);

    if (is_sorted(vs.begin(), vs.end())) {
        cout << "yes\n" << s + 1 << " " << e + 1 << ln;  // Convert to 1-based indexing
    } else {
        cout << "no\n";
    }
}

int main() {
    fast_cin();
    solve();
    return 0;
}

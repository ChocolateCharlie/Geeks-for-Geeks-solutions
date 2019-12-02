#include <algorithm>
#include <iostream>
#include <vector>
#define ll  long long

using namespace std;

struct  PrimeFactor {
    int val;
    ll  next;
    int i;
};


// Global variables
vector<ll>  g_ugly_nbs;
vector<PrimeFactor> g_pf = { {2, 2, 0}, { 3, 3, 0}, { 5, 5, 0} };


// Compute n-th ugly number
ll  getUglyNumber(int n) {
    if (g_ugly_nbs.empty()) g_ugly_nbs.push_back(1);
    if (g_ugly_nbs.size() >= n) return(g_ugly_nbs[n - 1]);

    ll  next;

    while (g_ugly_nbs.size() < n) {
        sort(g_pf.begin(), g_pf.end(),
             [](const PrimeFactor &a, const PrimeFactor &b)
             -> bool { return(a.next < b.next); });
        next = g_pf.front().next;
        g_ugly_nbs.push_back(next);

        for (int i = 0; i < g_pf.size(); i++) {
            if (g_pf[i].next == next)
                g_pf[i].next = g_ugly_nbs[++g_pf[i].i] * g_pf[i].val;
        }
    }

    return(g_ugly_nbs[n - 1]);
}



int main() {
    int T, n;

    cin >> T;

    while (T--) {
        cin >> n;
        cout << getUglyNumber(n) << endl;
    }

	return(0);
}

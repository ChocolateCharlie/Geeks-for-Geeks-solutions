#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    double  v, w;
};



double  fractionalKnapsack(vector<Item> &i, double w) {
    double  r;

    r = 0.0;
    sort(i.begin(), i.end(), [](const Item &a, const Item &b) -> bool {
         return(a.v / a.w < b.v / b.w); });

    while (w > 0.0 && !i.empty()) {
        if (i.back().w > w) {
            r += (i.back().v / i.back().w * w);
            w = 0.0;
        }
        else {
            r += i.back().v;
            w -= i.back().w;
        }

        i.pop_back();
    }

    return(r);
}



int main() {
    int T, n;
    double  w;

    cin >> T;

    while (T--) {
        cin >> n >> w;
        vector<Item>    items(n);
        for (int i = 0; i < n; i++) cin >> items[i].v >> items[i].w;
        cout << fixed << setprecision(2) << fractionalKnapsack(items, w) << endl;
    }

    return(0);
}

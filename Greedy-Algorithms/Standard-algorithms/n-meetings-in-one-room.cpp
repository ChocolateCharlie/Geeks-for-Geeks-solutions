#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct  Meeting {
    int id;
    int s;
    int f;
};



void    maxMeetings(vector<Meeting> &m) {
    vector<int> ans;
    int         t;

    t = -1;
    sort(m.begin(), m.end(), [](const Meeting &a, const Meeting &b) -> bool {
         return(a.f > b.f); });

    for (int i = m.size() - 1; i > -1; i--) {
        if (m[i].s >= t) {
            t = m[i].f;
            cout << m[i].id << " ";
        }

        m.pop_back();
    }

    cout << endl;
}



int main() {
    int T, n;

    cin >> T;

    while (T--) {
        cin >> n;

        vector<Meeting> m(n);
        for (int i = 0; i < n; i++) m[i].id = i + 1;
        for (int i = 0; i < n; i++) cin >> m[i].s;
        for (int i = 0; i < n; i++) cin >> m[i].f;

        maxMeetings(m);
    }

    return(0);
}

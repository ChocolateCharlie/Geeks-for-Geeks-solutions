#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct  Job {
    int id, d, p;
};



void    maxProfit(vector<Job> &j) {
    int nb_jobs;
    int profit;
    vector<bool>    dl;
    int k;
    bool    scheduled;

    nb_jobs = 0;
    profit = 0;
    sort(j.begin(), j.end(), [](const Job &a, const Job &b) -> bool {
        return(a.p < b.p); });

    for (int i = j.size() - 1; i > -1; i--) {
        while (dl.size() < j[i].d)  dl.push_back(false);
        k = j[i].d;
        scheduled = false;

        while (!scheduled && --k > -1) {
            if (!dl[k]) {
                nb_jobs++;
                profit += j[i].p;
                dl[k] = true;
                scheduled = true;
            }
        }
    }

    cout << nb_jobs << " " << profit << endl;
}



int main() {
    int T, n;

    cin >> T;

    while (T--) {
        cin >> n;
        vector<Job> j(n);
        for (int i = 0; i < n; i++) cin >> j[i].id >> j[i].d >> j[i].p;
        maxProfit(j);
    }

    return(0);
}

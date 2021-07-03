#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int m, n, k, l, d, myx1, myy1, myx2, myy2;
bool row1, col1;
vector< pair<int, int> > row, col;
vector<int> rows, cols;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    cin >> m >> n >> k >> l >> d;
    row.push_back(make_pair(0, 0));
    col.push_back(make_pair(0, 0));
    for (int i = 1; i <= m; i++)
        row.push_back(make_pair(i, 0));
    for (int i = 1; i <= n; i++)
        col.push_back(make_pair(i, 0));
    for (int i = 0; i < d; i++) {
        cin >> myx1 >> myy1 >> myx2 >> myy2;
        if (myx1 == myx2)
            col[min(myy1, myy2)].second++;
        if (myy1 == myy2)
            row[min(myx1, myx2)].second++;
    }
    sort(row.begin(), row.end(), cmp);
    sort(col.begin(), col.end(), cmp);
    for (int i = 0; i <= m && k; i++) {
        rows.push_back(row[i].first);
        k--;
    }
    for (int i = 0; i <= n && l; i++) {
        cols.push_back(col[i].first);
        l--;
    }
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    for (int i = 0; i < rows.size(); i++) {
        if (!row1)
            row1 = true;
        else
            cout << ' ';
        cout << rows[i];
    }
    cout << endl;
    for (int i = 0; i < cols.size(); i++) {
        if (!col1)
            col1 = true;
        else
            cout << ' ';
        cout << cols[i];
    }

    return 0;
}
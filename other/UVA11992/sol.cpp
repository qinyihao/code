#include <bits/stdc++.h>
using namespace std;

struct _sgt_node {
    int minv, maxv, sum, add, st;
    _sgt_node() {
        minv = maxv = sum = add = 0;
        st = -1;
    }
};

struct segment_tree {
    vector<_sgt_node> tree;

    void pushup(int rt) {
        tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
        tree[rt].maxv = max(tree[rt << 1].maxv, tree[rt << 1 | 1].maxv);
        tree[rt].minv = min(tree[rt << 1].minv, tree[rt << 1 | 1].minv);
    }

    void pushdown(int rt, int l, int r) {
        int mid = (l + r) >> 1;
        if (tree[rt].st != -1) {
            tree[rt << 1].st = tree[rt].st;
            tree[rt << 1 | 1].st = tree[rt].st;
            tree[rt << 1].maxv = tree[rt].st;
            tree[rt << 1 | 1].maxv = tree[rt].st;
            tree[rt << 1].minv = tree[rt].st;
            tree[rt << 1 | 1].minv = tree[rt].st;
            tree[rt << 1].sum = tree[rt].st * (mid - l + 1);
            tree[rt << 1 | 1].sum = tree[rt].st * (r - mid);
            tree[rt << 1].add = tree[rt << 1 | 1].add = 0;
            tree[rt].st = -1;
        }
        if (tree[rt].add) {
            tree[rt << 1].add += tree[rt].add;
            tree[rt << 1 | 1].add += tree[rt].add;
            tree[rt << 1].maxv += tree[rt].add;
            tree[rt << 1 | 1].maxv += tree[rt].add;
            tree[rt << 1].minv += tree[rt].add;
            tree[rt << 1 | 1].minv += tree[rt].add;
            tree[rt << 1].sum += tree[rt].add * (mid - l + 1);
            tree[rt << 1 | 1].sum += tree[rt].add * (r - mid);
            tree[rt].add = 0;
        }
    }

    void build(int rt, int l, int r) {
        if (l == r) {
            tree[rt] = _sgt_node();
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }

    void add(int rt, int l, int r, int ql, int qr, int x) {
        if (ql <= l && r <= qr) {
            tree[rt].add += x;
            tree[rt].sum += (r - l + 1) * x;
            tree[rt].maxv += x;
            tree[rt].minv += x;
            return;
        }
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            add(rt << 1, l, mid, ql, qr, x);
        }
        if (mid < qr) {
            add(rt << 1 | 1, mid + 1, r, ql, qr, x);
        }
        pushup(rt);
    }

    void assign(int rt, int l, int r, int ql, int qr, int x) {
        if (ql <= l && r <= qr) {
            tree[rt].sum = (r - l + 1) * x;
            tree[rt].minv = x;
            tree[rt].maxv = x;
            tree[rt].add = 0;
            tree[rt].st = x;
            return;
        }
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            assign(rt << 1, l, mid, ql, qr, x);
        }
        if (mid < qr) {
            assign(rt << 1 | 1, mid + 1, r, ql, qr, x);
        }
        pushup(rt);
    }

    int query_max(int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[rt].maxv;
        }
        pushdown(rt, l, r);
        int ans = INT_MIN, mid = (l + r) >> 1;
        if (ql <= mid) {
            ans = max(ans, query_max(rt << 1, l, mid, ql, qr));
        }
        if (mid < qr) {
            ans = max(ans, query_max(rt << 1 | 1, mid + 1, r, ql, qr));
        }
        return ans;
    }

    int query_min(int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[rt].minv;
        }
        pushdown(rt, l, r);
        int ans = INT_MAX, mid = (l + r) >> 1;
        if (ql <= mid) {
            ans = min(ans, query_min(rt << 1, l, mid, ql, qr));
        }
        if (mid < qr) {
            ans = min(ans, query_min(rt << 1 | 1, mid + 1, r, ql, qr));
        }
        return ans;
    }

    int query_sum(int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[rt].sum;
        }
        pushdown(rt, l, r);
        int ans = 0, mid = (l + r) >> 1;
        if (ql <= mid) {
            ans += query_sum(rt << 1, l, mid, ql, qr);
        }
        if (mid < qr) {
            ans += query_sum(rt << 1 | 1, mid + 1, r, ql, qr);
        }
        return ans;
    }
} trees[25];
int n, m, q;

int main() {
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        for (int i = 1; i <= n; ++i) {
            trees[i].tree.clear();
            for (int j = 0; j < (m << 2) + 10; ++j) {
                trees[i].tree.push_back(_sgt_node());
            }
            trees[i].build(1, 1, m);
        }
        while (q--) {
            int op, r1, c1, r2, c2, x;
            scanf("%d%d%d%d%d", &op, &r1, &c1, &r2, &c2);
            if (op == 1) {
                scanf("%d", &x);
                for (int i = r1; i <= r2; ++i) {
                    trees[i].add(1, 1, m, c1, c2, x);
                }
            } else if (op == 2) {
                scanf("%d", &x);
                for (int i = r1; i <= r2; ++i) {
                    trees[i].assign(1, 1, m, c1, c2, x);
                }
            } else {
                int sum = 0, minv = INT_MAX, maxv = INT_MIN;
                for (int i = r1; i <= r2; ++i) {
                    sum += trees[i].query_sum(1, 1, m, c1, c2);
                    minv = min(minv, trees[i].query_min(1, 1, m, c1, c2));
                    maxv = max(maxv, trees[i].query_max(1, 1, m, c1, c2));
                }
                printf("%d %d %d\n", sum, minv, maxv);
            }
        }
    }
    return 0;
}
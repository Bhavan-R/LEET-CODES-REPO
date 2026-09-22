class SegmentTree {
    int n;
    int k;
    struct Node {
        int prod;
        vector<long long> count;
        Node(int k = 1) : prod(1), count(k, 0) {}
    };
    vector<Node> tree;

    void combine(const Node& left, const Node& right, Node& res) {
        res.prod = (1LL * left.prod * right.prod) % k;
        for (int r = 0; r < k; ++r) {
            res.count[r] = left.count[r];
        }
        for (int r = 0; r < k; ++r) {
            if (right.count[r] > 0) {
                int new_rem = (1LL * left.prod * r) % k;
                res.count[new_rem] += right.count[r];
            }
        }
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(k);
            int val = nums[start] % k;
            tree[node].prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        combine(tree[2 * node], tree[2 * node + 1], tree[node]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = Node(k);
            int rem = val % k;
            tree[node].prod = rem;
            tree[node].count[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        combine(tree[2 * node], tree[2 * node + 1], tree[node]);
    }

    void query(int node, int start, int end, int l, int r, Node& res) {
        if (l <= start && end <= r) {
            res = tree[node];
            return;
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            query(2 * node, start, mid, l, r, res);
        } else if (l > mid) {
            query(2 * node + 1, mid + 1, end, l, r, res);
        } else {
            Node left(k), right(k);
            query(2 * node, start, mid, l, r, left);
            query(2 * node + 1, mid + 1, end, l, r, right);
            combine(left, right, res);
        }
    }

public:
    SegmentTree(const vector<int>& nums, int mod_k) {
        n = nums.size();
        k = mod_k;
        tree.resize(4 * n, Node(k));
        build(nums, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query_x(int start, int x) {
        Node res(k);
        query(1, 0, n - 1, start, n - 1, res);
        return res.count[x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            st.update(idx, val);
            ans.push_back(st.query_x(start, x));
        }

        return ans;
    }
};

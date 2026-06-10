class SegmentTree {
public:

    vector<int> segmentTree;
    int n;
    bool isMinTree;


    SegmentTree(vector<int>& arr, bool isMinTree) {

        this->n = arr.size();
        this->isMinTree = isMinTree;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, arr);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& arr) {

        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, arr);

        if(isMinTree)
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        else
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }


    int querySegmentTree(int start, int end,
                         int i, int l, int r) {

        // No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        // Complete overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if(isMinTree)
            return min(a, b);
        
        return max(a, b);
    }


    int query(int l, int r) {

        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};



class Solution {
public:
    typedef long long ll;


    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST) {

        int minEl = minST.query(l, r);
        int maxEl = maxST.query(l, r);

        return (ll)maxEl - minEl;
    }


    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        SegmentTree minST(nums, true);
        SegmentTree maxST(nums, false);


        // {value, l, r}
        priority_queue<tuple<ll, int, int>> pq;


        // Initially push best subarray for each l
        for (int l = 0; l < n; l++) {
            ll value = getValue(l, n - 1, minST, maxST);
            pq.push({value, l, n - 1});
        }


        ll result = 0;

        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nextValue = getValue(l, r - 1, minST, maxST);

            pq.push({nextValue, l, r - 1});
        }

        return result;
    }
};
class Solution {
public:
    struct Node {
        int count;
        double covered;
        Node() {
            count = 0;
            covered = 0;
        }
    };
    struct Event {
        double y;
        int x1, x2;
        int type;
    };
    struct Slice {
        double y1, y2, width;
    };
    vector<double> xs;
    vector<Node> seg;

    static bool eventCompare(const Event& a, const Event& b) {
        return a.y < b.y;
    }
    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            seg[idx].count += val;
        } else {
            int mid = (l + r) / 2;
            update(idx * 2, l, mid, ql, qr, val);
            update(idx * 2 + 1, mid, r, ql, qr, val);
        }
        if (seg[idx].count > 0) {
            seg[idx].covered = xs[r] - xs[l];
        } else if (l + 1 == r) {
            seg[idx].covered = 0;
        } else {
            seg[idx].covered = seg[idx * 2].covered + seg[idx * 2 + 1].covered;
        }
    }
    int getXIndex(double x) {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        xs.clear();
        for (int i = 0; i < squares.size(); i++) {
            double x = squares[i][0];
            double l = squares[i][2];
            xs.push_back(x);
            xs.push_back(x + l);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        for (int i = 0; i < squares.size(); i++) {
            double x = squares[i][0];
            double y = squares[i][1];
            double l = squares[i][2];

            int x1 = getXIndex(x);
            int x2 = getXIndex(x + l);

            Event e1;
            e1.y = y;
            e1.x1 = x1;
            e1.x2 = x2;
            e1.type = 1;

            Event e2;
            e2.y = y + l;
            e2.x1 = x1;
            e2.x2 = x2;
            e2.type = -1;

            events.push_back(e1);
            events.push_back(e2);
        }

        sort(events.begin(), events.end(), eventCompare);

        seg.assign(xs.size() * 4, Node());
        vector<Slice> slices;
        double prevY = events[0].y;

        for (int i = 0; i < events.size(); i++) {
            double curY = events[i].y;
            double width = seg[1].covered;
            if (curY > prevY && width > 0) {
                Slice s;
                s.y1 = prevY;
                s.y2 = curY;
                s.width = width;
                slices.push_back(s);
            }
            update(1, 0, xs.size() - 1, events[i].x1, events[i].x2,
                   events[i].type);
            prevY = curY;
        }
        double totalArea = 0;
        for (int i = 0; i < slices.size(); i++) {
            totalArea += slices[i].width * (slices[i].y2 - slices[i].y1);
        }
        double halfArea = totalArea / 2.0;
        double currArea = 0;

        for (int i = 0; i < slices.size(); i++) {
            double area = slices[i].width * (slices[i].y2 - slices[i].y1);
            if (currArea + area >= halfArea) {
                double remArea = halfArea - currArea;
                return slices[i].y1 + remArea / slices[i].width;
            }
            currArea += area;
        }
        return 0.0;
    }
};
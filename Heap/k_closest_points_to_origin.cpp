// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;

        for (auto p : points)
        {
            int x = p[0];
            int y = p[1];
            pq.push({x * x + y * y, x, y});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            vector<int> t = pq.top();
            pq.pop();
            ans.push_back({t[1], t[2]});
        }

        return ans;
    }
};
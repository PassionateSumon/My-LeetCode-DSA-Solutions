class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            pq.push(max1-max2);
        }
        return (pq.size() == 0) ? 0 : pq.top();
    }
};
class Solution {
public:
    struct MinQueue {
        deque<pair<int,int>> dq;

        int cnt_added = 0;
        int cnt_removed = 0;

        void push(int x) {
            while (!dq.empty() && dq.back().first < x)
                dq.pop_back();

            dq.push_back({x, cnt_added++});
        }

        void pop() {
            if (!dq.empty() && dq.front().second == cnt_removed)
                dq.pop_front();

            cnt_removed++;
        }

        int getMin() {
            return dq.front().first;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        queue<int> q;
        MinQueue dq;

        for(int i = 0; i < k; i++){
            dq.push(nums[i]);
            q.push(nums[i]);
        }

        result.push_back(dq.getMin());

        for(int i = k; i < nums.size(); i++){
            int x = nums[i], x1 = q.front();
            q.push(x);
            q.pop();

            dq.push(x);
            dq.pop();
            result.push_back(dq.getMin());
        }

        return result;
    }
};
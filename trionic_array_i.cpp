#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; // Need at least 4 elements for 0 < p < q < n-1

        int i = 0;

        // 1. Walk up (strictly increasing)
        while (i + 1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        // p must be > 0 (went up) and < n-1 (room for down+up)
        if (i == 0 || i == n - 1) return false;

        // 2. Walk down (strictly decreasing)
        int p = i;
        while (i + 1 < n && nums[i] > nums[i+1]) {
            i++;
        }
        // q must be > p (went down) and < n-1 (room for up)
        if (i == p || i == n - 1) return false;

        // 3. Walk up (strictly increasing)
        while (i + 1 < n && nums[i] < nums[i+1]) {
            i++;
        }

        // Must reach the end
        return i == n - 1;
    }
};

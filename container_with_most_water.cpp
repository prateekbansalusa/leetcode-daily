/**
 * Problem: Container With Most Water (Medium)
 * Link: https://leetcode.com/problems/container-with-most-water/
 *
 * Description:
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate current area
            int h = min(height[left], height[right]);
            int w = right - left;
            int current_area = h * w;
            
            max_water = max(max_water, current_area);

            // Move the pointer pointing to the shorter line inward
            // Logic: Limiting factor is the shorter line. Moving the longer line inward
            // can only decrease width without increasing height (bounded by shorter line).
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << sol.maxArea(heights) << endl; // Expected: 49
    return 0;
}

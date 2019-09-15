#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> taggedNums;

        for (int i = 0; i < nums.size(); i++) {
            taggedNums.push_back({nums[i], i});
        }
        sort(taggedNums.begin(), taggedNums.end());

        for (int i = 0; i < taggedNums.size() - 1; i++) {
            int tempTarget = target - taggedNums[i].first;

            vector<pair<int, int>> tempNums(taggedNums.begin() + i + 1, taggedNums.end());
            int targetNumPos = findTempTarget(tempNums, tempTarget);

            if (targetNumPos != -1) {
                return {taggedNums[i].second, targetNumPos};
            }
        }

        return {};
    }

    int findTempTarget(vector<pair<int, int>> taggedNums, int tempTarget) {
        int start = 0, end = taggedNums.size() - 1;
        int mid;

        while(start <= end) {
            mid = (start + end) / 2;

            if (taggedNums[mid].first == tempTarget) return taggedNums[mid].second;
            else if (taggedNums[mid].first > tempTarget) end = mid - 1;
            else start = mid + 1;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> input = {7, 11, 2, 15};

    vector<int> result = solution.twoSum(input, 9);

    cout << result[0] << " " << result[1];
}
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++) {
            int tempTarget = target - nums[i];

            auto iter = map.find(tempTarget);
            if ((iter != map.end()) && ((*iter).second != i)) {
                return {i, (*iter).second};
            }
        }

        return {};
    }
};

int main() {
    Solution solution;
    vector<int> input = {3, 3};

    vector<int> result = solution.twoSum(input, 6);

    cout << result[0] << " " << result[1];
}
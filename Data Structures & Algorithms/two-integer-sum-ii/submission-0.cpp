// 09:15
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        for (int i = 0, j = n - 1; i < j; ) {
            int diff = numbers[i] + numbers[j] - target;
            if (diff == 0) {
                return {i + 1, j + 1};
            } else if (diff < 0) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1};
    }
};

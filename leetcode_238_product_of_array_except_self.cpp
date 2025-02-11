#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_less_prod = 1;
        int zero_count = 0;
        std::vector<int> new_nums(nums);
        std::vector<int> output_vec(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
        }
        for (int i = 0; i < new_nums.size(); i++) {
            if (new_nums[i] == 0) {
                zero_count += 1;
                new_nums.erase(new_nums.begin()+i);
                i--;
            } else {
                zero_less_prod *= new_nums[i];
            }
        }
        std::fill(output_vec.begin(), output_vec.end(), product);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                output_vec[i] = product / nums[i];
            } else if(zero_count == nums.size()) {
                output_vec[i] = 0;
            } else if(zero_count > 1) {
                output_vec[i] = 0;
            } 
            else {
                output_vec[i] = zero_less_prod;
            }
        }
        return output_vec;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Output for test case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {0, 1, 2, 3, 4};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Output for test case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 0, 0, 3};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Output for test case 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

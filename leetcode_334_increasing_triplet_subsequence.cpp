#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            bool is_true = false;
            // for(int i = 0; i < nums.size() - 2; i++) {
            //     for (int j = i + 1; j < nums.size() - 1; j++) {
            //         for (int k = j + 1; k < nums.size(); k++) {
            //             if ((nums[i] < nums[j]) && (nums[j] < nums[k])) {
            //                 is_true = true;
            //                 break;
            //             }
            //         } 
            //     }
            // }
            int first = nums[0];
            int second = 0;
            bool first_found = false;
            bool second_found = false;
            for(auto num: nums) {
                while(first > num) {
                    first_found = false;
                }
                first_found = true;
                second = num;
                while (second > num) {
                    second_found = false;
                }
                second_found = true;
                if (first_found && second_found) {
                    is_true = true;
                } else {
                    is_true = false;
                }
            }
            return is_true;
        }
    };

int main() {
    Solution solution;

    // Test case 1
    // vector<int> nums1 = {1, 2, 3, 4, 5};
    // cout << "Test case 1: " << (solution.increasingTriplet(nums1) ? "True" : "False") << endl;

    // Test case 2
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test case 2: " << (solution.increasingTriplet(nums2) ? "True" : "False") << endl;

    // // Test case 3
    // vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    // cout << "Test case 3: " << (solution.increasingTriplet(nums3) ? "True" : "False") << endl;

    // // Test case 4 (Edge case with fewer than 3 elements)
    // vector<int> nums4 = {1, 2};
    // cout << "Test case 4: " << (solution.increasingTriplet(nums4) ? "True" : "False") << endl;

    // vector<int> nums5= {20,100,10,12,5,13};
    // cout << "Test case 5: " << (solution.increasingTriplet(nums5) ? "True" : "False") << endl;

    return 0;
}

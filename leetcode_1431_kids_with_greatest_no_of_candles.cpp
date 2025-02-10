#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::vector<int> *new_candies_vec = new std::vector<int>(candies.size()); 
        std::vector<bool> *new_candies_vec_bool = new std::vector<bool>(candies.size()); 
        std::vector<int> og_vector = candies;
        
        for(int i = 0; i < candies.size(); i++) {
            for (int j = i + 1; j < candies.size(); j++) {
                if(candies[i] > candies[j]) {
                    int temp = candies[i];
                    candies[i] = candies[j];
                    candies[j] = temp;
                }
            }
        }
        
        int highest_value = candies[candies.size() - 1];
        
        for(int i = 0; i < (*new_candies_vec).size(); i++) {
            og_vector[i] += extraCandies;
            (*new_candies_vec)[i] = og_vector[i];
            std::cout << (*new_candies_vec)[i] << std::endl;
            if ((*new_candies_vec)[i] >= highest_value) {
                (*new_candies_vec_bool)[i] = true;
            } else {
                (*new_candies_vec_bool)[i] = false;
            }
        }
        delete new_candies_vec;
        return (*new_candies_vec_bool);     
        delete new_candies_vec_bool;
    }
};

int main() {
    Solution solution;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    
    for (bool can : result) {
        cout << (can ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}

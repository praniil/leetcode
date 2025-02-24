#include <iostream>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string new_string;
        int length = word1.size() >= word2.size() ? word1.size() : word2.size();
        for (int i = 0; i < length; i++) {
            if (i < word1.size()) {
                new_string.push_back(word1[i]);
            }
            if (i < word2.size()) {
                new_string.push_back(word2[i]);
            }
        }
        return new_string;
    }
};

int main() {
    Solution solution;
    std::string word1 = "abc";
    std::string word2 = "defgh";
    std::cout << solution.mergeAlternately(word1, word2) << std::endl;
    return 0;
}

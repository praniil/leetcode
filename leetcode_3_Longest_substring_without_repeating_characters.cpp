#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::find

using namespace std;

class Solution {
public:
    std::vector<int> array;
    int first = 0, end = 0, index = 0, highest = 0; 
    int lengthOfLongestSubstring(string s) {
        while (end < s.length()) {
            if (std::find(array.begin(), array.end(), s[end]) == array.end()) {
                array.push_back(s[end]);
                end++;
                if (array.size() > highest) {
                    highest = array.size();
                }
            } else {
                array.erase(array.begin());
                first++;
            }
        }
        return highest;
    }
};

int main() {
    Solution sol;
    
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int result = sol.lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}

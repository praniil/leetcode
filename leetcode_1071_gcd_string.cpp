#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    std::string repeated;
    std::string gcd;
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int length = str1.size() > str2.size() ? str2.size() : str1.size();
        int hcf;
        hcf = greatest_common_divisor(str1.size(), str2.size());
        std::cout << hcf << std::endl;
        if (hcf == 1) {
            return str1.size() == 1? str1: str2;
        } else if (hcf == str2.size() && hcf == str1.size()) {
            return str1;
        }
        else {
            for (int i = 0; i < hcf; i++) {
                gcd.push_back(str2[i]);
            }
            return gcd;
        }
    }

    int greatest_common_divisor(int a, int b) {
        int res = min(a, b);
        while (res > 1) {
            if (a % res == 0 && b % res == 0)
                break;
            res--;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << solution.gcdOfStrings(str1, str2) << endl;
    return 0;
}

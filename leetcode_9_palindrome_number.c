#include<stdio.h>
#include <stdbool.h>

int main() {
    bool result = isPalindrome(121);
    printf("result: %d \n", result);
}



bool isPalindrome(int x) {
    long int original = x;
    long int temp = 0;
    bool result = false;
    if (x < 0) {
        result = false;
    } else {
        while (x > 0) {
            long int rem = x % 10;
            temp = temp * 10 + rem;
            x = x / 10;
        }
        if (original == temp) {
            result = true;
        }
    }
    return result;
}
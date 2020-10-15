#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#define LAND 1
#define WATER 0
#define NOT_CLASSIFY 0

class Solution {
public:
    int numDecodings(std::string input){
        // 1213  =>  [1,2,1,3], [12,1,3], [1,21,3], [1,2,13], [12,13] => output:5
        // 12715 =>  [1,2,7,1,5], [12,7,1,5], [12,7,15], [1,2,7,15] => output:4

        if(input.length() <= 0) {
            return 0;
        }
        int len = input.length();
        printf("len: %d\n", len);
        int *dp = new int[len + 1];
        for (int i = 0; i < len + 1; i++) {
            dp[i] = 0;
        }
        dp[0] = 1; // Empty string
        printf("dp[0]:%d\n", dp[0]);
        for (int i = 1; i <= input.length(); i++) {
            printf("[%d] input[%d]:%c\n", i, i-1, input[i-1]);

            // list all number (for one letter), require that input[i - 1] != '0'
            if (input[i - 1] > '0') {
                dp[i] += dp[i - 1];
            }
            // list all number (for 2 letter), require that i > 1 and the number 
            // combine from input[i-1] and input[i-2] must be less than "26" and larger than "10"
            if (i > 1 && input.substr(i - 2, 2) >= "10" && input.substr(i - 2, 2) <= "26") {
                printf("[%d] input[%d] concat input[%d]:%c%c\n", i, i-2, i-1, input[i-2], input[i-1]);
                dp[i] += dp[i - 2];
            }
            printf("[%d] dp[%d]:%d\n", i, i, dp[i]);
        }

        return dp[len];
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    int *dp;
    std::string tmp = argv[1];
    printf("output: %d\n", s -> numDecodings(tmp));
}
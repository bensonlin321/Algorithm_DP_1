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
    void decode_string(std::string input, int *dp){

        // 027 => 2,7
        // dp[0] = 1
        // dp[1] = 1
        // prev  = 0, curr = 0
        // prev  = 0, curr = 2
        // dp[2] = 1
        // prev  = 2, curr = 7
        // dp[3] = 1

        // 0114 => 11,4  1,14  1,1,4
        // dp[0] = 1
        // dp[1] = 1


        if(input.length() <= 0) {
            return;
        }
        int len = input.length();
        printf("len: %d\n", len);
        dp = new int[len + 1];
        for (int i = 0; i < len + 1; i++) {
            dp[i] = 0;
        }
        dp[0] = 1; // Empty string
        dp[1] = input.at(0) == '0' ? 1 : 0;
        char prev = '0', curr = input.at(0);

        printf("dp[0]:%d , dp[1]:%d\n", dp[0], dp[1]);

        for (int i = 2; i <= len; i++) {
            prev = curr;
            curr = input.at(i-1);
            printf("[%d] prev: %c, curr: %c\n", i, prev, curr);
            if (curr != '0') {
                dp[i] += dp[i-1];
            }
            if (prev == '1' || (prev == '2' && curr <= '6')) {
                dp[i] += dp[i-2];
            }
            printf("dp[%d]:%d\n", i, dp[i]);
        }
        printf("dp[len]: %d\n", dp[len]);
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    int *dp;
    std::string tmp = argv[1];
    s -> decode_string(tmp, dp);
}
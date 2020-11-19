/*
 * 反转数组
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
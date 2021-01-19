/*
 * 204. 计数质数
 * 统计所有小于非负整数 n 的质数的数量。
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 * 输入：n = 0
 * 输出：0
 *
 * 输入：n = 1
 * 输出：0
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i <n; i++){
            if (isPrime_sqrt(i))
                count++;
        }
        return count;
    }

    // 本科判断整数 n 是否是素数
    // 这样写的话时间复杂度 O(n^2)，问题很大。
    // 首先你用 isPrime 函数来辅助的思路就不够高效；
    // 而且就算你要用 isPrime 函数，这样写算法也是存在计算冗余的。
    bool isPrime(int n) {
        for (int i = 2; i < n; i++)
            if (n % i == 0) return false;  // 有其他整除因子
        return true;
    }

    // 优化1
    // 12 = 2 × 6
    // 12 = 3 × 4
    // 12 = sqrt(12) × sqrt(12)
    // 12 = 4 × 3
    // 12 = 6 × 2
    // 注意 i*i <= n
    // O(N * sqrt(N))
    bool isPrime_sqrt(int n) {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;  // 有其他整除因子
        return true;
    }

    // 高效优化
    // 高效解决这个问题的核心思路是和上面的常规思路反着来：
    // 首先从 2 开始，我们知道 2 是一个素数，那么 2 × 2 = 4, 3 × 2 = 6, 4 × 2 = 8... 都不可能是素数了。
    // 然后我们发现 3 也是素数，那么 3 × 2 = 6, 3 × 3 = 9, 3 × 4 = 12... 也都不可能是素数了。
    // 这个算法有个名字：Sieve of Eratosthenes
    // O(N * loglogN)
    int countPrimes_(int n) {
        if (n==0) return 0;
        bool isPrim[n];
        // 将数组都初始化为 true
        fill(isPrim, isPrim + n, true);

        for (int i = 2; i*i <= n; i++)
            if (isPrim[i])
                // i 的倍数不可能是素数了
                for (int j = i * i; j < n; j += i)
                    isPrim[j] = false;

        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrim[i]) count++;

        return count;
    }


};
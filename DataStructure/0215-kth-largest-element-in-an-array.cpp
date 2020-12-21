/*
 * 215. 数组中的第k个最大元素
 *
 * 在未排序的数组中找到第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 输入: [3,2,1,5,6,4] 和 k = 2
   输出: 5

   输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
   输出: 4
 */
/*
 * 解析：
 * 1. 使用堆，可以使用优先队列 priority_queue
   2. 维护一个 k 大小的小顶堆，堆顶就是第 k 个最大的数
   3. 注意：当堆的大小已经是 k 个的时候，需要注意直接与堆顶判断决定是否加入堆中，这样效率高

 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 方法一：优先队列
     * @param nums
     * @param k
     * @return
     */
    int findKthLargest_youxianduilie(vector<int>& nums, int k) {
        // greater : 小顶堆
        // 时间复杂度: 堆中始终都只有k个元素，所以维护堆的时间复杂度是O(logk) 外面套一层for
        // 总的时间复杂度：O(nlogk)
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& num : nums) {
            if (pq.size() == k && pq.top() > num) continue;
            if (pq.size() == k) {
                pq.pop();
            }
            pq.push(num);
        }
        return pq.top();
    }

    /**
     * 方法二：快速选择
     * @param nums
     * @param k
     * @return
     */
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        // 索引转化
        // 题目要求的是「第 k 个最大元素」，这个元素其实就是 nums 升序排序后「索引」为 len(nums) - k 的这个元素。
        k = nums.size() - k;
        while (lo <= hi) {
            // 在 nums[lo..hi] 中选一个分界点
            int p = partition(nums, lo, hi);
            if (p < k) {
                // 第 k 大的元素在 nums[p+1..hi] 中
                lo = p + 1;
            } else if (p > k) {
                // 第 k 大的元素在 nums[lo..p-1] 中
                hi = p - 1;
            } else {
                // 找到第 k 大元素
                return nums[p];
            }
        }
        return -1;
    }
    /**
     * 快速排序：
     * 原理：https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html
     * 代码：https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/3.3-qi-ta-suan-fa-pian/kuai-su-xuan-ze
     * @param nums
     */
    void quick_sort(vector<int>& nums) {}
    void sort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        int p = partition(nums, lo, hi);
        sort(nums, lo, p - 1);
        sort(nums, p + 1, hi);
    }
    int partition(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return lo;
        // 将 nums[lo] 作为默认分界点 pivot
        int pivot = nums[lo];
        // j = hi + 1 因为 while 中会先执行 --
        int i = lo, j = hi + 1;
        while (true) {
            // 从左往右找一个大于povot的数
            // 保证 nums[lo..i] 都小于 pivot
            while (nums[++i] < pivot) {
                if (i == hi) break;
            }
            // 从右往左找一个小于povot的数
            // 保证 nums[j..hi] 都大于 pivot
            while (nums[--j] > pivot) {
                if (j == lo) break;
            }
            if (i >= j) break;
            // 如果走到这里，一定有：
            // nums[i] > pivot && nums[j] < pivot
            // 所以需要交换 nums[i] 和 nums[j]，
            // 保证 nums[lo..i] < pivot < nums[j..hi]
            swap(nums[i], nums[j]);
        }
        // 将 pivot 值交换到正确的位置
        swap(nums[j], nums[lo]);
        // 现在 nums[lo..j-1] < nums[j] < nums[j+1..hi]
        return j;
    }
};
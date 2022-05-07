# LC

## 2258. 逃离火灾（正向 BFS ，反向 Dijkstra） ⭐️

正向 BFS ，计算每个位置着火的时间，得到 fire ．

反向 Dijkstra ，反推最迟到达时间，得到 late ．

TODO: grid 的 BFS 和 Dijkstra 模板．

- Time: $\mathcal{O}(mn)$
- Space: $\mathcal{O}(mn)$

## 2138. Divide a String Into Groups of Size k

## 1823. 找出游戏的获胜者（约瑟夫问题、DP） ⭐️

[官方题解](https://leetcode.cn/problems/find-the-winner-of-the-circular-game/solution/zhao-chu-you-xi-de-huo-sheng-zhe-by-leet-w2jd/)

在 $k'$ 出圈后，还有 $n-1$ 个数，问题转化为从 $k'+1$ 开始的 $f(n-1,k)$ ．

$$
f(n,k)=(f(n-1,k)+k'-1)\mod n + 1
$$

## 1679. K 和数对的最大数目（双指针）

## 1218. Longest Arithmetic Subsequence of Given Difference (DP)

## 1209. Remove All Adjacent Duplicates in String II (stack based solution)

A stack is useful because it allow us to simulate removing substrings without actually having to alter the string. This can be done by storing the substrings in `s` , and removing them once their length reaches `k`. Note also that once a substring is removed, we automatically get accesss to the previous substring, hence automatically 'concatenating' the left and the right substrings.

## 1027. Longest Arithmetic Subsequence (DP)

最长等差子序列．

## 937. 重新排列日志文件（自定义排序）

自定义排序．

官方题解：「数字日志保留原来的相对顺序。当使用稳定的排序算法时，可以认为所有数字日志大小一样。当使用不稳定的排序算法时，可以用日志在原数组中的下标进行比较。」

尽量用 C 的字符串操作可以避免拷贝，提高性能，节省内存．

C++ 20 的 `string_view` 和 `<=>` 也可以，但是 LeetCode 目前只支持 C++ 17 ．

## 713. 乘积小于 K 的子数组（滑动窗口） ⭐️

滑动窗口是常用技巧了，窗口右侧尽可能向右扩张，不满足条件时左侧还要向右收缩．

要搞明白的点是如何通过维持这个窗口来得到答案．

假设目前右侧移动一个位置（然后左侧可能需要相应地移动若干位），那么由于这个窗口大小的变化而新增的子数组一定要包括最右侧这个数，所以新增的子数组数就是 `r - l` ．

## 591. 标签验证器（递归下降子程序、栈的应用） ⭐️

递归下降子程序还是比较通用的方法，从代码量上看其实和栈的方法也没差多少．

如果理解了递归下降子程序，应该也可以顺利写出栈的版本．虽然栈的版本可以进一步优化，但是我选择 cv ．

## 456. 132 Pattern (前缀数组、单调栈) ⭐️

思路和代码来自大佬[「白」](https://leetcode.cn/u/vclip/)．

这道题的要求可以分成两步：

1. 在 $[0, k)$ 中找一个 $j$ ，满足 $nums[k] < nums[j]$
2. 在 $[0, j)$ 中找一个 $i$ ，满足 $nums[k] > nums[i]$

据此设计数据结构：

1. 为了尽可能找到 $i$ ，要求 $j$ 要尽可能大，即 $j$ 应该是 $k$ 左侧第一个满足 $nums[k] < nums[j]$ 的位置，维护这个位置，可以用单调栈．
2. 在确定了 $j$ 之后，只要看 $[0, j)$ 中的最小值是否小于 $nums[k]$ 即可，维护 $[0, j)$ 的最小值可以用前缀数组．

## 433. Minimum Genetic Mutation (BFS)

1. DNA 的位序可以当做编码．
2. 预处理出 `adj` ．

## 420. 强密码检查器（贪心） ⭐️

[【Sheep】420. 强密码检验器（贪心）](https://leetcode.cn/problems/strong-password-checker/solution/si-lu-qing-xi-c-0ms-by-13261896688/)

分别考虑三种修改方式在三个方面的影响．

## 225. Implement Stack using Queues (queue, stack)

There are basically 3 approaches to solve the problem.

### use 2 queues

<!-- When there is only one element in a queue `q1`, it can be seen as a stack directly. So an additional queue `q2` is maintained to make sure only one element is in queue `q1`. But you can choose the time to do the shift: either after pushing or before poping, which will make the time complexity of the operation rise from $\mathcal{O}(1)$ to $\mathcal{O}(n)$ respectively. -->

#### use 1 queue

<!-- We can keep the elements in a queue sorted the same way as they are in a stack. Just invert the elements before every pushing operation. -->

#### [simulate a linked list](https://leetcode.com/problems/implement-stack-using-queues/discuss/62522/O(1)-purely-with-queues)

another crazy idea.

## 64. 最小路径和（DP）

## 63. 不同路径 II（DP）

## 62. 不同路径（离散数学） ⭐️

要走 $m+n-2$ 步，从其中选择 $m-1$ （$n-1$）步向下（右）走．于是就是计算组合数了．

组合数是成对出现的，它们的值相同，首先要选那个比较好算的．

计算的技巧是每次乘一个数再除一个数，从大的开始乘，从小的开始除，一定能整除，中间结果也不至于过大．

TODO: 组合数

## 61. 旋转链表（链表） ⭐️

1. 连成一个环
2. 找到应该断开的位置
3. 断开

TODO: SingleList 模板

## 5. 最长回文子串（DP、Manacher） ⭐️

[官方题解](https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/) 中介绍的 Manacher 算法还可以再优化，可以假装插入了 `#` ，而不用真的插入，实际上就是一个字符映射的问题，

映射完成后，所有原字符串上的位置都是奇数，而且「当我们只考虑长度为奇数的回文字符串时，每次我们比较的两个字符奇偶性一定是相同的，所以原来字符串中的字符不会与插入的特殊字符互相比较，不会因此产生问题。」，那么当 `expand` 时，如果两个位置都是偶数，说明是 `#` ，直接判等．

## 4. 寻找两个正序数组的中位数（二分、划分） ⭐️

[官方题解](https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/)

### 二分查找

1. 在两个有序的数组上求中位数可以转化为求第 $K$ 小的元素问题．
2. 求第 $K$ 小的元素，只要累计删掉 $K - 1$ 个数就行．
3. 但要注意不能删多了，所以每次在每个数组上将第 $K / 2$ 小的数作为的分界点．

### 划分数组

1. 求中位数，可以转化在两个数组上确定一个划分．
2. 由中位数的性质，如果确定了一个数组中的划分位置，另一个数组中的位置也就相应确定了．
3. 所以只需要在一个数组上移动，找到正确的划分位置．
4. 而这个问题仍然是具有单调性质的，所以可以使用二分来确定划分的位置．
5. 这种方法的时间复杂度最小．

## 3. 无重复字符的最长子串（哈希）

哈希记录每个字符上次出现的位置．

## 2. 两数相加（链表的应用）

用链表模拟加法．

## 1. 两数之和（双指针、哈希）

哈希表 ，一边遍历一边更新哈希表就可以，因为总是可以在遇到第 2 个数的时候找到．

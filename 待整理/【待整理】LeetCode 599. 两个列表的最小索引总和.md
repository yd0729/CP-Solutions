---
created: 2022-03-14T21:55:12 (UTC +08:00)
tags: [力扣,力扣中国,leetcode,lingkou,leetcode中国,leetcode官网,在线编程,lc,leetcode题解,leetcode答案,面经,算法,面试,求职,招聘,校招,社招,内推,笔试,面试题,面试经验,刷题,leetcode题库,机器学习,算法岗,数据结构,代码,互联网,编程,开发,程序员,工程师,白板面试,码农,程序猿,领扣,领扣网,领扣网络,领扣中国,BAT,BAT面试,OJ,online judge,coding interview,技术面试,leetcode中文版,leetcodechina]
source: https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/
author: 
---

# 599. 两个列表的最小索引总和

假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用**最少的索引和**找出他们**共同喜爱的餐厅**。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。

**示例 1:**

```
输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
```

**示例 2:**

```
输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
```

**提示:**

- `1 <= list1.length, list2.length <= 1000`
- `1 <= list1[i].length, list2[i].length <= 30`
- `list1[i]` 和 `list2[i]` 由空格 `' '` 和英文字母组成。
- `list1` 的所有字符串都是 **唯一** 的。
- `list2` 中的所有字符串都是 **唯一** 的。

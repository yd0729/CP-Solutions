---
created: 2022-03-08T12:51:16 (UTC +08:00)
tags: []
source: https://pintia.cn/problem-sets/1500348586764443648/problems/1500348648013864960
author: 
---

# 题目详情 - 7-3 Is It A Binary Search Tree - Again (25 分)

> ## Excerpt
> 千名教师建设，万道高质量题目，百万用户拼题的程序设计实验辅助教学平台

---
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

-   The left subtree of a node contains only nodes with keys less than the node's key.
-   The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
-   Both the left and right subtrees must also be binary search trees.

A binary tree with positive keys can be represented by an array, which stores the keys in level-order as in a complete tree, with all the NULL nodes represented by −1\-1. For example, the following tree is stored in an array as { 40, 25, 60, -1, 30, -1, 80, -1, -1, 27 }.

![bst1.png](https://images.ptausercontent.com/1b843391-8809-4969-9792-567abd5f53ac.png)

Now given a sequence of integers in an array, you are supposed to tell if it corresponds to a BST, and output its inorder traversal sequence.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer NN (≤1000\\le 1000). Then NN integer keys (in the range (0, 100000)) are given in the next line. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, first print in a line `YES` if the sequence does correspond to a BST, or `NO` if not. Then print in the next line the inorder traversal sequence of that tree. It is guaranteed that the tree is non-empty.

All the numbers in a line must be separated by a space, and there must be no extra space at the beginning or the end of the line.

### Sample Input 1:

```
10
40 25 60 -1 30 -1 80 -1 -1 27
```

### Sample Output 1:

```
YES
25 27 30 40 60 80
```

### Sample Input 2:

```
11
40 50 60 -1 30 -1 -1 -1 -1 -1 35
```

### Sample Output 2:

```
NO
50 30 35 40 60
```

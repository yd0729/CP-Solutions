---
created: 2022-03-08T12:51:27 (UTC +08:00)
tags: []
source: https://pintia.cn/problem-sets/1500348586764443648/problems/1500348648013864960
author: 
---

# 题目详情 - 7-4 The Rescue (30 分)

> ## Excerpt
> 千名教师建设，万道高质量题目，百万用户拼题的程序设计实验辅助教学平台

---
![rescue.png](https://images.ptausercontent.com/cc812835-9801-422b-9a4a-1c6848d26a77.png)

When a group of hikers get lost in a forest and call the rescue team, the team leader would send the hikers a sequence of instructions. By following these instructions, the hikers can always move to a spot that the rescue team can reach, no matter where their original location was. Your job is to generate such a sequence for each given map.

A map is a rectangular（矩形） area consists of n×mn\\times m unit square areas. There is alway one square `X` that is marked to be the rescue spot. Some of the areas are blocked and marked to be `#`, meaning that the hikers cannot enter this block. We assume that the boundaries of the map are all blocked.

An instruction is an integer that represents a direction: 0 for North, 1 for East, 2 for South, and 3 for West. For example, the sequence of instructions `3001` tells the hikers to move toward West and enter the neighboring area first, then head toward North and cross two units, and finally move toward East into the neighboring area. If the destination area is blocked, the hikers must stay in the current area and wait for the next instruction. The sequence you generate must be able to direct the hikers to move into `X` no matter where they were in that map. Once they arrive at `X`, they will ignore the rest of the instructions.

There are many different ways of generating the sequence. Here we design a greedy algorithm, hoping to generate a not-too-long sequence. The algorithm works as the following:

-   Step 1: find the shortest paths from `X` to every other areas which the hikers might be in, and pick the furthest area `A`.
-   Step 2: generate sequence ss for directing from `A` to `X` along the shortest path.
-   Step 3: update the map according to ss -- that is, mark all the possible areas that the hikers might be in after following ss.
-   Step 4: if `X` is the only possible area that contains the hikers, stop; else goto Step 1.

The final sequence can be obtained by concatenating all the ss' generated in order.

Notice that while the shortest path might not be unique, you are supposed to output the smallest sequence. Sequence a1,a2,⋯ ,an{ a\_1, a\_2, \\cdots , a\_n } is **smaller than** sequence b1,b2,⋯ ,bn{ b\_1, b\_2, \\cdots , b\_n } if ther exists 1≤k≤n1\\le k \\le n so that ai\=bia\_i = b\_i for all i<ki<k, and ak<bka\_k < b\_k.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers 3≤n,m≤1003\\le n, m \\le 100. Then nn lines follow, each contains mm characters to represent the map. The rescue spot is `X`, a block is `#`, and `O` represents an open area.

### Output Specification:

Output in a line the sequence of instructions. There must be no space between the numbers, nor at the beginning or the end of the line.

It is guaranteed that the solution exists.

### Sample Input:

```
4 5
O#OOO
OOXOO
OO##O
OOO#O
```

### Sample Output:

```
0011300121133
```

### Hint:

During the 1st round, there are 3 candidates for `A`, as shown below:

```
O#OOO
OOXOO
OO##O
AOA#A
```

To direct them to X with the smallest sequence, we must choose the one at the lower-left corner, with the sequence `0011`. Since at the very beginning, the hikers might be in any of the open areas, we apply `0011` to every open area, and obtain a map as shown below:

```
?#OO?
OOXO?
OO##O
OO?#O
```

where `?` means that currently it is a possible position of the hikers. Now clearly we must pick the `?` in the last row to be the next `A`, and direct it to `X` with `3001`. After applying this sequence to other areas marked by `?`, we update the map as the following:

```
?#OO?
OOXOO
OO##O
OOO#O
```

Now both `?`'s have the same path length to `X`. We pick the upper-left corner to be `A` since it has the smaller sequence `211`. The map is updated as the following:

```
O#OOO
OOXO?
OO##O
OOO#O
```

Finally apply `33`, we can direct the last `?` to `X`.

Hence the output sequence is `0011` `3001` `211` `33`.

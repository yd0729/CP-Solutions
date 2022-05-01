---
created: 2022-03-08T12:46:30 (UTC +08:00)
tags: []
source: https://pintia.cn/problem-sets/1500348318013636608/problems/1500348383269396480
author: 
---

# 题目详情 - 7-2 Prize Game (35 分)

> ## Excerpt
> 千名教师建设，万道高质量题目，百万用户拼题的程序设计实验辅助教学平台

---
Zhezhe is participating in a variety show, in which the host gives a line of NN boxes, each contains a certain amount of prize. Zhezhe may first choose to multiply the prizes of a consecutive segment of boxes by a given number XX. Then he may choose another consecutive segment of boxes, and gain all the prizes in those boxes. Note: Zhezhe may choose NOT to do anything at any of these two stages.

Your job is to find out the maximum amount of prizes that Zhezhe can gain.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 integers: NN (1≤N≤1061\\le N\\le 10^6), the number of boxes, and XX which is described in the problem. Then NN integers follow in the next line, where the iith number corresponds to the prize in the iith box. It is guaranteed that the absolute values of XX and the prizes are less than 10410^4.

### Output Specification:

Output in a line the maximum amount of prizes that Zhezhe can gain.

#### Sample Input

```
10 -4
-2 5 4 -5 -1 8 10 -3 -6 2
```

#### Sample Output

```
59
```

#### Hint

Zhezhe may choose from the 8th to the 9th box at the first stage, and obtain

```
-2 5 4 -5 -1 8 10 12 24 2
```

Then he may take the total prize from the 2nd to the last box, which is 59.

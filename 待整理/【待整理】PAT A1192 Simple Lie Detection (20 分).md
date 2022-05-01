---
created: 2022-03-08T12:50:41 (UTC +08:00)
tags: []
source: https://pintia.cn/problem-sets/1500348586764443648/problems/1500348648013864960
author: 
---

# 题目详情 - 7-1 Simple Lie Detection (20 分)

> ## Excerpt
> 千名教师建设，万道高质量题目，百万用户拼题的程序设计实验辅助教学平台

---
![lie.jpg](https://images.ptausercontent.com/31c21458-3bb6-4de2-a8ba-6db5938d1d13.jpg)

Lie detection usually uses a set of prepared questions to ask the testee, and the result is obtained by analyzing the testee's reactions. The more advanced technology uses a polygraph (测谎仪) to monitor the physical activities of the testee. Our simple polygraph here is to make a judgment by analyzing the characteristics of the answers to the questions.

First, we ask the testee to complete NN multiple choice questions, each with a single answer. Each question has 8 options, which are represented by the lowercase English letters `a`\-`h`. Then we can obtain a string of length NN, consisting of only the lowercase English letters `a`\-`h`. Score each string, and those whose score exceeds a certain threshold (阈值) TT are judged as "suspected liars". The scoring rules are as follows:

-   the string starts with an `f` has its score −2\-2;
    
-   the string ends with an `a` has its score −1\-1;
    
-   for every longest segment of answeres where the same letter is chosen for consecutive questions, if the segment length is larger than 5, the score is to +3+3;
    
-   if an `a` is immediately followed by `e` or `h`, the score is to −4\-4;
    
-   for every longest segment of answeres where consecutively increasing letters are chosen to answer consecutive questions (such as `abcd` or `defgh`), if the segment length is larger than 3, the score is to +5+5.
    

Your job is to score the answers and make a judgement.

### Input Specification:

Each input file contains one test case. For each case, the first line gives 3 positive integers NN (6≤N≤1006\\le N \\le 100), the number of questions; TT (≤100\\le 100), the threshold for judging a liar; and KK (≤100\\le 100), the number of testees.

Then KK lines follow, each gives the string of answers of a testee.

### Output Specification:

For each testee, print in a line the total score of his/her answers. If the score exceeds the threshold, print `!!!` after the score.

### Sample Input:

```
12 1 6
fghaebcdeddd
ahhhhhhgbaaa
cdefffffffff
fffffghecaaa
feeeeeeeegcb
aaaaaabbbbbb
```

### Sample Output:

```
-1
-2
8!!!
-3
1
6!!!
```

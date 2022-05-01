---
created: 2022-03-08T12:46:35 (UTC +08:00)
tags: []
source: https://pintia.cn/problem-sets/1500348318013636608/problems/1500348383269396480
author: 
---

# 题目详情 - 7-3 Memories of Youth (35 分)

> ## Excerpt
> 千名教师建设，万道高质量题目，百万用户拼题的程序设计实验辅助教学平台

---
![mem.jpg](https://images.ptausercontent.com/c1ff10b4-f1ce-41f4-9c79-777d47916eea.jpg)

There was a group of 54 youths who were very good friends. Each one of them picked a card from a deck of cards to commemorate their friendship. But 54 years later, they cannot remember who has picked which card... Fortunately they have taken a lot of pictures at the time, and the card numbers have been recorded on the back of some pictures for some of them. Hopefully these clues are sufficient to recover the card numbers for everyone, even thought the correspondence between the person and the card was not recorded.

Now your job is to help these friends recover the memories of their youth.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers MM (≤54\\le 54) and NN (≤100\\le 100), which are the number of friends (hence it is assumed that each of them corresponds to a distinct card number in the range \[1, MM\]) and the number of pictures, respectively. Then NN pictures are given.

The information of each picture occupies 3 lines. The 1st line contains a positive integer kk (<M< M) which is the number of persons in that picture. The 2nd line gives kk distinct codes, each consists of 2 English capital letters, representing the names of the persons in that pictures. Their card numbers (kk distinct integers in \[1, MM\]) are given in the 3rd line.

All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the name code for each card in ascending order of the card numbers from 1 to MM. Each code occupies a line. In case that it is impossible to determine the person who corresponds to a certain card, print `?` in the line instead.

It is guarenteed that there will not be any conflict conclusions. There might be cases such as persons A and B correspond to cards n1n\_1 and n2n\_2, so without more information we cannot determine who corresponds to which card; yet there is no case so that a single card corresponds to more than one person.

### Sample Input:

```
8 5
2
AB CD
3 6
3
EF GH IJ
1 2 5
3
AB GH IJ
5 2 6
3
KL GH CD
4 2 3
2
UV XY
7 8
```

### Sample Output:

```
EF
GH
CD
KL
IJ
AB
?
?
```

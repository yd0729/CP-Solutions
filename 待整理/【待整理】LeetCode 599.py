from math import inf
from typing import List


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        index = {s: i for i, s in enumerate(list1)}
        ans = []
        index_sum = inf
        for id, str in enumerate(list2):
            if str in index:
                j = index[str]
                if id + j < index_sum:
                    index_sum = id + j
                    ans = [str]
                elif id + j == index_sum:
                    ans.append(str)
        return ans

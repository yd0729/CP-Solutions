/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
    const index = new Map();
    for (let i = 0; i < list1.length; i++) {
        index.set(list1[i], i);
    }

    const ret = [];
    let index_sum = Number.MAX_VALUE;
    for (let i = 0; i < list2.length; i++) {
        if (index.has(list2[i])) {
            const j = index.get(list2[i]);
            if (i + j < index_sum) {
                ret.length = 0;
                ret.push(list2[i]);
                index_sum = i + j;
            } else if (i + j == index_sum) {
                ret.push(list2[i]);
            }
        }
    }
    return ret;
};
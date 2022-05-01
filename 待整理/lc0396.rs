impl Solution {
    pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut sum_f = 0;

        for i in 0..nums.len() {
            sum += nums[i];
            sum_f += i as i32 * nums[i];
        }

        let mut max_f = sum_f;
        let len = nums.len() as i32;
        for i in 1..nums.len() {
            sum_f = sum_f - sum + len * nums[i - 1];
            max_f = max_f.max(sum_f);
        }

        max_f
    }
}

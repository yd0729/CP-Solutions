class Solution {
  public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
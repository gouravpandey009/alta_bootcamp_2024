class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // Store final answers
        vector<int> answer(n);

        // Generate answer for every index
        for (int i = 0; i < n; i++) {

            int product = 1;

            // Traverse complete array
            for (int j = 0; j < n; j++) {

                // Skip current element
                if (i != j) {
                    product *= nums[j];
                }
            }

            answer[i] = product;
        }

        return answer;
    }
};
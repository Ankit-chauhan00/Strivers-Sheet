int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 1; // Product from left to right
        long long suffix = 1; // Product from right to left
        long long ans = INT_MIN; // Stores the maximum product found
        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1; // Reset prefix if zero encountered
            if (suffix == 0)
                suffix = 1; // Reset suffix if zero encountered
            prefix *= nums[i]; // Update prefix product
            suffix *= nums[n - 1 - i]; // Update suffix product
            ans = max(ans, max(prefix, suffix)); // Update maximum product
        }
        return (int)ans; // Return the maximum product subarray
    }
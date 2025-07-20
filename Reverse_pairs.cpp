int merge_sort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt; // Base case: single element
        int mid = (low + high) / 2;
        cnt += merge_sort(arr, low, mid); // Sort left half
        cnt += merge_sort(arr, mid + 1, high); // Sort right half
        cnt += count_pairs(arr, low, mid, high); // Count reverse pairs
        merge(arr, low, mid, high); // Merge sorted halves
        return cnt;
    }

// Counts reverse pairs where arr[i] > 2 * arr[j] for i < j
int count_pairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                   (long long)arr[i] > 2 * (long long)arr[right]) {
                right++; // Move right pointer if condition is met
            }
            count += (right - (mid + 1)); // Add valid pairs for arr[i]
        }
        return count;
    }

// Merges two sorted subarrays arr[low..mid] and arr[mid+1..high]
void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        // Merge elements in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        // Add remaining elements from left subarray
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        // Add remaining elements from right subarray
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        // Copy merged elements back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

// Main function to count reverse pairs in the array
int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
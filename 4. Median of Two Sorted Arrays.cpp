// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

class Solution {
public:
    void merge(vector <int>& arr, int start, int mid, int end){
        vector <int> temp (end - start + 1);
        int left = start;
        int right = mid +1;
        int index = 0;
        while (left <= mid && right <= end){
            if (arr[left] <= arr[right]){
                temp[index] = arr[left];
                left++; index++;
            }
            else{
                temp[index] = arr[right];
                right++; index++;
            }
        }
        while (left <= mid){
            temp[index] = arr[left];
            left++;index++;
        }
        while (right <= end){
            temp[index] = arr[right];
            right++;index++;
        }
        index = 0;
        while(start<=end){
            arr[start] = temp[index];
            start++;index++;
        }
    }

    void mergesort(vector <int>& arr, int start, int end){
        if (start == end){
            return;
        }
        int mid = start + (end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> num3;

        for (int num : nums1) {
            num3.push_back(num);
        }
        for (int num : nums2) {
            num3.push_back(num);
        }
        int n = num3.size();
        mergesort(num3,0,n-1);
        int pos = n/2;
        double median;

        if (n % 2 != 0){
            median = num3[pos];
        }
        else{
            double med1 = num3[pos];
            double med2 = num3[pos-1];
            median = (med1 + med2)/2;
        }
        return median;
    }
};
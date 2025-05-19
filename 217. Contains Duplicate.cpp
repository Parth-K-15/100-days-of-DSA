// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]

// Output: true

// Explanation:

// The element 1 occurs at the indices 0 and 3.


// Example 2:

// Input: nums = [1,2,3,4]

// Output: false

// Explanation:

// All elements are distinct.


// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true




class Solution {
public:
//issue: time complexity (O(n^2))
    bool containsDuplicate(vector<int>& nums) {
        int i =0;
        int j = nums.size()-1;
        while(true){
            if (nums.size()==1){
                break;
            }
            else if(nums[i]==nums[j]){
                return true;
            }
            --j;
            if (i == j){
                i++;
                j = nums.size()-1;
            }
            if (i >= j){
                return false;
            }
        }
        return false;
    }
};






class Solution {
public:
//Accepted but can be optimised 
    void merge(vector<int>& nums, int start, int mid, int end){
        int left = start;
        int right = mid+1;
        int index = 0;
        vector <int> temp(end-start+1);
        while(left <= mid && right <= end){
            if (nums[left] <= nums[right]){
                temp[index] = nums[left];
                ++index;++left;
            }
            else{
                temp[index] = nums[right];
                ++index;++right;
            }
        }
        while(left <= mid){
            temp[index] = nums[left];
            ++index;++left;   
        }
        while(right <= end){
            temp[index] = nums[right];
            ++index;++right;
        }
        index = 0;
        while(start <= end){
            nums[start]=temp[index];
            ++start;++index;
        }
    }

    void mergesort(vector <int>&nums, int start, int end){
        if (start ==end){
            return;
        }
        int mid = start + (end-start)/2;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        merge(nums,start,mid,end);
    }

    bool containsDuplicate(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);

        for (int i = 0; i< nums.size();++i){
            if (i==nums.size()-1){
                return false;
            }
            if (nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};







class Solution {
public:
//Time C and SC is O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for (int iter:nums){
            if (seen.count(iter)){
                return true;
            }
            seen.insert(iter);
        }
        return false;
    }
};

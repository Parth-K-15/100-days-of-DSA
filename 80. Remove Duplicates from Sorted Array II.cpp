// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.






// TC : O(n^2)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1, count = 1;
        int curr = nums[0];
        if (nums.size() == 1) return 1;
        for (int i = 1; i<nums.size(); i++){
            if (curr == nums[i]){
                count++;
            } 
            else{
                count = 1;
            }
            curr = nums[i];
            if (count > 2){
                ans--;
                nums.erase(nums.begin()+i);
                i--;
            }
            ans++;
        }
        return ans;
    }
};





// optimised: O(n)
  class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};







// Initial State
// k = 0

// Array:

// [1,1,1,2,2,3]
// ITERATION 1
// i = 0

// Current:

// nums[i] = 1

// Condition:

// k < 2
// 0 < 2 → true

// So keep it.

// We write:

// nums[k] = nums[i]
// nums[0] = 1

// Increment:

// k = 1

// Array remains:

// [1,1,1,2,2,3]
// ITERATION 2
// i = 1

// Current:

// nums[i] = 1

// Condition:

// k < 2
// 1 < 2 → true

// Keep it.

// Write:

// nums[1] = 1

// Increment:

// k = 2

// Array:

// [1,1,1,2,2,3]
// ITERATION 3
// i = 2

// Current:

// nums[i] = 1

// Now condition becomes:

// nums[i] != nums[k-2]

// because:

// k = 2
// k-2 = 0

// Check:

// nums[2] != nums[0]
// 1 != 1 → false

// So DON'T keep it.

// Third duplicate removed logically.

// No writing.
// No k increment.

// ITERATION 4
// i = 3

// Current:

// nums[i] = 2

// Check:

// nums[i] != nums[k-2]

// Currently:

// k = 2
// k-2 = 0

// So:

// nums[3] != nums[0]
// 2 != 1 → true

// Keep it.

// Write:

// nums[2] = 2

// Array becomes:

// [1,1,2,2,2,3]

// Increment:

// k = 3
// ITERATION 5
// i = 4

// Current:

// nums[i] = 2

// Check:

// k = 3
// k-2 = 1

// Compare:

// nums[4] != nums[1]
// 2 != 1 → true

// Keep it.

// Write:

// nums[3] = 2

// Array:

// [1,1,2,2,2,3]

// Increment:

// k = 4
// ITERATION 6
// i = 5

// Current:

// nums[i] = 3

// Check:

// k = 4
// k-2 = 2

// Compare:

// nums[5] != nums[2]
// 3 != 2 → true

// Keep it.

// Write:

// nums[4] = 3

// Array becomes:

// [1,1,2,2,3,3]

// Increment:

// k = 5
// Final Answer

// Valid portion:

// [1,1,2,2,3]

// Return:

// 5

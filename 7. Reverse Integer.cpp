Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21





// class Solution {
// public:
//     int reverse(int x) {
//         string s = to_string(abs(x));
//         if (s.length()==1) return;
//         std::reverse(s.begin(),s.end());
//         s.erase(0,s.find_first_not_of('0'));
//         long long y = stoll(s);
//         return (x<0)? -y:y;
//     }
// };
class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x) {
            int a = x % 10;
            // Check for overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && a > 7))
                return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && a < -8))
                return 0;
            num = num * 10 + a;
            x /= 10;
        }
        return num;
    }
};

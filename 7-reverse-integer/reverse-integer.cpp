class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            if (rev > INT32_MAX / 10 || rev < INT32_MIN / 10)
                return 0;
            int temp = rev * 10 + digit;
            if ((temp - digit) / 10 != rev)
                return 0;
            rev = temp;
            x /= 10;
        }
        return rev;
    }
};

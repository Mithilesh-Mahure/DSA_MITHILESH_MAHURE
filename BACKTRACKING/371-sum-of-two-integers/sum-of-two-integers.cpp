class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = a & b;   // bits to carry over
            int sum = a ^ b;     // bits without carry
            a = sum;
            b = carry << 1;      // shift carry to add in next place
        }
        return a;
    }
};
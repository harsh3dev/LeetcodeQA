class Solution {
public:
    int bitwiseComplement(int num) {
        // if num is zero return 1
        // initialize mask variable with value ~0
        // if num and mask both have same 1 then left shift mask
        // return ~mask & ~num
        if(num==0) return 1;
        unsigned int mask = ~0;
        while(mask & num) {
            mask<<=1;
        }

        return ~mask & ~num;
    }
};
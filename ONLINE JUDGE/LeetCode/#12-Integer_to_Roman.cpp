class Solution {
public:
    string intToRoman(int num) {
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int decimal[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        int i = 0;
        while(num > 0) {
            if(num >= decimal[i]) {
                result += roman[i];
                num -= decimal[i];
            }
            else {
                i++;
            }
        }
        return result;
    }
};

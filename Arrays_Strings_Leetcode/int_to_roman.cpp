#include <iostream>
#include <string>
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"}; // Use double quotes for strings
        int i = 12;

        while (num > 0)
        {
            int quo = num / val[i];
            if (quo > 0)
            {
                // roman += string(quo, sym[i]);
                while (quo != 0)
                {
                    roman += sym[i];
                    quo--;
                }
                num %= val[i];
            }
            i--;
        }

        return roman;
    }
};
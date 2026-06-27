#include <format>
#include <map>

int romanToInt(std::string_view s)
{
    std::unordered_map<char, int> romanNumeralLookup;
    romanNumeralLookup['I'] = 1;
    romanNumeralLookup['V'] = 5;
    romanNumeralLookup['X'] = 10;
    romanNumeralLookup['L'] = 50;
    romanNumeralLookup['C'] = 100;
    romanNumeralLookup['D'] = 500;
    romanNumeralLookup['M'] = 1000;
    int total = 0;
    int prevVal = 0;
    for (auto &c : s)
    {
        const auto currVal = romanNumeralLookup[c];
        total += currVal;
        if (currVal > prevVal)
        {
            total = total - (prevVal * 2);
        }
        prevVal = currVal;
    }
    return total;
}

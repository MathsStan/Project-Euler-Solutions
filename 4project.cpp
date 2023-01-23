#include <iostream>
#include <string>
#include <cmath>

#define MAXDIGITS 5

bool ispalindrome(std::string);
int largestpalindromeproduct(int);

int main() {
    int digits;
    for (digits = 1; digits <= MAXDIGITS; digits++) {
        const int maxarg = pow(10, digits) - 1;
        std::cout << "The largest palindrome product of "<< digits;
        std::cout << " digit" << (digits > 1 ? "s" : "") << " is: " << largestpalindromeproduct(maxarg) << "\n";
    }
}

bool ispalindrome(std::string s) {
    int i, j;
    for (i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

int largestpalindromeproduct(int maxarg) {
    int maxdecrease, largestreturnval = -1, currentval;

    for (maxdecrease = 0; largestreturnval < 0; maxdecrease++) {
        for (int i = 0; i < maxdecrease / 2; i++){
            currentval = (maxarg - i) * (maxarg - maxdecrease + i);
            if (ispalindrome(std::to_string(currentval)))
                largestreturnval = currentval;
        }
    }
    return largestreturnval;
}


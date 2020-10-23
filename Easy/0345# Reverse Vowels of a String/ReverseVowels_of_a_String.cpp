/**** Leetcode-Easy 0345# Reverse Vowels of a String *****/

/***
Write a function that takes a string as input and reverse only the vowels of a string.
***/

/***
■ Example 1:

Input: "hello"
Output: "holle"

■ Example 2:

Input: "leetcode"
Output: "leotcede"

■ Note:
The vowels does not include the letter "y".
***/

//***********************************************************************************//
// Develop in C++ :

//!!! This is a two pointer solution. Go through the string by once.

class Solution {
public:
    string reverseVowels(string s) {
        int p1 = 0, p2 = s.size()-1;
        while(p1 < p2){
            while(p1 < p2 && !isVowel(s[p1]))
                p1++;
            while(p1 < p2 && !isVowel(s[p2]))
                p2--;
            if(p1 != p2)
                swap(s[p1++], s[p2--]);
        }
        return s;
    }
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};

/***
■  Runtime : 8 ms
■  Memory : 8.2 MB

■  Time complexity : O(log(n))
■  Space Complexity: O(1).
***/
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
// Develop in C :

//!!! This is a two pointer solution. Go through the string by once.

bool isVowel(char charac);

char * reverseVowels(char * s){
    //printf("Hellow");
    char *p1 = s;
    char *p2 = p1 + strlen(p1);
    while(p1 < p2){
        while(p1 < p2 && !(isVowel(*p1)))
            p1++;
        while(p1 < p2 && !(isVowel(*p2)))
            p2--;
        if(p1 != p2){
            char temp = *p1;
            *p1++ = *p2;
            *p2-- = temp;
        }
    }
    return s;
}

bool isVowel(char charac)
{
    int c = (int)charac;
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

/***
■  Runtime : 0 ms
■  Memory : 6.9 MB

■  Time complexity : O(log(n))
■  Space Complexity: O(1).
***/
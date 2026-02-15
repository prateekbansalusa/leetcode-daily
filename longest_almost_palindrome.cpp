#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestAlmostPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;

        // Helper to expand around center and count mismatches
        // We need to find the longest substring where we can remove AT MOST 1 char to make it a palindrome.
        // Wait, the definition says "removing EXACTLY one character".
        // This means pure palindromes might NOT count unless we can remove a char and it STAYS a palindrome (e.g. "aaa" -> remove 'a' -> "aa" ok).
        
        // Let's iterate through all substrings? No, O(N^3) or O(N^2) might be too slow if N is large.
        // Let's look at constraints. If N <= 2000, O(N^2) is fine.
        
        // Since it's a "Medium" and Q3, N is likely up to 2000 or 5000.
        // Let's try an O(N^2) approach by expanding around centers.
        
        // Actually, "remove exactly one character" is tricky for expansion.
        // A better brute force for O(N^3) would check every substring.
        // For O(N^2), we can iterate all substrings (i, j) and check "almost palindrome" in O(1) after precomputation?
        // Or simply: For every substring, check if it's an almost-palindrome.
        
        // Let's simply iterate all substrings and check. 
        // Optimization: Check from longest length downwards?
        
        for (int len = n; len >= 1; --len) {
            for (int i = 0; i <= n - len; ++i) {
                // Check substring s[i...i+len-1]
                int left = i, right = i + len - 1;
                if (isAlmostPalindrome(s, left, right)) {
                    return len;
                }
            }
        }
        return 0;
    }

private:
    bool isAlmostPalindrome(const string& s, int left, int right) {
        // We need to remove EXACTLY one character.
        // This means if we find a mismatch s[L] != s[R], we MUST remove either s[L] or s[R].
        // If we don't find a mismatch (it's already a palindrome), we must check if removing any char keeps it a palindrome.
        // Actually, if it's already a palindrome, removing any char makes it a palindrome ONLY if length is odd (middle char) 
        // or if all chars are same? No.
        // Example: "aba" -> remove 'b' -> "aa" (Palindrome). So "aba" IS almost-palindrome.
        // "abc" -> remove 'b' -> "ac" (Not palindrome).
        
        // Standard Palindrome Check with 1 skip allowed:
        int l = left, r = right;
        while (l < r) {
            if (s[l] != s[r]) {
                // Mismatch found. We MUST skip either l or r.
                // Case 1: Skip l
                if (isPalindrome(s, l + 1, r)) return true;
                // Case 2: Skip r
                if (isPalindrome(s, l, r - 1)) return true;
                
                return false; // Neither skip worked
            }
            l++;
            r--;
        }
        
        // If we get here, the string matches perfectly (it is already a regular palindrome).
        // BUT the requirement is "remove EXACTLY one".
        // Can we remove one char from a palindrome to get a palindrome?
        // - Yes, typically true for most palindromes (e.g. "aba" -> remove b -> "aa").
        // - Is there any palindrome where removing 1 char DOESN'T result in a palindrome?
        //   "abca" is not palindrome.
        //   "aba" is palindrome. Remove 'b' -> "aa" (Yes). Remove 'a' -> "ba" (No).
        //   Actually, we just need ANY valid removal.
        //   For ANY non-empty string, is it possible to remove 1 char to make it a palindrome?
        //   If it's already a palindrome, removing the middle element (if odd len) works?
        //   Actually, the problem asks for longest substring that satisfies the condition.
        
        // Wait, if input is "aa", can we remove 'a' -> "a" (Palindrome)? Yes.
        // So regular palindromes ARE almost-palindromes usually.
        return true; 
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

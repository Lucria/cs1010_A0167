#include <stdio.h>
#include <string.h>
#define MAX 20
/** 
Given a string, find the longest substring that contains only two unique characters. For example, given "ghjabcbbbbcccbdddadacb", 
the longest substring that contains 2 unique character is "bcbbbbcccb".
"teest"
*/

void insert (char, char [2]);
int contains (char, char[2]);

int main () {
	char str[MAX], check[2];
	printf("Enter string: ");
	scanf("%s", str);

	int i, d, count = 0, largestSum = 0;
	// Main operations
	for (i = 0; i < strlen(str); i++) {
		if (contains(str[i], check)) {
			// Good and continue 
			count++;
			if (count == 1) {
				// repetitve call - only to be called once to consider the first character missed 
				count++;
			}
		}else{
			insert(str[i], check);
			if (count >= 1) {
				count++; // To end off with the last letter as the last letter of subsequence is missed
				if (count > largestSum) {
					largestSum = count;
				}
			}
			count = 0;
		}
	}
	printf("Longest substring containing 2 unique characters: %d\n", largestSum);
	return 0;
}


int contains (char c, char check[2]) {
	int i, count = 0;
	for (i = 0; i < 2; i++) {
		if (check[i] == c) {
			return 1;
		}
	}
	return 0;
}

void insert (char c, char check[2]) {
    int i;
    for (i = 2-1; i >= 0; i--) {
        check[i+1] = check[i];
    }
    // Insert at zero
    check[0] = c;
}
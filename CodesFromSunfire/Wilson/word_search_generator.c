#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAX 50

int generate_SE (char [MAX][MAX], int , char [MAX], int, int);
int word_len (char [MAX]);
void display (char [MAX][MAX], int);
int generate_north (char [MAX][MAX], int, char [MAX], int, int);
int generate_south (char [MAX][MAX], int, char [MAX], int, int);
int generate_east (char [MAX][MAX], int, char [MAX], int, int);
int generate_west (char [MAX][MAX], int, char [MAX], int, int);
int generate_general (char [MAX][MAX], int, char [MAX], int, int, int);


int main () {
	srand(time(NULL));
	char word[MAX]; 
	char matrix[MAX][MAX];
	int size, x = rand()%(size-1), y = rand()%(size-1), Case = rand()%6+1;

	printf("Enter size of word search: ");
	scanf("%d", &size);

	// Init the word search
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = '-';
		}
	}

	// TODO: Add more cases of word traversal and finally dash replacement with random letters 
	// Also, add a condition to only accept upper case letters 

	// Generate the word search	
	// Keeps the prog running as long as user does not press ctrl-D
	printf("Enter word: ");
	while(scanf("%s", word) != EOF) {
		int length = word_len(word);
		if (length > size || length < 3) {
			printf("Word exceeding board or fewer than 3\n");
			printf("Enter word: ");
			continue;
		}
		while (!generate_general(matrix, size, word, x, y, Case)) {
			// Determines the number of cases that can be randomly generated 
			Case = rand()%6+1;
			x = rand()%size-1 + 0;
			y = rand()%size-1 + 0;
		}
		display(matrix, size);
		printf("Enter word: ");
	}
	
	printf("\nDone\n\n");
	display(matrix, size);

	return 0;
}

void display (char matrix[MAX][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%c ", matrix[i][d]);
		}
		printf("\n");
	}
}


int word_len (char word[MAX]) {
	int i;
	for (i = 0; word[i] != '\0'; i++);
	return i;
}

int generate_general (char matrix[MAX][MAX], int size, char word[MAX], int x, int y, int Case) {
	int boolean = 0;
	switch(Case) {
		case 1:
		boolean = generate_north(matrix, size, word, x, y);
		break;
		case 2:
		boolean = generate_south(matrix, size, word, x, y);
		break;
		case 3:
		boolean = generate_SE(matrix, size, word, x, y);
		break;
		case 4:
		boolean = generate_west(matrix, size, word, x, y);
		break;
		case 5:
		boolean = generate_east(matrix, size, word, x, y);
		break;
	}

	return boolean;
}

// Generators 
int generate_north (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	// return 0 when it exceeds the board
	if (y - length < 0) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; d--, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; d--, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_south (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	// return 0 when it exceeds the board
	if (y + length < size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; d++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; d++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_east (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	// return 0 when it exceeds the board
	if (x + length < size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_west (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	// return 0 when it exceeds the board
	if (x - length >= 0) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i--, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i--, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_SE (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	// return 0 when it exceeds the board
	if (x + length > size || y + length > size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i++, d++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i++, d++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
} 

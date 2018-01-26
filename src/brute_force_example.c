////////////////////////////////////////////////////////////////////////////////
////////////////////////////		EXAMPLES	////////////////////////
////////////////////////////////////////////////////////////////////////////////
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../includes/brute_force.h"

int check(char* str)
{
	return strcmp(str, "abc");
}

int main(int argc, char* argv[])
{
	const char alph[] = "abcdefghijklmnopqrstuvwxyz";
	const int alph_len = sizeof(alph) - 1;
	int max = 3, start_index = 0;

	if(argc == 2)
		max = atoi(argv[1]);

	// test simple
	print_brute(alph, alph_len, max, start_index);

	// test func
	//printf("%s\n", test_brute(alph, alph_len, max, check));
	
	return 0;
}


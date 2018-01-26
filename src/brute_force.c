////////////////////////////////////////////////////////////////////////////////
////////////////////////	BRUTE FORCE 	////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// come fare una somma con riporto
// vettore key risultato
// vettore indexes: per ogni carattere di key, indica l'indice di quel char
// nell'alphabet
// (key = [a b z] -> indexes = [1 2])

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

char* brute(const char alphabet[], const int alphabet_size, const int key_length, int (*test_func)(char*), int start_index)
{
	char* key = malloc(key_length + 1);
	int j = 0, elapsed, *indexes = malloc(sizeof(int)*(key_length + 1));
	clock_t start, time;

	// init str risultato col primo elemento dell'alfabeto e indici a 0
	for(j=0; j<key_length; j++)
	{
		indexes[j] = start_index;
		key[j] = alphabet[indexes[j]];
	}
	key[key_length] = '\0';
	if(test_func == NULL)
		printf("%s\n", key);

	// TIMER START
	start = clock();

	while(1)
	{
		// incrementa l'ultimo carattere (secondo alphabet) 
		// incrementa l'indice corrispondente 
		key[key_length-1] = alphabet[++indexes[key_length-1]];

		// cicla partendo dalla fine: se il carettere e' a fine alfabeto
		// lo azzera e incrementa quello prima
		// ma appena ne trova uno non alla fine, si ferma
		for(j=key_length-1; j>0; j--)
		{
			if(indexes[j] == alphabet_size)
			{
				indexes[j] = 0;
				key[j] = alphabet[0];
				key[j-1] = alphabet[++indexes[j-1]];
			}
			else
				break;
		}

		// finisce quando ha passato il riporto fino al primo carattere
		if(indexes[0] == alphabet_size)
			break;
			
		// se c'e' una funzione da testare chiama quella, seno' printf
		if(test_func == NULL)
			printf("%s\n", key);
		else if((*test_func)(key) == 0)
		{
			printf("KEY FOUND!\n%s\n", key);
			break;
		}
	}
	
	// TIMER STOP
	time = clock() - start;
	elapsed = time * 1000 / CLOCKS_PER_SEC;
	printf("\nTIME TAKEN:\n%d seconds %d milliseconds\n", elapsed/1000, elapsed%1000);
	
	free(indexes);

	return key;
}

// puoi passare la tua funzione (test_func) e lui fa brute force su questa:
// come strcmp la funzione deve restituire 0 se il controllo passa
// prende in input una stringa da controllare e ritorna un intero
char* test_brute(const char alphabet[], const int alphabet_size, const int key_length, int (*test_func)(char*), int start_index)
{
	return brute(alphabet, alphabet_size, key_length, test_func, start_index);
}

// stampa semplicemente tutte le combinazioni
void print_brute(const char alphabet[], const int alphabet_size, const int key_length, int start_index)
{
	brute(alphabet, alphabet_size, key_length, NULL, start_index);
}

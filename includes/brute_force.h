# ifndef BRUTE_FORCE_H
# define BRUTE_FORCE_H

/*
 * Calcola tutte le possibili combinazioni degli elementi di <alphabet>.
 * Continua fino a produrre una stringa di lunghezza <max_length>.
 * Stampa soltanto le combinazioni.
 */
void print_brute(const char alphabet[], const int alphabet_size, const int max_length, int start_index);

/*
 * Calcola tutte le possibili combinazioni degli elementi di <alphabet>.
 * Continua fino a produrre una stringa di lunghezza <max_length>.
 *
 * Testa le varie combinazioni passando i vari valori alla funzione di test
 * <(*test_func)(char*)>: passando come argomento un puntatore a funzione, 
 * (che si deve comportare come strcmp), ritorna la stringa che per prima
 * fa passare il test.
 *
 * test_func deve prendere in input una stringa e restituire 0 se questa passa
 * il test. (Ad esempio potrebbe ritornare una strcmp(input, "abc")).
 */
char* test_brute(const char alphabet[], const int alphabet_size, const int max_length, int (*test_func)(char*), int start_index);

# endif

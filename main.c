#include "hash.h"

int main(void) {

    HashTable h;
    char word[2] = "AA";

    
    InitHash(h);
    LoadDictionary(h);
    ChainedSearch(h, word);
    
    //PrintHashTable(h);

    return 0;
}

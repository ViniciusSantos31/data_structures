#pragma once

#include "sll.h"



typedef struct Sll* HashTable[length];

void InitHash(HashTable h);

unsigned int Hash(char* word);

void ChainedInsert(HashTable h, char* word);

int ChainedSearch(HashTable h, char* word);

void LoadDictionary(HashTable h);

void PrintHashTable(HashTable h);

void TestHashTable(HashTable h);

void wrong_w(char* word);

void Results();

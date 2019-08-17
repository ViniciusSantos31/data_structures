#pragma once

#define length 5000
#define words 5000

#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Sll {

    struct Node* head;
    struct Node* tail;
    int size;

    char table[words];
};

struct Node {

    char* word;
    struct Node* next;
};

void Prepend(struct Sll* list, char* word);

void Append(struct Sll* list, char* word);

void DestroyList(struct Sll* list);

void PrintList(struct Sll* list);

void Delete(struct Sll* list, struct Node* node);

struct Sll* CreateNode();

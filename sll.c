#include "sll.h"

struct Sll* CreateNode() {

    struct Sll* list;

    list = (struct Sll*) malloc(sizeof(struct Sll));
    list->head = NULL;
    list->tail = NULL;
    ++list->size;

    return list;
}

void Append(struct Sll* list, char* word) {

    struct Node* n1;

    if(list->head == NULL) {

        list->head = (struct Node*) malloc(sizeof(struct Node));

        list->head->word = word;
        list->head->next = NULL;
        list->tail = list->head;
        list->tail->next = NULL;
        printf("teste\n");

    }else {

        list->tail = list->head;

        while(list->tail->next != NULL)
            list->tail = list->tail->next;

        n1 = (struct Node*) malloc(sizeof(struct Node));
        n1->word = word;
        n1->next = NULL;
        list->tail->next = n1;

    }

    ++list->size;

}

void Prepend(struct Sll* list, char* word) {

    struct Node* n1;

    if(list->head == NULL) {

        list->head = (struct Node*) malloc(sizeof(struct Node));

        list->head->word = word;
        list->head->next = NULL;
        list->tail = list->head;
        list->tail->next = NULL;
        

    }else {

        n1 = (struct Node*) malloc(sizeof(struct Node));

        n1->word = word;
        n1->next = list->head;
        list->head = n1;

    }

    ++list->size;

}

void DestroyList(struct Sll* list) {

    if(list->head == NULL) {

        free(list);

    }else {

        struct Node* aux;

        aux = list->head;

        while(aux->next != NULL) {

            list->head = aux->next;
            free(aux);
            aux = list->head;

        }

        free(aux);
        free(list);
    }

}

void Delete(struct Sll* list, struct Node* node) {

    if(list == (struct Sll*) node) {

        list = NULL;
        free(node);

    }else {

        struct Node* aux;
        struct Node* aux2;

        aux = list->head;

        while(aux != node) {

            aux2 = aux;
            aux = aux->next;

        }

        aux2->next = aux->next;
        free(aux);

    }

}

void PrintList(struct Sll* list) {

    if(list->head == NULL) {

        printf("Vazio.\n");

    }else {

        struct Node* aux;

        aux = list->head;

        int i = 0;
        printf("i, %d\n", i);

        while(aux != NULL) {

            printf("SLL, List[%i] = %s\n", i, aux->word);
            i++;
            printf("i, %d\n", i);

            aux = aux->next;

        }

        free(aux);

    }
}


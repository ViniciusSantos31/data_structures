#include "hash.h"

unsigned int Hash(char* word) {

    int size = strlen(word);
	int i;
	unsigned int value = 5381;

	for(i = 0; i < size; ++i) {

	    value += (value << 5)  + word[i];

	}

	return value;
}

void InitHash(HashTable h) {

    int i;

    for (i = 0; i < length; i++)
    {
        h[i] = NULL;
    }

}
void LoadDictionary(HashTable h) {

	FILE* f = fopen("asciiii.txt", "r");
    char teste[60];

	if(f == NULL) {

		fprintf(stderr, "failed to open input.\n");

	}else{

        //printf("Upload Complete.\n");
        while(fscanf(f, "%s ", teste) != EOF){ // le o arquivo do dicionario;

            ChainedInsert(h, teste); //Chama Funccao que calcula o hash e inseri na table

        }
	}
	fclose(f);
}

void ChainedInsert(HashTable h, char* word) {

	unsigned int index = (Hash(word) % length);

    struct Sll* lista = CreateNode();

    if(h[index] == NULL) {

		//printf("Inseriu, %s\n", word);

		h[index] = lista;

		//strcpy(h[index]->table, word);
		Prepend(lista, word);
		
		//printf("teste\n");


	}else {
        //printf("Inseriu else, %s\n", word);

		lista = h[index];

		//strcpy(h[index]->table, word);

		Prepend(lista, word);



	}
	//printf("hash word, [%d]\n", Hash(word)% length);

}

int ChainedSearch(HashTable h, char* word) {

	int index = (Hash(word) % length);

	if(h[index] != NULL) {

		printf("entrou no if\n");

		struct Sll* list = h[index];

		struct Node* aux = list->head;

		while (aux != NULL) {

			printf("Entrou no while\n");
			printf("%s, %s\n", aux->word, word);

			if((strcmp(aux->word, word)) == 0) {

				printf("encontrou.\n");

				return 1;

			}else {

				if (aux == NULL){
					
					wrong_w(word);
					printf("Palavra não encontrada!\n");
				}

			}

			aux = aux->next;
		}
	} 

	

	return 0;
}

void wrong_w(char* word){

	FILE* f = fopen("wrong_words.txt", "w");

	fprintf(f, "%s", word);

	fclose(f);
	
}

/*void PrintHashTable(HashTable h) {

	int i;

	for(i = 0; i < length; ++i) {

		struct Sll* list = h[i];
		struct Node* aux = list->head;

		if(aux != NULL) {

			while(aux != NULL) {

				printf("table[%i] = %s\n", i, aux->word);

				aux = aux->next;

			}
		}
	}

}*/


void Results() {

	printf("Numero total de palavras do texto: \n");
	printf("Tempo total da verificao: \n");
	printf("Numero de palavras que falharam no spell check: \n");
	printf("Lista de palavras que falham no spell check: \n");

	printf("Num.   Ocorrencia  -  Palavra\n");
	printf("-------------------------------\n");

}

void TestHashTable(HashTable h) { //Função para teste

    int i;
	char exp[words];

    for (i = 0; i < 3; i++)
    {
        printf("palavra[%i] = ", i);
        scanf("%s", exp);

        ChainedInsert(h, exp);
    }

    printf("===================\n");

    for(i = 0; i < 3; ++i) {

        printf("palavra[%i] = ", i);
        scanf("%s", exp);

        ChainedSearch(h, exp);

    }

}

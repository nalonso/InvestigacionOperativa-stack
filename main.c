#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct element {
	int data;
	struct element *next;
};

struct stack {
	struct element *top;
	int size;
};


int newStack(struct stack *);
int pushStack(struct stack *, int data);
int popStack(struct stack *, struct element *);
int isEmptyStack(struct stack);

int main()
{
    /*
     * Inicialización de las Pilas
     *
     */

    struct stack tempStack;
    struct stack oddStack;
    struct stack evenStack;

    newStack(&tempStack);
    newStack(&oddStack);
    newStack(&evenStack);


    /*
     *
     *
     */
    int count = 1;
    int toInsert;
    while(count < 100 && toInsert > 0){
        printf( "Ingrese un Número para insertar en la pila (si no desea insertar más coloque -1)\n");
        scanf("%d", &toInsert );
        pushStack(&tempStack, toInsert);
        count++;
    }


    printf("Hello world!\n");
    return 0;
}

int newStack(struct stack *p) {
	p->top = NULL;
	p->size = 0;
	return 1;
}

int pushStack(struct stack *p, int toPush){
	struct element *newElement = (struct element *) malloc(sizeof(struct element));

	if (newElement == NULL) return -1;

	newElement->data = toPush;
	newElement->next = p->top;

	p->top = newElement;
	p->size++;
	return 1;
}

int popStack(struct stack *p, struct element *elementOut){
	if (isEmptyStack(*p) ) { return -1; }

	elementOut->data = p->top->data;
	p->top = p->top->next;
	p->size--;
}

int isEmptyStack(struct stack p){
	if (p.size == 0) { return 1; }
	return 0;
}

int size(struct stack p){
	return p.size;
}

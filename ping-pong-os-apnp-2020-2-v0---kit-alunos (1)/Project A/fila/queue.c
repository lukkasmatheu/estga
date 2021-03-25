#include "queue.h"
#include <stdio.h>


void queue_append (queue_t **queue, queue_t *elem){
    // Condicoes a verificar, gerando msgs de erro:
    // - o elemento nao deve estar em outra fila    CHECK!!!!
    // - a fila deve existir                        CHECK!!!!
    // - o elemento deve existir                    CHECK!!!!
    // Insere um elemento no final da fila.         

    if(queue == NULL || elem == NULL){
        if(queue == NULL){
            printf("\nFila inexistente\n");
        }else{
            printf("\nElemento inexistente\n");
        }
        return;
    }else if(elem->prev == NULL && elem->next == NULL){
        if(*queue == NULL){
            *queue = elem ;
            (*queue)->prev = (*queue)->next = elem;
        }
        else{
            // elem->prev = (*queue)->prev;
            // (elem->prev)->next = elem;
            // (*queue)->prev = elem ;
            // elem->next = *queue;

            printf("esta aqui");
                    elem->next = *queue;
                    elem->prev = (*queue)->prev;
                    ((*queue)->prev)->next = elem;
                    (*queue)->prev = elem;

        }
    }else{
        printf("\nElemento ja esta em outra fila\n");
    }
}


// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir                        CHECK!!!!
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: apontador para o elemento removido, ou NULL se erro

queue_t *queue_remove (queue_t **queue, queue_t *elem) {
    int achou = 0;
    if(queue == NULL || elem == NULL){
        if(queue == NULL){
            printf("\nFila inexistente\n");
        }else{
            printf("\nElemento inexistente\n");
        }
        return NULL;
    }
    else if(*queue == NULL){
        printf("\nFila vazia\n");
        return NULL;
    }
    queue_t *auxiliar = *queue;
    for( auxiliar ; auxiliar->next != *queue ;auxiliar = auxiliar->next ){
        if(auxiliar == elem){
            achou = 1;
            break;
        }
    }
    if(achou == 1){
        if(auxiliar->next == auxiliar && auxiliar->prev == auxiliar ){
            *queue = (*queue)->prev = (*queue)->next = NULL;
            
        }else{
            auxiliar->prev->next = auxiliar->next;
            auxiliar->next->prev = auxiliar->prev;
        }
        return auxiliar;
    }else{
        printf("\nElemento nao encontrado na lista\n");
        return NULL;
    }
    
}


void queue_print (char *name, queue_t *queue, void print_elem (void*) ) {
    if(queue == NULL){
        printf("\nFila vazia\n");
        return;
    }
    queue_t *auxiliar = queue ;
    for( auxiliar ; auxiliar->next != queue ;auxiliar = auxiliar->next ){
       print_elem(auxiliar);
    }
}


int queue_size (queue_t *queue) {
    if(!queue) return 0;
    int i;
    queue_t *auxiliar = queue;
    for(i=1, auxiliar; auxiliar->next != queue ; i++ , auxiliar = auxiliar->next )
    return i;
}
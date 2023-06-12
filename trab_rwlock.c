#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_LEITORES 14
#define NUM_ESCRITORES 2

int tabela[100];

pthread_rwlock_t rwlock;

void* reader(void* arg) {
    int id_leitor = *(int*)arg;

    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Leitor %d acessou a tabela.\n", id_leitor);
        pthread_rwlock_unlock(&rwlock);

        sleep(1);
    }

    return NULL;
}

void* writer(void* arg) {
    int id_escritor = *(int*)arg;

    while (1) {
        pthread_rwlock_wrlock(&rwlock);
        printf("Escritor %d acessou a tabela.\n", id_escritor);
        pthread_rwlock_unlock(&rwlock);
        
        sleep(1);
    }

    return NULL;
}

int main(){
    // Inicialização do rwlock
    pthread_rwlock_init(&rwlock, NULL);

    // Threads para leitores
    pthread_t leitores[NUM_LEITORES];
    int ids_leitores[NUM_LEITORES];

    // Threads para escritores
    pthread_t escritores[NUM_ESCRITORES];
    int ids_escritores[NUM_ESCRITORES];

    int i;

    // Criação das threads para leitores
    for (i = 0; i < NUM_LEITORES; i++) {
        ids_leitores[i] = i;
        pthread_create(&leitores[i], NULL, reader, &ids_leitores[i]);
    }

    // Criação das threads para escritores
    for (i = 0; i < NUM_ESCRITORES; i++) {
        ids_escritores[i] = i;
        pthread_create(&escritores[i], NULL, writer, &ids_escritores[i]);
    }

    // Aguardar o término das threads
    for (i = 0; i < NUM_LEITORES; i++) {
        pthread_join(leitores[i], NULL);
    }

    for (i = 0; i < NUM_ESCRITORES; i++) {
        pthread_join(escritores[i], NULL);
    }

    // Liberação do rwlock
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
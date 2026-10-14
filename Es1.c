//
// Created by Alessia Di Paolo on 14/10/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    //dichiaro i due pipe e l'array
    int fd[2];
    int array[10]={1,2,3,4,5,6,7,8,9,10};

    //conto i pari
    pid_t pid = fork();
    if(pid == 0) {
        close(fd[0]);
        somma_pari = 0;
        for (int i = 0; i < 10; i++) {
            if (array[i]%2 == 0) {
                somma_pari += array[i];
            }
        }
        close(fd[1]);
        exit(0);
    }
    //conto i dispari
    else {
        close(fd[1]);
        somma_dispari = 0;
        for (int i = 0; i < 10; i++) {
            if (array[i]%2 == 1) {
                somma_dispari += array[i];
            }
        }
        //riprendo i valori del pari
        read(fd[0], &somma_pari_ricevuta, sizeof(somma_pari_ricevuta));
        close(fd[0]);
        exit(0);
        int somma_totale = somma_pari_ricevuta + somma_dispari;

        //porto tutto su desktop
        printf("Somma totale = %d\n", somma_totale);
        printf("Somma pari = %d\n", somma_pari_ricevuta);
        printf("Somma dispari = %d\n", somma_dispari);
    }
    return 0;
}
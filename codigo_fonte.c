//Grupo: Caio Augusto, Danilo Lopes e Phoebe Regina//

#include <stdio.h>
#include <stdlib.h> //inclui a biblioteca que possui as funções rand e o srand
#include <time.h> //usada para inicializar a geração de números aleatórios
#include <windows.h> //usada para o sleep

int main() {
    int matriz[4][4];
    int valores[16];
    int i, j;
    
    srand(time(NULL)); //faz os números serem diferentes a cada execução

    //gera 8 pares de números aleatórios (0 a 9)
    for (i = 0; i < 8; i++) {
        int n = rand() % 10; //gera um número inteiro aleatório (rand) entre 0 e 9 (% 10)
        valores[i * 2] = n; //guarda o número na 1ª posição do par
        valores[i * 2 + 1] = n; //guarda o mesmo número na 2ª posição do par
    }

    //embaralha os 16 valores
    for (i = 0; i < 16; i++) {
        int r = rand() % 16;//gera um número inteiro aleatório (rand) entre 0 e 15 (% 16)
        int temp = valores[i];
        valores[i] = valores[r];//troca os valores das posições i e r, embaralhando-os
        valores[r] = temp;
    }

    //preenche a matriz
    int k = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            matriz[i][j] = valores[k++];

    // Mostra a matriz original por 5 segundos
    printf("Matriz com números:\n\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    Sleep(5000); //espera 5 segundos
    
    system("cls"); //limpa a tela
    
    //mostra a matriz com o simbolo escolhido
    char simbolo = 3;
    
    printf("Matriz com os simbolos ASCII:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%c", simbolo);
        printf("\n");
    }
}

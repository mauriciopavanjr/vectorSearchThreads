/*
compilar:
 g++ -std=c++11 -pthread threads.cpp 
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <thread>

bool flag = false;

void buscaVetor(int v[], int ini, int fim, int k, int verificador){
	if (verificador == 0){
		while (flag == false){
		printf("esquerda: %d\n", fim);
		if ( ini > fim ) return;
		else if( v[fim] == k ){
                printf("vetorEsq achou! Posicao %d", fim);
	        	flag = true;
                }
        else
                	fim--;
		}	
	}
	else{
		while (flag == false){
		printf("direita: %d\n", ini);
		if ( ini > fim) return;
		else if( v[ini] == k ){
                	printf("vetorDir achou! Posicao %d", ini);
	        	flag = true;
                }
                else
                	ini++;
		}	
	}
}

int main () {
    int v[] = {8,13,20,2,3,9,19,12,1,4,18,15,5,7,10,11,14,17,16,6};
    int n = 20;
	int meio = n/2;
	std::thread t1 (buscaVetor, v, 0, meio-1, 6, 0);
	std::thread t2 (buscaVetor, v, meio, n, 6, 1);
    t1.join();
    t2.join();
	return 0;
}
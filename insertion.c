
/***************************************************************************
 *   insertion.c                              Version 20170618.215221      *
 *                                                                         *
 *   Insertion Sorting Algorithm in C                                      *
 *   Copyright (C) 2017         by Daidson Alves                           *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Daidson Fonseca Alves                                                 * 
 *   Email: daidson.alves@gmail.com                                        *
 *   Webpage: https://github.com/daidson                                   *
 *   Phone: +55 81 99954-6310                                              *
 ***************************************************************************/

#include <stdio.h>

#define MAX 15

int arr[MAX] = {1, 7, 53, 2, 31, 90, 119, 871, 17, 63, 5432, 4321, 6, 81, 212};
int i, j, k, n;

/* funcao para imprimir o vetor a ser ordenado*/
void imprimeVetor()
{ 
    printf("Vetor a ser ordenado ");
    for(i = 0; i < MAX; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\n\n");
}

/* função para ordenar o vetor escolhido */
void insertion()
{
    for(i = 1; i < MAX; i++)
    {
        k = arr[i];
        j = i - 1;

        /* mover elementos do vetor que são maiores que a chave para uma posicao a frente da sua posicao atual */
        while(j >= 0 && arr[j] > k)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

/* função para imprimir o vetor com o tamanho MAX */
void imprime()
{
    printf("Vetor ordenado: ");
    for(i = 0; i < MAX; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

/* Programa para testar a ordenação por insertion */
int main(void)
{ 
    printf("Ordenação Insertion em C.\n");
    printf("-------------------------\n\n");
    n = sizeof(arr)/sizeof(arr[0]);
    
    imprimeVetor(arr, n);
    insertion(arr, n);
    imprime(arr, n);

    return 0;
}
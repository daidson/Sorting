
/***************************************************************************
 *   bubble.c                                 Version 20170618.215033      *
 *                                                                         *
 *   Bubble Sorting Algorithm in C                                         *
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
#include <stdlib.h>
#include <stdbool.h>

#define MAX 14

int listA[MAX] = {5,5,2,2,1,6,5,4,2,6,5,4,6,5};
int listB[MAX] = {6,2,4,1,3,5,4,2,3,5,4,3,5,4};

void display()
{
    int i;
    /* navegar pelos itens */
    for(i = 0; i < MAX; i++)
    {
        printf("\tLista 1: %d, Lista 2: %d\n", listA[i], listB[i]);
    }
    printf("\n");
}

void bubbleSort()
{
    int temp;
    int i, j;
    bool swapped = false;

    /* loop de todos os numeros */
    for(i = 0; i < MAX-1; i++)
    {
        swapped = false;

        /* loop nos numeros caindo na frente */
        for(j = 0; j < MAX - 1 - i; j++)
        {
            printf("    Itens comparados: [ %d, %d ]\n", listA[j], listB[j]);

            /* checa se o proximo numero eh menor que o numero atual *
             * troca os numeros. (bubble no numero mais alto)        */
            if(listA[j] > listB[j])
            {
                temp = listA[j];
                listA[j] = listB[j];
                listB[j] = temp;
                swapped = true;
                printf(" => Trocou [ %d, %d ]\n", listA[j], listB[j]);
            }
            else
            {
                printf(" => Nao foi trocado\n");
            }
        }

        /* se nenhum numero foi trocado, significa que o vetor esta organizado, deve-se quebrar o loop */
        if(!swapped)
        {
            break;
        }

        printf("Iteração %d#: \n", (i+1));
        display();
    }
}

int main(void)
{
    printf("Ordenação Bubble em C.\n");
    printf("----------------------\n\n");
    printf("Vetor de Entrada: \n");
    display();
    printf("\n");

    bubbleSort();
    printf("Vetor de Saida: \n");
    display();

    return 0;
}
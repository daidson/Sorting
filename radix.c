
/***************************************************************************
 *   radix.c                                  Version 20170618.171201      *
 *                                                                         *
 *   Radix Sorting Algorithm in C                                          *
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

/* funcao para imprimir o vetor */
void imprimeVetor(int * arrdx, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Numero: %d\n", arrdx[i]);
    }
}

/*funcao para encontrar o maior numero */
int achaMaiorNum(int * arrdx, int size)
{
    int i;
    int maxNum = -1;
    for(i = 0; i < size; i++)
    {
        if(arrdx[i] > maxNum)
        {
            maxNum = arrdx[i];
        }
    }
    return maxNum;
}

/* funcao para fazer a ordenacao radix */
void radix(int * arrdx, int size)
{
    printf("Ordenação Radix em lista desordenada!\n\n");

    /* Uso da base 10 */
    int i;
    int meiaOrdem[size];
    int algarismo = 1;
    int maiorNum = achaMaiorNum(arrdx, size);

    /* Loop para achar o maior algarismo significativo */
    while(maiorNum / algarismo > 0)
    {
        printf("\nOrdenando: %d casa decimal. \n", algarismo);
        imprimeVetor(arrdx, size);

        int balde[10] = {0};

        /* Conta o numero de digitos que vai em cada 'balde' */
        for(i = 0; i < size; i++)
        {
            balde[(arrdx[i]/algarismo) % 10]++;
        }

        /* Adiciona a conta aos baldes anteriores *
         * Pega o indice depois do limite de cada *
         * balde no vetor. Trabalha de maneira eq *
         * uivalente ao algoritmo count sort      */
        for(i = 1; i < 10; i++)
        {
            balde[i] += balde[i - 1];
        }

        /* Usa o balde para preencher o vetor 'meiaOrdem' */
        for(i = size -1; i >= 0; i--)
        {
            meiaOrdem[--balde[(arrdx[i]/algarismo) % 10]] = arrdx[i];
        }

        for(i = 0; i < size; i++)
        {
            arrdx[i] = meiaOrdem[i];
        }

        /* Vai para o proximo algarismo significativo */
        algarismo *= 10;

        printf("\nOrdenacao: \n");
        imprimeVetor(balde, 10);
    }
}

int main(void)
{
    printf("Ordenação Radix em C.\n");
    printf("---------------------\n");

    int size = 12;
    int listA[] = {10, 2, 303, 4021, 293, 1, 0, 429, 480, 92, 2999, 14};

    printf("\nLista desordenada: \n");
    imprimeVetor(&listA[0], size);

    radix(&listA[0], size);

    printf("\nLista ordenada: \n");
    imprimeVetor(&listA[0], size);
    printf("\n");

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:00:29 by achacon-          #+#    #+#             */
/*   Updated: 2023/03/28 13:01:22 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <stdio.h>

bool check(int array[10][10], int i, int j)
{
    bool checkcolum = true;
    bool checkfila = true;
    bool checkdiag1 = true;
    bool checkdiag2 = false;
    int fila, colum;
    fila = 0;
    colum = 0;
    while(colum < 10) //esto comprueba si hay una reina en esa columna
    {
        if (array[i][colum] == 1)
        {
            checkcolum = false;
            break;
        }
        colum ++;
    }
     while(fila < 10) //esto comprueba si hay una reina en esa fila
    {
        if (array[fila][j] == 1)
        {
            checkfila = false;
            break;
        }
        fila ++;
    }
    fila = i;
    colum = j;
    while(colum >= 0 && fila >= 0) //esto pone marcadores en el inicio de la diagonal sup izq
    {
        fila --;
        colum --;
    }
    while(colum <= 9 && fila <= 9) // esto comprueba que no hay reinas en la diagonal 1 (que va de izquierda a derecha, de arriba a abajo)
    {
        if(array[fila][colum] == 1)
        {
            checkdiag1 = false;
            break;
        }
        colum ++;
        fila ++;
    }
    fila = i;
    colum = j;
    while(fila <= 9 && colum <= 9) //esto pone marcadores en el inicio de la diagonal inf der
    {
        fila ++;
        colum ++;
    }
    while(colum >= 0 && fila >= 0) // esto comprueba que no hay reinas en la diagonal 2 (que va de derecha a izquierda abajo a arriba)
    {
        if(array[fila][colum] == 1)
        {
            checkdiag2 = false;
            break;
        }
        colum --;
        fila --;
    }
    if(checkfila == true && checkcolum == true && checkdiag1 == true && checkdiag2 == true)
        return (true);
    return false;

}

int main (void)
{
	int tablero[10][10];
    int posiciones[10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; i++)
		{
			tablero[i][j] = 0; // esto rellena la matriz de 0s
		}
	}
    for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; i++)
		{
			if(check(tablero, i, j) == true)
            {
                tablero[i][j] = 1;
                posiciones[i] = j;
            }
		}
	}
    for (int i = 0; i <= 9; i++)
    {
        printf("%i", posiciones[i]);
    }
}
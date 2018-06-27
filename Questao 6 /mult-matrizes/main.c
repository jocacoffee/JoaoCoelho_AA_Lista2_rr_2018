//
//  main.c
//  mult-matrizes
//
//  Created by João on 26/06/18.
//  Copyright © 2018 João. All rights reserved.
//

#include<stdio.h>
#include<limits.h>

// Matriz Ai tem dimensão p[i-1] x p[i] para i = 1..n
int OrdemDeMatrizes(int p[], int n)
{
    
    /* Para simplicidade do programa, uma linha e uma coluna extras
      são alocadas em m[][].  0-esima linha e 0-esima
     coluna de m[][] não são utilizadas */
    int m[n][n];
    
    int i, j, k, L, q;
    
    /* m[i,j] = O número minimo de multiplicações escalares necessárias
     para computar a matriz A[i]A[i+1]...A[j] = A[i..j] onde
     a dimensção de A[i] é p[i-1] x p[i] */
    
    // custo é zero quando multiplicando uma matriz
    for (i=1; i<n; i++)
        m[i][i] = 0;
    
    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                // q = custo/por multiplicação escalar
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    
    return m[1][n-1];
}

int main()
{
    int arr[] = {4, 3, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("O número mínimo de multiplicações é: %d ",
           OrdemDeMatrizes(arr, size));
    
    getchar();
    return 0;
}

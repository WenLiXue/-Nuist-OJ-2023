#include<stdio.h>
#include<iostream> 
#define N 500
int main()
{
    int m;    
    int n;       
    int lim_t[N];           
    int fine[N];             
    int is_free[N];

    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            is_free[i] = 0;
            scanf("%d", &lim_t[i]);               
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &fine[i]);          ¬¾
        }
        for (int i = 0; i < n - 2; i++)                  
        {
            for (int j = 0; j < n - 2 - i; j++)
            {
                if (fine[j]<fine[j+1])
                {
                    int temp;
                    temp = lim_t[j];
                    lim_t[j] = lim_t[j + 1];
                    lim_t[j + 1] = temp;
                    temp = fine[j];
                    fine[j] = fine[j + 1];
                    fine[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = lim_t[i]; j >= 1; j--)
            {
                if (is_free[j] == 0)
                {
                    is_free[j] = 1;
                    break;
                }
                if (j == 1)
                {
                    m = m - fine[i];         
                }
            }
        }
        printf("%d\n", m);

    }
    return 0;

}
 
 

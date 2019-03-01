#include <stdio.h>
#include <string.h>
 
int main()
{
    int print[1000];
    char dish[31], arr[1000];
    int i, len, k = 0, m = 0, top = 0, plus = 0;
  
    scanf("%s", dish);
 
 
    len = strlen(dish);
 
    while(1)
    {
        if(k == len) break;
        else if(dish[k] == arr[top - 1])
        {
            k++;
            print[m] = 1;
            m++;
            pop_cnt++;
            push_cnt--;
            top--;
        }
 
        else
        {
            arr[top] = 'a' + plus;
            if(plus==len) 
            {
                printf("impossible");
                return 0;
            }
            plus++;
            print[m] = 2;
            m++;
            push_cnt++;
            top++;
        }
 
 
    }
    for(i=0; i<m; i++){
        if(print[i] == 2)
        {
            printf("push\n");
        }
 
        else if(print[i] == 1)
        {
            printf("pop\n");
        }
    }
 
 
 
    return 0;
}
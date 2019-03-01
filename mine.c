#include <stdio.h>
#include <string.h>
  
int main()
{
    int n, i, j, a, b;
    char mine[12][12], click[12][12];
    int cnt = 0, over = 0;
    char print[12][12] ={0, };
  
    scanf("%d", &n);
    getc(stdin);    //scanf 했을 때 뒤에 '\n' 입력되는 것 제거
  
    /* 모든 배열 -1로 초기화 */
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            mine[i][j] = '0';
        }
    }
  
      
    /* 지뢰 설정 */
    for (i = 1; i <= n; i++) {
        gets(mine[i]);
        memmove(mine[i] + 1, mine[i], n);
        mine[i][0] = '0';
    }
  
   // printf("%c", mine[1][2]);
  
  
    /* 클릭 설정 */
    for (i = 1; i <= n; i++) {
        gets(click[i]);
        memmove(click[i] + 1, click[i], n);
        click[i][0] = '0';
    }
  
     
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
 
            if(click[i][j] == 'x' && mine[i][j] == '*')
            {
                for(a=1; a<=n; a++){
                    for(b=1; b<=n; b++){
                        if(mine[a][b] == '*') print[a][b]='*';
                    }
                }
                over = 1;
            }
 
            else if(click[i][j]=='x')
            {
                if(mine[i-1][j-1] == '*') cnt++;
                if(mine[i-1][j] == '*') cnt++;
                if(mine[i-1][j+1] == '*') cnt++;
                if(mine[i][j+1] == '*') cnt++;
                if(mine[i+1][j+1] == '*') cnt++;
                if(mine[i+1][j] == '*') cnt++;
                if(mine[i+1][j-1] == '*') cnt++;
                if(mine[i][j-1] == '*') cnt++;
                 
                print[i][j] = cnt +48;
                cnt = 0;
 
            }
 
            else if(over == 1)
            {
                if(mine[i][j] == '*') print[i][j] = '*';
                else print[i][j] = '.';
            }
 
            else print[i][j] = '.';
        }
    }
     
     for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%c", print[i][j]);
        }
        printf("\n");
     }
  
  
  
      
  
  
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count;

int strmatch(char *text,char *pat,int n,int m)
{
    count=0;
    int i,j;
    for(i=0;i<n-m;i++)
    {
        j=0;
        while(j<m)
        {
            count++;
            if(pat[j]!=text[i+j])
                break;
            j++;
        }
        if(j==m)
        {
            printf("Pattern found\n");
            return count;
        }
    }
        printf("Pattern not found\n");
        return count;
    
}

int main()
{
    int m, n;
    char text[100], pattern[100];
    printf("ENTER THE TEXT LENGTH\n");
    scanf("%d", &n);
    printf("ENTER THE TEXT\n");
    scanf(" %s", text);

    printf("ENTER THE PATTERN LENGTH\n");
    scanf("%d", &m);
    printf("ENTER THE PATTERN\n");
    scanf("%s", pattern);
    
    strmatch(text, pattern, n, m);
    return 0;
}

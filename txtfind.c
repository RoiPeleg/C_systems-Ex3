#include "txtfind.h"
#include <stdio.h>
int getLine(char s[])
{
    int i = 0;
    while (i < LINE && *(s + i) != '\n')
    {
        scanf(" %c", &s);
        *(s + i);
        i++;
    }
    return i;
}
int getWord(char s[])
{
    int i = 0;
    while (i < WORD && (*(s + i) != '\n' || *(s + i) != '\t' || *(s + i) != ' '))
    {
        scanf(" %c", &s);
        *(s + i);
        i++;
    }
    return i;
}
int substring(char *str1, char *str2)
{
    int i = 0, j = 0;

    while (*(str2 + j) != '\0')
    {
        while (*(str1 + i) != '\0')
        {
            if (*(str1 + i) != *(str2 + j))
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    return 0;
}
int similar(char *s, char *t, int n)
{

    char *pointer1 = s;
    char *pointer2 = t;

    while (*pointer1 != '\0' && *pointer2 != '\0')
    {
        if (*pointer1 != *pointer2)
        {
            if(n==0){
                return -1;
            }
            pointer1++;
            n--;
        }
        pointer1++;
        pointer2++;
    }
    return 1;
}
void print_lines(char *str)
{
}
void print_similar_words(char *str)
{
}
int main()
{
}
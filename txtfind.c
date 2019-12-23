#include "txtfind.h"
#include <stdio.h>
int getLine(char s[])
{
    int i = 0;
    char g = ' ';
    while (i < LINE && *(s + i) != '\n')
    {
        g= getc(stdin);
        *(s+i) = g;
        i++;
    }
    return i;
}
int getWord(char s[])
{
    int i = 0;
    char g=' ';
    while (i < WORD && (*(s + i) != '\n' || *(s + i) != '\t' || *(s + i) != ' '))
    {
        g= getc(stdin);
        *(s+i) = g;
        i++;
    }
    return i;
}
int substring(char *str1, char *str2)
{
    int f = 1;
    int k = 0;
    int len1 = 0, len2 = 0;
    while (*(str2 + k) != '\0')
        len2++;
    k = 0;
    while (*(str1 + k) != '\0')
        len1++;
    for (int i = 0; i < len1 - len2; i++)
    {
        f = 1;
        for (int j = i; j < +i + len2; j++)
        {
            if (*(str1 + j) != *(str2 + j - i))
            {
                f = -1;
                break;
            }
        }
        if (f == 1)
            return 1;
    }
        return -1;
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
    char s[LINE] = {'0'};
    while (*s != EOF)
    {
        if (substring(s, str))
        {
            printf("%s", s);
        }

        getLine(s);
    }
}
void print_similar_words(char *str)
{
    char s[WORD] = {'0'};
    while (*s != EOF)
    {
        if (similar(s, str, 1))
        {
            printf("%s", s);
        }
        getWord(s);
    }
}
int main()
{
    char s[WORD] = {};
    char *ptr = s;
    getWord(ptr);
    char *wordtosearch = s;
    ptr = s;
    getWord(ptr);
    char option = *s;
    getLine(s);
    if (option == 'a')
    {
        print_lines(wordtosearch);
    }
    else if (option == 'b')
    {
        print_similar_words(wordtosearch);
    }
    else
    {
        printf("%c is not valid", option);
    }

    return 0;
}
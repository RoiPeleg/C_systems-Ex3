#include "txtfind.h"
#include <stdio.h>
int getLine(char s[])
{
    int i = 0;
    char g = ' ';
    g= getc(stdin);
    if(g==EOF)return 0;
    while (i < LINE && g != '\n' && g!=EOF)
    {
        *(s+i) = g;
        g= getc(stdin);
        i++;
    }
    *(s+i) = '\0';
    i--;
    return i;
}
int getWord(char s[])
{
    int i = 0;
    char g = getc(stdin);
    while(g==' '|| g=='\t'||g=='\n')g=getc(stdin);
    while (i < WORD &&  g != ' ' && g != '\t' && g != '\n' && g!=EOF)
    {
        *(s+i) = g;
        g = getc(stdin);
        i++;
    }
    *(s+i)='\0';
    return i;
}
int substring(char *str1, char *str2)
{
    int f = 0;
    int len1 = 0, len2 = 0;
    while (*(str2 + len2) != '\0'){
        len2++;
    }
    while (*(str1 + len1) != '\0')
    {
        len1++;
    }

    for (int i = 0; i < len1; i++)
    {
        f=1;
        for (int j = 0; j < len2; j++)
        {
            if(*(str1+i+j)!=*(str2+j))
            {
                f=0;
            }
        }
        if(f==1) return 1;
    }
    /*
    for (int i = 0; i < len1 - len2; i++)
    {
        f = 1;
        for (int j = i; j < i + len2; j++)
        {
            if (*(str1 + j) != *(str2 + (j - i)))
            {
                f = 0;
            }
        }
        
        if (f == 1)
            return 1;
    }
    */
    return 0;
}
int similar(char *s, char *t, int n)
{
     int lens=0;
    while (*(s+lens) != '\0')lens++;
     int lent=0;
    while (*(s+lent) != '\0')lent++;
    //if(lens < lent)return 0;
    char *pointer1 = s;
    char *pointer2 = t;

    while (*pointer1 != '\0')
    {
        if (*pointer1 != *pointer2)
        {
            if(n==0){
                return 0;
            }
            pointer1++;
            n--;
        }
        pointer1++;
        pointer2++;
    }
    if(*pointer1 == '\0' && *pointer2 == '\0'&&n==0){
    return 1;
    }
    return 0;
}
void print_lines(char *str)
{
    char s[LINE] = {'\0'};
    char* ptr = s;
    int l = getLine(ptr);
    while (l)
    {
        if (substring(s, str))
        {
            printf("%s\n",s);
        }
        ptr = s;
        l = getLine(ptr);
    }
}
void print_similar_words(char *str)
{
    int l = 1;
    char s[WORD] = {' '};
    while (l)
    {
        l = getWord(s);
        if (similar(s, str, 1)||similar(s,str,0))
        {
            printf("%s\n",s);
        }
    }
}
int main()
{
    char s[WORD] = {'\0'};
    char *ptr = s;
    char wordtosearch[WORD]= {' '};
    int size = getWord(ptr);
    int i=0;
    for (i = 0; i <= size; i++)
    {
        *(wordtosearch+i) = *(s+i);
    }
    *(wordtosearch+i+1) ='\0';
    ptr = s;
    char option = ' ';
    option = getc(stdin);
    getc(stdin);
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
        printf("%c is not valid \n", option);
    }
    return 0;
}
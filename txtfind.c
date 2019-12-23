#include "txtfind.h"
#include <stdio.h>
int getLine(char s[]){
    int i=0;
    while (i<LINE && *(s+i)!='\n')
    {
    scanf(" %c",&s);
    *(s+i);
    i++;
    }
    return i;
}
int getWord(char s[])
{
    int i=0;
    while (i<WORD && (*(s+i)!='\n'|| *(s+i)!='\t' || *(s+i)!=' '))
    {
    scanf(" %c",&s);
    *(s+i);
    i++;
    }
    return i;
}
int substring( char * str1, char * str2)
{
    int i=0,j=0;

     while (*(str2+j) != '\0'){
          while (*(str1+i) != '\0')
          {
              if(*(str1+i)!=*(str2+j))
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
int similar (char *s, char *t, int n){
return 0;
}
void print_lines(char * str){

}
void print_similar_words(char * str)
{

}
int main()
{
    
}
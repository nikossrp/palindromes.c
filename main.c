#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
char* Input;    

int Match(char c, char d)
{
    return c == d;
}


char *Keepletters(char *str)    
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >='A' && str[i] <= 'Z')) 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
}

// for the lower letters
void mikra(char* str)
{ 
    int i = 0;
    while(str[i]){
    if (str[i] >= 'A' && str[i] <= 'Z')
    str[i] = str[i] - ('A'-'a'); 
    i++;
    }
}

int main()
{
    int i=0, j=0, k = 0;
    
    
    char word[100] ;
    char ch;
    char temp;
    char* InitializeArray;
    int slen;
    Input = (char*)malloc(100);
    Stack S;
    FILE* file = fopen("palindromes.txt", "r");

 if(file)    
  while(ch != EOF){
       InitializeStack(&S);
        
        i = 0;
        j = 0;
        k = 0;
        Input = (char*)malloc(100);
        InitializeArray = Input;
        while((ch = getc(file)) != EOF) { 
            if(ch == '\n') break;
             InitializeArray[k++] = ch;            //put the first sentence in an array
             
        }

        strcpy(word, Input);
        Keepletters(Input);    //ignore white spaces , punctuation
        mikra(Input);       //convert lower letters
        slen = strlen(Input);
        printf("%s  ", word);
        if(slen%2 == 0){    
            for(i = 0; i < slen/2; i++) 
                Push(&S, Input[i]);
        i = slen/2;
        j = i;
        
            while(i--){
                Pop(&S, &temp);
                if(temp != Input[j++]) { 
                    printf("Non-Palindrome!\n");
                    break;
                }
            }
            if(Empty(&S)) printf("Palindrome!\n");
           

        } else {        //an einai peritos
            for( i = 0; i < (int)slen/2; i++)   
                Push(&S, Input[i]);
            i = (int)slen/2;
            j = i+1;        //ignore the middle letter
            while(i--){
                Pop(&S, &temp);
                if(temp != Input[j++]) { 
                    
                    printf("Non-Palindrome!\n");
                    break;
                }
            }
            if(Empty(&S)) printf("Palindrome!\n");
        }

     } else printf("palindromes.txt not exist!!\n");
    free(Input);
    
}

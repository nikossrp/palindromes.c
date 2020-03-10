#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h" 

char *Keepletters(char *str)    //krataei mono ta grammata
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if((str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >='A' && str[i] <= 'Z')) //an einai kati diaforetiko apo xarakthra to agnwei
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
}

void mikra(char* str)  //metatroph olhs thn sumboloseira se mikra
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
    char*  Input = (char*)malloc(100);  //o pinakas gia na kratame thn sumboloseira
    char temp;
    int slen;
    Stack S;  
       
    InitializeStack(&S);
    i = 0;
    j = 0;
    
    scanf("%[\n^]s", Input);        //read until '/n'

    Keepletters(Input);    //agnohsh kenwn , shmeia stixeis k.o.k
     
    mikra(Input);       //metatropi ola se mikra gramata
    
    slen = strlen(Input);   //upologizoume to mhkos tis sumboloseiras

    if(slen%2 == 0){    //an einai artios plhthos apo grammata
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
        
        } else { 

            for( i = 0; i < (int)slen/2; i++)   
                Push(&S, Input[i]);

            i = (int)slen/2;
            j = i+1;        //agnooume to mesaio stoixeio
            
            while(i--){
                Pop(&S, &temp);
                if(temp != Input[j++]) {         
                    printf("Non-Palindrome!\n");
                    break;
            }
        }

        if(Empty(&S)) printf("Palindrome!\n");
        }

   //     free(Input);
 
}
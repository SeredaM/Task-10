#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delsp(char *s)
{
 char newstr[100]="";
 char *word;
 word = strtok(s,". ");
 while (word != NULL)
 {
     strcat(newstr,word);
     strcat(newstr," ");
     word = strtok(NULL,". ");
 }
strcpy(s,newstr);
}
void delw(char *s)
{
 char newstr[100]="";
 char *temp;
 char copy[100];
 char lastword[50];
 char *word;
 strcpy(copy,s);
 temp = strtok(copy,". ");

 while (temp != NULL)
 {
     strcpy(lastword,temp);
     temp = strtok(NULL,". ");
 }
 word = strtok(s,". ");
 while (word != NULL)
 {
     if (strcmp(word,lastword)!=0)
     {
     strcat(newstr,word);
     strcat(newstr," ");
     }
     word = strtok(NULL,". ");
 }
 strcpy(s,newstr);
}
void changew(char *s)
{
 char *t;
 char nw[20]="";
 char newstr[100]="";
 t=strtok(s," ");
 int j=0;
 while (t!=NULL)
 {
     for (int i = 0;i<strlen(t);i++)
     {

       if (strchr(nw,(int)(t[i]))==NULL)
       {
           nw[j]=t[i];
           j++;
       }
     }
     strcat(newstr,nw);
     strcat(newstr," ");
     for (int k=0;k<j;k++) nw[k]='\0';
     j=0;
     t=strtok(NULL," ");
 }

 strcpy(s,newstr);
}

int main()
{
    char s[100],s2[100];
    FILE *file_in, *file_out;
    printf("Enter file name/path for reading: \n");
    gets(s);
    file_out=fopen(s,"r");
     printf("Enter file name/path for saving: \n");
    gets(s2);
    file_in=fopen(s2,"w");
    fgets(s,100,file_out);
    delsp(s);
    fputs(s,file_in);
    fputs("\n",file_in);
    delw(s);
    fputs(s,file_in);
    fputs("\n",file_in);
    changew(s);
    fputs(s,file_in);
    fputs("\n",file_in);
}

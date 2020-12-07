#include <stdio.h>
#include <stdlib.h>

void delsp (char *s)
{
    int j=0;
  char s2[100];
  for (int i=0;i<100;i++)
  {
      if (s[i]!=' ')
      {
          s2[j]=s[i];
          j++;
      }
      else
      {
          if ((s2[j-1]!=' ')&&(j>0))
          {
              s2[j]=' ';
              j++;
          }

      }
  }
  strcpy(s,s2);
}
void delword(char *s)
{
  int j=0,l=0,i;
  char w[100];
  i=strlen(s)-1;
  while (s[i]!=' ')
  {
  l++;
  i--;
  }
  for (int i=strlen(s)-l;i<=strlen(s)-1;i++)
  {
    w[j]=s[i];
    j++;
  }
  w[j+1]='\0';
  j=0;
  for (int i=0;i<strlen(s);i++)
  {
      int k=i;
      while ((w[j]==s[k])&&(k<strlen(s)))
      {
        j++;
        k++;
      }
      if (((j==l)&&((s[k]==' ')||(k==strlen(s))))&&((s[i-1]==' ')||(i==0)))
        for (int q=i;q<k;q++)
          s[q]=' ';
      j=0;
  }
  delsp(s);

}
void changewords(char *s)
{
    char temp[100], snew[100];
    int j=0,f=0,l;
    strcpy(temp,"");
    strcpy(snew,"");
    for (int i=0;i<strlen(s);i++)
    {
       if (s[i]!=' ')
       {
           l=j;
           if (j==0)
            {
                 temp[j]=s[i];
                 j++;
            }
           for (int k=0;k<l;k++)
           {
               if (temp[k]==s[i])
               {
                s[i]=' ';
               }
                else
                {
                 temp[j]=s[i];
                 j++;
                }
           }
       }
       else
       {
         strcpy(temp,"");
         j=0;
       }
    }
delsp(s);
}
int main()
{
    char s[100],s2[100];
    FILE *file_in, *file_out;
    printf("Enter file name/path for reading: \n");
    gets(s);
    file_out=fopen(s,"r");
    fgets(s,100,file_out);
    printf("Your srting: \n");
    puts(s);
    delsp(s);
    delword(s);
    changewords(s);
    printf("New string: \n");
    puts(s);
    printf("Enter file name/path for saving the string: \n");
    gets(s2);
    file_in=fopen(s2,"w");
    fputs(s,file_in);
}

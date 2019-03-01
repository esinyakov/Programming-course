#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    const int n =500;
    char c[n];
    int i,j,wordcount=0,maxlength=0;

    for(i=0,j=0;c[i] = getchar();i++)
    {
        if (c[i] != ' ')
        {
            j++;
            if (j>maxlength) maxlength=j;
        }
        else j=0;

        if ((i !=0 && c[i] == ' ' && c[i-1] != ' ')||(c[i]=='\n' && c[i-1]!=' ')) wordcount++;
        if(c[i]=='\n')
        {
            c[i]=' ';
            break;
        }
    }


    char** str = (char**)malloc(wordcount*sizeof(char*));

    for(i=0;i<wordcount;i++)
    {
        str[i]=(char*)malloc(maxlength*sizeof(char));
    }


    str[0]=strtok (c, " ");
    i=1;

    while (str[i] !=NULL && i<wordcount)
    {
        str[i] = strtok (NULL," ");
        i++;
    }

    char* tmp1;
    for (i=0;i<wordcount-1;i++)
    {
        for (j=0;j<wordcount-1-i;j++)
        {
            if(strcmp(str[j],str[j+1])>0)
            {
                tmp1 = str[j+1];
                str[j+1]=str[j];
                str[j]=tmp1;
            }
        }
    }

    for(i=0;i <wordcount;i++)
    {
        printf("\n%s\n",str[i]);
    }

    getch();
}

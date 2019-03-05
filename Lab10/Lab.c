#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    const int n =15;
    struct workers
    {
        int id;
        char name[3];
        int professioncode;
    } w[n];

    int i,j, r1 = 25,r2=6;

    srand((unsigned)time(NULL));

    for (i = 0; i<n;i++)
    {
        w[i].id=i;
        for (j=0;j<3;j++)
        {
            w[i].name[j]=((char)(rand()%r1)+97);
        }
        w[i].name[3]='\0';
        w[i].professioncode=(int)(rand()%r2);
    }

    int k[6]={0};
    for (i = 0; i<n;i++)
    {
        printf("worker id: %d name: %s professioncode: %d\n",w[i].id,w[i].name,w[i].professioncode);
        switch (w[i].professioncode)
        {
            case 0: k[0]++; break;
            case 1: k[1]++; break;
            case 2: k[2]++; break;
            case 3: k[3]++; break;
            case 4: k[4]++; break;
            case 5: k[5]++; break;
        }
    }

    int imax=0,max = k[0];
    for(i=0;i<6;i++)
    {
        if(k[i]>max)
        {
            max = k[i];
            imax =i;
        }
    }

    printf("most popular professioncode: %d",imax);
    getch();

}

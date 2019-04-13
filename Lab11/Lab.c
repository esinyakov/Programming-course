#include <stdio.h>

int main ()
{
    struct cars
    {
        int id;
        char detail[10];
        int weight
    } c[5];
    FILE* fp;

    int i,car;
    int weight = 0;
    char *fname1 = "C:\\Users\\Evgeny\\Documents\\Programming-course\\Lab11\\cars.txt";

    fp = fopen(fname1,"r");

    for(i=0;i<5;i++)
    {
        fscanf(fp,"%d %s %d",&c[i].id,c[i].detail,&c[i].weight);
    }

    fclose(fp);

    for(i=0;i<5;i++)
    {
        printf("car id: %d detail: %s weight: %d\n",c[i].id,c[i].detail,c[i].weight);
    }

    char *fname2 = "C:\\Users\\Evgeny\\Documents\\Programming-course\\Lab11\\detail.txt";

    printf("enter car number\n");
    scanf("%d",&car);

    fp = fopen(fname2,"w");
    for(i=0;i<5;i++)
    {
        if(c[i].id==car)
        {
            fprintf(fp,"car id: %d detail: %s weight: %d\n",c[i].id,c[i].detail,c[i].weight);
            weight+=c[i].weight;
        }
    }
    fprintf(fp,"sum details weight: %d\n",weight);
    fclose(fp);
    getch();
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"hash.h"

int main()
{
    struct timespec start1,start2,start3,end1,end2,end3;
    int n,key;
    int collis1=0,collis2=0,collis3=0;
    scanf("%d",&n);
    int *input=(int*)malloc(sizeof(int)*n);
    node *sc[n];
    int *lp=(int *)malloc(sizeof(int)*n);
    int *dh=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        sc[i]=NULL;
        lp[i]=-1;
        dh[i]=-1;
    }
    scanf("%d",&key);

    
     clock_gettime(CLOCK_REALTIME,&start1);
    
     for(int i=0;i<n;i++)
     {
         if(input[i]==-1)
         {
             break;
         }
         int index=hashfunc(input[i],n);
         int add=seperatechaining(n,sc,index,input[i]);
         collis1+=add;
     }
     int index1=findsp(n,sc,key);

     clock_gettime(CLOCK_REALTIME,&end1);
     unsigned long long timeinnanoseconds1=end1.tv_nsec-start1.tv_nsec;


    
    clock_gettime(CLOCK_REALTIME,&start2);

    for(int i=0;i<n;i++)
    {
        if(input[i]==-1)
        {
            break;
        }
        int index=hashfunc(input[i],n);
        if(lp[index]!=-1)
        {
            collis2++;
            index=linearprobing(index,lp,n);
        }
        lp[index]=input[i];
    }
    int index2=findlp(lp,n,key);

    clock_gettime(CLOCK_REALTIME,&end2);
	unsigned long long timeinnanoseconds2=end2.tv_nsec-start2.tv_nsec;



     clock_gettime(CLOCK_REALTIME,&start3);

     for(int i=0;i<n;i++)
     {
         if(input[i]==-1)
         {
             break;
         }
         int index=hashfunc(input[i],n);
         if(dh[index]!=-1)
         {
             collis3++;
             index=doublehash(dh,n,index,input[i]);
         }
         if(index!=-1)
         {
             dh[index]=input[i];
         }
     }
     int index3=finddh(dh,n,key);

     clock_gettime(CLOCK_REALTIME,&end3);
     unsigned long long timeinnanoseconds3=end3.tv_nsec-start3.tv_nsec;

    


     printf("\n\n");

    


     printf("For seperate chaining :\n");
    
     printf("Hash table is -\n");
     for(int i=0;i<n;i++)
     {
         while(sc[i]!=NULL)
         {
             printf("%d ",sc[i]->data);
             sc[i]=sc[i]->link;
         }
         printf("\n");
     }

     printf("Collisions : %d\n",collis1);

     if(index1==-1)
     {
         printf("Element not found\n");
     }
     else
     {
         printf("Index : %d\n",index1);
     }

     printf("Time : %llu\n",timeinnanoseconds1);


     printf("\n\n");


    printf("For linear probing :\n");
    
    printf("Hash table is -\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",lp[i]);
    }

    printf("Collisions : %d\n",collis2);

    if(index2==-1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Index : %d\n",index2);
    }

    printf("Time : %llu\n",timeinnanoseconds2);


    printf("\n\n");


     printf("For double hashing :\n");

     printf("Hash table is -\n");
     for(int i=0;i<n;i++)
     {
         printf("%d\n",dh[i]);
     }

     printf("Collisions : %d\n",collis3);
    
     if(index3==-1)
     {
         printf("Element not found\n");
     }
     else
     {
         printf("Index : %d\n",index3);
     }

     printf("Time : %llu\n",timeinnanoseconds3);
}

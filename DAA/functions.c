#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"hash.h"

int hashfunc(int x,int n)
{
    x=pow(x,2);
    int sum_of_digits=0;
    while(x)
    {
        int y=x%10;
        sum_of_digits+=y;
        x=x/10;
    }
    return sum_of_digits%n;
}


int seperatechaining(int n, node *a[n],int index,int x)
{
    if(a[index]==NULL)
    {
        a[index]=(node *)malloc(sizeof(node));
        a[index]->link=NULL;
        a[index]->data=x;
        return 0;
    }
    else
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->link=a[index];
        temp->data=x;
        a[index]=temp;
        return 1;
    }
}

int linearprobing(int index,int *a,int n)
{
    while(a[index]!=-1)
    {
        index=(index+1)%n;
    }
    return index;
}

int hashfunc2(int x)
{
    return (7-(x%7));
}
int doublehash(int *dh,int n,int index,int x)
{
    int index1=index;
    int i=1;
    int ele_index=hashfunc2(x);
    while(dh[index1]!=-1 && i<n+20)
    {
        index1=(index+i*ele_index)%n;
        i++;
    }
    if(i==n+20 && dh[index1]!=-1)
    {
        return -1;
    }
    return index1;
}

/*int quadprobing(int index,int *a,int n)
{
    int i;
    int flag;
    for(i=0;i<(n-1)/2;i++)
    {
        if(a[(index+pow(i,2))%n]==-1)
        {
            break;
            flag=0;
        }
        else if(a[abs(index-pow(i,2))%n]==-1)
        {
            break;
            flag=1;
        }
    }
    if(flag==0)
    {
        return ((index+pow(i,2))%n);
    }
    else if(flag==1)
    {
        return (abs(index-pow(i,2))%n);
    }
}*/




int findsp(int n,node *a[n],int key)
{
    int index=hashfunc(key,n);
    node *temp=a[index];
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return index;
        }
        temp=temp->link;
    }
    return -1;
}


int findlp(int *a,int n,int key)
{
    int index=hashfunc(key,n);
    for(int i=0;i<n;i++)
    {
        int x=(index+i)%n;
        if(a[x]==key)
        {
            return x;
        }
        else if(a[x]==-1)
        {
            return -1;
        }
    }
    return -1;
}


int finddh(int *a,int n,int key)
{
    int index=hashfunc(key,n);
    int ele_index=hashfunc2(key);
    int i=1;
    int index1=index;
    while(a[index1]!=key && i<n+20)
    {
        index1=(index+i*ele_index)%n;
        i++;
    }
    if(i==n+20 && a[index1]!=key)
    {
        return -1;
    }
    return index1;
}

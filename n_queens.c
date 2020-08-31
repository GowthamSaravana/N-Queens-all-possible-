#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
int n;
bool issafe(int arr[][n],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        if(arr[i][c]==1)
            return false;
    }
    for(i=r,j=c;i>=0 && j>=0;i--,j--)
    {
        if(arr[i][j]==1)
            return false;
    }
    for(i=r,j=c;i>=0 && j<n;i--,j++)
    {
        if(arr[i][j]==1)
            return false;
    }

    return true;

}
void nqueensol(int arr[][n],int r)
{
    if(r==n)
    {
        for(int i=0;i<n;i++,printf("\n"))
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",arr[i][j]);
            }
        }
        printf("\n");
        return;
    }

        for(int i=0;i<n;i++)
        {
            if(issafe(arr,r,i))
            {
                arr[r][i]=1;

                nqueensol(arr,r+1);

                arr[r][i]=0;

            }
        }
}
int main()
{
    printf("Enter the value of array");
    scanf("%d",&n);
    int nqueen[n][n];
    memset(nqueen,0,sizeof nqueen);
    nqueensol(nqueen,0);

    return 0;
}

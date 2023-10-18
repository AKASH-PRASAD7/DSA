#include<stdio.h>
void bubblesort(float r[],int w[], int p[],int n){
    int temp;
    for (int i = 0; i < n; i++)
    {
       for (int j = i+1; i < n; i++)
       {
           if(r[j]>r[i]){
               temp=r[j];
               r[j]=r[i];
               r[i]=temp;

               temp=w[j];
               w[j]=w[i];
               w[i]=temp;

               temp=p[j];
               p[j]=p[i];
               p[i]=temp;



           }
       }
       
    }
    

}
void show(float r[],int w[], int p[],int n){
    
    //printf("ITEM ");
    //for (int i = 0; i < n; i++)
    //{
        
      //  printf(" %d ",i);
       
        
        
        
    //}
    printf("\nWEIGHT");
    for (int i = 0; i < n; i++)
    {
         
        
         printf(" %d ",w[i]);
    }
   // printf("\nPROFIT ");
    //for (int i = 0; i <n; i++)
    //{
       //printf(" %d ",p[i]);
    //}
   // printf("\nRATIO ");
    //for (int i = 0; i <n; i++)
    //{
       //printf(" %d ",r[i]);
    //}
    
    
    
}
int main()
{
   int n,m;
   printf("ENTER NUMBER OF ITEMS: ");
   scanf("%d",&n);
   printf("\nENTER TOTAL CAPACITY: ");
   scanf("%d",&m);
   int w[n],p[n];
   float r[n];
   for (int i = 1; i <=n; i++)
   {
      printf("ENTER ITEM %d WEIGHT AND PROFIT: ",i);
      scanf("%d %d",&w[i],&p[i]);
      printf("\n");

   }
   for (int i = 1; i <=n; i++)
   {
       r[i]=p[i]/w[i];
     

   }
   bubblesort(r,w,p,n);
   show(r,w,p,n);
   
   
   int i=1;
   //while(m!=0){
      // printf("ITEM  %d WEIGHT %d AND PROFIT %d ",i,w[i],p[i]);
       //printf("\n");
       //i++; m=m-w[i];
  // }


   

return 0;
}
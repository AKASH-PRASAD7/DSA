# include<stdio.h>
# define Max 100
void knapsack(int n, int item[], float weight[], float profit[], float capacity)
{
float x[Max], tp = 0;
int i, j, u,rem[Max];
u = capacity;
for (i = 0; i < n; i++)
x[i] = 0.0;
for (i = 0; i < n; i++)
{
if (weight[i] > u)
break;
else
{
x[i] = 1.0;
rem[i] = u;
tp = tp + profit[i];
u = u - weight[i];
}
}
if (i < n)
x[i] = u / weight[i];
tp = tp + (x[i] * profit[i]);
printf("\n\n The Resultant knapsack contains items in ratio :- ");
for(i=0;i<n;i++)
{
printf("\n ITEM %d - %.3f , Remaining Capacity: %d \n",item[i],x[i],rem[i]);
}
printf("\n\n Maximum Profit is :- %.3f", tp);
}
int main()
{
int num, i, j,c=0,item[Max];
float ratio[Max],weight[Max], profit[Max],capacity, temp;
printf("Enter the No. of Item :- ");
scanf("%d", &num);
printf("\nEnter the Weight and Profits of each Item :- \n");
for (i = 0; i < num; i++)
{
scanf("%f %f", &weight[i], &profit[i]);
}
printf("\nEnter the Capacity of Knapsack :- ");
scanf("%f", &capacity);
for(i=0;i<num;i++)
{
item[i]= ++c;
}
for (i = 0; i < num; i++)
{
ratio[i] = profit[i]/weight[i];
}
for (i = 0; i < num; i++)
{
for (j = i + 1; j < num; j++)
{
if (ratio[i] < ratio[j])
{
temp = item[i];
item[i] = item[j];
item[j] = temp;
temp = ratio[j];
ratio[j] = ratio[i];
ratio[i] = temp;
temp = weight[j];
weight[j] = weight[i];
weight[i] = temp;
temp = profit[j];
profit[j] = profit[i];
profit[i] = temp;
}
}
}
printf("\n The Table After Sorting based on the Ratio: \n");
printf("\nItem:\t\t");
for(i=0;i<num;i++)
{
printf("%d\t",item[i]);
}
printf("\nProfit:\t\t");
for(i=0;i<num;i++)
{
printf("%.f\t",profit[i]);
}
printf("\nWeight:\t\t");
for(i=0;i<num;i++)
{
printf("%.f\t",weight[i]);
}
printf ("\nRATIO:\t\t");
for (i = 0; i < num; i++)
{
printf ("%.2f\t", ratio[i]);
}
knapsack(num, item, weight, profit, capacity);
return 0;
}
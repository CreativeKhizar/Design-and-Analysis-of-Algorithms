#include<stdio.h>
void main()
{
	float w[20],p[20];
	float vd[20];
	float benefit=0.0;
	float tw=0;
	float mw;
	int i,j,n;
	float temp;
	printf("Enter the maximum weight : ");
	scanf("%f",&mw);
	printf("Enter the total number of items : ");
	scanf("%d",&n);
	
	printf("Enter the weight of the items\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	
	printf("Enter the profits for items\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i]);
	}
	
	
	// Value Density
	
	for(i=0;i<n;i++)
	{
		vd[i]=p[i]/w[i];
	}
	
	// Sorting by value density
	
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(vd[j]<vd[j+1])
			{
				temp=vd[j];
				vd[j]=vd[j+1];
				vd[j+1]=temp;
				
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
			if(tw+w[i]>=mw)
			{
				break;
			}
			tw+=w[i];
			benefit+=p[i];
	}
	benefit+=(mw-tw)*vd[i];
	printf("Benefit is %f",benefit);
	
}

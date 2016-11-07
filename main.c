/*Use Union Find*/

#include<stdio.h>
#define MAX 50000

int par[MAX+1];
int student[MAX + 1];

int FindPar(int i)
{
	if (par[i] != i)
		par[i] = FindPar(par[i]);
	return par[i];
}

/*int query(int a, int b)
{
	return FindPar(a) == FindPar(b);
}*/

void merge(int a, int b)
{
	int i = FindPar(a);
	int j = FindPar(b);
	if (i == j)
		return;
	else
	{
		student[i] += student[j];
		par[j] = i;
	}
}

int main(void)
{
	int num;
	int pair;
	int a, b,k;
	int result;
	int kcase = 0;
	scanf("%d %d", &num, &pair);
	while ((num != 0) && (pair != 0))
	{
		kcase++;
		for (k = 1; k <=num; k++)
		{
			par[k] = k;
			student[k] = 1;
		}
		for ( k = 1; k <=pair; k++)
		{
			scanf("%d %d",&a,&b);
			merge(a, b);
		}
		
		result = num;
		for ( k = 1; k <=num; k++)
			if ( FindPar(k)==k && student[k]>1 )
				result = result - student[k]+1;
		printf("Case %d: %d\n",kcase, result);
		scanf("%d %d", &num, &pair);
	}

	getchar();
	return 0;
}

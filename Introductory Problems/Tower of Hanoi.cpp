#include <stdio.h>
long long int count =1;
void hanoi(int n, int start, int end)
{
	if(n==1)
	{
		printf("%d %d\n",start, end);
		return;
	}
	else{
		int i = --n;
		hanoi(i,start,6-start-end);
		printf("%d %d\n",start, end);		
		hanoi(i,6-start-end,end);	
	}
}
 
int main() 
{
	int k,starting,ending;
	scanf("%d",&k);
	printf("%d\n", (count<<k) -1);
	hanoi(k,1,3);
 
	return 0;
}


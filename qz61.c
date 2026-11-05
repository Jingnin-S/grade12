#include <stdio.h>
int josephus(int n, int k) { 
	//¡ï¡ï¡ïÇë²¹È«´úÂë
    if(n==1)
        return 1;
    return (josephus(n-1,k)+k-1)%n+1;

}


int main() 
{
    int n, k;
    scanf("%d%d", &n, &k);
printf("%d %d %d\n", n, k, josephus(n, k));

return 0;
}

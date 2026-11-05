#include<stdio.h>
float findMax(float A[], int i, int j)
{
//★★★请补全代码
    float max=0;
    if(j==0)
        return A[0];
    if( A[i]>=max&&i<=j)
    {
        max=A[i];
        if(i<j)
        { 
            return findMax(A,i+1,j);
        
        }
    }
    
    return max;
}
	
int main() {
	int i,n = 10;
	float A[10];
for(i=0; i<n; i++)
   scanf("%f", &A[i]);
	float max = findMax(A, 0, n - 1);
	printf("最大值：%.2f\n", max);
}



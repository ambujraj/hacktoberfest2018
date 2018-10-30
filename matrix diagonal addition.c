#include <stdio.h>
main(){
int i,j,k,sum=0,ullu=0;
scanf("%d",&i);
int a[i][i];
for(k=0;k<=(i-1);k++){
    for(j=0;j<=(i-1);j++)
        scanf("%d",&a[k][j]);
}
for(j=0;j<=(i-1);j++)
    sum=sum+a[j][j];
k=(i-1);
for(j=0;j<=(i-1);j++){
    ullu=ullu+a[j][k];
    k--;
}
if(ullu>sum)
    sum=ullu-sum;
else
    sum=sum-ullu;
printf("%d",sum);
}

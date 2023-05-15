#include<stdio.h>
int main(){
    int alloc[100][100];
    int max[100][100];
    int available[100];
    int need[100][100];
    int a,n,k;
    printf("enter no. of processes\n");
    scanf("%d",&n);
    printf("enter no. of instances\n");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        printf("write no. of allocated resources for %dP\n",i);
        for(int j=0;j<k;j++){
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        printf("write no. of max resources for %dP\n",i);
        for(int j=0;j<k;j++){
            scanf("%d",&max[i][j]);
        }
        printf("\n");
    }
    printf("write available resources\n");
    for(int i=0;i<k;i++){
          scanf("%d",&available[i]);
    }
    int avail[3] = {3, 3, 2};
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++){
        f[k] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (int k = 0; k < 5; k++){
        for (int i = 0; i < n; i++){
            if (f[i] == 0){
                int flag = 0;
                for (int j = 0; j < n; j++){
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    ans[ind++] = i;
                    for (y = 0; y < n; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++){
        if (f[i] == 0){
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }
    if (flag == 1){
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }
    return (0);
}

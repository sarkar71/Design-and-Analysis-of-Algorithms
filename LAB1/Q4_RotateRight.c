#include<stdio.h>
int main(){
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    int ans[n];
    ans[0] = arr[k - 1];
    for(int i = 1; i < k; i++){
        ans[i] = arr[i - 1];
    }
    for(int i = k; i < n; i++){
        ans[i] = arr[i];
    }

    for(int i = 0; i < n; i++){
       printf("%d ", ans[i]); 
    }
}
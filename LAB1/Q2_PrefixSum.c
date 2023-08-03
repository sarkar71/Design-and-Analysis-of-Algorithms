#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n], pref[n + 1];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i <= n; i++){
        pref[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        pref[i] = arr[i - 1] + pref[i - 1];
        printf("%d ", pref[i]);
    }   
}
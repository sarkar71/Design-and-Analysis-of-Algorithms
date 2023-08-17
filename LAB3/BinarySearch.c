#include<stdio.h>
int binarySearch(int arr[], int n, int k){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] > k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return -1;
}
int main(){
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    scanf("%d", &key);
    int ans = binarySearch(arr, n, key);
    if(ans != -1)
    printf("Index of %d is: %d", key, ans);
    else
    printf("Element not found");
}
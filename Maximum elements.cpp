#include <stdio.h>
int maxElement(int arr[], int n) {
 if (n == 1) return arr[0];
 int max = maxElement(arr, n - 1);
 return (arr[n - 1] > max) ? arr[n - 1] : max;
}
int main() {
 int arr[] = {10, 324, 45, 90, 9808};
 int n = sizeof(arr) / sizeof(arr[0]);
 printf("Maximum element in the array: %d\n", maxElement(arr, n));
 return 0;
}

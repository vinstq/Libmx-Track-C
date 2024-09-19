#include "libmx.h"

int partition(char **arr, int left, int right, int *count) {
    int pivot_id = left + (right - left) / 2;
    int i = left;
    int j = right;

    while(i <= j) {
        while(mx_strlen(arr[i]) < mx_strlen(arr[pivot_id])) {
            i++;
        }
        while(mx_strlen(arr[j]) > mx_strlen(arr[pivot_id])) {
            j--;
        }

        if(i <= j) {
            if(mx_strlen(arr[i]) != mx_strlen(arr[j])) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                (*count)++;
            }
            i++;
            j--;
        }
    }
    return i;
}

int mx_quicksort(char **arr, int left, int right) {
    if(!arr) {
        return -1;
    }

    int count = 0;

    if(left < right) {
        int pivot_id = partition(arr, left, right, &count);
        count += mx_quicksort(arr, left, pivot_id - 1);
        count += mx_quicksort(arr, pivot_id, right);
    }

    return count;
}





#include <stdio.h>
#include <string.h>

int get_back(int* arr, int arr_length) {
    return arr[arr_length - 1];
}

int get_front(int* arr){
    return arr[0];
}

int* push_back(int* arr, int arr_length, int value){
    int *result_arr;
    
    int temp_arr[arr_length + 1];
    memcpy(temp_arr, arr, sizeof(arr));
    temp_arr[arr_length] = value;
    result_arr = temp_arr;
    
    return result_arr;
    
}

int main() {
    int result[3] = {0};
    int* temp =  push_back(result, 1,2);
    int* temp1 =  push_back(temp, 2,2);

    for(int i = 0; i < 3; i ++){
        printf("%d", temp1[i]);
    }
}


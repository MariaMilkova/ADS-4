// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mean = (start + end) / 2;
        if (value == arr[mean]) {
            int flag = mean + 1;
            while (value == arr[mean]) {
                mean--;
                count++;
            }
            while (value == arr[flag]) {
                flag++;
                count++;
            }
            return count;
        } else if (value < arr[mean]) {
            end = mean - 1;
        } else if (value > arr[mean]) {
            start = mean + 1;
        }
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int start = 0;
    int end = len - 1;
    while (start < end) {
        for (int i = start + 1; i <= end; i++) {
            if (arr[start] + arr[i] == value) {
                count++;
            }
        }
        start++;
        for (int j = end - 1; j >= start; j--) {
            if (arr[end] + arr[j] == value) {
                count++;
            }
        }
        end--;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int flag = i + 1;
        count += cbinsearch(arr + flag, len - i, value - arr[i]);
    }
    return count;
}

#include<stdio.h>
#define SIZE 10
#define SUMMARY(A, B)\
(\
    {\
int sum;\
sum=A[B-2]+A[B-1]; \
  sum;\
    }\
) 
int main() {
    FILE* e = fopen("array.txt", "r");
    int arr[16], i;
    for (i = 0; !feof(e); i++) {
        fscanf(e, "%d", &arr[i]);

    }
    fclose(e);
    int j, arrr[2], sum = 0, k;
    for (j = 0, k = 0; j < i; j++, k++) {
        if (k != 2) {
            arrr[k] = arr[j];
        }
        if (k == 2) {
            sum += SUMMARY(arrr, 2);
            k = 0;
        }

    }
    printf("sum = %d", sum);
    return 0;
}

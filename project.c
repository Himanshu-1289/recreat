#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 1000

void printArray(int arr[],int size,int selected1, int selected2){
    for(int i = 0; i< size;i ++){
        if(i == selected1|| i == selected2){
            printf("\x1b[31m%d  \x1b[0m",arr[i]);
        }
        else{
            printf("%d  ", arr[i]);
        }
        
    }
     printf("\r");
     fflush(stdout);
}
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void delay (int microsecond){
    int nanoseconds = microsecond*1000;
    for(int i =0; i<nanoseconds; i++);
}


void bubblesort(int arr[],int size){
    for(int i = 0;i <size -1 ; i++){
        for(int j=0;j<size - i - 1; j++){
            if (arr[j]>arr[j+1]){
                swap (&arr[j],&arr[j+1]);
                printArray (arr,size,j,j+1);
                delay(DELAY_MICROSECONDS);
            }
        }
    }
}



void main(){
    srand (time(NULL));

int arr[ARRAY_SIZE];
for (int i =0; i<ARRAY_SIZE;i++){
arr[i] = rand()%100;
}
printf("original array");
printArray(arr, ARRAY_SIZE,-1,-1);
printf("\n");

printf("sorting Array\t");
bubblesort(arr,ARRAY_SIZE);

printf("\n sorted array\t");
printArray(arr,ARRAY_SIZE,-1,-1);
printf("\n");



}
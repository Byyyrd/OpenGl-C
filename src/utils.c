#include "utils.h"
void printArray(float data[],int size){
    printf("Data: %f",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%f",data[i]);
    }
    printf("\n");
}
void printArray(char data[],int size){
    printf("Data: %c",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%c",data[i]);
    }
    printf("\n");
}
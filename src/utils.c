#include "utils.h"
void f_printArray(float data[],int size){
    printf("Data: %f",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%f",data[i]);
    }
    printf("\n");
}
void f_printArray_fmt(float data[],int size, int newLineInterval){
    printf("Data: %f",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%f",data[i]);
        if((i + 1) % newLineInterval == 0){
            printf("\n");
        }
    }
    printf("\n");
}
void c_printArray(char data[],int size){
    printf("Data: %c",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%c",data[i]);
    }
    printf("\n");
}
void u_printArray(unsigned int data[],int size){
    printf("Data: %u",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%u",data[i]);
    }
    printf("\n");
}
void u_printArray_fmt(unsigned int data[],int size, int newLineInterval){
    printf("Data: %u",data[0]);
    for(int i = 1;i < size; i++){
        printf(",%u",data[i]);
        if((i + 1) % newLineInterval == 0){
            printf("\n");
        }
    }
    printf("\n");
}
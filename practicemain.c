#include<stdio.h>

int main(){
    //declaration
    int cell[11],new[11];
    int i;

    for(i = 0; i <11; i++){ // asks then stores the input values
        printf("give me a number: ");
        scanf("%d",&cell[i]);  // checks if the values are even

    }
    for(i = 0; i < 11; i++){ // stored inside the array
        if(cell[i] % 2 == 0){
            printf("it is even \n");
        }
        else
        {
            printf("it is odd \n");
        }
        new[i] = cell[i];
    }


    return 0;
}


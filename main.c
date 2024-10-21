#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void control_input (int b, int c, int* ret);

int main()
{
    int ret = EXIT_SUCCESS;
    int b = 0, c = 0, B, B1;
    printf("Zadej dve cisla:\n");
    B = scanf("%d", &b);
    B1 = scanf("%d", &c);


    if(b != 0 && c==0){
        if(B && (b < 3 || b > 69))
    {
        fprintf(stderr, "Error: Vstup mumo interval!\n");
        return 101;
    }
    if(!B){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    for(int i = 0; i < b; i++){
        for(int j = 0; j < b; j++){
        if(i == 0 || i == b-1)
            printf("X");

        else if(j == 0 || j == b-1)
            printf("X");

        else
            printf(" ");

    }
    printf("\n");
    }
    }else if(b!=0 && c!=0){

    if(B && (b < 3 || b > 69))
    {
        fprintf(stderr, "Error: Vstup mumo interval!\n");
        return 101;
    }
    else if(!B){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    else if(b%2 == 0){
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }


    if(B1 && (c < 3 || c > 69))
    {
        fprintf(stderr, "Error: Vstup mumo interval!\n");
        return 101;
    }
    else if(!B1){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    for(int i = 0; i < (b/2); i++){
        printf(" ");
    }
    printf("X\n");

    int mid1 = b/2, mid2 = (b/2)+2;

    for(int i = 0; i < (b/2) - 1; i++){
        for(int j = 0; j<b; j++){

            if(j == mid1-1){
                printf("X");
                mid1--;
            }
            else if(j == mid2-1){
                printf("X");
                mid2++;
                break;
            }
            else{
            printf(" ");
            }
        }
           printf("\n");
    }
    if(b!=c){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < b; j++){
            if(i == c-1){
               printf("X");
          }
          else if(j == 0 || j == b-1){
               printf("X");
         }
         else if(i == 0 || i == b-1){
            printf("X");
        }
          else{
               printf(" ");
        }
    }
    printf("\n");
    }
    }
    else{
    for(int i = 0; i < c; i++){
        for(int j = 0; j < b; j++){
            if(i == c-1){
               printf("X");
          }
          else if(j == 0 || j == b-1){
               printf("X");
         }
         else if(i == 0 || i == b-1){
            printf("X");
        }
          else if(j%2 == 1 && i%2 == 0){
               printf("*");
        }
        else if(j%2 == 0 && i%2 == 0)
               printf("o");

         else if(j%2 == 1 && i%2 == 1)
               printf("o");

        else if(j%2 == 0 && i%2 == 1) {
                printf("*");
            }
        }
     printf("\n");
    }
    }
    }
    return ret;
}

void control_input (int b, int c, int* ret) {

}

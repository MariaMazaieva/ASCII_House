#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int control_input(int *w, int *h, int *ret);
void print_roof(int w,h);
void print_house(int w);

int main()
{
    int ret = EXIT_SUCCESS;
    int w = 0, h = 0;
    // int result_scan_1 = scanf("%d %d", &w,&h);
    printf("w %d,h %d\n",w,h);
    // int result_scan_2 = 1;


    control_input(&w,&h, &ret);

    if (ret == EXIT_SUCCESS) {
        print_roof(w,h);
        print_house(w);
    }

    // if(w != 0 && h==0){
    //     if(result_scan_1 && (w < 3 || w > 69))
    // {
    //     fprintf(stderr, "Error: Vstup mumo interval!\n");
    //     return 101;
    // }
    // if(!result_scan_1){
    //     fprintf(stderr, "Error: Chybny vstup!\n");
    //     return 100;
    // }

        // }
        // if(w!=0 && h!=0){

            // for(int i = 0; i < (w/2); i++){
            //     printf(" ");
            // }
            // printf("X\n");
            //
            // int mid1 = w/2, mid2 = (w/2)+2;
            //
            // for(int i = 0; i < (w/2) - 1; i++){
            //     for(int j = 0; j<w; j++){
            //
            //         if(j == mid1-1){
            //             printf("X");
            //             mid1--;
            //         }
            //         else if(j == mid2-1){
            //             printf("X");
            //             mid2++;
            //             break;
            //         }
            //         else{
            //             printf(" ");
            //         }
            //     }
            //     printf("\n");
            // }
            // if(w!=h){
            //     for(int i = 0; i < h; i++){
            //         for(int j = 0; j < h; j++){
            //             if(i == h-1){
            //                 printf("X");
            //             }
            //             else if(j == 0 || j == w-1){
            //                 printf("X");
            //             }
            //             else if(i == 0 || i == w-1){
            //                 printf("X");
            //             }
            //             else{
            //                 printf(" ");
            //             }
            //         }
            //         printf("\n");
            //     }
            // }
            // print_roof(w,h);
    //         else{
    //             for(int i = 0; i < h; i++){
    //                 for(int j = 0; j < w; j++){
    //                     if(i == h-1){
    //                         printf("X");
    //                     }
    //                     else if(j == 0 || j == w-1){
    //                         printf("X");
    //                     }
    //                     else if(i == 0 || i == w-1){
    //                         printf("X");
    //                     }
    //                     else if(j%2 == 1 && i%2 == 0){
    //                         printf("*");
    //                     }
    //                     else if(j%2 == 0 && i%2 == 0)
    //                         printf("o");
    //
    //                     else if(j%2 == 1 && i%2 == 1)
    //                         printf("o");
    //
    //                     else if(j%2 == 0 && i%2 == 1)
    //                         printf("*");
    //
    //                 }
    //                 printf("\n");
    //             }
    //         }
    //     }
    // // }
    return ret;
}

int control_input(int *w, int *h, int *ret) {
    int result_scan_1 = scanf("%d %d", w,h);

    if (result_scan_1 != 2) {
        fprintf(stderr, "Error: Chybny vstup!\n");
        *ret = 100;
        return *ret;
    }
    if((*w < 3 || *w > 69)||  (*h < 3 || *h > 69)) {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        *ret = 100;
        return *ret;
    }
    if(*w % 2 == 0) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        *ret = 102;
        return *ret;
    }
}

void print_roof(int w, int h) {
    for(int i = 0; i < (w/2); i++){
        printf(" ");
    }
    printf("X\n"); //print first X
    //w=5,h=3
    int mid1 = w/2, mid2 = (w/2)+2;

    for(int i = 0; i < (w/2) - 1; i++){
        for(int j = 0; j<w; j++){

            if(j == mid1-1){
                printf("X");
                mid1--;
            }
            else if(j == mid2-1){
                printf("X");
                mid2++;
                break;
            }
            else
                printf(" ");

        }
        printf("\n");
    }
    // if(w!=h){
    //     for(int i = 0; i < h; i++){
    //         for(int j = 0; j < h; j++){
    //             if(i == h-1){
    //                 printf("X");
    //             }
    //             else if(j == 0 || j == w-1){
    //                 printf("X");
    //             }
    //             else if(i == 0 || i == w-1){
    //                 printf("X");
    //             }
    //             else{
    //                 printf(" ");
    //             }
    //         }
    //         printf("\n");
    //     }
    // }

}

void print_house(int w) {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++){
            if(i == 0 || i == w-1)
                printf("X");

            else if(j == 0 || j == w-1)
                printf("X");

            else
                printf(" ");

        }
        printf("\n");
    }
}

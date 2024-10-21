#include <stdio.h>

#include <stdlib.h>

int control_input(int *w, int *h, int *ret);
void print_roof(int w,h);
void print_house(int h, int w);

int main()
{
    int ret = EXIT_SUCCESS;
    int w = 0, h = 0;
    // printf("w %d,h %d\n",w,h);

    control_input(&w,&h, &ret);

    if (ret == EXIT_SUCCESS) {
        print_roof(w,h);
        print_house(h,w);
    }

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
}

void print_house(int h, int w) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++){
            if(i == 0 || i == h-1)
                printf("X");

            else if(j == 0 || j == w-1)
                printf("X");

            else
                printf(" ");

        }
        printf("\n");
    }
}

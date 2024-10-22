#include <stdio.h>

#include <stdlib.h>

int control_input(int *w, int *h,int *k, int *ret);
void print_roof(int w, int h );
void print_house(int h, int w, int k);
void print_filling(int w);
void print_filling_reversed(int w) ;
void print_side_build(int w);
void print_side_build_vertical(int w);
int main()
{
    int ret = EXIT_SUCCESS;
    int w = 0, h = 0, k =0;
    control_input(&w,&h,&k, &ret);

    if (ret == EXIT_SUCCESS) {
        print_roof(w,h);
        print_house(h,w, k);
    }

    return ret;
}

int control_input(int *w, int *h, int *k, int *ret) {
    int result_scan_1 = scanf("%d %d %d", w,h, k);

    if (result_scan_1 != 3) {
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
    if(*k>*h) {
        fprintf(stderr, "Error: Neplatna velikost plotu!\n");
        *ret = 103;
        return *ret;
    }
}

void print_roof(int w, int h) {
    for(int i = 0; i < (w/2); i++){
        printf(" ");
    }
    printf("X\n"); //print first X
    //w=5,h=3
    //find midpoint to know where print first X
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

void print_house(int h, int w, int k) {
    for(int i = 0; i < h; i++) { //i = raw, j = colon
        for(int j = 0; j < w; j++){
            if(i == 0 || i == h-1) //upper part, and lawer part plus side building lower part
                  if(i == w-1 && j == h-1 ) {
                      putchar('X');print_side_build(k);
                  }
                  else
                      putchar('X');

            else if(j == 0 || j == w-1) {
                if(i == w-k && j == w-1)
                {putchar('X');print_side_build(k);} //printing side building horizontal part at the given height
                else if(i > w-k && j == w-1)
                    {putchar('X');print_side_build_vertical(k);} //vertical part

                else
                    putchar('X');
            }

            else if( i % 2 == 0 && j ==1)
                print_filling(w);
            else if ( i % 2 != 0 && j ==1)
                print_filling_reversed(w);

        }
        putchar('\n');
    }
}

void print_filling(int w) {
    for(int i = 0; i < w-2; i++) {
        if( i % 2 == 0)
            putchar('*');
        else
            putchar('o');
    }
}

void print_filling_reversed(int w) {
    for(int i = 0; i < w-2; i++)  {
        if( i % 2 == 0)
            putchar('o');
        else
            putchar('*');
    }
}


void print_side_build(int k) {
    for(int i = 0; i < k; i++) {
        if( i % 2 == 0)
            putchar('-');
        else
            putchar('|');
    }
}

void print_side_build_vertical(int k) {
    for(int i = 0; i < k; i++) {
        if( i % 2 == 0)
            putchar(' ');
        else
            putchar('|');
    }
}

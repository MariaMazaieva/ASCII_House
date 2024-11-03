#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 69
#define MIN_VALUE 3
int control_input(int *w, int *h,int *k, int *ret);
void print_roof(int w);
void print_house(int h, int w, int k);
void print_filling(int w);
void print_filling_reversed(int w) ;
void print_side_build(int w);
void print_side_build_vertical(int w);
void k_is_given(int w, int i,int j);
int main()
{
    int ret = EXIT_SUCCESS;
    int w = 0, h = 0, k =1;
    control_input(&w,&h,&k, &ret);

    if (ret == EXIT_SUCCESS) {
        print_roof(w);
        print_house(h,w, k);
    }

    return ret;
}

/*Function reads numbers from stdin to variables w and h, and k if its not a \n.
 * @var result_scan_1  - used to read amount of successfully scanned numbers from input.
 * @var result_2  - used to read amount if successfully scanned number k from input.
 * @ret - EXIT_SUCCESS, otherwise number of error if integer was not read.
 * MIN_VALUE is set to 3, MAX_VALUE is set to 69
 */

int control_input(int *w, int *h, int *k, int *ret) {
    int result_scan_1 = scanf("%d %d", w,h);
    int ch = getchar();
    int result_2; //cant initialize variable because of (2.)condition for range of input
    if (ch != '\n')
       result_2 = scanf("%d",k);

    if (result_scan_1 != 2 || result_2 != 1) {
        fprintf(stderr, "Error: Chybny vstup!\n");
        *ret = 100;
        return *ret;
    }
    if((*w < MIN_VALUE || *w > MAX_VALUE)||(*h < MIN_VALUE || *h > MAX_VALUE) ||(*k > *h || *k <= 0)) {
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

/*Function describe:
     *use mid-points to define where is 'middle'. middle - distance from left side and right side.
     *Later on just count distance from two sides
     *Print 'X' when two midpoints are the same
     *there is condition for printing filling if k is given or not
     */

void print_roof(int w) {
    for(int i = 0; i < (w/2); i++){
        printf(" ");
    }
    printf("X\n"); //print first X
    int mid1 = w/2; //find midpoint to know where print first X
    int mid2 = (w/2)+2;

    for(int i = 0; i < (w/2) - 1; i++){
        for(int j = 0; j<w; j++){

            if(j == mid1-1){
                putchar('X');
                mid1--;
            }
            else if(j == mid2-1){
                putchar('X');
                mid2++;
                break;
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

void print_house(int h, int w, int k) {
    for(int i = 0; i < h; i++) { //i = raw, j = colon
        for(int j = 0; j < w; j++){
            if(i == 0 || i == h-1) //upper part, and lower part plus side building lower part
                  if(i == w-1 && j == h-1 ) {
                      putchar('X');
                      print_side_build(k);
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
            else if (k != 1)
                k_is_given(w,i,j);
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

void k_is_given(int w, int i,int j) {
    if( i % 2 == 0 && j ==1)
        print_filling(w);
    else if ( i % 2 != 0 && j ==1)
        print_filling_reversed(w);
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

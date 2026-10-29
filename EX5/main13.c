#include <stdio.h>
int multi(int i, int j){
    if (j == 1){
        printf("%d*%d=%-2d\t", i, j, i*j);
        return 0;
    } else{
        multi(i, j-1);
        printf("%d*%d=%-2d\t", i, j, i*j);
    }
    return 0;//
}

//
void print_table(int i){
    if (i > 9){
        return;//
    }
    multi(i,9);//
    printf("\n");//
    print_table(i + 1);//
}

int main(){
    print_table (1);//
    return 0;
}

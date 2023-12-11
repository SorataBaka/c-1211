#include <stdio.h>

int main(void){
    int x;
    int sum = 0;
    while(1){
        if(scanf("%d\n", &x) == EOF) break;
        sum += x;
    }

    printf("%d\n", sum);
    return 0;

}
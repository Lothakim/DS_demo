#include <stdio.h>
#include <string.h>

void str_union(int a[], int b[]);

int main() {
    int a[7]={1,2,3,4,0,0,0};
    int b[3]={5,6,7};

    str_union(a,b);
    for (int i = 0; i < 7; ++i) {
        printf("a[%d] = %d\n",i,a[i]);
    }

    return 0;
}

void str_union(int a[], int b[]){

    for(int i=0;i<3;i++){
        for (int j = 0; j < 7; j++) {
            if (a[j] == b[i])
                break;
            else
                a[4+i]=b[i];
        }
    }
}
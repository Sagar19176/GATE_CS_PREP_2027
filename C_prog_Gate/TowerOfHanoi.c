#include<stdio.h>

void TOH(int n, char source, char dest, char aux){
    if(n ==1) {
        printf("%c -> %c\n", source,dest);
    }else{
        TOH(n-1,source, aux, dest);
        printf("%c -> %c\n",source,dest);
        TOH(n-1,aux, dest, source);
    }
}

void main(){
    int n;
    printf("Enter the number of discs: ");
    scanf("%d",&n);
    TOH(n,'A','C','B');
}
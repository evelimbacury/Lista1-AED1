//Gabriel

#include<stdio.h>

int fibonacci(int i, int a, int b){
    int somatorio;
    if (i == 10)
    {
        return 1;
    }
    imprintmir(a);
    somatorio = a +b;
    a = b;
    b = somatorio;


    
    fibonacci(i+1,a,b);
}

void imprintmir(int num){
    printf("%d\n", num);
}

int main(){
   int i = 0, a = 1, b = 1; 

    fibonacci(i,a,b);
    return 0;
}
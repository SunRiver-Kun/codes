#include<stdio.h>
#include<complex.h>
int main()
{ double _Complex x=3+5i;  //i��дСд������
double complex y=4-6i;
double complex z=x+y;
double complex j,k;
j=cproj(z);
k=conj(z);
printf("z=%f+%fi",creal(z),cimag(z)); //%lf��%f������
printf("\nj=%f+%fi",creal(j),cimag(j));
printf("\nk=%f+%fi",creal(k),cimag(k));

}

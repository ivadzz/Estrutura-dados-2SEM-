#include<stdio.h>

int main(int argc, char* argv[]){
   int n=-11;
   int n2=0;
   float f1=1.5;
   double d1=1.55555;
   char letra='D';

    
   

   if(n2){
    printf("0 eh verdadeiro\n");

   }
   if(n){
    printf("11 eh verdadeiro\n");
   }

   for(n = 0; n<10; n++){
    printf("%d ",n);
   }

   n=0;
   do{
    printf("%d ",n);
    n++;
   }while(n<10);

   printf("\n");
   return 0;


}
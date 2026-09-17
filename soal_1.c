#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N;
    long long A;
    long long jumlah = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i <N; i++){
        scanf("%lld", &A);
        jumlah += A;
   }
   if (jumlah < 0)
   jumlah = -jumlah;
   
   printf("%lld", jumlah);
   printf("\n");
   
   return 0;
  } 
   
        

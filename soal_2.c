#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long a, b, c;
    
    scanf("%lld %lld %lld", &a, &b, &c);
    
    long long ab = llabs(a - b);
    long long ac = llabs(a - c);
    long long bc = llabs(b - c);
    
    long long hasil = ab;
    
    if (ac < hasil)
    hasil = ac;
    
    if (bc < hasil)
    hasil = bc;
    
    printf("%lld", hasil);
    printf("\n");
    
    return 0;
}
 

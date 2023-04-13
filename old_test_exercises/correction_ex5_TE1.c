#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int** adressesCoin(const int* adr, size_t n, size_t m);


int main()
{
    const int M[][4] = {{1,2,3, 4},{5,6, 7, 8},{9,10,11,12}};
    int** coins = adressesCoin((int*)M, 3, 4);
    // affiche les valeurs des 4 coins
    printf("%d, %d, %d, %d", *coins[0], *coins[1], *coins[2], *coins[3]);
    return EXIT_SUCCESS;
}

int** adressesCoin(const int* adr, size_t n, size_t m){
    assert(adr && n && m);
    int** ptr = (int**) calloc(4, sizeof(int*));
    if(ptr){
        ptr[0] = (int*) adr;
        ptr[1] = (int*) adr + m - 1;
        ptr[2] = (int*) adr + (n - 1) * m;
        ptr[3] = (int*) adr + n * m - 1;
    }
    return ptr;
}

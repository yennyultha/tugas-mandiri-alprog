#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007LL

void merge(long long a[], long long temp[], int kiri, int tengah, int kanan) {
    int i = kiri;
    int j = tengah + 1;
    int k = kiri;

    while (i <= tengah && j <= kanan) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= tengah) {
        temp[k++] = a[i++];
    }

    while (j <= kanan) {
        temp[k++] = a[j++];
    }

    for (i = kiri; i <= kanan; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(long long a[], long long temp[], int kiri, int kanan) {
    if (kiri >= kanan)
        return;

    int tengah = kiri + (kanan - kiri) / 2;

    mergeSort(a, temp, kiri, tengah);
    mergeSort(a, temp, tengah + 1, kanan);

    merge(a, temp, kiri, tengah, kanan);
}

int main() {
    int N;
    scanf("%d", &N);

    long long *A = malloc(N * sizeof(long long));
    long long *temp = malloc(N * sizeof(long long));

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    mergeSort(A, temp, 0, N - 1);

    long long hasil = ((long long)N * (N - 1) / 2) % MOD;

    int i = 0;

    while (i < N) {
        int j = i + 1;

        while (j < N && A[j] == A[i]) {
            j++;
        }

        long long jumlah = j - i;

        long long sama = (jumlah * (jumlah - 1) / 2) % MOD;

        hasil = (hasil - sama + MOD) % MOD;

        i = j;
    }

    printf("%lld\n", hasil);

    free(A);
    free(temp);

    return 0;
}

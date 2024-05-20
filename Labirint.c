#include <stdio.h>
#include <stdlib.h>

#define N 10

int validare(int si, int sj, int labirint[N][N]) {
    if (si >= 0 && si < N && sj >= 0 && sj < N && labirint[si][sj] == 0)
        return 1;
    return 0;
}

int solutie(int si, int sj, int fi, int fj) {
    if (si == fi && sj == fj)
        return 1;
    return 0;
}

void afisare(int labirint[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", labirint[i][j]);
        printf("\n");
    }
    printf("\n");
}

int rezolvareLabirint(int* st, int varf, int labirint[N][N], int si, int sj, int fi, int fj) {
    if (solutie(si, sj, fi, fj)) {
        labirint[si][sj] = 2;  // Marcare a celulei finale în cale
        afisare(labirint);
        return 1;
    }

    labirint[si][sj] = 2;  // Marcare a celulei ca parte din cale

    int ct;
    for (ct = 0; ct < 4; ct++) {
        st[varf] = ct;
        int n_si = si, n_sj = sj;
        switch (ct) {
        case 0: n_si++; break;  // Mergi în jos
        case 1: n_sj--; break;  // Mergi la stânga
        case 2: n_si--; break;  // Mergi în sus
        case 3: n_sj++; break;  // Mergi la dreapta
        }

        if (validare(n_si, n_sj, labirint)) {
            if (rezolvareLabirint(st, varf + 1, labirint, n_si, n_sj, fi, fj))
                return 1;
        }
    }

    labirint[si][sj] = 0;  // Marcare ca nevizitat la revenirea din recursie
    return 0;  // Returnat 0 dacă nu s-a găsit soluția
}

int main() {
    int labirint[N][N] = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int stiva[N * N];
    if (!rezolvareLabirint(stiva, 0, labirint, 0, 0, 9, 9))
        printf("Nu exista solutie!\n");

    return 0;
}

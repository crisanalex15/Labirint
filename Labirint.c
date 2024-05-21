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

void afisareMiscari(int* st, int varf)
{
    for (int i = 0; i < varf; i++)
    {
        switch (st[i])
        {
        case 0: printf("Jos\n");
            break;
        case 1: printf("Stanga\n");
            break;
        case 2: printf("Sus\n");
            break;
        case 3: printf("Dreapta\n");
            break;
        }
    }
}

int rezolvareLabirint(int* st, int varf, int labirint[N][N], int si, int sj, int fi, int fj) {
    if (solutie(si, sj, fi, fj)) {
        labirint[si][sj] = 2;  // Marcare a celulei finale în cale
        afisare(labirint);
		printf("Doresti sa aflii si miscariile? (1/0): ");
		int optiune;
		scanf("%d", &optiune);
		if (optiune == 1)
			afisareMiscari(st, varf);
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
    int stiva[N * N],varf=0,optiune;
	printf("=======MENIU=======\n");
	printf("1. Rezolvare labirint\n");
	printf("0. Iesire\n");
	printf("Optiunea dvs.: ");
	scanf("%d", &optiune);
    while (1)
    {
		switch (optiune)
		{
		case 1:
			if (!rezolvareLabirint(stiva, varf, labirint, 0, 0, 9, 9))
				printf("Nu exista solutie!\n");
			break;
		case 0:
			exit(0);
		default:
			printf("Optiune invalida!\n");
			break;
		}
        printf("1. Rezolvare labirint\n");
        printf("2. Afisare miscari\n");
        printf("0. Iesire\n");
        printf("Optiunea dvs.: ");
        scanf("%d", &optiune);
    }

    return 0;
}

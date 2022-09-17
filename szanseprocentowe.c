#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BAZA 1000
#define PYTANIA 25
#define NAZALICZNIE 12
#define CONS 1000

static int tablica[1001] = {0};
static int trafione[1001] = {0};
static int ilezdanychnacons[1001] = {0};

static int *losowanie_kartkówki(int n) {
    int i = 1;
    while (i <= n) {
        int losowe = rand() % BAZA + 1;
        if (tablica[losowe] == 0) {
            tablica[losowe] = 1;
            i++;
        }
    }
    return tablica;
}

static int  * trafianie(int n) {
    int i = 1;
    while (i <= n) {
        int losowe = rand() % BAZA + 1;
        if (trafione[losowe] == 0) {
            trafione[losowe] = 1;
            i++;
        }
    }
    return trafione;
}

static int sprawdzanietrafienia(void) {
    int iletrafionych = 0;
    for (int i=1; i<BAZA; i++) {
        if (trafione[i] == 1 && tablica[i] ==1) {
            iletrafionych++;
        }
    }

    return iletrafionych;
}

static int *czyszczenie1(void) {
    for (int i=0; i<=BAZA; i++) {
        trafione[i] = 0;
    }
    return trafione;
}

static int *czyszczenie2(void) {
    for (int i=0; i<=BAZA; i++) {
        tablica[i] = 0;
    }
    return tablica;
}
int main(void) {
    srand((unsigned) time(NULL));
    for (int i=0; i<=BAZA; i++) {
        int licznik = 0;
        for (int j=0; j<CONS; j++) {
            losowanie_kartkówki(PYTANIA);
            trafianie(i);
            int s = sprawdzanietrafienia();
            if (s >= 16) {
                licznik++;
            }
            czyszczenie1();
            czyszczenie2();
        }
        ilezdanychnacons[i] = licznik;
        printf("%d\n",ilezdanychnacons[i]);
    }
}

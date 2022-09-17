#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BAZA 1000
#define PYTANIA 25
#define PROCENTNAZALICZNIE 45
#define ILOŚĆSYMULACJI 100

static int test[BAZA + 1] = {0};
static int student[BAZA + 1] = {0};
static int ilezdanychnacons[BAZA + 1] = {0};

static int *losowanie_testu(int n) {
    int i = 1;
    while (i <= n) {
        int losowe = rand() % BAZA + 1;
        if (test[losowe] == 0) {
            test[losowe] = 1;
            i++;
        }
    }
    return test;
}

static int *czyszczenie_testu(void) {
    for (int i=0; i<=BAZA; i++) {
        test[i] = 0;
    }
    return test;
}

static int  *symulacja_rozwiązania(int n) {
    int i=1;
    while (i <= n) {
        int losowe = rand() % BAZA + 1;
        if (student[losowe] == 0) {
            student[losowe] = 1;
            i++;
        }
    }
    return student;
}

static int *czyszczenie_studenta(void) {
    for (int i=0; i<=BAZA; i++) {
        student[i] = 0;
    }
    return student;
}

static int sprawdzanie_wspólnych(void) {
    int ile_wspólnych = 0;
    for (int i=1; i<BAZA; i++) {
        if (student[i] == 1 && test[i] ==1) {
            ile_wspólnych++;
        }
    }

    return ile_wspólnych;
}

static int oblicz_ile_pkt_na_zalicznie(void) {
    int pkt_na_zaliczenie = 0;
    while (pkt_na_zaliczenie * 100 <= PROCENTNAZALICZNIE * PYTANIA) {
        pkt_na_zaliczenie++;
    }
    
    return pkt_na_zaliczenie;
}

int main(void) {
    srand((unsigned) time(NULL));
    for (int i=0; i<=BAZA; i++) {
        int licznik = 0;
        for (int j=0; j<ILOŚĆSYMULACJI; j++) {
            losowanie_testu(PYTANIA);
            symulacja_rozwiązania(i);
            int s = sprawdzanie_wspólnych();
            if (sprawdzanie_wspólnych() >= oblicz_ile_pkt_na_zalicznie()) {
                licznik++;
            }
            czyszczenie_testu();
            czyszczenie_studenta();
        }
        ilezdanychnacons[i] = licznik;
        printf("%d\n",ilezdanychnacons[i]);
    }
}

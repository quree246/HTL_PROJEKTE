#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Spielfeld-Deklaration: 6 Zeilen, 7 Spalten
char feld[6][7]; 

// Funktion zur Anzeige des aktuellen Spielfelds
void zeige() {
    // Jede Zeile des Spielfelds wird ausgegeben
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[0][0], feld[0][1], feld[0][2], feld[0][3], feld[0][4], feld[0][5], feld[0][6]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[1][0], feld[1][1], feld[1][2], feld[1][3], feld[1][4], feld[1][5], feld[1][6]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[2][0], feld[2][1], feld[2][2], feld[2][3], feld[2][4], feld[2][5], feld[2][6]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[3][0], feld[3][1], feld[3][2], feld[3][3], feld[3][4], feld[3][5], feld[3][6]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[4][0], feld[4][1], feld[4][2], feld[4][3], feld[4][4], feld[4][5], feld[4][6]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", feld[5][0], feld[5][1], feld[5][2], feld[5][3], feld[5][4], feld[5][5], feld[5][6]);
    printf(" 1 2 3 4 5 6 7\n"); // Spaltennummern zur Orientierung
}

// Prüft, ob ein Spieler gewonnen hat
int hat_gewonnen(int zeile, int spalte, char zeichen) {
    int i, z, s, zähler;

    // Prüfe horizontal (Zeile)
    zähler = 0;
    for (i = 0; i < 7; i++) {
        if (feld[zeile][i] == zeichen) {
            zähler++;
            if (zähler == 4) return 1; // 4 in einer Reihe gefunden
        } else zähler = 0;
    }

    // Prüfe vertikal (Spalte)
    zähler = 0;
    for (i = 0; i < 6; i++) {
        if (feld[i][spalte] == zeichen) {
            zähler++;
            if (zähler == 4) return 1;
        } else zähler = 0;
    }

    // Prüfe Diagonale (\)
    z = zeile; s = spalte;
    while (z > 0 && s > 0) { z--; s--; } // Bis zum Start der Diagonale zurück
    zähler = 0;
    while (z < 6 && s < 7) {
        if (feld[z][s] == zeichen) {
            zähler++;
            if (zähler == 4) return 1;
        } else zähler = 0;
        z++; s++;
    }

    // Prüfe Diagonale (/)
    z = zeile; s = spalte;
    while (z > 0 && s < 6) { z--; s++; }
    zähler = 0;
    while (z < 6 && s >= 0) {
        if (feld[z][s] == zeichen) {
            zähler++;
            if (zähler == 4) return 1;
        } else zähler = 0;
        z++; s--;
    }

    return 0; // Kein Gewinn gefunden
}

int main() {
    int spieler = 1;    // Startet mit Spieler 1
    int gegen_bot = 0;  // Spielmodus: 1 = 2 Spieler, 2 = gegen Bot
    int zeile, spalte;
    char zeichen;

    srand(time(NULL)); // Zufallsgenerator für den Bot initialisieren

    // Spielfeld leeren (mit Leerzeichen füllen)
    for (zeile = 0; zeile < 6; zeile++)
        for (spalte = 0; spalte < 7; spalte++)
            feld[zeile][spalte] = ' ';

    // Spielmodus abfragen
    printf("1 = Zwei Spieler\n2 = Gegen Bot\nAuswahl: ");
    scanf("%d", &gegen_bot);

    // Hauptspielschleife
    while (1) {
        zeige(); // Aktuelles Spielfeld anzeigen

        if (spieler == 1) {
            zeichen = 'X';
            printf("Spieler 1 (X), Spalte wahlen (1-7): ");
            scanf("%d", &spalte);
            spalte--; // Array-Index anpassen
        } else {
            zeichen = 'O';
            if (gegen_bot == 2) {
                // Bot wählt eine zufällige freie Spalte
                do {
                    spalte = rand() % 7;
                } while (feld[0][spalte] != ' ');
                printf("Bot (O) wahlt Spalte %d\n", spalte + 1);
            } else {
                printf("Spieler 2 (O), Spalte wahlen (1-7): ");
                scanf("%d", &spalte);
                spalte--;
            }
        }

        // Prüfen, ob Spalteneingabe gültig ist
        if (spalte < 0 || spalte > 6) {
            printf("Ungultige Spalte!\n");
            continue; // Eingabe wiederholen
        }

        // Stein in die nächstfreie Zeile der Spalte legen (von unten nach oben)
        for (zeile = 5; zeile >= 0; zeile--) {
            if (feld[zeile][spalte] == ' ') {
                feld[zeile][spalte] = zeichen;
                break;
            }
        }

        // Prüfen, ob die Spalte voll ist
        if (zeile < 0) {
            printf("Spalte voll!\n");
            continue; // Eingabe wiederholen
        }

        // Prüfen, ob der aktuelle Spieler gewonnen hat
        if (hat_gewonnen(zeile, spalte, zeichen)) {
            zeige(); // Endstand anzeigen
            if (spieler == 2 && gegen_bot == 2)
                printf("Der Bot hat gewonnen!\n");
            else
                printf("Spieler %d (%c) hat gewonnen!\n", spieler, zeichen);
            break; // Spiel beenden
        }

        // Spieler wechseln
        if (spieler == 1)
            spieler = 2;
        else
            spieler = 1;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Spielfeld zeichnen

void zeichneLabyrinth(char feld[20][20], int zeile, int spalte) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == zeile && j == spalte){
                printf("@");
            }
            else{
                printf("%c", feld[i][j]);
        }
        
    }
    printf("\n");
}
}
int main() {
    int spielerzeile = 1;
    int spielerspalte = 1;
    char feld[20][20];
    char buffer[500];
  
    FILE *fp = fopen("lab.dat", "r");
    if (NULL == fp) {
        printf("Fehler beim Öffnen der Datei!\n");
        return -1;
    }

    for (int k = 0; k < 20; k++) {
        fgets(buffer, sizeof(buffer), fp);
        for (int i = 0; i < 20; i++) {
            feld[k][i] = buffer[i];
        }
    }
    fclose(fp);

    
    for (int i = 0; i < 100; i++) {
        zeichneLabyrinth(feld, spielerzeile, spielerspalte);

        printf("Bewege dich (WASD): ");
        char eingabe;
        scanf(" %c", &eingabe);

        int neuezeile = spielerzeile;
        int neuespalte = spielerspalte;

        switch (eingabe) {
            case 'w': neuezeile--; 
            break;
            case 'a': neuespalte--; 
            break;
            case 's': neuezeile++; 
            break;
            case 'd': neuespalte++;
            break;
            default: printf("Ungültige Eingabe!\n"); 
            break;
        }

        if (feld[neuezeile][neuespalte] == '#') {
            printf("sie haben einen Wand getroffen, zuruck zum Start: \n");
            system("pause");
            spielerzeile = 1;
            spielerspalte = 1;
        }
        else if (feld[neuezeile][neuespalte] == 'Z') {
            zeichneLabyrinth(feld, neuezeile, neuespalte);
            printf("\n Sie haben gewonnen! \n");
            break; // ende
        }
        else {
            spielerzeile = neuezeile;
            spielerspalte = neuespalte;
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// ==================== PROTOTYPES ====================
void algorithme_tri_a_bulle(int *tab, int taille);
void algorithme_tri_a_bulle_v2(int *tab, int taille);
void algorithme_tri_a_bulle_v3(int *tab, int taille);
void tri_cocktail(int tab[], int taille);
void algorithme_tri_selection(int *tab, int taille);
void algorithme_tri_par_insertion(int *tab, int taille);
void algorithme_tri_par_comptage(int *tab, int taille);
int* tri_fusion(int tab[], int debut, int fin);
void tri_rapide(int *tab, int debut, int fin);

typedef struct {
    char nom[50];
    double temps;
} Resultat;

void copier_tableau(int *source, int *dest, int taille) {
    for (int i = 0; i < taille; i++) dest[i] = source[i];
}

void wrapper_tri_fusion(int *tab, int taille) {
    int *resultat = tri_fusion(tab, 0, taille - 1);
    copier_tableau(resultat, tab, taille);
    free(resultat);
}

void wrapper_tri_rapide(int *tab, int taille) {
    tri_rapide(tab, 0, taille - 1);
}

// ==================== LECTURE BENCHMARK ====================
void lire_benchmark(char *nom_fichier, int **tab_croissant, int **tab_decroissant, 
                   int **tab_constant, int ***tabs_aleatoires, int *taille, int *nb_aleatoires) {
    FILE *fp = fopen(nom_fichier, "r");
    if (!fp) {
        printf("❌ Erreur: impossible d'ouvrir %s\n", nom_fichier);
        *taille = 0;
        return;
    }
    
    fscanf(fp, "%d", taille);
    *tab_croissant = (int*)malloc(sizeof(int) * (*taille));
    *tab_decroissant = (int*)malloc(sizeof(int) * (*taille));
    *tab_constant = (int*)malloc(sizeof(int) * (*taille));
    
    for (int i = 0; i < *taille; i++) fscanf(fp, "%d", &(*tab_croissant)[i]);
    for (int i = 0; i < *taille; i++) fscanf(fp, "%d", &(*tab_decroissant)[i]);
    for (int i = 0; i < *taille; i++) fscanf(fp, "%d", &(*tab_constant)[i]);
    
    *nb_aleatoires = 0;
    long pos = ftell(fp);
    int temp;
    while (fscanf(fp, "%d", &temp) == 1) {
        for (int i = 1; i < *taille; i++) {
            if (fscanf(fp, "%d", &temp) != 1) break;
        }
        (*nb_aleatoires)++;
    }
    
    fseek(fp, pos, SEEK_SET);
    *tabs_aleatoires = (int**)malloc(sizeof(int*) * (*nb_aleatoires));
    for (int i = 0; i < *nb_aleatoires; i++) {
        (*tabs_aleatoires)[i] = (int*)malloc(sizeof(int) * (*taille));
        for (int j = 0; j < *taille; j++) {
            fscanf(fp, "%d", &(*tabs_aleatoires)[i][j]);
        }
    }
    fclose(fp);
}

// ==================== MESURE UN SEUL TABLEAU ====================
double mesurer_un_tableau(void (*fonction_tri)(int*, int), int *tableau, int taille) {
    int *tab_copie = (int*)malloc(sizeof(int) * taille);
    copier_tableau(tableau, tab_copie, taille);
    
    clock_t debut = clock();
    fonction_tri(tab_copie, taille);
    clock_t fin = clock();
    
    free(tab_copie);
    return (double)(fin - debut) / CLOCKS_PER_SEC;
}

// ==================== MESURE MOYENNE SUR TABLEAUX ALÉATOIRES ====================
double mesurer_moyenne_aleatoires(void (*fonction_tri)(int*, int), int **tabs, int nb_tabs, int taille) {
    double somme = 0.0;
    for (int i = 0; i < nb_tabs; i++) {
        somme += mesurer_un_tableau(fonction_tri, tabs[i], taille);
    }
    return somme / nb_tabs;
}

// ==================== MAIN ====================
int main() {
    int tailles[] = {1000, 2000, 3000, 4000, 5000, 10000, 15000, 20000, 25000};
    int nb_tailles = 9;
    
    // ========== CRÉATION DES 8 FICHIERS CSV ==========
    FILE *csv[8];
    csv[0] = fopen("resultats_croissant_petite.csv", "w");
    csv[1] = fopen("resultats_croissant_grande.csv", "w");
    csv[2] = fopen("resultats_decroissant_petite.csv", "w");
    csv[3] = fopen("resultats_decroissant_grande.csv", "w");
    csv[4] = fopen("resultats_constant_petite.csv", "w");
    csv[5] = fopen("resultats_constant_grande.csv", "w");
    csv[6] = fopen("resultats_aleatoire_petite.csv", "w");
    csv[7] = fopen("resultats_aleatoire_grande.csv", "w");
    
    // Vérifier que tous les fichiers sont ouverts
    for (int i = 0; i < 8; i++) {
        if (!csv[i]) {
            printf("❌ Erreur lors de la création des fichiers CSV\n");
            return 1;
        }
    }
    
    // En-têtes
    for (int i = 0; i < 8; i++) {
        fprintf(csv[i], "taille,bulle_v1,bulle_v2,bulle_v3,cocktail,selection,insertion,comptage,fusion,rapide\n");
    }
    
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║    ANALYSE COMPLÈTE : 4 SCÉNARIOS × 2 TYPES DE VALEURS        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n\n");
    
    // ========== BOUCLE SUR LES TAILLES ==========
    for (int t = 0; t < nb_tailles; t++) {
        int taille = tailles[t];
        printf("📊 Taille %d\n", taille);
        
        // ========== CHARGER PETITES VALEURS ==========
        char nom_petite[100];
        sprintf(nom_petite, "benchmark_petite_%d.txt", taille);
        int *tab_c_p, *tab_d_p, *tab_const_p, **tabs_alea_p;
        int nb_alea_p;
        lire_benchmark(nom_petite, &tab_c_p, &tab_d_p, &tab_const_p, &tabs_alea_p, &taille, &nb_alea_p);
        if (taille == 0) continue;
        
        // ========== CHARGER GRANDES VALEURS ==========
        char nom_grande[100];
        sprintf(nom_grande, "benchmark_grande_%d.txt", taille);
        int *tab_c_g, *tab_d_g, *tab_const_g, **tabs_alea_g;
        int nb_alea_g;
        lire_benchmark(nom_grande, &tab_c_g, &tab_d_g, &tab_const_g, &tabs_alea_g, &taille, &nb_alea_g);
        
        // ========== DÉFINIR LES ALGOS ==========
        void (*algos[9])(int*, int) = {
            algorithme_tri_a_bulle,
            algorithme_tri_a_bulle_v2,
            algorithme_tri_a_bulle_v3,
            tri_cocktail,
            algorithme_tri_selection,
            algorithme_tri_par_insertion,
            algorithme_tri_par_comptage,
            wrapper_tri_fusion,
            wrapper_tri_rapide
        };
        
        char noms[9][20] = {"Bulle v1", "Bulle v2", "Bulle v3", "Cocktail", 
                             "Selection", "Insertion", "Comptage", "Fusion", "Rapide"};
        
        // ========== MESURER LES 8 CAS ==========
        double temps[8][9]; // 8 cas × 9 algos
        
        // Cas 0: Croissant Petite
        printf("   🔹 Croissant petite...");
        for (int a = 0; a < 9; a++) {
            temps[0][a] = mesurer_un_tableau(algos[a], tab_c_p, taille);
        }
        printf(" ✅\n");
        
        // Cas 1: Croissant Grande
        printf("   🔹 Croissant grande...");
        for (int a = 0; a < 9; a++) {
            temps[1][a] = mesurer_un_tableau(algos[a], tab_c_g, taille);
        }
        printf(" ✅\n");
        
        // Cas 2: Décroissant Petite
        printf("   🔹 Décroissant petite...");
        for (int a = 0; a < 9; a++) {
            temps[2][a] = mesurer_un_tableau(algos[a], tab_d_p, taille);
        }
        printf(" ✅\n");
        
        // Cas 3: Décroissant Grande
        printf("   🔹 Décroissant grande...");
        for (int a = 0; a < 9; a++) {
            temps[3][a] = mesurer_un_tableau(algos[a], tab_d_g, taille);
        }
        printf(" ✅\n");
        
        // Cas 4: Constant Petite
        printf("   🔹 Constant petite...");
        for (int a = 0; a < 9; a++) {
            temps[4][a] = mesurer_un_tableau(algos[a], tab_const_p, taille);
        }
        printf(" ✅\n");
        
        // Cas 5: Constant Grande
        printf("   🔹 Constant grande...");
        for (int a = 0; a < 9; a++) {
            temps[5][a] = mesurer_un_tableau(algos[a], tab_const_g, taille);
        }
        printf(" ✅\n");
        
        // Cas 6: Aléatoire Petite
        printf("   🔹 Aléatoire petite...");
        for (int a = 0; a < 9; a++) {
            temps[6][a] = mesurer_moyenne_aleatoires(algos[a], tabs_alea_p, nb_alea_p, taille);
        }
        printf(" ✅\n");
        
        // Cas 7: Aléatoire Grande
        printf("   🔹 Aléatoire grande...");
        for (int a = 0; a < 9; a++) {
            temps[7][a] = mesurer_moyenne_aleatoires(algos[a], tabs_alea_g, nb_alea_g, taille);
        }
        printf(" ✅\n\n");
        
        // ========== ÉCRIRE DANS LES CSV ==========
        for (int cas = 0; cas < 8; cas++) {
            fprintf(csv[cas], "%d", taille);
            for (int a = 0; a < 9; a++) {
                fprintf(csv[cas], ",%.6f", temps[cas][a]);
            }
            fprintf(csv[cas], "\n");
        }
        
        // ========== LIBÉRER MÉMOIRE ==========
        free(tab_c_p); free(tab_d_p); free(tab_const_p);
        for (int i = 0; i < nb_alea_p; i++) free(tabs_alea_p[i]);
        free(tabs_alea_p);
        free(tab_c_g); free(tab_d_g); free(tab_const_g);
        for (int i = 0; i < nb_alea_g; i++) free(tabs_alea_g[i]);
        free(tabs_alea_g);
    }
    
    // ========== FERMER LES FICHIERS ==========
    for (int i = 0; i < 8; i++) fclose(csv[i]);
    
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                     MESURES TERMINÉES !                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n\n");
    
    printf(" 8 fichiers CSV créés :\n");
    printf("   1. resultats_croissant_petite.csv\n");
    printf("   2. resultats_croissant_grande.csv\n");
    printf("   3. resultats_decroissant_petite.csv\n");
    printf("   4. resultats_decroissant_grande.csv\n");
    printf("   5. resultats_constant_petite.csv\n");
    printf("   6. resultats_constant_grande.csv\n");
    printf("   7. resultats_aleatoire_petite.csv\n");
    printf("   8. resultats_aleatoire_grande.csv\n\n");
    
    return 0;
}
// les tris 
void algorithme_tri_a_bulle(int *tab, int taille){
    int i, j, tmp;
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille-1; j++){
            if(tab[j] > tab[j+1]){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}

void algorithme_tri_a_bulle_v2(int *tab, int taille){
    int tmp;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille-1-i; j++){  
            if(tab[j] > tab[j+1]){
                tmp = tab[j];
                tab[j] = tab[j+1];  
                tab[j+1] = tmp;
            }
        }
    }
}

void algorithme_tri_a_bulle_v3(int *tab, int taille){
    int i = 0;
    bool continuer = true;
    int tmp;
    while((i < taille-1) && (continuer == true)){
        continuer = false;
        for(int j = 0; j < taille-1-i; j++){
            if(tab[j] > tab[j+1]){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
                continuer = true;
            }
        }
        i++;  
    }
}

void algorithme_tri_selection(int *tab, int taille){
    int i, j, min, tmp;
    for(i = 0; i < taille-1; i++){
        min = i;
        for(j = i+1; j < taille; j++){
            if(tab[j] < tab[min]){
                min = j;
            }
        }
        if(i != min){
            tmp = tab[i];
            tab[i] = tab[min];
            tab[min] = tmp;
        }
    }
}

void tri_cocktail(int tab[], int taille){
    bool swap = true;
    int debut = 0;
    int fin = taille-2;

    while(swap == true){
        swap = false;
        int tmp; 
        for(int i = debut; i <= fin; i++){
            if(tab[i] > tab[i+1]){
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                swap = true;
            }
        }
        fin--;
        for(int i = fin; i >= debut; i--){
            if(tab[i] > tab[i+1]){
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                swap = true;
            }
        }
        debut++;  
    }
}

void algorithme_tri_par_insertion(int *tab, int taille){
    int i, j, x;
    for(i = 1; i < taille; i++){
        x = tab[i];
        j = i;
        while(j > 0 && tab[j-1] > x){
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = x;
    }
}

int trouver_max(int *tab, int taille){
    int indice_max = 0;
    for(int i = 1; i < taille; i++){
        if(tab[i] > tab[indice_max]){
            indice_max = i;
        }
    }
    return tab[indice_max];
}

void algorithme_tri_par_comptage(int *tab, int taille){
    int max = trouver_max(tab, taille);
    int x = 0;
    int *comptage = (int*)calloc(max+1, sizeof(int));  
    for(int i = 0; i < taille; i++){
        comptage[tab[i]] = comptage[tab[i]] + 1;
    }
    for(int i = 0; i <= max; i++){  
        for(int j = 0; j < comptage[i]; j++){  
            tab[x] = i;
            x++;
        }
    }
    free(comptage);  
}

int* fusion_simple(const int T1[], const int T2[], int s1, int s2) {
    int *T = malloc(sizeof(int) * (s1 + s2));
    if (!T) exit(1);

    int i = 0, j = 0, k = 0;

    while (i < s1 && j < s2) {
        if (T1[i] <= T2[j])
            T[k++] = T1[i++];
        else
            T[k++] = T2[j++];
    }

    while (i < s1)
        T[k++] = T1[i++];

    while (j < s2)
        T[k++] = T2[j++];

    return T;
}
int* tri_fusion(int tab[], int debut, int fin) {
    int taille = fin - debut + 1;

    if (taille == 1) {
        int *res = malloc(sizeof(int));
        res[0] = tab[debut];
        return res;
    }

    int milieu = (debut + fin) / 2;
    int taille_1 = milieu - debut + 1;
    int taille_2 = fin - milieu;

    int *tab_1 = tri_fusion(tab, debut, milieu);
    int *tab_2 = tri_fusion(tab, milieu + 1, fin);

    int *tab_fusion = fusion_simple(tab_1, tab_2, taille_1, taille_2);

    free(tab_1);
    free(tab_2);

    return tab_fusion;
}


int partition(int *tab, int debut, int fin) {
    int pivot = tab[fin];
    int i = debut;

    for (int j = debut; j < fin; j++) {
        if (tab[j] <= pivot) {
            int tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
        }
    }

    int tmp = tab[i];
    tab[i] = tab[fin];
    tab[fin] = tmp;

    return i;
}

void tri_rapide(int *tab, int debut, int fin) {
    if (debut >= fin) return;

    int pivot_index = partition(tab, debut, fin);

    tri_rapide(tab, debut, pivot_index - 1);
    tri_rapide(tab, pivot_index + 1, fin);
}

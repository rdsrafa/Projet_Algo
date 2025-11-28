#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (debut >= fin) {
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


int main(){
    return 0;
}
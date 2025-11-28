#include <stdio.h>
#include <stdlib.h>

void benchmark(char *nom, int taille, int min, int max)
{
    int i,val,j;
    FILE *fp;
    fp=fopen(nom,"w");
    fprintf(fp,"%d\n",taille);
    
    // Tableau croissant
    for(i=0; i<taille; i++) fprintf(fp,"%d ",i);
    fprintf(fp,"\n");
    
    // Tableau décroissant
    for(i=0; i<taille; i++) fprintf(fp,"%d ",taille-i-1);
    fprintf(fp,"\n");
    
    // Tableau constant
    val = rand()%(max-min)+min;
    for(i=0; i<taille; i++) fprintf(fp,"%d ",val);
    
    // Tableaux aléatoires
    for(i=0; i<500; i++)
    {
        fprintf(fp,"\n");
        for(j=0; j<taille; j++) fprintf(fp,"%d ",rand()%(max-min)+min);
    }
    fclose(fp);
}

int main(){
    char nom[255];
    int taille;
    
    printf("🔧 Génération des benchmarks...\n\n");
    
    printf(" Génération des tableaux avec GRANDES valeurs (0-1000000)...\n");
    for(taille = 1000; taille<=25000; taille += 1000){
        sprintf(nom,"benchmark_grande_%d.txt",taille);
        benchmark(nom, taille, 0, 1000000);
        printf("    %s\n", nom);
    }
    

    printf("\n Génération des tableaux avec PETITES valeurs (0-100)...\n");
    for(taille = 1000; taille<=25000; taille += 1000){
        sprintf(nom,"benchmark_petite_%d.txt",taille);
        benchmark(nom, taille, 0, 100);  /
        printf("    %s\n", nom);
    }
    
    printf("\n Génération terminée !\n");
    printf(" Fichiers créés :\n");
    printf("   - benchmark_grande_*.txt (valeurs 0-1000000)\n");
    printf("   - benchmark_petite_*.txt (valeurs 0-100)\n");
    
    return 0;
}

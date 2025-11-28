#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *cmd = (char*)malloc(sizeof(char) * 6000);
    
    printf("Generation des graphiques separes...\n\n");
    

    printf("1. Aleatoire - Petites valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableaux ALEATOIRES - Petites valeurs (0-100)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_aleatoire_petite.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_aleatoire_petite.png");
    system(cmd);
    

    printf("2. Aleatoire - Grandes valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableaux ALEATOIRES - Grandes valeurs (0-1000000)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_aleatoire_grande.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_aleatoire_grande.png");
    system(cmd);

    printf("3. Croissant - Petites valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau CROISSANT - Petites valeurs (0-100)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_croissant_petite.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_croissant_petite.png");
    system(cmd);
    

    printf("4. Croissant - Grandes valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau CROISSANT - Grandes valeurs (0-1000000)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_croissant_grande.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_croissant_grande.png");
    system(cmd);
    

    printf("5. Decroissant - Petites valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau DECROISSANT - Petites valeurs (0-100)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_decroissant_petite.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_decroissant_petite.png");
    system(cmd);

    printf("6. Decroissant - Grandes valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau DECROISSANT - Grandes valeurs (0-1000000)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_decroissant_grande.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_decroissant_grande.png");
    system(cmd);
    
    // ========== 7. CONSTANT - PETITES valeurs ==========
    printf("7. Constant - Petites valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau CONSTANT - Petites valeurs (0-100)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_constant_petite.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_constant_petite.png");
    system(cmd);
    

    printf("8. Constant - Grandes valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tableau CONSTANT - Grandes valeurs (0-1000000)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot for [i=2:10] 'resultats_constant_grande.csv' using 1:i title columnheader lw 2.5 ps 1.5\" > graph_constant_grande.png");
    system(cmd);
    

    printf("9. Comparaison 3 versions Bulle - Petites\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Comparaison 3 versions BULLE - Petites valeurs'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_aleatoire_petite.csv' using 1:2 title 'Bulle v1' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:3 title 'Bulle v2' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:4 title 'Bulle v3' lw 2.5 ps 2\" > graph_comparaison_bulles_petite.png");
    system(cmd);
    

    printf("10. Comparaison 3 versions Bulle - Grandes\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Comparaison 3 versions BULLE - Grandes valeurs'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_aleatoire_grande.csv' using 1:2 title 'Bulle v1' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:3 title 'Bulle v2' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:4 title 'Bulle v3' lw 2.5 ps 2\" > graph_comparaison_bulles_grande.png");
    system(cmd);

    printf("11. Meilleurs algorithmes - Petites valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Algorithmes performants - PETITES valeurs'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_aleatoire_petite.csv' using 1:7 title 'Insertion' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:8 title 'Comptage' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:9 title 'Fusion' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:10 title 'Rapide' lw 2.5 ps 2\" > graph_meilleurs_petite.png");
    system(cmd);
    
 
    printf("12. Meilleurs algorithmes - Grandes valeurs\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Algorithmes performants - GRANDES valeurs'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_aleatoire_grande.csv' using 1:7 title 'Insertion' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:8 title 'Comptage' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:9 title 'Fusion' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:10 title 'Rapide' lw 2.5 ps 2\" > graph_meilleurs_grande.png");
    system(cmd);
    

    printf("13. Tri COMPTAGE - Impact des valeurs (COMPARAISON DIRECTE)\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri COMPTAGE - Impact MAJEUR des valeurs'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_aleatoire_petite.csv' using 1:8 title 'Comptage PETITES (0-100)' lw 3 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:8 title 'Comptage GRANDES (0-1M)' lw 3 ps 2\" > graph_comptage_comparaison.png");
    system(cmd);
    

    printf("\n=== Generation des analyses specifiques par algorithme ===\n");
    

    printf("14. Tri Bulle v1 - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri BULLE v1 - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:2 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:2 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:2 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:2 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:2 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:2 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:2 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:2 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_bulle1_scenarios.png");
    system(cmd);

    printf("15. Tri Bulle v2 - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri BULLE v2 - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:3 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:3 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:3 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:3 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:3 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:3 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:3 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:3 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_bulle2_scenarios.png");
    system(cmd);
    
    printf("16. Tri Bulle v3 - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri BULLE v3 - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:4 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:4 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:4 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:4 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:4 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:4 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:4 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:4 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_bulle3_scenarios.png");
    system(cmd);
    

    printf("17. Tri Cocktail - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri COCKTAIL - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:5 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:5 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:5 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:5 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:5 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:5 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:5 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:5 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_cocktail_scenarios.png");
    system(cmd);
    

    printf("18. Tri Selection - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri SELECTION - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:6 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:6 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:6 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:6 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:6 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:6 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:6 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:6 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_selection_scenarios.png");
    system(cmd);
    

    printf("19. Tri Insertion - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri INSERTION - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:7 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:7 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:7 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:7 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:7 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:7 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:7 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:7 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_insertion_scenarios.png");
    system(cmd);
    

    printf("20. Tri Comptage - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri COMPTAGE - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:8 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:8 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:8 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:8 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:8 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:8 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:8 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:8 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_comptage_scenarios.png");
    system(cmd);
    

    printf("21. Tri Fusion - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri FUSION - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:9 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:9 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:9 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:9 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:9 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:9 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:9 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:9 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_fusion_scenarios.png");
    system(cmd);
    

    printf("22. Tri Rapide - Tous scenarios\n");
    strcpy(cmd, "gnuplot -e \"set terminal png size 1400,900; ");
    strcat(cmd, "set title 'Tri RAPIDE - Tous scenarios (Petites vs Grandes)'; ");
    strcat(cmd, "set key outside right; set xlabel 'Taille'; set ylabel 'Temps (s)'; ");
    strcat(cmd, "set datafile separator comma; set style data linespoints; set grid; ");
    strcat(cmd, "plot 'resultats_croissant_petite.csv' using 1:10 title 'Croiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_croissant_grande.csv' using 1:10 title 'Croiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_decroissant_petite.csv' using 1:10 title 'Decroiss petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_decroissant_grande.csv' using 1:10 title 'Decroiss GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_constant_petite.csv' using 1:10 title 'Constant petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_constant_grande.csv' using 1:10 title 'Constant GRANDE' lw 2.5 ps 2 dt 2, ");
    strcat(cmd, "'resultats_aleatoire_petite.csv' using 1:10 title 'Alea petite' lw 2.5 ps 2, ");
    strcat(cmd, "'resultats_aleatoire_grande.csv' using 1:10 title 'Alea GRANDE' lw 2.5 ps 2 dt 2\" > graph_rapide_scenarios.png");
    system(cmd);
    
    free(cmd);
    
    printf("\n=== TERMINE ===\n");
    printf("22 graphiques generes :\n");
    printf("  1. graph_aleatoire_petite.png\n");
    printf("  2. graph_aleatoire_grande.png\n");
    printf("  3. graph_croissant_petite.png\n");
    printf("  4. graph_croissant_grande.png\n");
    printf("  5. graph_decroissant_petite.png\n");
    printf("  6. graph_decroissant_grande.png\n");
    printf("  7. graph_constant_petite.png\n");
    printf("  8. graph_constant_grande.png\n");
    printf("  9. graph_comparaison_bulles_petite.png\n");
    printf(" 10. graph_comparaison_bulles_grande.png\n");
    printf(" 11. graph_meilleurs_petite.png\n");
    printf(" 12. graph_meilleurs_grande.png\n");
    printf(" 13. graph_comptage_comparaison.png\n");
    printf("\n=== Analyses specifiques par algorithme ===\n");
    printf(" 14. graph_bulle1_scenarios.png\n");
    printf(" 15. graph_bulle2_scenarios.png\n");
    printf(" 16. graph_bulle3_scenarios.png\n");
    printf(" 17. graph_cocktail_scenarios.png\n");
    printf(" 18. graph_selection_scenarios.png\n");
    printf(" 19. graph_insertion_scenarios.png\n");
    printf(" 20. graph_comptage_scenarios.png\n");
    printf(" 21. graph_fusion_scenarios.png\n");
    printf(" 22. graph_rapide_scenarios.png\n");
    
    return 0;
}

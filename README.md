# IN3I21 - Compression Huffman

## Description des fichiers
content.c, content.h : Structure contenant les données.
tas.c, tas.h : Librarie pour la gestion de tas.  
tas_huffman.c, tas_huffman.h : Librarie pour la gestion de tas_huffman.  

## TODO
Général :
-transformer dictinary en content : actualiser fonction free et alloc
-Ne pas tout mettre dans le main.c  

Silvère :
-Faire un systeme de test pour tashuffman (reprendre exemple contrôle)  

-tas.c & tas.h isLeaf(id) (est une feuille)  
-tas.c & tas.h tas_node_is_full(id)  
-tas.c & tas.h mergeTas(tas1, tas2, contentSommet)  

-tas_huffman.c finir tas_huffman_get_min_node + test  
-tas_huffman.c tas_huffman_add_one_layer  
-tas_huffman.c create_tas_huffman  
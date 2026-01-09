
----- LAST RECTIF AVANT PUSH -------

Norme src + includes : OK
Makefile sans wildcards : OK

Bug map : 14 lignes OK / 15 Error








------------- ERROR HANDLING ----------------

HEADER 

1 - Une ligne manquante dans le header : OK
2 - Ligne invalide (Lettres invalides/chemin de la texture incorrect) : OK
3 - Doublon : OK
4 - Texture dans une autre extension que le .xpm : OK
5 - Un espace/tabs après le path de la texture : OK
6 - Une tab où un espace avant la ligne : OK
7 - Changer l'ordre des lignes du Header : OK
8 - Plusieurs saut de lignes entre deux lignes du Header : OK

MAP 

2 - map coupée par des lignes vides : OK
4 - Si on crée une île : ERROR ----> À patcher
9 - Espaces après une ligne de map : OK
1 - Tab dans la map : OK
3 - Plusieurs retours à la ligne à la fin du fichier : OK
5 - Plusieurs player pos : OK
6 - Mauvais caractère pour le player pos : OK
7 - Pas de player pos : OK
8 - Caractère invalide sur la map : OK

------- ERROR ------------

2 - Peu importe par quoi on remplace NO dans le header ça fonctionne quand même.
3 - test.cub ne fonctionne pas, alors qu'elle devrait.



Résumé -----

1 - ray.x et ray.y correspondent aux coordonnées du point d'impact du rayon avec un obstacle (Un mur).

2 - Selon si le côté du mur touché est horizontal où vertical, on va récupérer la partie décimale de x où y.
Ce coef_coord va correspondre à la position de la colonne de la texture que l'on souhaite afficher. 

3 - On a calculé au préalable la hauteur de l'obstacle depuis notre position. start_y étant le point auquel le mur commence, et end_y celui ou il termine.
end_y - start_y = wall_height.

4 - Wall_height nous donne une valeur fixe. Cependant, notre texture doit être mise à l'echelle puisqu'elle a une résolution de 64x64, et qu'on veut qu'elle soit
affichée complêtement, et non pas seulement une partie de celle-çi.
En conséquence, si le mur est plus grand que la texture, on va répéter chaque pixel le nombre de fois nécessaires, si il est plus petit, on réduit. 

5 - Ce coefficient de scaling sera donc float scale = texture_height / wall_height.

6 - Pour chaque pixel de la bande verticale (entre start_y et end_y) on doit :
---> Trouver la bonne position dans la texture (coordonnées texture_x et texture_y)
---> Récupérer la couleur de ce pixel dans la texture.
---> Dessiner ce pixel à la position correspondante dans l'écran (De haut en bas?)












On reprend tout depuis le début :


1 - mlx_init() ---> On initialise la minilibx avec qui retourne un pointeur vers un contexte minilibx, requis pour les fonctions
de manipulation de la fenetre.

2 - mlx_new_window(void *mlx_ptr, int width, int height, char *title) --> Création de la fenetre graphique, avec le pointeur
sur le contexte minilibx, largeur et hauteur d´ecran, et le nom de la fenetre graphique.

3 - mlx_xpm_file_to_image(void *mlx_ptr, char *file, int *witdh, int *height) 
---> Sert a charger une image en memoire (texture en .xpm). Cette fonction renvoie un pointeur sur l'image chargee en memoire.

C'est ici que cub3d differe de so_long, dans la gestion des images. Dans so_long on appliquait directement l'image chargee sur l'image mlx avec mlx_put_image_to_window, a un endroit particulier, avec la resolution voulu.
Dans cub3d on va fonctionner differemment.

4 - mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
---> Une fois notre texture .xpm chargée par mlx_xpm_file_to_image(), on récupère le pointeur sur l'image chargée en memoire. Get_data_addr va prendre le pointeur sur l'image, et les variables d'une structure qui va récupérer les informations de l'image xpm. On s'en servira ensuite pour dessiner les pixels de l'image avec pixel_put, et les calculs du raycasting. 


---- Raycasting & textures----

Afin d'appliquer la bonne partie des pixels de la textures, on va avoir besoin de plusieurs composantes.

Tout d'abord, on va stocker le void * renvoyé par get_addr dans un int *, puisque cette fonction nous renvoie un pointeur sur le premier octet
de la texture, qui contrairement on fichier xpm va être stocké en ligne, pas en tableau 2D. 

Exemple, pour une texture 64x64 on va avoir une ligne de 64 x 64 x 4(bytes). 
Donc, si on veut récupérer le pixel en coordonnées {2, 5} de la texture, on fera une fonction get_pixel(y, x) qui renverra l'addr[width * y + x] (Donc 64 * 2 + 5);


1 - La coordonnée d'impact du rayon, donc le vecteur du hit. 
2 - Pour chaque rayon, on va donc faire math.floor(x) (x étant l'ordonnée du point d'impact du ray)
si on a hit_y = 2, hit_x = 4,7, math.floor de 4,7 va nous renvoyer l'arrondi à l'entier inférieur, donc 4. On va soustraire ce résultat à hit_x
ce qui nous donne donc 0,7. 
3 - Ce 0,7 va nous servir a print la colonne 70% de la textures. Pour scale correctement la texture à la résolution du l'écran, on aura un calcul
à effectuer pour répéter le print du pixel * la valeur nécessaire pour scale la texture.

In fine, notre boucle de display ressemblera à :

for(int it = 0; it++; i < height) (height, parce qu'on print colonne par colonne)
{
	mlx_pixel_put(addr[width * it + (width / math.floor(hit.x))])
}

example.xpm {
	.widht = 20,
	.height = 20,
	.bpp = 4,
};

void * addr = mlx_xpm_to_addr(example.xpm);

sizeof(void *) --> 20 * 20 * 4

char *addr = (char *) addr;
int *addr = (int *) addr;

get pixel (y = 2, x = 5) --> addr[width * y + 5]

ray(2, 4.7)


for (0..height) |it| {
	mlx_pixel_put(addr[width * it + (width / 0.7)])
}


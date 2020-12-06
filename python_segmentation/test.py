from PIL import Image  # Importation de la librairie d'image PIL
from math import sqrt

image_ = Image.open(
    "Image8.bmp"
)  # Ouverture du fichier d'image (voir plus bas pour d'autres formats)
# Importer les données des pixels sous forme d'une matrice px :
matrice_pixels = image_.load()  # chargement des pixels de l'image
# Obtenir la taille de cette image :
width, height = image_.size
# Afficher l'image à l'écran
image_.show()
# Ecrire une image sur le disque
image_.save("nom_dur_disque.bmp")

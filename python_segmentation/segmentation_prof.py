from PIL import Image  # Importation de la librairie d'image PIL
import math


def GetPixel(x, y):
    print(f"matrice_pixels[x, y]: {matrice_pixels[x, y]}")
    return matrice_pixels[x, y]


def PutPixel(x, y, r, g, b, t):
    matrice_pixels[x, y] = int(r), int(g), int(b), int(t)  # Il faut des ints !


def PutRegion(x, y, width, height, quad_color):
    for i in range(x, x + width):
        for j in range(y, y + height):
            PutPixel(i, j, quad_color[0], quad_color[1], quad_color[2], quad_color[3])


def Average(corner_x, corner_y, region_w, region_h):
    sum_red, sum_green, sum_blue, sum_trans = 0, 0, 0, 0  # Initialisation des compteurs
    area = region_w * region_h  # Calcul de la superficie de la région
    for i in range(corner_x, corner_x + region_w):
        for j in range(corner_y, corner_y + region_h):
            r, g, b, t = GetPixel(i, j)  # Nous lisons les données r, v, b d'un pixel
            sum_red += r  # somme de chaque composant
            sum_green += g
            sum_blue += b
            sum_trans += t

    # Normalisation
    sum_red /= area
    sum_green /= area
    sum_blue /= area
    sum_trans /= area

    return (
        sum_red,
        sum_green,
        sum_blue,
        sum_trans,
    )  # Retour des valeurs r, g, b moyennes


def Mesures_Std_et_Mu(corner_x, corner_y, region_w, region_h):
    av_red, av_blue, av_green, av_trans = Average(
        corner_x, corner_y, region_w, region_h
    )
    sum_red2, sum_green2, sum_blue2, sum_trans2 = 0.0, 0.0, 0.0, 0.0
    for i in range(corner_x, corner_x + region_w):
        for j in range(corner_y, corner_y + region_h):
            red, green, blue, trans = GetPixel(i, j)
            sum_red2 += red ** 2
            sum_green2 += green ** 2
            sum_blue2 += blue ** 2
            sum_trans2 += trans ** 2

    area = region_w * region_h * 1.0
    r, g, b, t = 0, 0, 0, 0
    r = math.sqrt(abs(sum_red2 / area - av_red ** 2))
    g = math.sqrt(abs(sum_green2 / area - av_green ** 2))
    b = math.sqrt(abs(sum_blue2 / area - av_blue ** 2))
    t = math.sqrt(abs(sum_trans2 / area - av_trans ** 2))
    return ((av_red, av_blue, av_green, av_trans), (r + b + g + t) / 4.0)


def Decouper_en4(x, y, width, height, threshold_alpha):
    if height * width < 4:
        return  # rien à découper
    # Cas de région uniforme : une couleur uniforme est affectée à la partition
    color, rm = Mesures_Std_et_Mu(x, y, width, height)
    if rm < threshold_alpha:  # Affectation de la couleur moyenne à la partition
        PutRegion(x, y, width, height, color)
    else:  # Dans le cas contraire, la partition non−uniforme est coupée en 4 (récursivement)
        Decouper_en4(x, y, width // 2, height // 2, threshold_alpha)
        Decouper_en4(x + width // 2, y, width // 2, height // 2, threshold_alpha)
        Decouper_en4(x, y + height // 2, width // 2, height // 2, threshold_alpha)
        Decouper_en4(
            x + width // 2, y + height // 2, width // 2, height // 2, threshold_alpha
        )


def save_image(image: object, file_name: str):
    """Save image in current path with file_name."""
    print("Start save_image")
    save_name = file_name + ".bmp"
    image.save(save_name)
    print("End save_image")


if __name__ == "__main__":
    # nom_fic_image="Image_Lyon.bmp"
    image_ = Image.open("image.bmp")
    matrice_pixels = image_.load()  # Importation des pixels de l'image
    width, height = image_.size
    Decouper_en4(0, 0, width, height, 25)
    # On sauvegarde le résultat
    save_image(image_, "save_test_2")

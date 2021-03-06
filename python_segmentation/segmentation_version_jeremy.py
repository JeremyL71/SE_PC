from PIL import Image  # Importation de la librairie d'image PIL
import random
import math


def random_pixel_value():
    """Get random pixel value between 0 and 255."""
    return random.randint(0, 255)


def random_data_color():
    """Get random_data_color."""
    data_color = {
        "red_value": random_pixel_value(),
        "green_value": random_pixel_value(),
        "blue_value": random_pixel_value(),
        "transparency_value": random_pixel_value(),
    }
    return data_color


def get_width_height(image: object):
    """Get width and height into a dict.

    example:
    {
        "width": 300,
        "height": 500
    }
    """
    print("Start get_width_height")
    width, height = image.size
    size_data = {"width": width, "height": height}
    print(f"size_data: {size_data}")
    print("End get_width_height")
    return size_data


def get_dict_pixel_color(matrice_pixels: list, coord_x: int, coord_y: int):
    """Get value of Red, Green, Blue, transparency" from pixel into a dict.

    example:
    {
        "red_value": 155,
        "green_value"": 60,
        "blue_value"": 6,
        "transparency_value"": 255,
    }
    """
    print("Start get_dict_pixel_color")
    tuple_r_g_b_t = matrice_pixels[coord_x, coord_y]
    dict_pixel_color = {
        "red_value": tuple_r_g_b_t[0],
        "green_value": tuple_r_g_b_t[1],
        "blue_value": tuple_r_g_b_t[2],
        "transparency_value": tuple_r_g_b_t[3],
    }
    print(f"dict_pixel_color: {dict_pixel_color}")
    print("End get_dict_pixel_color")
    return dict_pixel_color


def create_matrice_pixels(image: object):
    print("Start create_matrice_pixels")
    matrice_pixels = image.load()
    print(f"matrice_pixels: {matrice_pixels}")
    print("End create_matrice_pixels")
    return matrice_pixels


def open_image(path: str):
    """Return image object."""
    print("Start open_image")
    image = Image.open(path)
    print("End open_image")
    return image


def print_image(image: object):
    print("Start print_image")
    """Print image."""
    image.show()
    print("End print_image")


def save_image(image: object, file_name: str):
    """Save image in current path with file_name."""
    print("Start save_image")
    save_name = file_name + ".bmp"
    image.save(save_name)
    print("End save_image")


def average_color_region(
    matrice_pixels: list,
    cornet_x: int,
    corner_y: int,
    width_region: int,
    height_region: int,
):
    """Return average color pixems"""
    print("Start average_color_region")
    sum_red, sum_green, sum_blue, sum_transparency = 0, 0, 0, 0
    area = width_region * height_region

    for pixel_x in range(cornet_x, cornet_x + width_region):
        for pixel_y in range(corner_y, corner_y + height_region):
            dict_pixel_color = get_dict_pixel_color(matrice_pixels, pixel_x, pixel_y)
            sum_red += dict_pixel_color["red_value"]
            sum_green += dict_pixel_color["green_value"]
            sum_blue += dict_pixel_color["blue_value"]
            sum_transparency += dict_pixel_color["transparency_value"]

    sum_red /= area
    sum_green /= area
    sum_blue /= area
    sum_transparency /= area

    dict_sum_color = {
        "sum_red": sum_red,
        "sum_green": sum_green,
        "sum_blue": sum_blue,
        "sum_transparency": sum_transparency,
    }
    print("End average_color_region")
    return dict_sum_color


def put_pixel(matrice_pixels: list, coord_x: int, coord_y: int, data_color: dict):
    """Change value of RGB and transparency pixel.
    return matrice_pixels modified"""

    print(f"data_color: {data_color}")
    matrice_pixels[coord_x, coord_y] = (
        int(data_color["red_value"]),
        int(data_color["green_value"]),
        int(data_color["blue_value"]),
        int(data_color["transparency_value"]),
    )
    return matrice_pixels


def mesures_std_et_mu(
    matrice: list,
    cornet_x: int,
    corner_y: int,
    width_region: int,
    height_region: int,
):
    """ Calcul de l'écart type des couleurs d'une région de l'image."""
    dict_sum_color = average_color_region(
        matrice, cornet_x, corner_y, width_region, height_region
    )
    sum_red2, sum_green2, sum_blue2, sum_transparency = 0.0, 0.0, 0.0, 0.0

    for pixel_x in range(cornet_x, cornet_x + width_region):
        for pixel_y in range(corner_y, corner_y + height_region):
            dict_pixel_color = get_dict_pixel_color(matrice, pixel_x, pixel_y)
            sum_red2 += dict_pixel_color["red_value"] ** 2
            sum_green2 += dict_pixel_color["green_value"] ** 2
            sum_blue2 += dict_pixel_color["blue_value"] ** 2
            sum_transparency += dict_sum_color["sum_transparency"] ** 2

    area = width_region * height_region
    red = math.sqrt(abs(sum_red2 / area - dict_sum_color["sum_red"]))
    green = math.sqrt(abs(sum_green2 / area - dict_sum_color["sum_green"]))
    blue = math.sqrt(abs(sum_blue2 / area - dict_sum_color["sum_blue"]))
    transparency = math.sqrt(
        abs(sum_transparency / area - dict_sum_color["sum_transparency"])
    )

    result = (
        (
            dict_sum_color["sum_red"],
            dict_sum_color["sum_green"],
            dict_sum_color["sum_blue"],
            dict_sum_color["sum_transparency"],
        ),
        (red + blue + green + transparency) / 4.0,
    )
    print(f"mesures_std_et_mu result: {result}")
    return result


def Decoupage_en_4(
    matrice: list, coord_x: int, coord_y: int, width: int, height: int, threshold_alpha
):
    """ Fonction de découpage en quadrilles."""
    if height * width < 4:
        return None
    color, rm = mesures_std_et_mu(matrice, coord_x, coord_y, width, height)
    if rm < threshold_alpha:
        put_region(matrice, coord_x, coord_y, width, height, color)
    else:
        Decoupage_en_4(
            matrice, coord_x, coord_y, width // 2, height // 2, threshold_alpha
        )
        Decoupage_en_4(
            matrice,
            coord_x + width // 2,
            coord_y,
            width // 2,
            height // 2,
            threshold_alpha,
        )
        Decoupage_en_4(
            matrice,
            coord_x,
            coord_y + height // 2,
            width // 2,
            height // 2,
            threshold_alpha,
        )
        Decoupage_en_4(
            matrice,
            coord_x + width // 2,
            coord_y + height // 2,
            width // 2,
            height // 2,
            threshold_alpha,
        )


def put_region(
    matrice_pixels: list,
    width_region: int,
    height_region: int,
    first_coord_x: int,
    first_coord_y: int,
    data_color: dict,
):
    """put color data into a region

    example:

         1 2 3 4 5 6 7 coord_x
      1 ├─────────────│
      2 |             │
      3 |  x x x x    │
      4 |  x x x x    │
      5 |             │
      6 |             │
      7 |             │
      8 |             │
        └─────────────│
    coord_y

    width_region = 4
    height_region = 2
    first_coord_x = 2
    first_coord_y = 3
    """
    print("Start put_region")

    for pixel_x in range(first_coord_x, first_coord_x + width_region):
        for pixel_y in range(first_coord_y, first_coord_y + height_region):

            put_pixel(matrice_pixels, pixel_x, pixel_y, data_color)

    print("End put_region")


def custom_main():
    """Custom main."""
    print("Start custom_main")

    image = open_image("image.bmp")
    matrice = create_matrice_pixels(image)

    width_region = 50
    height_region = 50
    first_coord_x = 25
    first_coord_y = 25
    data_color = random_data_color()

    dict_average_color = average_color_region(
        matrice, first_coord_x, first_coord_y, width_region, height_region
    )
    print(f"dict_average_color: {dict_average_color}")

    put_region(
        matrice, width_region, height_region, first_coord_x, first_coord_y, data_color
    )

    put_region(
        matrice, width_region, height_region, first_coord_x, first_coord_y, data_color
    )
    save_image(image, "save_me")

    print("End custom_main")


if __name__ == "__main__":
    print("Start main")

    image = open_image("little_image.bmp")
    matrice = create_matrice_pixels(image)
    size_data = get_width_height(image)
    print_image(image)
    threshold_alpha = 1

    Decoupage_en_4(
        matrice, 0, 0, size_data["width"], size_data["height"], threshold_alpha
    )
    save_image(image, "save_test")

    print("End main")

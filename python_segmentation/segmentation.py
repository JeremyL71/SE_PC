from PIL import Image  # Importation de la librairie d'image PIL
import random


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


def Get_r_g_b_t(matrice_pixels: list, coord_x: int, coord_y: int):
    """Get value of Red, Green, Blue, transparency" from pixel into a dict.

    example:
    {
        "red_value": 155,
        "green_value"": 60,
        "blue_value"": 6,
        "transparency_value"": 255,
    }
    """
    print("Start Get_r_g_b_t")
    tuple_r_g_b_t = matrice_pixels[coord_x, coord_y]
    r_g_b_t_data = {
        "red_value": tuple_r_g_b_t[0],
        "green_value": tuple_r_g_b_t[1],
        "blue_value": tuple_r_g_b_t[2],
        "transparency_value": tuple_r_g_b_t[3],
    }
    print(f"r_g_b_t_data: {r_g_b_t_data}")
    print("End Get_r_g_b_t")
    return r_g_b_t_data


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


def put_pixel(matrice_pixels: list, coord_x: int, coord_y: int, data_color: dict):
    """Change value of RGB and transparency pixel.
    return matrice_pixels modified"""
    print("Start put_pixel")
    matrice_pixels[coord_x, coord_y] = (
        int(data_color["red_value"]),
        int(data_color["green_value"]),
        int(data_color["blue_value"]),
        int(data_color["transparency_value"]),
    )
    print("End put_pixel")
    return matrice_pixels


def put_region(
    matrice_pixels: list,
    width_region: int,
    height_region: int,
    first_coord_x: int,
    first_coord_y: int,
    data_color: dict,
):
    """put color data into a region"""
    print("Start put_region")

    for pixel_x in range(first_coord_x, first_coord_x + width_region):
        for pixel_y in range(first_coord_y, first_coord_y + height_region):

            put_pixel(matrice_pixels, pixel_x, pixel_y, data_color)

    print("End put_region")


if __name__ == "__main__":
    print("Start main")

    image = open_image("image.bmp")
    matrice = create_matrice_pixels(image)
    size_data = get_width_height(image)

    width_region = 50
    height_region = 50
    first_coord_x = 25
    first_coord_y = 25
    data_color = random_data_color()

    put_region(matrice, width_region, height_region, first_coord_x, first_coord_y, data_color)

    save_image(image, "save_me")

    print("End main")

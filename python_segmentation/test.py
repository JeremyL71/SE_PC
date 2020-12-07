from PIL import Image  # Importation de la librairie d'image PIL


def get_width_height(image: object):
    """Get width and height into a dict."""
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
        "red": 155,
        "green": 60,
        "blue": 6,
        "transparency": 255,
    }
    """
    print("Start Get_r_g_b_t")
    tuple_r_g_b_t = matrice_pixels[coord_x, coord_y]
    r_g_b_t_data = {
        "red": tuple_r_g_b_t[0],
        "green": tuple_r_g_b_t[1],
        "blue": tuple_r_g_b_t[2],
        "transparency": tuple_r_g_b_t[3],
    }
    print(f"r_g_b_t_data: {r_g_b_t_data}")
    print("End Get_r_g_b_t")
    return r_g_b_t_data


def create_matrice_pixels(image_: object):
    print("Start create_matrice_pixels")
    matrice_pixels = image_.load()
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


if __name__ == "__main__":
    print("Start main")

    image = open_image("image.bmp")
    matrice = create_matrice_pixels(image)

    r_g_b_t_data = Get_r_g_b_t(matrice, 1, 1)
    size_data = get_width_height(image)
    save_image(image, "save_me")

    print("End main")

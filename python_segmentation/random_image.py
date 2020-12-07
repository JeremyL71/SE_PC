from PIL import Image
import random

imagePath = "image.bmp"
newImagePath = "image_random.bmp"
im = Image.open(imagePath)


def random_color():
    return random.randint(0, 255)


def random_tableau(im):
    newimdata = []
    for color in im.getdata():
        newimdata.append((random_color(), random_color(), random_color()))
    newim = Image.new(im.mode, im.size)
    newim.putdata(newimdata)
    return newim


random_tableau(im).save(newImagePath)

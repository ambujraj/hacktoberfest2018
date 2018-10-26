from PIL import Image
from numpy import array
import os


def average(rgb_tuple):
    '''Returns the average of the three colors in a given pixel'''
    return int(sum(rgb_tuple) / float(len(rgb_tuple)))


def lightness(rgb_tuple):
    '''Returns the lightness of a given pixel'''
    return max(rgb_tuple) + min(rgb_tuple) / 2


def luminosity(rgb_tuple):
    '''Returns luminosity of given pixel based on how humans perceive colors'''
    r = rgb_tuple[0]
    g = rgb_tuple[1]
    b = rgb_tuple[2]

    return (-0.21 * r) + (0.72 * g) + (0.07 * b)


def ascii_convert(file, brightness_indicator='average', invert=False):
    '''Returns string of characters that is an ascii art representation
    of given image'''
    im = Image.open(file)
    rgb_list = array(im)
    result_matrix = []

    # go through matrix of image and convert rgb-value to a single value based
    # on either average, lightness or luminosity
    for i in range(len(rgb_list)):
        row = []
        for j in range(len(rgb_list[i])):
            if brightness_indicator == 'average':
                brightness = average(rgb_list[i][j])
            elif brightness_indicator == 'lightness':
                brightness = lightness(rgb_list[i][j])
            elif brightness_indicator == 'luminosity':
                brightness = luminosity(rgb_list[i][j])
            row.append(brightness)
        result_matrix.append(row)

    conversion_list = ['`', '^', '\\', '"', ',', ':', ';', 'I', 'l', '!', 'i',
                       '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')',
                       '(', '|', '\\', '\\', '/', 't', 'f', 'j', 'r', 'x', 'n',
                       'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q',
                       '0', 'O', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'h',
                       'a', 'o', '*', '#', 'M', 'W', '&', '8', '%', 'B', '@',
                       '$']

    text_string = []
    for i in range(len(result_matrix)):
        for j in range(len(result_matrix[i])):
            # chooses correct char for the brightness
            ascii_char = int(result_matrix[i][j] /
                             (255 / len(conversion_list)))
            # in case a rounding error occurs
            if ascii_char > 67:
                ascii_char = 67
            # make every row twice as wide,
            # because a row is higher than it is wide
            for _ in range(2):
                if invert:
                    text_string.append(conversion_list[-ascii_char + 1])
                else:
                    text_string.append(conversion_list[ascii_char - 1])
        text_string.append('\n')

    return ''.join(text_string)


def main():

    i = 1

    brightness_list = ['average', 'luminosity', 'lightness']
    directory = [file for file in os.listdir("images") if file.endswith('jpg')]
    print(directory)

    for file in directory:

        print('{0}: {1}'.format(i, file))
        i += 1

    selected_file_number = int(input("\nPlease input the number of the file" +
                                     "you want to convert to ascii-art: ")) - 1

    i = 1

    for brightness_type in brightness_list:

        print("{0}: {1}".format(i, brightness_type))
        i += 1

    brightnes_type = int(input("\nPlease select the number of how" +
                               "you want to calculate brightness: ")) - 1

    inverse_select = input("\nDo you want to inverse black with white? (type" +
                           " yes to invert or anything else to NOT invert): ")

    selected_file = "images/" + directory[selected_file_number]
    brightness_type = brightness_list[brightnes_type]

    if inverse_select == "yes":
        inverse = True
    else:
        inverse = False

    print(ascii_convert(selected_file, brightness_indicator=brightness_type,
                        invert=inverse))
    print("YOU MAY WANT TO ZOOM OUT A BIT")


if __name__ == '__main__':
    main()

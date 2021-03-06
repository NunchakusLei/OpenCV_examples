import cv2, numpy as np
import struct
import sys

def load_float_image(filename):
    # open file
    file = open(filename, "rb")

    # load info
    value = file.read(4)
    width = struct.unpack('i', value)[0]
    value = file.read(4)
    height = struct.unpack('i', value)[0]

    z_image = np.zeros((height, width))
    for y in range(height):
        for x in range(width):
            value = file.read(4)
            a_pixel = struct.unpack('f', value)[0]
            z_image[y][x] = a_pixel

    return z_image



if __name__ == "__main__":
    filename = "32FC1.bin"
    filename = sys.argv[1]
    depth_image = load_float_image(filename)
    print(depth_image)
    depth_image = 255. * (depth_image / 4.)
    cv2.imshow("test", depth_image.astype(np.uint8))
    cv2.waitKey()

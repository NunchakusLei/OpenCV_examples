#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat colorImage;
    colorImage = imread( argv[1], 1 );

    if ( !colorImage.data )
    {
        printf("No image data \n");
        return -1;
    }

    // convert color image to greyscale image
    Mat greyImage;
    cvtColor( colorImage, greyImage, CV_BGR2GRAY);

    namedWindow("Grey Image to Save", WINDOW_AUTOSIZE);
    imshow("Grey Image to Save", greyImage);
    waitKey(0);

    imwrite("greyImage.png", greyImage);
    printf("Saved to file greyImage.png\n");

    return 0;
}

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    // Get user arguments
    if ( argc != 2 )
    {
        printf("usage: ./GetROI <Image_Path>\n");
        return -1;
    }

    // Read image
    Mat colorImage, mask, output;
    colorImage = imread( argv[1], 1 );

    if ( !colorImage.data ) // Validate image data
    {
        printf("No image data \n");
        return -1;
    }

    // Create the mask
    mask.create( colorImage.size(), CV_8UC1 );

    // Create a rectangle as the ROI 
    // Here we try to extract the ROI at the center
    int x = colorImage.size().width / 4;
    int y = colorImage.size().height / 4;
    int width = colorImage.size().width / 2;
    int height = colorImage.size().height / 2;
    cv::Rect rect(x, y, width, height);
    cv::rectangle(mask, rect, cv::Scalar(255), CV_FILLED);

    // Retrieve ROI (method 1)
    colorImage.copyTo( output, mask );

    // Retrieve ROI (method 2)
    // convert color image to greyscale image
    // mask.convertTo( mask, colorImage.type() );
    // cvtColor( mask, mask, CV_GRAY2BGR);
    // cv::bitwise_and( colorImage, mask, output );

    // Display input, mask, and output
    namedWindow("Color Image", WINDOW_AUTOSIZE );
    namedWindow("mask", WINDOW_AUTOSIZE);
    namedWindow("output", WINDOW_AUTOSIZE);
    imshow("Color Image", colorImage);
    imshow("mask", mask);
    imshow("output", output);
    waitKey(0);

    return 0;
}

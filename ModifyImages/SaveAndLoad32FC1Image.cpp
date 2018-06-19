#include <stdio.h>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;

int save32FC1Image(std::string filename, Mat image)
{
  // validate the image type
  if ( image.type() != 5 )
  {
    std::cerr << "The image type trying to save is not CV_32FC1. " << '\n';
    return 1;
  }

  // open a file
  std::ofstream file (filename, std::ios::out | std::ios::binary);

  // save the dimension info
  file.write ((char *) &(image.cols), sizeof (int));
  file.write ((char *) &(image.rows), sizeof (int));

  // save pixels
  // file.write((char*)& image, sizeof(image));
  for (int y = 0; y < image.rows; y++)
  {
    float *rowPtr = image.ptr<float> (y);
    for (int x = 0; x < image.cols; x++)
    {
      file.write ((char *) &(rowPtr[x]), sizeof (float));
    }
  }

  // close file when saving is done
  file.close();
  return 0;
}



int load32FC1Image(std::string filename, Mat * image)
{
  // validate the image type
  if ( image->type() != 0 )
  {
    std::cerr << "The image type is not empty" << '\n';//CV_32FC1. " << '\n';
    return 1;
  }

  // open a file
  std::ifstream file (filename, std::ios::in | std::ios::binary);

  // load the dimension info
  int cols, rows;
  file.read ((char *) &cols, sizeof (int));
  file.read ((char *) &rows, sizeof (int));

  std::cout << " cols : " << cols << " rows : " << rows << std::endl;

  // create iamge
  image->create( Size(cols, rows), CV_32FC1);
  *image = Scalar::all (0);

  // load pixels
  // file.read((char*) image, sizeof(*image));
  for (int y = 0; y < image->rows; y++)
  {
    float *rowPtr = image->ptr<float> (y);
    for (int x = 0; x < image->cols; x++)
    {
      file.read ((char *) &(rowPtr[x]), sizeof (float));
    }
  }

  // close file when loading is done
  file.close();
  return 0;
}



int main(int argc, char** argv )
{
    std::string filename = "32FC1.bin";

    // if ( argc != 2 )
    // {
    //     printf("usage: DisplayImage.out <Image_Path>\n");
    //     return -1;
    // }

    Mat image;
    image.create(Size (5, 5), CV_32FC1);
    image = Scalar::all (256);

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    printf("The Mat type is %d\n", image.type());

    // imwrite("32FC1.png", image);
    save32FC1Image(filename, image);
    std::cout << "image = "<< '\n' << " "  << image << '\n' << std::endl;
    std::cout << "Saved to file " << filename << '\n' << std::endl;


    Mat newImage;
    // newImage.create( Size(image.cols, image.rows), CV_32FC1);
    // newImage = Scalar::all (0);
    // newImage = imread("32FC1.png");
    load32FC1Image(filename, &newImage);
    std::cout << "image = "<< '\n' << " "  << newImage << '\n' << '\n';
    printf("The Mat type is %d\n", newImage.type());


    return 0;
}

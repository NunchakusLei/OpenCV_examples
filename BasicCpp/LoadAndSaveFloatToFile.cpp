#include <iostream>
#include <fstream>

using namespace std;

int saveFloatToFile(string filename, float * data, int data_len)
{
  // open a file
  ofstream file (filename, ios::out | ios::binary);

  // save data to file
  for (int i=0; i<data_len; i++)
  {
    file.write ((char *) &(data[i]), sizeof(float));
  }

  // close file when saving is done
  file.close();
  return 0;
}


int loadFloatFromFile(string filename, float * data, int data_len)
{
  // open a file
  ifstream file (filename, ios::in | ios::binary);

  // load file data
  for (int i=0; i<data_len; i++)
  {
    file.read ((char*) &(data[i]), sizeof(float));
    cout << "Loaded : " << data[i] << '\n';
  }

  // close file when loading is done
  file.close();
  return 0;
}


int main(int argc, char** argv)
{
  float data[10] = {255, 30.1, 1, 2, 3, 4, 5, 6, 7, 8};
  float buff[10];

  saveFloatToFile("result.bin", data, 10);
  cout << "saved to file result.bin" << '\n';

  cout << "reads from file result.bin" << '\n';
  loadFloatFromFile("result.bin", buff, 10);
  for (int i=0; i<10; i++)
  {
    cout << "data loaded: " << buff[i] <<'\n';
  }

  return 0;
}

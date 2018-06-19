#include <iostream>
#include <fstream>

using namespace std;

int saveToFile(string filename, char * data, int data_len)
{
  // open a file
  ofstream file (filename, ios::out | ios::binary);

  // save data to file
  for (int i=0; i<data_len; i++)
  {
    file.write (&(data[i]), sizeof(char));
  }

  // close file when saving is done
  file.close();
  return 0;
}


int loadFromFile(string filename, char * data, int data_len)
{
  // open a file
  ifstream file (filename, ios::in | ios::binary);

  // load file data
  for (int i=0; i<data_len; i++)
  {
    file.read (&(data[i]), sizeof(char));
    cout << "Loaded : " << data[i] << '\n';
  }

  // close file when loading is done
  file.close();
  return 0;
}


int main(int argc, char** argv)
{
  char data[10] = {'a','b','c','d','e','f','g','h','i','j'};
  char buff[10];

  saveToFile("result.bin", data, 10);
  cout << "saved to file result.bin" << '\n';

  cout << "reads from file result.bin" << '\n';
  loadFromFile("result.bin", buff, 10);

  return 0;
}

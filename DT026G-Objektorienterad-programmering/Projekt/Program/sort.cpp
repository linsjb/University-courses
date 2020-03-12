/*=======================================
* Project: Sort DT026G
* Filename: sort.cpp
* Author: Linus Sjöbro
* Author mail: lisj1502@student.miun.se
* =====================================*/
#include "sort.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

using namespace std;

/*============================================================
* Function type: void
* Function name: read_input
* Description: Method to choose wich type of input method to use
* ==========================================================*/
void Sort::read_input(string inputType, string flagInputFileName, char columnDivider)
{
  if(inputType == "pipe")
    pipe_input(columnDivider);

  else if(inputType == "flag")
    flag_input(flagInputFileName, columnDivider);
}

/*============================================================
* Function type: void
* Function name: row_splitter
* Description: Split the readed row from the file and
* push it back into a vector that is the row of the matrix
* ==========================================================*/
void Sort::row_splitter(char columnDivider)
{
  //Create a new vector that hold the row for the 2D vector
  matrix.push_back(newRow);

  //Create a string stream with the current line from the textfile
  istringstream currenLineStream(currentLine);
  string segment;

  //Loop throught the current line and split the line where a colon is presented
  while(getline(currenLineStream, segment, columnDivider))
  {
    //Push back the content (column) for the current line to the vector at the given row
    matrix.at(vectorRowCounter).push_back(segment);
  }
  //Raise the counter to step to the next row in the matrix vector
  vectorRowCounter++;
}

/*============================================================
* Function type: void
* Function name: pipe_input
* Description: Method to use we pipe an input to the program
* ==========================================================*/
void Sort::pipe_input(char columnDivider)
{
  //If a file is not piped via console
  if(isatty(STDIN_FILENO))
    throw string("No file as input");

  //Loop through the file line by line and fetch the line
  while(getline(cin, currentLine))
  {
    //Split the row with the row_splitter method and insert it into our matrix
    row_splitter(columnDivider);
  }
}

/*============================================================
* Function type: void
* Function name: flag_input
* Description: Method to use when we use a flag argument as input
* ==========================================================*/
void Sort::flag_input(string flagInputFileName, char columnDivider)
{
  //Open a filestream
  fstream file(flagInputFileName);

  //Control if the file isn't open
  if(!(file.is_open()))
  {
    //Throw error message to catch
    throw string("File does not exist!");
  }

  //Fetch row by row from the file
  while(file>>currentLine)
  {
    //Split the row with the row_splitter method and insert it into our matrix
    row_splitter(columnDivider);
  }
  file.close();
}

/*============================================================
* Function type: void
* Function name: print
* Description: Method to choose what kind of print we want to do
* ==========================================================*/
void Sort::print(string printType, string outputFilename, bool keyPrint, size_t key)
{
  //Standard print to screen
  if(printType == "screen" && !keyPrint)
    matrix_print();

  //Key only print to screen
  else if(printType == "screen" && keyPrint)
    matrix_print_keyonly(key);

  //Standard print to file
  else if(printType == "file" && !keyPrint)
    flag_output(outputFilename);

  //Key only print to file
  else if(printType == "file" && keyPrint)
    flag_output_keyonly(outputFilename, key);

}

/*============================================================
* Function type: void
* Function name: matrix_print
* Description: Print the matrix to the screen
* ==========================================================*/
void Sort::matrix_print()
{
  //Steg through the rows
  for(int row=0; row<matrix.size(); row++)
  {
    //Steg through the columns
    for(int column=0; column<matrix.at(row).size(); column++)
    {
      cout << matrix[row][column] << " ";
    }
    cout << endl;
  }
}

/*============================================================
* Function type: void
* Function name: matrix_print_keyonly
* Description: Print only the column that is sorted to screen
* ==========================================================*/
void Sort::matrix_print_keyonly(size_t key)
{
  //step through rows
  for(int row=0; row<matrix.size(); row++)
  {
    cout << matrix[row][key] << endl;
  }
}

/*============================================================
* Function type: void
* Function name: flag_output
* Description: Print the matrix to given file
* ==========================================================*/
void Sort::flag_output(string flagOutputFileName)
{
  ofstream file(flagOutputFileName);

  for(int row=0; row<matrix.size(); row++)
  {
    //Steg throught columns
    for(int column=0; column<matrix.at(row).size(); column++)
    {
      file << matrix[row][column] << " ";
    }
    file << endl;
  }
}

/*============================================================
* Function type: void
* Function name: flag_output_keyonly
* Description: Print only the sorted column to given file
* ==========================================================*/
void Sort::flag_output_keyonly(string flagOutputFileName, size_t key)
{
  ofstream file(flagOutputFileName);

  //step through rows
  for(int row=0; row<matrix.size(); row++)
  {
    file << matrix[row][key] << endl;
  }
}

/*============================================================
* Function type: vector
* Function name: matrix_sort
* Description: Sorting the matrix
* Return: matrix
* ==========================================================*/
vector<vector<string> > Sort::matrix_sort(size_t specifiedColumn, bool numrericSort, bool reverseSort)
{
  //Sort the matrix with the comperator
  sort(matrix.begin(), matrix.end(), matrix_sorter_compare(specifiedColumn, numrericSort, reverseSort));
  return matrix;
}

/*============================================================
* Function type: struct
* Function name: matrix_sorter_compare
* Description: Struct that hold's variables and
* operator for sorting
* ==========================================================*/
Sort::matrix_sorter_compare::matrix_sorter_compare(size_t specifiedColumn, bool numrericSort, bool reverseSort)
{
  //Set's this instance values to the values
  this->specifiedColumn = specifiedColumn;
  this->numrericSort = numrericSort;
  this->reverseSort = reverseSort;
}

/*============================================================
* Function type: Bool
* Function name: Operator
* Description: Operator for sorting
* Return: True/false
* ==========================================================*/
bool Sort::matrix_sorter_compare::operator()(vector<string>&a, vector<string>&b)
{
  //If the sort is set to be numreric
  if(numrericSort)
  {
    //Control if the given column is not a number
    if(!(isdigit(a[specifiedColumn][0])) && !(isdigit(b[specifiedColumn][0])))
      //Throw error message to catch
      throw string("Given column is not a number! \nRemove -n option to sort this column");

    //Convert from string to double
    double aNum = stod(a[specifiedColumn]);
    double bNum = stod(b[specifiedColumn]);

    //If the sort is set to be reversed
    if(!reverseSort)
      return aNum < bNum;

    else
      return aNum > bNum;
  }

  //If the sort is alfabetic
  else
  {
    //If the sort is set to be reversed
    if(!reverseSort)
      return a[specifiedColumn] < b[specifiedColumn];

    else
      return a[specifiedColumn] > b[specifiedColumn];
  }
}

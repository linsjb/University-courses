/*=======================================
* Project: Sort DT026G
* Filename: sort.h
* Author: Linus Sjöbro
* Author mail: lisj1502@student.miun.se
* =====================================*/
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <vector>
#include <string>

class Sort
{
  public:
    //Method to choose wich type of input we should use
    void read_input(std::string inputType, std::string flagInputFileName, char columnDivider);

    //Splitt the reded row into sections that is inserter into columns in a matrix
    void row_splitter(char columnDivider);

    //Input a file form terminal via pipe
    void pipe_input(char columnDivider);

    //Input a file from terminal via flag argument
    void flag_input(std::string flagInputFileName, char columnDivider);

    //Method to choose wich type of print we want to do
    void print(std::string printType, std::string outputFilename, bool keyPrint, size_t key);

    //Print the sorted matrix(file) to the screen
    void matrix_print();

    //Print only the sorted column to the screen
    void matrix_print_keyonly(size_t key);

    //Print the matrix(file) to an specified file
    void flag_output(std::string flagOutputFileName);

    //Print only the sorted column to a specified file
    void flag_output_keyonly(std::string flagOutputFileName, size_t key);

    //Sort the matrix after given parameters
    std::vector<std::vector<std::string> > matrix_sort(size_t specifiedColumn, bool numrericSort, bool reverseSort);

  private:
    /*Vector that we use to read everything from a given file,
    sorting the file and printing it*/
    std::vector<std::vector<std::string> > matrix;

    /*Class global variables to be used when we read the files from
    a given file and inserting each segment of the file into
    the vector "matrix" */
    std::vector<std::string> newRow;
    int vectorRowCounter = 0;
    std::string currentLine;

    struct matrix_sorter_compare
    {
      //Struct's constructor
      matrix_sorter_compare(size_t specifiedColumn, bool numrericSort, bool reverseSort);

      //Struct's variables
      size_t specifiedColumn;
      bool numrericSort;
      bool reverseSort;

      //Sorter operator to specify what we want to do with our sorter
      bool operator()(std::vector<std::string>&a, std::vector<std::string>&b);
    };
};

#endif

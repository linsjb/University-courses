/*=======================================
* Project: Sort DT026G
* Filename: main.cpp
* Author: Linus Sjöbro
* Author mail: lisj1502@student.miun.se
* =====================================*/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>

#include "sort.h"

using namespace std;

int main(int argc, char *argv[])
{
  //Holder for the amount of options avaliable for getopt
  const int NUM_OF_FLAGS = 9;

  //Sorting control variables
  bool reverseSort = false;
  bool numrericSort = false;
  size_t specifiedColumn = 0;

  //Divider type control variable
  char columnDivider = ':';

  //Input type control variables
  string flagInputFileName = "";
  string inputType = "pipe";

  //Print to file control variables
  string outputFilename = "";

  //Print type control variables
  string printType = "screen";
  bool keyPrint = false;

  //Bool to disable input control
  bool disableInput = false;

  int getopt;
  while(true)
  {
    //Struct array for getopt options
    struct option options[NUM_OF_FLAGS+1] =
    {
      {"numreric",  no_argument,        nullptr,  'n'},
      {"reverse",   no_argument,        nullptr,  'r'},
      {"column",    required_argument,  nullptr,  'c'},
      {"input",     no_argument,        nullptr,  'i'},
      {"output",    required_argument,  nullptr,  'o'},
      {"keyonly",   no_argument,        nullptr,  'k'},
      {"divider",   required_argument,  nullptr,  'd'},
      {"help",      no_argument,        nullptr,  'h'},
      {"version",   no_argument,        nullptr,  'v'},
      {nullptr,     0,                  nullptr,  0  }
    };

    //Getopt options description
    string optionsDescription[NUM_OF_FLAGS] =
    {
      "Sort the given file in numreric order",
      "Sort the given file reversed",
      "Sort after column N",
      "Use the file as input",
      "Print the sorted result to file instead of screen",
      "Print only the sorted value per row",
      "Specify the divider that seperates the column in file, default is ':'",
      "Print avaliable switches",
      "Print version number",
    };

    //Getopt_long option's index
    int option_index = 0;

    getopt = getopt_long (argc, argv, "nrc:i:o:kd:hv", options, &option_index);

    //Detect the end of the options
    if(getopt == -1)
      break;

    //Switch for getopt arguments
    switch(getopt)
    {
      //Numreric sort
      case 'n':
        numrericSort = true;
        break;

      //Reverse sort
      case 'r':
        reverseSort = true;
        break;

      //Sort after specified column
      case 'c':
        specifiedColumn = atoi(optarg)-1;
        break;

      //File input
      case 'i':
        inputType = "flag";
        flagInputFileName = optarg;
        break;

      //Print to file
      case 'o':
        printType = "file";
        outputFilename = optarg;
        break;

      //Key only
      case 'k':
        keyPrint = true;
        break;

      //Specify char to seperate the columns
      case 'd':
        // columnDivider = optarg;
        break;

      case 'h':
        //Disable input from terminal/console
        disableInput = true;

        cout << "Available switches" <<
            endl << "------------------" << endl << endl;

        //Print out all the options with description
        for(int i=0; i < NUM_OF_FLAGS; i++)
        {
          cout
            << "-" << (char)options[i].val
            << ", --" << options[i].name
            << "  |  " << optionsDescription[i]
            << endl;
        }

        break;

      case 'v':
        //Disable input from terminal/console
        disableInput = true;

        cout << "Version: 1.0" << endl;
        break;

      default:
        return EXIT_FAILURE;
        break;
    }//end getopt switch
  }//end getopt while

  try
  {
    //Create a new instance of sort class
    Sort sorter;

    /*If disable input variable is false
    This means that we will read the input from flag or pipe
    This prevent an error from being printed when we use flag's as help and version*/
    if(!disableInput)
    {
      sorter.read_input(inputType, flagInputFileName, columnDivider);
    }

    //Sort the vector
    sorter.matrix_sort(specifiedColumn, numrericSort, reverseSort);

    //Print the sorted data
    sorter.print(printType, outputFilename, keyPrint, specifiedColumn);
  }//end try

  //Catch errors
  catch(string &error)
  {
    //Print error message
    cerr << error << endl;

    return EXIT_FAILURE;
  }//end catch

  return EXIT_SUCCESS;

}//end main-loop

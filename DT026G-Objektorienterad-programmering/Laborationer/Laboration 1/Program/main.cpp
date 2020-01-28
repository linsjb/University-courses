/*=======================================
* Project: Laboration 1 DT026G
* Filename: main.cpp
* Author: Linus Sjöbro
* Author mail: lisj1502@student.miun.se
* =====================================*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

struct location
{
  string street;
  string city;
  int zip;
};

struct person
{
  string name;
  string id;
  location address;
};

//Function initializations
istream& operator>>(istream& in, person& p);
string get_line(istream& in);
vector<person> read_file(string filename);
size_t find_in_names(vector<person> loadedFile, string searchString);
vector<person> find_person_from_city(vector<person> haystack, string city);
void menu(vector<person> loadedFile);
string input(string out);

int main()
{
  //Loads file into vector
  vector<person> loadedFile = read_file("names.txt");

  menu(loadedFile);

  return 0;
}

/*====================================================================================================
* Function type: void
* Function name: menu
* Description: Programs main menu
* ==================================================================================================*/
void menu(vector<person> loadedFile)
{
  vector<person> persons = loadedFile;

  bool menuControl = true;
  while(menuControl)
  {
    const static char SEARCH_PERSON     = '1';
    const static char SEARCH_CITIES     = '2';
    const static char EXIT_APPLICATION  = '3';

    cout << "Main menu" << endl;
    cout << "1. Search person" << endl;
    cout << "2. Search city" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Choose: ";

    char menuChoice;
    cin >> menuChoice;

    switch (menuChoice)
    {
      //Search persons
      case SEARCH_PERSON:
      {
        system("clear");
        cout << "Search names" << endl << "--------------------" << endl;

        while(true)
        {
          int numberOfNamesFound = find_in_names(persons, input("Search phrase: "));

          //No names found
          if (numberOfNamesFound == 0)
          {
            cout << endl << "No names found!" << endl << endl;
            break;
          }

            //Names found
            else
            {
              //Print results
              cout << "Number of found results: " << numberOfNamesFound << endl << endl;

              //Exit the while loop
              break;
            }// end else
        }// end while
        break;
      }// end case

      case SEARCH_CITIES:
      {
        system("clear");
        cout << "Search city" << endl << "--------------------" << endl;

        while(true)
        {
          vector<person> foundCities = find_person_from_city(persons, input("Search phrase: "));

          //No cities found
          if(foundCities.size() == 0)
          {
            cout << endl << "No cities found!" << endl << endl;
            break;
          }

          //Cities found
          else
          {
            system("clear");
            cout << "Results" << endl << "====================" << endl << "--------------------" << endl;

            for(person p : foundCities)
            {
              //Print search result
              cout << p.name << ", " << p.address.city << endl;
              cout << "--------------------" << endl;
            }// end for

            //Exit the while loop
            break;

            cout << "====================" << endl << endl;
          }// end else
        }// end while
        break;
      }// end case

      //Exit program
      case EXIT_APPLICATION:
      {
        //Breaks out from while loop and kill the program
        menuControl = false;
        system("clear");
        break;
      }// end case

      //Default statement
      default:
      {
        cout << "Wrong input, try again!" << endl << endl;
        break;
      }
    }// exit switch
  }// end while
}// exit menu()

/*====================================================================================================
* Function type: string
* Function name: input
* Description: Read keyboard input from user
* Return type: string
* Return: input
* ==================================================================================================*/
string input(string out)
{
  cout << out;
  string input;
  cin.ignore();
  getline(cin, input);

  return input;

} //end input()

/*====================================================================================================
* Function type: site_t
* Function name: find_in_names
* Description: Search after given name and return number of found results
* Return type: int
* Return: count
* ==================================================================================================*/
size_t find_in_names(vector<person> persons, string name_part)
{
  int count = 0;
  vector<person> loadedFile = persons;

  //Transform search phrase to lowercasing
  transform(name_part.begin(), name_part.end(), name_part.begin(), ::tolower);

  string name;
  //Loop through vector
  for(person p : loadedFile)
  {
    name = p.name;
    //Transform name element in vector to lowercasing
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    //Is the current vector element matching the search phrase?
    bool searchResult = name.find(name_part) != string::npos;

    //If true, add one to counter
    if(searchResult)
    {
      count++;
    }
  }

  return count;

}// end find_in_names()

/*====================================================================================================
* Function type: vector
* Function name: find_person_from_city
* Description: Search after given city and return a vector with the matching elements
* Return type: vector
* Return: searchResult
* ==================================================================================================*/
vector<person> find_person_from_city(vector<person> haystack, string city)
{
  vector<person> searchResult;

  //Transform search phrase to lowercasing
  transform(city.begin(), city.end(), city.begin(), ::toupper);

  string city_;
  //Loop through vector
  for(person p : haystack)
  {
    //Transform city element in vector to uppercasing
    city_ = p.address.city;
    transform(city_.begin(), city_.end(), city_.begin(), ::toupper);

    //Is the current vector element matching the search phrase?
    // bool elementCompare = city_.find(city) != string::npos;

    //If true, push result in to searchResult vector
    // if(elementCompare)
    // {
    //   searchResult.push_back(p);
    // }

    if(city == city_)
    {
      searchResult.push_back(p);
    }
  }

  return searchResult;

}// end find_person_from_city()

/*====================================================================================================
* Function type: vector
* Function name: read_file
* Description: Read textfile in to a vector
* Return type: vector
* Return: fileLoading
* ==================================================================================================*/
vector<person> read_file(string filename)
{
  vector<person> fileLoading;

  ifstream file;
  file.open(filename);

  //Is the file open?
  if(file.is_open())
  {
    //While reading hasn't read through end of file
    while (file && file.peek() != EOF)
    {
      person p;
      file >> p;
      fileLoading.push_back(p);
    }
  }

    //File loading error
    else
    {
      cout << "Error while loading file" << endl;
      return fileLoading;
    }

  file.close();

  return fileLoading;

}// end read_file()

/*====================================================================================================
* In-stream operator
* Description: Catch in-stream operator for struct person p
* Return type: In-stream operator
* Return: in
* ==================================================================================================*/
istream& operator>>(istream& in, person& p)
{
  //Get name line from file
  string name = get_line(in);
  p.name = name;

  //Get ID line from file
  string id = get_line(in);
  p.id = id;

  //Get address line from file
  string address = get_line(in);

  //Find comma in address line
  int commaPos = address.find(",");

  //Find double space in address line
  int doubleSpacePos = address.find("  ");

  //Substract street from address line
  string street = address.substr(0, commaPos);
  p.address.street = street;

  //substract zip from address line
  string zip = address.substr(commaPos + 1, 7);
  zip.erase(remove(zip.begin(), zip.end(), ' '), zip.end());
  int zip_ = stoi(zip);
  p.address.zip = zip_;

  //Substract city from address line
  string city = address.substr(doubleSpacePos + 2, address.length());

  //Is the back of the string a space?
  while(city.back() == ' ')
  {
    //Then remove the space
    city.pop_back();
  }
  p.address.city = city;

  return in;

}// end >> operator

/*====================================================================================================
* Function type: string
* Function name: get_line
* Description: Get current textfile line
* Return type: string
* Return: line
* ==================================================================================================*/
string get_line(istream& in)
{
  string line;
  getline(in, line);

  return line;

}// end get_line()

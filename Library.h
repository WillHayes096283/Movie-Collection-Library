/**
 * @file Library.h
 * @author William Hayes, Jackson Horton, Kenneth Wallace
 * @date 2022-10-11
 * @brief documentation and definitions for Library methods and data members.
 * 
 * This declares the methods and data members for the Library class and movie structure.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

/**
 * The movie struct
 *
 * @class movie Library.h "Movie-Collection-Library/Library.h"
 * @brief Contains everything that pertains to a movie object; used by Library's list
 * Holds strings: title, director name, movie format
 *   int: runtime, year released
 *   float: price
 */
struct movie {
  std::string title;
  std::string director;
  std::string format;
  
  int runtime;
  int year;
  float price;
};



/**
 * Library is a class that lets users manage their library of movies by allowing them to add, print, remove, and search for movies within the list.
 *
 * @class Library Library.h "Movie-Collection-Library/Library.h"
 * @brief A class that lets users manage a list of movies.
 *
 */
class Library {
 private:
  std::list<movie> library;
  
 public:
  

/**
 * Method for reading data from an input file.
 *
 * @param std::string fName the filename that the user wants to open.
 * @pre Have a class
 * @return void 
 * @post Data will be read in from the file.
 * 
 */
  void readFile(std::string fName);
  

/**
 * Method for writing data to an output file.
 *
 * @param std::string fName the filename that the user wants to write to.
 * @pre Have a class
 * @return void 
 * @post Data will be output to the file.
 * 
 */
  void writeFile(std::string fName);
  

/**
 * Method for automatically sorting all input data alphabetically into the list.
 *
 * @param movie m a movie struct to sort into the list.
 * @pre Have a class
 * @return void 
 * @post Input movie struct is sorted into the list alphabetically.
 * 
 */
  void insertSorted(movie m);
  

/**
 * Method for searching for all movies made by a specific Director.
 *
 * @param std::string name name of the director to search for.
 * @pre Have a class
 * @return void 
 * @post Prints all movies and respective info on the movies made by a specified Director
 * 
 */
  void directorSearch(std::string name);


/**
 * Method for searching for all movies containing a specific word or words.
 *
 * @param std::string query the word/words to search for.
 * @pre Have a class
 * @return void 
 * @post All movies containing the specific word/words have their information printed to console.
 * 
 */
  void findMovie(std::string query);
  

/**
 * Method for removing a movie entry by entering its name.
 *
 * @param std::string usrTitle the name of the movie to remove.
 * @pre Have a class
 * @return void 
 * @post The specified movie is removed.
 * 
 */
  void remove(std::string usrTitle);
  

/**
 * Method for printing all movies and their information to the console.
 *
 * @pre Have a class
 * @return void 
 * @post All movies and their information are printed to the console.
 * 
 */
  void print();
  

/**
 * Method for printing a looping menu to the console that the user can interact with to interface with the Library class.
 *
 * @pre Have a class
 * @return void 
 * @post The menu is printed to screen until user inputs the quit command.
 * 
 */
  void menu();
};

#endif //LIBRARY_H

/**
 * @file Library.h
 * @author William Hayes, Jackson Horton, Kenneth Wallace
 * @date 2022-10-11
 * @brief short
 * 
 * long
 */

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


class Library {
 private:
  std::list<movie> library;
  
 public:
  void readFile(std::string fName);
  
  void writeFile(std::string fName);
  
  void insertSorted(movie* m);
  
  void directorSearch(std::string name);

  void findMovie(std::string query);
  
  void remove(std::string usrTitle);
  
  void print();
};

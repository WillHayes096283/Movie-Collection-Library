/**
 * @file Library.cpp
 * @author William Hayes
 * @date 2022-10-11
 * @brief short
 * 
 * long
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Library.h"

using namespace std;

void Library::readFile(string fName) { //might use insertSort here to automatically sort when reading files
  string movieName;
  string directName;
  string movieFormat;
  float moviePrice = 0.0;
  int time = 0;
  int yearReleased = 0;

  movie temp;
  
  ifstream inFS;

  inFS.open(fName);

  getline(inFS, movieName);

  while(inFS) {
    getline(inFS, directName);

    inFS >> time;

    inFS.get();

    getline(inFS, movieFormat);

    inFS >> moviePrice;

    inFS >> yearReleased;

    inFS.get();

    temp.title = movieName;
    temp.director = directName;
    temp.runtime = time;
    temp.format = movieFormat;
    temp.price = moviePrice;
    temp.year = yearReleased;

    library.push_back(temp);

    getline(inFS, movieName);
  }

  inFS.close();
}


void Library::writeFile(string fName) {
  ofstream outF;

  outF.open(fName);

  list<movie>::iterator it;

  for(it = library.begin(); it != library.end(); it++) {
    outF << it -> title << endl;
    outF << it -> director << endl;
    outF << it -> runtime << it -> format << it -> price << it -> year << endl;
  }

  outF.close();
}

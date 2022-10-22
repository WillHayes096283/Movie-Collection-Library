/**
0;95;0c * @file Library.cpp
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

void Library::insertSorted(movie m) {
  // if library is empty, push to front
  if (library.empty()) {
    library.push_front(m);
    return;
  }

  // iterate through library to find correct insert position for given m
  list<movie>::iterator it;
  for (it = library.begin(); it != library.end(); it++) {
    // if the current title is > than given m's title, insert there
    if (it->title > m.title) {
      library.insert(it, m);
      return;
    }
  }

  // else, push to back
  library.push_back(m);
}

void Library::print() {
  list<movie>::iterator it;

  for (it = library.begin(); it != library.end(); it++) {
    cout << "'" << it->title << "' ";
  }
  cout << endl;
}
  

void Library::readFile(string fName) {
  movie temp;
  ifstream inFS;

  // open file with given file name
  inFS.open(fName);

  // priming read; read first line
  getline(inFS, temp.title);

  while(inFS) {
    // read second line
    getline(inFS, temp.director);
    // read third line
    inFS >> temp.runtime;
    inFS >> temp.format;
    inFS >> temp.price;
    inFS >> temp.year;
    inFS.get();
    
    //    cout << temp.title << endl << temp.director << endl << temp.runtime << endl << temp.format << endl << temp.price << endl << temp.year << endl << endl;
    
    insertSorted(temp);

    // try to read next line; if EOF, will close while loop
    getline(inFS, temp.title);
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

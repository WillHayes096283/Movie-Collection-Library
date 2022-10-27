/**
* @file Library.cpp
 * @author William Hayes
 * @date 2022-10-11
 * @brief implementations for Library class.
 * 
 * Method implementations for the Library class.
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

  int temp = 1;
  
  for (it = library.begin(); it != library.end(); it++) {

    cout << fixed << setprecision(2)
	 << temp << "). Title: " << it->title << "\n"
         << "\tDirector: " << it->director << "\n"
	 << "\tYear: " << it->year << "\n"
         << "\tRuntime: " << it->runtime << " minutes\n"
	 << setw(4) << right << "\tFormat: " << it->format
	 << "\tPrice: $" << it->price << endl << endl; 
    temp++;
  }
}
  
void Library::remove(string title) {
  // creates an iterator, then iterates through library
  list<movie>::iterator it;

  for (it = library.begin(); it != library.end(); it++) {
    // if current title matches passed title to remove, erase it
    if (it->title == title) {
      cout << "Removing: '" << title << "'" << endl;
      library.erase(it);
      
      return;
    }
    
  }

  // if movie title not found:
  cout << "Movie not found; can't remove." << endl;
}

void Library::directorSearch(string name) {
  // creates an iterator, then iterates through library
  list<movie>::iterator it;

  int temp = 1;
  
  cout << "Movies directed by " << name << ":" << endl << endl;
  
  for (it = library.begin(); it != library.end(); it++) {

    // if the passed director directs a movie, print out that movie's info
    
    if (it->director == name) {
      
      cout << fixed << setprecision(2)
	   << temp << ". " << it->title << "(" << it->year
	   << ")\n" << "\tRuntime: " << it->runtime << " minutes\n"
	   << setw(4) << right << "\tFormat: " << it->format
	   << "\t Price: $" << it->price << endl << endl; 

      temp++;
    }
    
  }
}

void Library::findMovie(string query) {
  // creates an iterator, then iterates through library
  list<movie>::iterator it;

  int temp = 1;
  
  cout << "Movies that contain '" << query << "':" << endl << endl;
  
  for (it = library.begin(); it != library.end(); it++) {

    // if the substring query is found within a movie's title, print it out
    
    if ( it->title.find(query) != string::npos ) {
      
      cout << fixed << setprecision(2)
	   << temp << "). Title: " << it->title << "\n"
	   << "\tDirector: " << it->director << "\n"
	   << "\tYear: " << it->year << "\n"
	   << "\tRuntime: " << it->runtime << " minutes\n"
	   << setw(4) << right << "\tFormat: " << it->format
	   << "\tPrice: $" << it->price << endl << endl;
      temp++;
    }
  }
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
    outF << it -> runtime  << " " << it -> format << " " <<  it -> price << " " <<  it -> year << endl;
  }

  outF.close();
}


void Library::menu() {

  cout << "Welcome to your Movie Library!" << endl;
  int selection = 0;
  
  while (selection != 8) {
    cout << "1. Read from file" << endl
	 << "2. Write to file" << endl
	 << "3. Add a movie" << endl
	 << "4. Remove a movie" << endl
	 << "5. Search by movie title" << endl
	 << "6. Search by director" << endl
	 << "7. Print out library" << endl
	 << "8. Exit" << endl;
    
    cout << "Type the number of your selection: ";
    cin >> selection;
   
    cout << endl;
    // runs function based on selection
    switch (selection) {
    case 1:
      {
	string fname = "";

	cout << "Enter filename to read from: ";
	cin >> fname;

	this->readFile(fname);
	break;
      }
    case 2:
      {
	string fname = "";

	cout << "Enter filename to write to: ";
	cin >> fname;

	this->writeFile(fname);
	break;
      }
    case 3:
      {
	movie m;
	cout << "Enter the followind details about the movie" << endl;
	cout << "Movie title: ";
	cin.get();
	getline(cin, m.title);
	cout << "Director name: ";
	getline(cin, m.director);
	cout << "Runtime (in minutes): ";
	cin >> m.runtime;
	cout << "Movie format (DVD, Blu-ray, VHS, Digital): ";
	cin >> m.format;
	cout << "Price (i.e. 11.99): ";
	cin >> m.price;
	cout << "Year: ";
	cin >> m.year;

	this->insertSorted(m);

	break;
      }
    case 4:
      {
	string title = "";
	cout << "Enter name of movie to remove: ";
	cin.get();
	getline(cin, title);

	this->remove(title);

	break;
      }
    case 5:
      {
	string title = "";
	cout << "Search (enter movie name): ";
	cin.get();
	getline(cin, title);

	this->findMovie(title);

	break;
      }
    case 6:
      {
	string name = "";
	cout << "Search (enter director's name): ";
	cin.get();
	getline(cin, name);

	this->directorSearch(name);

	break;
      }
    case 7:
      this->print();
      break;
    default:
      break;
    }

    cout << endl;

    /*
     * if the user types in something other than an int, this
     * fixes the cin buffer; stops infinite loops
     */
    if (cin.fail()) {
      cin.clear();
      cin.ignore(256, '\n');
    }
    
  }
  
}

# Movie Collection Library

* **Names:** Jackson Horton William Hayes, Kenneth Wallace

* **Date:** 10-22-2022

In this assignment, we created a library class to store a collection of movies. In runtime, a user can modify the movie library and read/write to and from a file. We used an internal stl list to store the movies, and all of a movie's info is stored within a *movie struct*.

# TODO
 - [X] implement a menu system
 - [ ] finish documentation
 - [X] clean and setup main.cpp

# The Library Class
The Library class uses a stl linked list. However, we are using the list to store movies in alphabetical order. To do this, we implemented a sorted insert function. It uses an iterator to locate where a new movie should be, then insert it into the corrct postion.

The remove function, similarly, uses an iterator to remove a movie from the library.

# Menu-driven interaction
**TODO**

## Library File Format
Library files don't need to be named in a certain way, the format of library files is important. An example of a library file with one movie is shown here:
```
The Room
Tommy Wiseau
99 DVD 11.99 2003
```
The movie title is on the first line and the director is on the second line.
On the third line (from left to right) are the movie's runtime (`99`), the movie's format (`DVD`), the price (`11.99`), and the year released (`2003`).

There can be multiple movies stored in a library file. To see an example of this, look at the provided [movies.txt](https://github.com/WillHayes096283/Movie-Collection-Library/blob/master/movies.txt)

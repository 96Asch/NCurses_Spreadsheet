Authors:
Andrew Huang(s1913999)
Ruben van Erkelens(s1437267)
Karl Freeke(s1551973) 
Paul Peters(s1453440)	

This project is build with make. The makefile in the root folder calls
the makefiles in the different subfolders to build the objects needed
for compilation. The submakefiles create a shared library from the objects.
Then finally the main makefile uses the shared libraries and it's own
objects to create the executable.

Compiled with g++
Using C++ 14
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) 

Run export LD_LIBRARY_PATH="src/lib" in the terminal
Build with 'make' in root folder
Build and run tests with 'make check' in root folder
Run ./spreadsheet

Taakverdeling:
Basis datastructuur: Andrew & Karl & Paul
Celladdress parsen: Andrew & Karl & Paul
Formule parser: Andrew
Range en iterator: Andrew & Karl & Paul & Ruben
UI basis & UI edit & controllers: Ruben & Paul
FormulaParser: Andrew
Tests: Andrew & Karl
Denkwerk: Andrew & Karl & Paul & Ruben
Bugfixes: Andrew & Karl & Paul & Ruben

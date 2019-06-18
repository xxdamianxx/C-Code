// This program creates a text file with a list of classical music composers.

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile;

    outputFile.open("demofile.txt");

    // Open the output file
    cout << "Now writing a list into a text file.\n";

    // Write four names to the file
    outputFile << "Bach\n";
    outputFile << "Beethoven\n";
    outputFile << "Mozart\n";
    outputFile << "Schubert";

    // Close the file
    outputFile.close();

    cout << "Done.\n";

    // In case you're a moron, this line ends the compilation.
    return 0;
}
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

// Function to print the menu and read user input
int PrintMenu() {
    int choice = 0;
    cout << "\nCorner Grocer" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Display frequency for a specific item" << endl;
    cout << "2. Display a list of all items and their frequencies" << endl;
    cout << "3. Display histogram of all items" << endl;
    cout << "4. Exit Application" << endl;
    cout << "Please enter your selection as a number 1-4:" << endl;
    cin >> choice;
    return choice;
}

int main() {
    ifstream inFS("InputFile.txt");
    ofstream outFS("frequency.dat");

    if (!inFS.is_open()) {
        cout << "Could not open file InputFile.txt." << endl;
        return 1; // Return an error code indicating failure
    }

    string word;
    map<string, unsigned> wordCount;

    // Read words from input file and count frequencies
    while (inFS >> word) {
        cout << word << endl; // Debug: Print words as they are read
        wordCount[word]++;    // Count occurrences of each word
    }

    int c = 0;
    vector<int> bins; // Vector to store histogram bins

    while (true) {
        c = PrintMenu(); // Display menu and get user's choice

        if (c == 1) {
            cout << "Which item would you like to search for?" << endl;
            string userWord;
            cin >> userWord;
            cout << "Count is " << wordCount[userWord] << endl;
        } else if (c == 2) {
            for (const auto& pair : wordCount) {
                outFS << pair.first << " " << pair.second << endl;
            }
            cout << "Frequencies written to frequency.dat" << endl;
        } else if (c == 3) {
            bins.resize(wordCount.size()); // Resize bins vector based on wordCount size

            int i = 0;
            for (const auto& pair : wordCount) {
                bins[i] = pair.second; // Store frequencies in bins vector
                i++;
            }

            // Display histogram
            for (size_t i = 0; i < bins.size(); ++i) {
                cout << "*" << bins[i] << endl;    /*can't get item to print out in console*/
            }
        } else if (c == 4) {
            cout << "Exiting Program. Have A Wonderful Day!" << endl;
            break; // Exit the while loop and end the program
        } else if((c > 4 )||(c < 1)){ {  //user validation?
            cout << "You have entered an invalid selection. Please try again with a number 1-4:" << endl;
        }
    }

    // Close files before exiting
    inFS.close();
    outFS.close();

    return 0;
}
}

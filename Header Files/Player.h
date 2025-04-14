#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class player {
public:
    string name;
    int levelsUnlocked;
    string badges;

public:
    // Default constructor
    player() : name("Guest Player"), levelsUnlocked(1) 
    {
        return;
        setBadge("NewBie");
    }
    // Parameterized constructor
    player(string n) {
        return;
        if (n == "") {
            n = "Guest Player";
        }

        if (playerExists(n)) {
            cout << "Player " << n << " already exists. Loading existing data." << endl;
            // Load player data from file if player exists
            ifstream file("players.txt");
            string line;
            while (getline(file, line)) {
                if (line == n) {
                    getline(file, line); // Get levels unlocked
                    levelsUnlocked = stoi(line);
                    giveBadge(levelsUnlocked);                    
                    break;
                }
            }
            file.close();
        }
        else {
            cout << "Creating new player: " << n << endl;
            // Create new player if not found in file
            name = n;
            levelsUnlocked = 1;
            setBadge("NewBie");
            // Write new player data to file
            writePlayerToFile();
        }
    }

    // Private method to check if player exists in file
    bool playerExists(const string& playerName) const {
        ifstream file("players.txt");
        string line;
        while (getline(file, line)) {
            if (line == playerName) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    // Private method to write player data to file
    void writePlayerToFile() const {
        ofstream file("players.txt", ios::app);
        file << name << endl;
        file << levelsUnlocked << endl;
        file.close();
    }

    void setPlayer(string n) {
        if (n == "") {
            n = "Guest Player";
        }

        if (playerExists(n)) {
            cout << "Loading existing player: " << n << endl;
            // Load player data from file if player exists
            ifstream file("players.txt");
            string line;
            while (getline(file, line)) {
                if (line == n) {
                    getline(file, line); // Get levels unlocked
                    levelsUnlocked = stoi(line);
                    name = n;
                    giveBadge(levelsUnlocked);
                    break;
                }
            }
            file.close();
        }
        else {
            cout << "Creating new player: " << n << endl;
            // Create new player if not found in file
            name = n;
            levelsUnlocked = 1;
            giveBadge(levelsUnlocked);
            // Write new player data to file
            writePlayerToFile();
        }
    }

    void giveBadge(int levels)
    {
        if (levels == 1 || levels == 2)
            setBadge("NewBie");
        else if (levels == 3 || levels == 4)
            setBadge("Veteran");
        else if (levels == 5 || levels == 6)
            setBadge("Master");
    }

    void setBadge(string badge)
    {
        badges = badge;
    }

    void increaseLevelsUnlocked(int num) {
        if (levelsUnlocked < num) {
            // Increase levelsUnlocked by one
            levelsUnlocked = num;

            // Update the player's data in the file
            ifstream inFile("players.txt");
            ofstream tempFile("temp.txt");

            string line;
            bool playerFound = false;

            // Iterate through the file, copying data to a temporary file
            while (getline(inFile, line)) {
                if (line == name) {
                    // Found the player, update levelsUnlocked
                    tempFile << line << endl;
                    tempFile << levelsUnlocked << endl;
                    playerFound = true;
                    getline(inFile, line); // Consume levelsUnlocked line
                }
                else {
                    // Copy other player data unchanged
                    tempFile << line << endl;
                    getline(inFile, line); // Consume levelsUnlocked line
                    tempFile << line << endl;
                }
            }

            inFile.close();
            tempFile.close();

            // Replace the original file with the temporary file
            remove("players.txt");
            rename("temp.txt", "players.txt");

            if (!playerFound) {
                // If player not found (unlikely scenario), add player data at the end of file
                ofstream outFile("players.txt", ios::app);
                outFile << name << endl;
                outFile << levelsUnlocked << endl;
                outFile.close();
            }
        }
    }

    string getName () const
    {
        return name;
    }
};
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    string song_file_path = "song.txt"; 
    ifstream song_file(song_file_path); 
    string line;
    int wait_time;

    while (getline(song_file, line)) {
        if (line.empty()) {
            continue; 
        }
        cout << line << endl; 
        if (song_file >> wait_time) {
            this_thread::sleep_for(chrono::milliseconds(wait_time)); 
        }
    }

    song_file.close(); 

    return 0;
}

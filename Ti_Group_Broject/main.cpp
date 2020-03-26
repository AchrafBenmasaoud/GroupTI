#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Random {
public:
    Random() {srand((unsigned)time(0));}
};

int rooms[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0};                // array of room characterics; four for each of 3 rooms (0-2) and 1 current room (3).
string hazards[3] = {"I smell the wumpus.", "I feel a breeze.", "I hear a bat."};    //  array of room hazards. 

double upplimit() {                                                                  // set upper limit for probability range.
	double limu = 40 + 40 * rand()/RAND_MAX;
	return limu;
}

double lowlimit() {                                                                  // set lower limit for probability range.
	double liml = 60 * rand()/RAND_MAX;
	return liml;
}

int room_num() {                                                                     // randomize room numbers of adjacent rooms.
	int rm = rand() % 1000;
	return rm;
}

int player() {                                                                       // validate play made by player.
    int play_room = 0;
    int play = 0;
    cin >> play;
    if (play < 1000 || play > 3000) {
       	cout << "You have entered an invalid play.  Please try again." << endl;
	cin >> play;
    }
    play_room = play - 1000;
    if (play > 1000 && play < 2000 && play_room != rooms[0][0] && play_room != rooms[1][0] && play_room != rooms[2][0]) {
	cout << "You have not chosen a valid room to which to move.  Please try again." << endl;
	cin >> play;
    }
    play_room = play - 2000;
    if (play > 2000 && play < 3000 && play_room != rooms[0][0] && play_room != rooms[1][0] && play_room != rooms[2][0]) {
	cout << "You have not chosen a valid room into which to shoot.  Please try again." << endl;
	cin >> play;
    }
    return play;
}

int shoot(int play) {
    double prob_wumpus = rand()/RAND_MAX;
    int flag = 0;

    for (int i = 0; i < 3; i++) {                   // outcome of shooting at the wumpus. 
        if (play == 2000 + rooms[i][0]) {
	    if (rooms[i][1] == 1) {
		cout << "You shot the wumpus!  YOU WIN!!!" << endl;
		flag = 1;
	    }
	    if (rooms[i][1] == 0 && prob_wumpus > 0.70) {
		cout << "You missed the wumpus.  It has come into your room and eaten you!" << endl;
		flag = 1;
	    } else if (rooms[i][1] == 0 && prob_wumpus <= 0.70) {
		cout << "You missed the wumpus.  Play again." << endl;
		flag = 0;
	    }
	}
    }
    return flag;
}

int move(int play) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {                  // outcome of moving to another room.
        for (int j = 0; j < 4; j++) {
	    if (play == 1000 + rooms[i][0]) {
	        rooms[3][j] = rooms[i][j];
	    }
	}
    }
	
    if (rooms[3][1] == 1) {
        cout << "The wumpus is in the room.  You are eaten!" << endl;
	flag = 1;
    } 
	
    if (rooms[3][2] == 1 && rooms[3][1] == 0) {
        cout << "You have fallen into a pit and died!" << endl;
        flag = 1;
    }

    if (rooms[3][3] == 1 && rooms[3][2] == 0 && rooms[3][1] == 0) {
	cout << "A bat has taken you to another room!" << endl;
  	rooms[3][0] = room_num();
	cout << "You are now in room " << rooms[3][0] <<"!" << endl;
	flag = 0;
    }
    return flag;
}

int main() {

int flag = 0;
int play = 0;
int shots = 5;
int shot = 0;

cout << "You are safe and in room 100!" << endl;

while (flag == 0) {

    if (shot == 0) {
	for (int i = 0; i < 3; i++) {                     // loop for the rooms.
	    rooms[i][0] = room_num();                     // randomizing of room numbers.
	    if (rooms[i][0] == rooms[3][0]) {i--;}        // to prevent the current room from being selected for an adjacent room. 
	}

	for (int i = 0; i < 3; i++) {                     // loop for the rooms.
	    for (int j = 1; j < 4; j++) {                 // loop for the wumpus, pit, and bat.
	        double prob = 100.0 * rand()/RAND_MAX;
                if ((prob > lowlimit() && prob < upplimit()) && (rooms[0][j] == 0 && rooms[1][j] == 0 && rooms[2][j] == 0)) {     // randomizing of wumpus, pit, and bat.   
		    rooms[i][j] = 1;                                            // True => 1.
	        } else {
		    rooms[i][j] = 0;                                            //  False => 0.
	        }
	    }
	}
    }


    cout << "There are passage ways to rooms " << rooms[0][0] <<", " << rooms[1][0] <<", and " << rooms[2][0] <<"." << endl;

    for (int j = 1; j < 4; j++) {                                           // existence of room hazards. 
        if (rooms[0][j] == 1 || rooms[1][j] == 1 || rooms[2][j] == 1) {
	    cout << hazards[j-1] << endl;
	}
    }
	
    cout << endl;
    cout << "Do you wish to move or shoot?" << endl;
    cout << "Play 1,000 + the room number for moving, or 2,000 + the room number for shooting." << endl;                          
    cout << "You have " << shots << " shots remaining." << endl;              // there is a limit of 5 shots.  The game ends if a player runs out of shots.

    play = player();

    shot = 0;
    if (play > 2000) {
	flag = shoot(play);
	shot = 1;
	shots -= 1;
	if (shots == 0) {
	    cout << "You have no more shots!" << endl;
	    flag = 1;
	}
    }

    if (play < 2000) {
	flag = move(play);
        if (rooms[3][1] == 0 && rooms[3][2] == 0 && rooms[3][3] == 0) {
	    cout << "You are safe and in room " << rooms[3][0] <<"!" << endl;
	}
    }
}

cout << "Game Over." << endl;


return 0;
}
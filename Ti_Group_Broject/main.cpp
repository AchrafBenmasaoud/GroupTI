#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

vector<vector <int>> aantalkamers(vector<vector<int>> &rooms){
//    for(int i = 0; i < 8; i++){
//		vector<int> lijst;
//		for(int j = 0; j < 4; j++){ 
//			int kamers = rand() % 8;
//			lijst.push_back(kamers);
//		}
//		rooms.push_back(lijst);
//	}
	return rooms;
}

int main(){
	srand(time(NULL));
	vector<vector <int>> rooms= {
								{4, 5, 7},
								{2, 4, 5},
								{1, 3, 6},
								{2, 4, 7},
								{0, 1, 3},
								{0, 1, 6},
								{2, 5, 7},
								{0, 3, 6}};
//	aantalkamers(rooms);
	int index = rand() % 8;
	int input = 0;
	
	cout << "(Typ '-1' als je wilt stoppen met spelen, snoepie!)" << endl; 
	while(input != -1){
		cout << endl << "Je zit nu in kamer: " << index << endl << "Deze kamer is verbonden met: ";
		
		for(int j = 0; j < 3; j++){ 
		cout << rooms[index][j] << " ";
		}
		cout << endl <<"Naar welke kamer zou je willen verplaatsen: ";
		cin >> input; 
		
		if(cin.fail()){
			cout << endl << "!!!Foutieve syntax!!!" << endl; 
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else{
			while(input != rooms[index][0] && input != rooms[index][1] && input != rooms[index][2]){
				if(input == -1){
					break;
				}
				else if(input == index){
					cout << endl << "!!!Je zit al in die kamer!!!";
					cout << endl <<"Naar welke kamer zou je willen verplaatsen: ";
					cin >> input;
				}
				else if(cin.fail()){
					cout << endl << "!!!Foutieve syntax!!!"; 
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << endl <<"Naar welke kamer zou je willen verplaatsen: ";
					cin >> input;
				}
				else{
					cout << endl << "!!!Verkeerde kamer!!!";
					cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
					cin >> input;
				}
			}
			index = input;
		}
	}
	return 0;
}
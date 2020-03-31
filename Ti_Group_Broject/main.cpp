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
								{10, 11, 19},  	//0
								{2, 10, 11},   	//1
								{1, 3, 12},		//2
								{2, 4, 13},		//3
								{3, 5, 14},		//4
								{4, 6, 15},		//5
								{5, 7, 16},		//6
								{6, 8, 17},		//7
								{7, 9, 18},		//8
								{8, 10, 19},	//9
								{0, 1, 9},		//10
								{0, 1, 12},		//11
								{2, 11, 13},	//12
								{3, 12, 14},	//13
								{4, 13, 15},	//14
								{5, 14, 16},	//15
				
		FOIIUUITNKWGJLM;L,S
		
GSG{6, 15, 17},	//16
								{7, 16, 18},	//17
								{8, 17, 19},	//18
								{0, 9, 18}};	//19
//	aantalkamers(rooms);
	int index = rand() % 20;
	int input = 0;
	int Rn_Wumpus = rand() % 20;
	
	cout << "(Typ '-1' als je wilt stoppen met spelen, snoepie!)" << endl; 
	while(input != -1){
		cout << endl << "Je zit nu in kamer: " << index << endl << "Deze kamer is verbonden met: ";
		
		for(int j = 0; j < 3; j++){ 
		cout << rooms[index][j] << " ";
		}
		cout << endl <<"Naar welke kamer zou je willen verplaatsen: ";
		cin >> input; 
		
		if(cin.fail()){
			cout << endl << "!!!Foutieve Syntax!!!" << endl; 
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
					cout << endl << "!!!Foutieve Syntax!!!"; 
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << endl <<"Naar welke kamer zou je willen verplaatsen: ";
					cin >> input;
				}
				else{
					cout << endl << "!!!Ongeldige Keuze!!!";
					cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
					cin >> input;
				}
			}
			index = input;
		}
	}
	return 0;
}

#include "game.h"
#include<iostream>
#include<conio.h>
using namespace std;

game::game()
{
	//d = 0;
}
game::~game()
{
	cout << "destroy";
}
int game:: emptyfield(int a){												//Core part where X and O is filled 
	for (int i = 0; i<5; i++){
		cout << endl;
		for (int j = 0; j<5; j++){
			if (i == 1 || i == 3 || j == 1 || j == 3){
				cout << "\t";
				matrix[i][j] = '.';
				cout << matrix[i][j];
				copymatrix[i][j] = matrix[i][j];
			}
			else{
				cout << "\t";
				if (copymatrix[i][j] == 'x' || copymatrix[i][j] == 'o'){
					cout << copymatrix[i][j];
					f = a;
				}
				matrix[i][j] = inputloop(i, j, a);
				if (matrix[i][j] == 1){

					if (count % 2 == 0){
						matrix[i][j] = 'x';
						copymatrix[i][j] = matrix[i][j];
						cout << copymatrix[i][j];
						f = a;
					}
					else{
						matrix[i][j] = 'o';
						copymatrix[i][j] = matrix[i][j];
						cout << copymatrix[i][j];
						f = a;
					}
				}
			}
		}
	}
	return (f);
}
int game::inputloop(int x, int y, int user_input){				//this function return 1 to sun main fxn if below function gives value 1
	c = fieldvalue(x, y, user_input);
	if (c == 1){
		return 1;
	}
	else{
		return 0;
	}
}
int game::fieldvalue(int x, int y, int user_input){         //Checks user input value and matrix index to identfy respective matrix position&return 1 if correct
	if (x == 4 && y == 0 && user_input == 1)
		return 1;
	else if (x == 0 && y == 0 && user_input == 7)
		return 1;
	else if (x == 2 && y == 0 && user_input == 4)
		return 1;
	else if (x == 0 && y == 2 && user_input == 8)
		return 1;
	else if (x == 0 && y == 4 && user_input == 9)
		return 1;
	else if (x == 2 && y == 2 && user_input == 5)
		return 1;
	else if (x == 2 && y == 4 && user_input == 6)
		return 1;
	else if (x == 4 && y == 2 && user_input == 2)
		return 1;
	else if (x == 4 && y == 4 && user_input == 3)
		return 1;

}
void game::emptyfield1(){										//Creates Tic tac toe field
	for (int i = 0; i<5; i++){
		cout << endl;
		for (int j = 0; j<5; j++){
			if (i == 1 || i == 3 || j == 1 || j == 3){
				cout << "\t";
				matrix[i][j] = '.';
				cout << matrix[i][j];
			}
			else{
				cout << "\t ";
			}

		}

	}

}
int game::checkcondition(int a){                                //fills the specific position in matrix where data has been filled 

	if (a == 1){
		if (a == matrixs[4][0]){
			return a;
		}
		matrixs[4][0] = a;
	}
	else if (a == 2){
		if (a == matrixs[4][2]){
			return a;
		}
		matrixs[4][2] = a;
	}
	else if (a == 3){
		if (a == matrixs[4][4]){
			return a;
		}
		matrixs[4][4] = a;
	}
	else if (a == 4){
		if (a == matrixs[2][0]){
			return a;
		}
		matrixs[2][0] = a;
	}
	else if (a == 5){
		if (a == matrixs[2][2]){
			return a;
		}
		matrixs[2][2] = a;
	}
	else if (a == 6){
		if (a == matrixs[2][4]){
			return a;
		}
		matrixs[2][4] = a;
	}
	else if (a == 7){
		if (a == matrixs[0][0]){
			return a;
		}
		matrixs[0][0] = a;
	}
	else if (a == 8){
		if (a == matrixs[0][2]){
			return a;
		}
		matrixs[0][2] = a;
	}
	else if (a == 9){
		if (a == matrixs[0][4]){
			return a;
		}
		matrixs[0][4] = a;
	}
	return 0;
}
int game::win_lose_draw(){                                                          //Determines win or lose 

	if (copymatrix[4][0] == 'x'&&copymatrix[2][0] == 'x'&&copymatrix[0][0] == 'x'){
		return 1;
	}
	if (copymatrix[4][0] == 'x'&&copymatrix[2][2] == 'x'&&copymatrix[0][4] == 'x'){
		return 1;
	}
	if (copymatrix[0][0] == 'x'&&copymatrix[0][2] == 'x'&&copymatrix[0][4] == 'x'){
		return 1;
	}
	if (copymatrix[2][0] == 'x'&&copymatrix[2][2] == 'x'&&copymatrix[2][4] == 'x'){
		return 1;
	}
	if (copymatrix[0][0] == 'x'&&copymatrix[2][2] == 'x'&&copymatrix[4][4] == 'x'){
		return 1;
	}
	if (copymatrix[4][0] == 'x'&&copymatrix[4][2] == 'x'&&copymatrix[4][4] == 'x'){
		return 1;
	}
	if (copymatrix[0][2] == 'x'&&copymatrix[2][2] == 'x'&&copymatrix[4][2] == 'x'){
		return 1;
	}
	if (copymatrix[0][4] == 'x'&&copymatrix[2][4] == 'x'&&copymatrix[4][4] == 'x'){
		return 1;
	}
	if (copymatrix[4][0] == 'o'&&copymatrix[2][0] == 'o'&&copymatrix[0][0] == 'o'){
		return 2;
	}
	if (copymatrix[4][0] == 'o'&&copymatrix[2][2] == 'o'&&copymatrix[0][4] == 'o'){
		return 2;
	}
	if (copymatrix[0][0] == 'o'&&copymatrix[0][2] == 'o'&&copymatrix[0][4] == 'o'){
		return 2;
	}
	if (copymatrix[2][0] == 'o'&&copymatrix[2][2] == 'o'&&copymatrix[2][4] == 'o'){
		return 2;
	}
	if (copymatrix[0][0] == 'o'&&copymatrix[2][2] == 'o'&&copymatrix[4][4] == 'o'){
		return 2;
	}
	if (copymatrix[4][0] == 'o'&&copymatrix[4][2] == 'o'&&copymatrix[4][4] == 'o'){
		return 2;
	}
	if (copymatrix[0][2] == 'o'&&copymatrix[2][2] == 'o'&&copymatrix[4][2] == 'o'){
		return 2;
	}
	if (copymatrix[0][4] == 'o'&&copymatrix[2][4] == 'o'&&copymatrix[4][4] == 'o'){
		return 2;
	}
	return 0;
}
void game::design(){

	cout << "                                          ____                            _____         " << endl;
	cout << "------------------       /\\    /\\       | | ) )      /\\    /\\          / /       --------" << endl;
	cout << "------------------      /  \\  /  \\      |_|_/_/     /  \\  /  \\        | |        -------- " << endl;
	cout << "------------------     /    \\/    \\     | | ) )    /    \\/    \\       | |        --------  " << endl;
	cout << "------------------    /            \\    |_|__)_)  /            \\       \\\\______  --------- " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                       Project=tic-tac-toe                        ___                                " << endl;
	cout << "                                                                 |___|   /       /                   " << endl;
	cout << "                                                               _________/_______/_______             " << endl;
	cout << "                                                                       /  \\/   /                    " << endl;
	cout << "                                                             _________/___/\\_ /_________            " << endl;
	cout << "                                                                     /       /                       " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                     " << endl;
	cout << "                                                                                                 Made by" << endl;
	cout << "                                                                                            Sagar Sigdel" << endl;
	cout << "                                                                                          Subham Pokhrel" << endl;
}
int game::submain(){
		char ans;
		int winner = 8;
		design();
		do{
			cout << "\nPress any to skip.... " << endl;
			cin >> s;
			system("cls");
			cout << "  Consider 7 8 9 of numlock pad as your game field" << endl;
			cout << "           4 5 6" << endl;
			cout << "           1 2 3" << endl;
			emptyfield1();
			count = 0;
			for (i = 0; i<5; i++){
				for (j = 0; j<5; j++){
					copymatrix[i][j] = ' ';
					matrix[i][j] = ' ';
					matrixs[i][j] = 0;
				}
			}
			while (count <= winner){
				int a;
			L:
				cout << "\nenter number";
				cin >> a;
				if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9){
					if (a == matrixs[4][0] || a == matrixs[4][2] || a == matrixs[4][4] || a == matrixs[2][0] || a == matrixs[2][2] || a == matrixs[2][4] || a == matrixs[0][0] || a == matrixs[0][2] || a == matrixs[0][4]){
						cout << "Already occupied enter different number";
						goto L;
					}
					system("cls");
					b = emptyfield(a);
					checkcondition(b);
					g = win_lose_draw();
					if (g == 1){
						cout << "\n\nplayer x Win!!!";
						break;
					}
					else if (g == 2){
						cout << "\n\nplayer o win!!!";
						break;
					}
					if (count == winner){
						cout << "\n\nDraw";
					}
					count++;
					}		
			}	
			cout << "\n\nDo want to play again(y/n)?" << endl;
			cin >> ans;
		} while (ans == 'y');
		return 0;
}
int main(){
	game G;
	G.submain();
}


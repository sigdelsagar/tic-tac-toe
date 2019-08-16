#pragma once
class game
{
private:
	char matrix[5][5];
	char copymatrix[5][5];
	int matrixs[5][5];
	int i, j, c, f, b, g;
	int count;
	char s;

public:
	game();
	~game();
	int emptyfield(int);
	void emptyfield1();
	void design();
	int checkcondition(int);
	int inputloop(int, int, int);
	int copyD(int, int);
	int win_lose_draw();
	int fieldvalue(int x, int y, int user_input);
	int submain();
};


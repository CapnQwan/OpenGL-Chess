#pragma once

class cBoard
{
public:
	int Square[64];
	int activePiece = -1;

	cPiece Piece;

public:
	cBoard();
	~cBoard();

	void Simulate();
	void ChangePiece(int pos, int original_pos);
	bool possibleMoves(int pos, int original_pos);
	void Draw();
};


#include "chess_cBoard.h"

cBoard::cBoard()
{
	
	Square[0] = Piece.White | Piece.Rook;
	Square[1] = Piece.White | Piece.Knight;
	Square[2] = Piece.White | Piece.Bishop;
	Square[3] = Piece.White | Piece.King;
	Square[4] = Piece.White | Piece.Queen;
	Square[5] = Piece.White | Piece.Bishop;
	Square[6] = Piece.White | Piece.Knight;
	Square[7] = Piece.White | Piece.Rook;
	Square[8] = Piece.White | Piece.Pawn;
	Square[9] = Piece.White | Piece.Pawn;
	Square[10] = Piece.White | Piece.Pawn;
	Square[11] = Piece.White | Piece.Pawn;
	Square[12] = Piece.White | Piece.Pawn;
	Square[13] = Piece.White | Piece.Pawn;
	Square[14] = Piece.White | Piece.Pawn;
	Square[15] = Piece.White | Piece.Pawn;

	Square[48] = Piece.Black | Piece.Pawn;
	Square[49] = Piece.Black | Piece.Pawn;
	Square[50] = Piece.Black | Piece.Pawn;
	Square[51] = Piece.Black | Piece.Pawn;
	Square[52] = Piece.Black | Piece.Pawn;
	Square[53] = Piece.Black | Piece.Pawn;
	Square[54] = Piece.Black | Piece.Pawn;
	Square[55] = Piece.Black | Piece.Pawn;
	Square[56] = Piece.Black | Piece.Rook;
	Square[57] = Piece.Black | Piece.Knight;
	Square[58] = Piece.Black | Piece.Bishop;
	Square[59] = Piece.Black | Piece.King;
	Square[60] = Piece.Black | Piece.Queen;
	Square[61] = Piece.Black | Piece.Bishop;
	Square[62] = Piece.Black | Piece.Knight;
	Square[63] = Piece.Black | Piece.Rook;
	

	//Square[35] = Piece.White | Piece.Rook;
}

cBoard::~cBoard()
{

}

void cBoard::Simulate()
{

}

void cBoard::ChangePiece(int pos, int original_pos)
{
	bool det_enemy_piece = false;
	bool can_move = true;
	if (Square[activePiece] / 8 == 1) {
		if (Square[pos] / 8 != 1)
		{
			switch (Square[activePiece])
			{
			case 9:
				if (pos == activePiece + 1 || pos == activePiece - 1 || pos == activePiece + 8 || pos == activePiece - 8 || pos == activePiece + 7 || pos == activePiece + 9 || pos == activePiece - 7 || pos == activePiece - 9)
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else
				{
					break;
				}
			case 10:
				if (pos == activePiece + 8 && Square[pos] == 0)
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else if (pos == activePiece + 7 && Square[pos] != 0)
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else if (pos == activePiece + 9 && Square[pos] != 0)
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else if (pos == activePiece + 16 && activePiece / 8 == 1)
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else
				{
					break;
				}
			case 11:
				if ((pos == activePiece + 17 && activePiece % 8 < 7) ||
					(pos == activePiece + 15 && activePiece % 8 > 0) ||
					(pos == activePiece + 10 && activePiece % 8 < 6) ||
					(pos == activePiece + 6 && activePiece % 8 > 1) ||
					(pos == activePiece - 17 && activePiece % 8 > 0) ||
					(pos == activePiece - 15 && activePiece % 8 < 6) ||
					(pos == activePiece - 10 && activePiece % 8 > 1) ||
					(pos == activePiece - 6 && activePiece % 8 < 6))
				{
					Square[pos] = Square[activePiece];
					Square[activePiece] = 0;
					break;
				}
				else
				{
					break;
				}
			case 12:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos - 7) % 8 == 0)
							{
								return;
							}
							pos -= 7;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos - 9) % 8 == 7)
							{
								return;
							}
							pos -= 9;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
				else if (pos < activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos + 7) % 8 == 7)
							{
								return;
							}
							pos += 7;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos + 9) % 8 == 0)
							{
								return;
							}
							pos += 9;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
				break;
			case 13:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos -= 8;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (pos < (activePiece - (activePiece % 8)))
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos -= 1;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
				else if (pos < activePiece)
				{
					if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos += 8;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (pos > activePiece + (8 - (activePiece % 8)))
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos += 1;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
				break;
			case 14:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos - 7) % 8 == 0)
							{
								return;
							}
							pos -= 7;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos - 9) % 8 == 7)
							{
								return;
							}
							pos -= 9;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos -= 8;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (pos < (activePiece - (activePiece % 8)))
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos -= 1;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
				else
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos + 7) % 8 == 7)
							{
								return;
							}
							pos += 7;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							if ((pos + 9) % 8 == 0)
							{
								return;
							}
							pos += 9;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return;
							}
							pos += 8;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return;
							}
							if (pos > activePiece + (8 - (activePiece % 8)))
							{
								return;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								break;
							}
							pos += 1;
						}
						Square[original_pos] = Square[activePiece];
						Square[activePiece] = 0;
						break;
					}
				}
			default:
				break;
			}
		}
	}
	else 
	{
		switch (Square[activePiece])
		{
		case 17:
			break;
		case 18:
			if (pos == activePiece - 8)
			{
				Square[pos] = Square[activePiece];
				Square[activePiece] = 0;
				break;
			}
		default:
			break;
		}
	}

	/*
	if (pos != activePiece)
	{
		Square[pos] = Square[activePiece];
		Square[activePiece] = 0;
	}
	*/
}

bool cBoard::possibleMoves(int pos, int original_pos)
{
	bool det_enemy_piece = false;
	if (Square[activePiece] / 8 == 1) {
		if (Square[pos] / 8 != 1)
		{
			switch (Square[activePiece])
			{
			case 9:
				if (pos == activePiece + 1 || pos == activePiece - 1 || pos == activePiece + 8 || pos == activePiece - 8 || pos == activePiece + 7 || pos == activePiece + 9 || pos == activePiece - 7 || pos == activePiece - 9)
				{
					return true;
				}
				else
				{
					return false;
				}
			case 10:
				if (pos == activePiece + 8 && Square[pos] == 0)
				{
					return true;
				}
				else if (pos == activePiece + 7 && Square[pos] != 0)
				{
					return true;
				}
				else if (pos == activePiece + 9 && Square[pos] != 0)
				{
					return true;
				}
				else if (pos == activePiece + 16 && activePiece / 8 == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			case 11:
				if ((pos == activePiece + 17 && activePiece % 8 < 7) || 
					(pos == activePiece + 15 && activePiece % 8 > 0) || 
					(pos == activePiece + 10 && activePiece % 8 < 6) || 
					(pos == activePiece + 6 && activePiece % 8 > 1) || 
					(pos == activePiece - 17 && activePiece % 8 > 0) || 
					(pos == activePiece - 15 && activePiece % 8 < 6) || 
					(pos == activePiece - 10 && activePiece % 8 > 1) || 
					(pos == activePiece - 6 && activePiece % 8 < 6))
				{
					return true;
				}
				else
				{
					return false;
				}
			case 12:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos - 7) % 8 == 0)
							{
								return false;
							}
							pos -= 7;
						}
						return true;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos - 9) % 8 == 7)
							{
								return false;
							}
							pos -= 9;
						}
						return true;
					}
				}
				else if (pos < activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos + 7) % 8 == 7)
							{
								return false;
							}
							pos += 7;
						}
						return true;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos + 9) % 8 == 0)
							{
								return false;
							}
							pos += 9;
						}
						return true;
					}
				}
				return false;
			case 13:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos -= 8;
						}
						return true;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (pos < (activePiece - (activePiece % 8)))
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos -= 1;
						}
						return true;
					}
				}
				else if (pos < activePiece)
				{
					if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos += 8;
						}
						return true;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (pos > activePiece + (8 - (activePiece % 8)))
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos += 1;
						}
						return true;
					}
				}
				return false;
			case 14:
				if (pos > activePiece)
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos - 7) % 8 == 0)
							{
								return false;
							}
							pos -= 7;
						}
						return true;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos - 9) % 8 == 7)
							{
								return false;
							}
							pos -= 9;
						}
						return true;
					}
					else if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos -= 8;
						}
						return true;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (pos < (activePiece - (activePiece % 8)))
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos -= 1;
						}
						return true;
					}
				}
				else
				{
					if ((pos - activePiece) % 7 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos + 7) % 8 == 7)
							{
								return false;
							}
							pos += 7;
						}
						return true;
					}
					else if ((pos - activePiece) % 9 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							if ((pos + 9) % 8 == 0)
							{
								return false;
							}
							pos += 9;
						}
						return true;
					}
					else if ((pos - activePiece) % 8 == 0)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos += 8;
						}
						return true;
					}
					else if (pos / 8 == activePiece / 8)
					{
						while (pos != activePiece)
						{
							if (Square[pos] != 0 && pos != original_pos) {
								return false;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && !det_enemy_piece)
							{
								det_enemy_piece = true;
							}
							else if (Square[pos] != 0 && Square[pos] / 8 != 1 && det_enemy_piece)
							{
								return false;
							}
							if (pos > activePiece + (8 - (activePiece % 8)))
							{
								return false;
							}
							if (Square[pos] != 0 && Square[pos] / 8 == 1)
							{
								return false;
							}
							pos += 1;
						}
						return true;
					}
				}
			default:
				return false;
			}
		}
		return false;
	}
	else
	{
		switch (Square[activePiece])
		{
		case 17:
			break;
		case 18:
			if (pos == activePiece - 8)
			{
				return true;
			}
			else
			{
				return false;
			}
		default:
			return false;
		}
	}

	/*
	if (pos != activePiece)
	{
		Square[pos] = Square[activePiece];
		Square[activePiece] = 0;
	}
	*/
}

void cBoard::Draw()
{
	for (int i = 0; i < 64; i++)
	{
		if (Square[i] != 0)
		{
			if (i == activePiece) {
				part_val = Square[activePiece];
				if (Square[i] / 8 == 1) {
					draw_rect((pt.x / ((render_state.height / 100) + 0.78125f)) - 50, ((pt.y / ((render_state.height / 100) + 0.78125f)) - 50) * -1, 3.125f, 3.125f, 0xffffff);
				}
				else {
					draw_rect((pt.x / ((render_state.height / 100) + 0.78125f)) - 50, ((pt.y / ((render_state.height / 100) + 0.78125f)) - 50) * -1, 3.125f, 3.125f, 0x000000);
				}
				//draw_rect((pt.x/((render_state.height/100) + 0.78125f))-50, ((pt.y / ((render_state.height / 100) + 0.78125f)) - 50 )* -1, 3.125f, 3.125f, 0xffffff);
			}
			else
			{
				if (Square[i] / 8 == 1) {
					draw_rect(-43.75 + ((i % 8) * 12.5f), -43.75 + ((i / 8) * 12.5f), 3.125f, 3.125f, 0xffffff);
				}
				else {
					draw_rect(-43.75 + ((i % 8) * 12.5f), -43.75 + ((i / 8) * 12.5f), 3.125f, 3.125f, 0x000000);
				}
							}
			//draw_rect(-43.75 + (1 * 12.5f), -43.75 + (1 * 12.5f), 3.125f, 3.125f, 0xffffff);
		}

		if (activePiece != -1)
		{
			//possibleMoves(i
			if (possibleMoves(i, i))
			{
				if ((i + (i/8)) % 2  == 0) {
					draw_rect(-43.75 + ((i % 8) * 12.5f), -43.75 + ((i / 8) * 12.5f), 6.25f, 6.25f, 0x1dd132);
				}
				else {
					draw_rect(-43.75 + ((i % 8) * 12.5f), -43.75 + ((i / 8) * 12.5f), 6.25f, 6.25f, 0x119120);
				}
			}
		}
	}
}
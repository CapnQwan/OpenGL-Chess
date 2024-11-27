#include "chess_cPiece.cpp"
#include "chess_cBoard.cpp"

cBoard chessBoard;
int active_piece;
int new_pos;

internal void
simulate_game(Input* input, float dt) {
	clear_screen(0x333333);
	render_chessboard();

	chessBoard.Draw();

	if (mouse_changed)
	{
		mouse_changed = false;
		if (chessBoard.activePiece == -1) {
			active_piece = ((pt.x / (render_state.height / 8)) + (56-((pt.y / (render_state.height / 8) * 8))));
			if (chessBoard.Square[active_piece] != 0) {
				chessBoard.activePiece = active_piece;
			}
		}
		else
		{
			new_pos = ((pt.x / (render_state.height / 8)) + (56 - ((pt.y / (render_state.height / 8) * 8))));
			chessBoard.ChangePiece(new_pos, new_pos);
			chessBoard.activePiece = -1;
			cur_actv_pc = chessBoard.activePiece;
		}
	}
}
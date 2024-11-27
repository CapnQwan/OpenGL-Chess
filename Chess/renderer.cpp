global_variable float render_scale = 0.01f;
global_variable float chess_tile_hs;
global_variable float boardsize;

internal void
clear_screen(u32 color) {
	u32* pixel = (u32*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
}


internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {

	x0 = clamp(0, x0, render_state.width);
	x1 = clamp(0, x1, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	y1 = clamp(0, y1, render_state.height);

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state.memory + x0 + y * render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}


internal void
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color) {

	x *= render_state.height * render_scale;
	y *= render_state.height * render_scale;
	half_size_x *= render_state.height * render_scale;
	half_size_y *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;

	// Change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;

	draw_rect_in_pixels(x0, y0, x1, y1, color);
}


internal void
render_chessboard() {
	if (render_state.width >= render_state.height) {
		chess_tile_hs = render_state.height / 8;
		boardsize = render_state.height;
	}
	else {
		chess_tile_hs = render_state.width / 8;
		boardsize = render_state.width;
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++)
		{
			if ((x + y) % 2 != 0) {
				draw_rect(-43.75 + (x * 12.5f), -43.75 + (y * 12.5f), 6.25f, 6.25f, 0x4f4747);
			}
			else {
				draw_rect(-43.75 + (x * 12.5f), -43.75 + (y * 12.5f), 6.25f, 6.25f, 0xb4d8d9);
			}
		}
	}
}
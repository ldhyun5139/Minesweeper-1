#include "pch.h"
#include "tipsware.h"

void OnLButtonDown(int a_mixed_key, POINT a_pos)
{
	unsigned int x = (unsigned int)a_pos.x / 30, y = (unsigned int)a_pos.y / 30;

	if (x < 15 && y < 15) {
		char(*p_data)[15] = (char(*)[15])GetAppData();
		p_data[y][x] = !p_data[y][x];
		COLORREF border_color[2] = { RGB(0, 100, 200), RGB(200, 100, 0) };
		COLORREF fill_color[2] = { RGB(0, 0, 128), RGB(128, 0, 0) };
		for (int y = 0; y < 15; y++) {
			for (int x = 0; x < 15; x++) {
				Rectangle(x * 30, y * 30, (x + 1) * 30, (y + 1) * 30, border_color[p_data[y][x]], fill_color[p_data[y][x]]);
			}
		}
		ShowDisplay();
	}
}

MOUSE_MESSAGE(OnLButtonDown, NULL, NULL)

int main()
{
	char state[15][15] = { { 0, }, };
	SetAppData(state, sizeof(state));

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++) {
			Rectangle(x * 30, y * 30, (x + 1) * 30, (y + 1) * 30, RGB(0, 100, 200), RGB(0, 0, 128));
		}
	}

	ShowDisplay();
	return 0;
}
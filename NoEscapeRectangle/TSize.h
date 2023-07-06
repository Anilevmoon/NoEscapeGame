#pragma once

static int g_sRectangleWidth = 1;
static int g_sYDefaultLength = 1;
static int g_sZDefaultHeight = 2;

struct TSize {
	TSize() = default;
	TSize(int xInput, int yInput, int zInput);
	int x;
	int y;
	int z;
};


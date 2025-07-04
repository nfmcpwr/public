#include <math.h>

typedef struct
{
	int X;
	int Y;
} POINT;

void DrawUFO(int, int);

int DrawLine(int srcX, int srcY, int dstX, int dstY)
{
	int sx = dstX;
	int sy = dstY;
	int dx = srcX;
	int dy = srcY;

	if (srcX < dstX)
	{
		sx = srcX;
		dx = dstX;
	}

	if (srcY < dstY)
	{
		sy = srcY;
		dy = dstY;
	}

	double h, v;
	if (abs(srcX - dstX) < abs(srcY - dstY))
	{
		h = 1;
		v = abs(srcY - dstY) / abs(srcX - dstX);
	}
	else
	{
		h = abs(srcX - dstX) / abs(srcY - dstY);
		v = 1;
	}

	if (srcX == dstX)
	{
		h = 0;
	}

	if (srcY == dstY)
	{
		v = 0;
	}

	sx -= 16;
	sy -= 16;
	dx -= 16;
	dy -= 16;

	int count = 0;
	int r = 1;
	while (1)
	{
		DrawUFO(mx, my);

		sx += (int)h;
		sy += (int)v;

		if (dx < sx && dy < sy)
		{
			break;
		}

		count++;
		if (1000 < count)
		{
			r = -1;
			break;
		}
	}

	return r;
}

int DrawLines(POINT psrc[], POINT pdst[], int length)
{
	int r;
	for (int i = 0; i < length; i++)
	{
		r = DrawLine(psrc[i].X, psrc[i].Y, pdst[i].X, pdst[i].Y);

		if (r == -1)
		{
			break;
		}
	}

	return r;
}
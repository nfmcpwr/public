#include <math.h>

typedef struct
{
	int X;
	int Y;
} POINT;

void DrawUFO(int, int);

int DrawLine(int srcX, int srcY, int dstX, int dstY)
{
	int px = 1;
	int py = 1;
	int mx = dstX;
	int my = dstY;
	int lx = srcX;
	int ly = srcY;

	if (srcX < dstX)
	{
		mx = srcX;
		lx = dstX;
	}

	if (srcY < dstY)
	{
		my = srcY;
		ly = dstY;
	}

	double w, h;
	if (abs(srcX - dstX) < abs(srcY - dstY))
	{
		w = 1;
		h = abs(srcY - dstY) / abs(srcX - dstX);
	}
	else
	{
		w = abs(srcX - dstX) / abs(srcY - dstY);
		h = 1;
	}

	if (srcX == dstX)
	{
		w = 0;
	}

	if (srcY == dstY)
	{
		h = 0;
	}

	px *= (int)w;
	py *= (int)h;

	mx -= 16;
	my -= 16;
	lx -= 16;
	ly -= 16;

	int count = 0;
	int r = 1;
	while (1)
	{
		DrawUFO(mx, my);

		mx += px;
		my += py;

		if (lx < mx && ly < my)
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
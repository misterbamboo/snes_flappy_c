#include <snes.h>

extern char snesfont;

void put16ColorsMode()
{
	setMode(BG_MODE1, 0);
	bgSetDisable(1);
	bgSetDisable(2);
}

void clearConsole()
{
	unsigned short i;
	for (i = 0; i < 26; i++)
	{
		consoleDrawText(0, i, "                                ");
	}
}

int main(void)
{
	// Initialize SNES
	consoleInit();

	// Initialize text console with our font
	consoleInitText(0, 0, &snesfont);

	// Now Put in 16 color mode and disable Bgs except current
	put16ColorsMode();

	unsigned short yText = 0;

	// Wait for nothing :P
	setScreenOn();

	while (1)
	{
		clearConsole();

		yText++;
		consoleDrawText(0, yText, "test");
		if (yText > 24)
		{
			yText = 0;
		}

		WaitForVBlank();
	}
	return 0;
}
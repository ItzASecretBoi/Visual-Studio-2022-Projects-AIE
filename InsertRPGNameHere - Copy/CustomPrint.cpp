#include <iostream>
#include <string>
#include <fstream>
#include "CustomPrint.h"
#include "Windows.h"
#include <conio.h>

CustomPrint::CustomPrint()
{
}

void CustomPrint::Clear()
{
	system("cls");
}

void CustomPrint::TypewriterPrintENDL(string text, int delayMS)
{

	bool skip = false;

	for (char c : text)
	{
		cout << c;

		cout.flush();

		if (_kbhit())
		{
			_getch();
			skip = true;
		}

		if (!skip)
		{
			this_thread::sleep_for(chrono::milliseconds(delayMS));
		}
	}

	cout << endl;
}

void CustomPrint::TypewriterPrintENDLENDL(string text, int delayMS)
{

	bool skip = false;

	for (char c : text)
	{
		cout << c;

		cout.flush();

		if (_kbhit())
		{
			_getch();
			skip = true;
		}

		if (!skip)
		{
			this_thread::sleep_for(chrono::milliseconds(delayMS));
		}
	}

	cout << endl << endl;
}

void CustomPrint::TypewriterPrint(string text, int delayMS)
{
	bool skip = false;

	for (char c : text)
	{
		cout << c;

		cout.flush();

		if (_kbhit())
		{
			_getch();
			skip = true;
		}

		if (!skip)
		{
			this_thread::sleep_for(chrono::milliseconds(delayMS));
		}
	}

}

void CustomPrint::Wait(int seconds)
{
	int totalMS = seconds * 1000;
	int stepMS = 50; // check every 50ms

	for (int elapsed = 0; elapsed < totalMS; elapsed += stepMS)
	{
		if (_kbhit())
		{
			_getch(); // Consume the key press
			break;    // Exit the wait early
		}

		this_thread::sleep_for(chrono::milliseconds(stepMS));
	}
}

void CustomPrint::WaitMS(int milliseconds)
{
	int stepMS = 50; // check every 50ms

	for (int elapsed = 0; elapsed < milliseconds; elapsed += stepMS)
	{
		if (_kbhit())
		{
			_getch(); // Consume the key press
			break;    // Exit the wait early
		}

		this_thread::sleep_for(chrono::milliseconds(stepMS));
	}
}


void CustomPrint::OpenPNG(string path)
{
	std::wstring widePath(path.begin(), path.end());

	ShellExecute(NULL, L"open", widePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}



void CustomPrint::Test()
{
	CustomPrint print;

	print.TypewriterPrintENDLENDL(print.BOLD + "I hate apples so much they make me so mad." + print.RESET, 20);
	print.Wait(1);
	print.TypewriterPrintENDLENDL("I mean really, who seriously thought of this stuff?!?" + print.RESET, 20);
	print.Wait(1.5);
	print.TypewriterPrintENDLENDL(print.BG_RED + "RED FRUIT? " + print.RESET, 20);
	print.Wait(1);
	print.TypewriterPrint(print.FG_RED + "D I S G U S T I N G . . .\n" + print.RESET, 80);

	print.OpenPNG("apple.png");
}

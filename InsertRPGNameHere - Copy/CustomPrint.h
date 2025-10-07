#pragma once

#ifndef CUSTOMPRINT_H
#define CUSTOMPRINT_H

using namespace std;

#include <iostream>
#include <string>
#include <chrono> 
#include <thread>
#include <Windows.h>
#include <conio.h>

class CustomPrint
{

public:

	// Reset
	const std::string RESET = "\033[0m";

	// Styles
	const std::string BOLD = "\033[1m";
	const std::string INVERSE = "\033[7m";

	// Foreground (Text) Colors
	const std::string FG_BLACK = "\033[30m";
	const std::string FG_RED = "\033[31m";
	const std::string FG_GREEN = "\033[32m";
	const std::string FG_YELLOW = "\033[33m";
	const std::string FG_BLUE = "\033[34m";
	const std::string FG_MAGENTA = "\033[35m";
	const std::string FG_CYAN = "\033[36m";
	const std::string FG_WHITE = "\033[37m";

	// Bright Foreground Colors (high intensity)
	const std::string FG_BRIGHT_BLACK = "\033[90m";  // Gray
	const std::string FG_BRIGHT_RED = "\033[91m";
	const std::string FG_BRIGHT_GREEN = "\033[92m";
	const std::string FG_BRIGHT_YELLOW = "\033[93m";
	const std::string FG_BRIGHT_BLUE = "\033[94m";
	const std::string FG_BRIGHT_MAGENTA = "\033[95m";
	const std::string FG_BRIGHT_CYAN = "\033[96m";
	const std::string FG_BRIGHT_WHITE = "\033[97m";

	// Background Colors
	const std::string BG_BLACK = "\033[40m";
	const std::string BG_RED = "\033[41m";
	const std::string BG_GREEN = "\033[42m";
	const std::string BG_YELLOW = "\033[43m";
	const std::string BG_BLUE = "\033[44m";
	const std::string BG_MAGENTA = "\033[45m";
	const std::string BG_CYAN = "\033[46m";
	const std::string BG_WHITE = "\033[47m";

	// Bright Background Colors (high intensity)
	const std::string BG_BRIGHT_BLACK = "\033[100m";  // Dark gray
	const std::string BG_BRIGHT_RED = "\033[101m";
	const std::string BG_BRIGHT_GREEN = "\033[102m";
	const std::string BG_BRIGHT_YELLOW = "\033[103m";
	const std::string BG_BRIGHT_BLUE = "\033[104m";
	const std::string BG_BRIGHT_MAGENTA = "\033[105m";
	const std::string BG_BRIGHT_CYAN = "\033[106m";
	const std::string BG_BRIGHT_WHITE = "\033[107m";


	CustomPrint();

	void TypewriterPrintENDLENDL(string text, int delayMS);

	void TypewriterPrintENDL(string text, int delayMS);

	void TypewriterPrint(string text, int delayMS);

	void Wait(int seconds);

	void WaitMS(int milliseconds);

	void Test();

	void Clear();

	void OpenPNG(string path);
};

#endif
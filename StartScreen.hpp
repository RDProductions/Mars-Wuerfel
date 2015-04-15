#ifndef STARTSCREEN_HPP
#define STARTSCREEN_HPP

#include <iostream>
#include <string>

class StartScreen
{
public:
	StartScreen();
	std::string ShowTitle();
	std::string ShowHelp();
	std::string ShowMiniHelp();
private:
	std::string minihelp;
	std::string title;
	std::string help;
};

#endif;

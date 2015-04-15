#ifndef MULTIPLAYER_HPP
#define MULTIPLAYER_HPP

#include "MainMenu.hpp"
#include <time.h>

class Multiplayer
{
public:
	Multiplayer();
	void PlayStatePlayer1(int hardness);
	void PlayStatePlayer2(int hardness);
	void PlayState(int  hardness);
private:
	std::string face;
	int würfel;
	int cube[13];
	int select_player1;
	int select_player2;
	int selectface;
	int punktespieler1, punktespieler2, gesamtpunktespieler1, gesamtpunktespieler2, gesamtpanzer, gesamtstrahler, gesamtkühe, gesamthühner, gesamtmenschen;
	//für Würfel-weglegen
	int anzahlstrahler, anzahlkühe, anzahlmenschen, anzahlhühner, anzahlwürfel;
	//damit Lebewesen nicht 2x gestohlen werden / Wiederholung Spieler 1 / 2
	bool genutztkühe, genutztmenschen, genutzthühner, whsp1, whsp2, nochmal;
};

#endif

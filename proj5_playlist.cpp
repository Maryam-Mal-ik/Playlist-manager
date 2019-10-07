// proj5_playlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "proj5_playlist.h"
Song sample;

//--------------------Definition of functions---------------------

//********************Default Constructor********************//
playlist::playlist()
{
	size = 2;                                  //default size=2
	no_of_song = size;
	plist = new Song[size];                    //dynamic array of defaault size
	for (int i = 0; i < size; i++)
	{
		if (*(plist + i) == sample)                   
			no_of_song--;                      //Calculating number of songs
	}
}

//********************Default destructor*********************//

playlist::~playlist()
{
	delete []plist;
}

//********************addsong()********************//

void playlist::addsong(const Song & s)
{{
		*(plist + no_of_song) = s;
	}
	no_of_song++;                              //after adding one song increasing the no_of-song by 1
	if (no_of_song * 2 != size)
		doublesong();
	cout << "The " << s << " song has been added to playlist." << endl << endl;
}

//********************deletesong()********************//

bool playlist::deletesong(const Song & s)
{
	bool c = false;
	for (int i = 0; i <= no_of_song; i++)
	{
		if (s == *(plist + i))                            //searching song 's' in the playlist
		{
			for (int j = i; j < no_of_song - 1; j++)
			{
				Song temp = *(plist + j);              //swapping the songs and placing 's' on last index           
				*(plist + j) = *(plist + j + 1);
				*(plist + j + 1) = temp;
			}
			*(plist + no_of_song - 1) = sample;          //deleting the song fromlast index
			no_of_song--;
			c = true;
			cout << "The " << s << " song has been deleted from playlist." << endl << endl;
		}
	}if (no_of_song < size / 2)
	{
		if(no_of_song!=0)
		halfsong();                                    //adjusting the size
	}

	/*if (no_of_song == 0)
	{
		playlist p;
		this->p;
	}*/
	if (no_of_song == 0)
	{
		while (size != 2)
		{
			halfsong();
		}
	}
	return c;
}

//********************DoubleSize()********************//

void playlist::doublesong()
{
		int new_size = no_of_song * 2;                          
		Song *new_plist = new Song[new_size];
		for (int f1 = 0; f1 < size; f1++)
		{
			new_plist[f1] = plist[f1];
		}
		this->size = new_size;
		plist = new_plist;
}

//********************HalfSzie()********************//

void playlist::halfsong()
{
		int new_size = no_of_song*2;
		Song *new_plist = new Song[new_size];
		for (int f1 = 0; f1 < new_size; f1++)
		{
			new_plist[f1] = plist[f1];
		}
		this->size = new_size;
		plist = new_plist;
}

//********************showall()********************//

void playlist::showall() const
{
	for (int y = 0; y < size; y++)
	{
		if (*(plist + y) == sample)
			cout << "";
		else
		cout << *(plist + y) << endl;
	}
}

//********************play(int num)********************//
void playlist::play(int num)
{
	for (int y = index; y < num; y++)
	{			
				if (*(plist + y) == sample)
					cout << "";
				else
					cout << *(plist + y) << endl;
				if (y == no_of_song - 1)
				{
					num = num - no_of_song;
					y=-1;
				}
				index = y + 1;
	}
}

//********************showstatus()********************//

void playlist::showstatus() const
{
	cout << "The size of playlist is = " << size << endl;
	cout << "The number of songs in playlist = " << no_of_song << endl;
	cout << "The index of current of song = " << index << endl;
}

playlist operator+(const Song & s)
{
	playlist plist;
	plist.addsong(s);
	return plist;
}

playlist operator+(playlist &plist,Song & F1)
{
	plist.addsong(F1);
	return plist;
}

playlist operator-(playlist &plist, Song & F1)
{
	plist.deletesong(F1);
	return plist;
}

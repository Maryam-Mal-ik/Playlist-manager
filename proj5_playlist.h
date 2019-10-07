#include"pch.h"
#include<iostream>
#include"song.h"

using namespace std;
//void swap(Song s1, Song s2);
class playlist{
private:
	Song *plist=0;
	int size = 0;
	int no_of_song = 0;
	int index = 0;
public:
	playlist();
	~playlist();
	void addsong(const Song &s);
	bool deletesong(const Song &s);
	void doublesong();
	void halfsong();
	void showall() const;
	void play(int num = 1);
	void showstatus() const; 
	friend playlist operator + (playlist &plist,Song& F1);
	friend playlist operator - (playlist &plist, Song& F1);
};

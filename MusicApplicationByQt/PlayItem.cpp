
#include "PlayItem.h"

PlayItem::PlayItem()
{
	Id = "";
	numPlay = 0;
	inTime = 0;
}

PlayItem::PlayItem(string inid)
{
	Id = inid;
	numPlay = 0;
	inTime = 0;
}

string PlayItem::GetId() const
{
	return Id;
}

int PlayItem::GetNumPlay()
{
	return numPlay;
}

int PlayItem::GetInTime()
{
	return inTime;
}

void PlayItem::SetId(string inid)
{
	Id = inid;
}

void PlayItem::SetIdFromKB()
{
	cout << "Enter Music's ID :"; cin >> Id;
}

void PlayItem::SetInTime(int time)
{
	inTime = time;
}

void PlayItem::Up_numPlay(int count)
{
	numPlay += count;
}

void PlayItem::setNumplay(int count)
{
	numPlay = count;
}

bool PlayItem::operator==(PlayItem data)
{
	if (data.GetId() == this->Id) {
		return true;
	}
	return false;
}

bool PlayItem::operator>(PlayItem data)
{
	
	return this->Id >data.GetId();
}

bool PlayItem::operator<(PlayItem data)
{
	return this->Id < data.GetId();
}

ostream & operator<<(ostream & os, const PlayItem & item)
{
	os << "Id: " << item.GetId() << endl;
	return os;
}

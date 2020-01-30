
#include "PlayerType.h"

int PlayerType::AddSong(PlayItem item)
{
	if (!playlist.IsFull()) {
		playlist.Add(item);
		return 1;
	}
	else return 0;
}

int PlayerType::DeleteSong(PlayItem item)
{
	if (playlist.Delete(item)) {
		return 1;
	}
	else {
		return 0;
	}
}

int PlayerType::ReplaceSong(PlayItem item)
{
	if (playlist.Replace(item)) {
		return 1;
	}
	else {
		return 0;
	}
}




string PlayerType::GetNextSongId(string curid, bool& isend)
{
	playlist.ResetList();
	PlayItem pi(curid);
	playlist.Get(pi);
	if (playlist.GetNextItem(pi) == -1) {
		isend = true;
		pi = playlist.at(0);
	}
	return pi.GetId();

}

string PlayerType::GetPreSongId(string curid, bool& isfirst)
{
	
	PlayItem pi(curid);
	playlist.Get(pi);
	int curindex = playlist.GetCurIndex();
	if ( curindex == 0) {
		isfirst = true;
		pi = playlist.at(playlist.GetLength() - 1);
	}
	else {
		pi = playlist.at(curindex-1);
	}
	return pi.GetId();
}

int PlayerType::GetCurIndex()
{
	return playlist.GetCurIndex();
}

int PlayerType::GetSongIdByIndex(int index, PlayItem& item)
{
	if (index >= 0 && index < playlist.GetLength()) {
		item = playlist.at(index);
		return 1;
	}
	else return 0;
}

int PlayerType::GetSongIndex(string id)
{
	PlayItem pi(id);
	if (playlist.Get(pi)) {
		return playlist.GetCurIndex();
	}
	else return -1;
}

void PlayerType::SwapSong(int index1, int index2)
{
	playlist.swap(index1, index2);
}

int PlayerType::GetPlaylistSize()
{
	return playlist.GetLength();
}

string PlayerType::GetPLName()
{
	return name;
}

ArrayList<PlayItem> PlayerType::GetPlayList()
{
	return playlist;
}


void PlayerType::SetName(string _name)
{
	name = _name;
}

void PlayerType::SetNameFrKb()
{
	cout << "Enter the play list name : ";
	cin >> name;
}

void PlayerType::SetPlaylist(ArrayList<PlayItem> pl)
{
	playlist = pl;
}




bool PlayerType::operator==(PlayerType other)
{
	return (this->name == other.GetPLName());
}

bool PlayerType::operator<(PlayerType other)
{
	return (this->name < other.GetPLName());
}

bool PlayerType::operator>(PlayerType other)
{
	return (this->name > other.GetPLName());
}

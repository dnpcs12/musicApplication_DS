
#include "SingerType.h"

SingerType::SingerType()
{
	name = ' ';
	age = 0;
	isMale = false;

}

void SingerType::SetName(string _name)
{
	name = _name;
}

void SingerType::SetAge(int _age)
{
	age = _age;
}

void SingerType::SetIsMale(bool bmale)
{
	isMale = bmale;
}

void SingerType::SetNameByFB()
{
	cout << "Enter the singer's name : "; cin >> name;
}

void SingerType::SetSingerByFB()
{
	char s;
	cout << "Enter the singer's name : "; cin >> name;
	cout << "Enter the singer's age : "; cin >> age;
	while (1) {
		cout << "Enter the gender (M or F) : "; cin >> s;
		if (s == 'M' || s == 'm') {
			isMale = true;
			break;
		}
		else if (s == 'F' || s == 'f') {
			isMale = false;
			break;
		}
		else {
			cout << "¡Ø Enter M or F \n";
		}
	}
}

string SingerType::GetName() const
{
	return name;
}

int SingerType::GetAge() const
{
	return age;
}

bool SingerType::GetIsMale() const
{
	return isMale;
}

void SingerType::AddSoog(SoogType soog)
{
	soogList.Add(soog);
}

void SingerType::DisplayAll()
{
	SoogType temp;
	soogList.ResetList();
	while (soogList.GetNextItem(temp) != -1) {
		cout << "ID :" << temp.id;
		cout << "Name : " << temp.soogName;
	}
}

int SingerType::GetNextSoogID(string & _id)
{
	SoogType temp;
	if (soogList.GetNextItem(temp) != -1) {
		_id = temp.id;
		return 1;
	}
	else return -1;
}

void SingerType::ResetSoogList(){
	soogList.ResetList();
}

bool SingerType::operator==(SingerType other)
{
	return (this->name == other.name);
}

bool SingerType::operator<(SingerType other)
{
	return (this->name < other.name);
}

bool SingerType::operator>(SingerType other)
{
	return (this->name > other.name);
}

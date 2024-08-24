#include "Room.h"
#include "Matchentity.h"
using namespace std;

const int MAXITEMNUM = 32;

template< typename type >
inline type& extract(istream& s, type& t)
{
	s >> t; 
	return t;
}

item Room::findItem(string& p_item){
	list<item>::iterator itr = fine_if(m_items.begin(), m_items.end(), matchEntityFull(p_item));
	
	if (itr != m_items.end()) {
		return *itr;
	}
	else {
		itr = fine_if(m_items.begin(), m_items.end(), matchEntity(p_item));
		if (itr != m_items.end()) {
			return *itr;
		}
	}

	return 0;
}

void Room::getRoomType(string p_arr) {
	char chr = p_arr[0];

	switch (chr) {
	case 'N':
		m_type = NORTH;
		break;
	case 'S':
		m_type = SOUTH;
		break;
	case 'W':
		m_type = WEST;
		break;
	case 'E':
		m_type = EAST;
		break;
	default:cout << "Error" << endl;
	}
}

void Room::addItem(item p_item){
	if (m_items.size() >= MAXITEMNUM)
		m_items.pop_front();

	m_items.push_back(p_item);
}

void Room::removeItem(item p_item){
	m_items.erase(find(m_items.begin(),m_items.end(),(entityid)p_item));
}

void Room::loadTemplate(istream& p_stream){
	string temp;

	p_stream >> temp >> ws;    
	getline(p_stream, m_name);
	p_stream >> temp >> ws;    
	getline(p_stream, m_des);
	p_stream >> temp >> temp;       
	m_type = getRoomType(temp);
	p_stream >> temp >> m_data;

	for (int d = 0; d < NUMDIRECTIONS; d++)
		p_stream >> temp >> m_rooms[d];

	p_stream >> temp >> m_enemy;
	p_stream >> temp >> m_maxenemies;
	p_stream >> temp >> m_npc;

}

void Room::loadData(istream& p_stream){
	string temp;
	p_stream >> temp;

	m_items.clear();
	entityid last;
	while (extract(p_stream, last) != 0)
		m_items.push_back(last);

	p_stream >> temp;   
	p_stream >> m_money;
}

void Room::saveData(ostream& p_stream){
	p_stream << "[ITEMS] ";

	list<item>::iterator itr = m_items.begin();
	while (itr != m_items.end())
	{
		p_stream << *itr << " ";
		itr++;
	}

	p_stream << "0\n";

	p_stream << "[MONEY] " << m_money << "\n";
}

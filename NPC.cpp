#include <fstream>
#include "NPC.h"
using namespace std;

NPC::NPC(string p_name) :m_name(p_name) {
	m_level = 1;
	//m_statpoints = 0;
	m_type = GOLD;
	m_weapon = -1;
	m_armor = -1;
	recalculateStats();
	m_hitpoints = getAttr(MAXHITPOINTS);
	cout << "NPC" << m_name << "�ɹ���" << endl;
}

//�ȼ�����
void NPC::addExp(int exp){
	m_exp += exp;

	while (needforNextLevel() <= 0) {
		m_level++;
	}
	while (m_exp < needforLevel(m_level)) {
		m_level--;
	}
}

int NPC::needforLevel(int p_level){
	return (int)(100 * pow(1.4, p_level - 1) - 1);
}

int NPC::needforNextLevel(){
	return needforLevel(m_level + 1) - m_exp;
}

//���Ժ���
int NPC::getAttr(int p_attr){
	int val = m_attributes[p_attr] + m_baseattributes[p_attr];
	return val;
}

void NPC::setBaseAttr(int p_attr, int p_val){
	m_baseattributes[p_attr] = p_val;
	recalculateStats();
}

void NPC::addToBaseAttr(int p_attr, int p_val){
	m_baseattributes[p_attr] += p_val;
	recalculateStats();
}

int NPC::getType(){
	if (m_type == LIGHT) {
		return 1;
	}
	else if (m_type == GOLD) {
		return 2;
	}
	else if (m_type == FIRE) {
		return 3;
	}
	else if (m_type == GRASS) {
		return 4;
	}
	else {
		cout << "AttackType Error!";
		exit(2);
	}
}

void NPC::setType(int p_attr){
	switch (p_attr) {
	case 1:
		m_type = LIGHT;
		break;
	case 2:
		m_type = GOLD;
		break;
	case 3:
		m_type = FIRE;
		break;
	case 4:
		m_type = GRASS;
	default:
		cout << "AttackType Error!";
		exit(3);
	}
}

//�ӳ�
void NPC::addDynamicBonuses(item p_item){
	Item& i = *p_item;

	if (p_item == 0)
		return;

	for (int x = 0; x < NUMATTRIBUTES; x++)
		m_attributes[x] += i.getAttr(x);
}

void NPC::addBonuses(item p_item){
	Item& i = *p_item;
	int t = 0;

	if (p_item == 0) {
		return;
	}//���ɹ���δ�ҵ�
	else {
		t = i.Min() + rand() % (i.Max() - i.Min());
	}

	if (i.Type() == HEALING) {
		addHitPoints(t);
	}
	else if (i.Type() == EXP) {
		addExp(t);
	}

	recalculateStats();
}

//Ѫ��
void NPC::addHitPoints(int p_hitpoints){
	m_hitpoints += p_hitpoints;

	if (m_hitpoints < 0) {
		m_hitpoints = 0;
	}
	else if (m_hitpoints > getAttr(MAXHITPOINTS)) {
		m_hitpoints = getAttr(MAXHITPOINTS);
	}
}

//���¼�������ֵ
void NPC::recalculateStats(){
	m_attributes[MAXHITPOINTS] = 10 + ((int)(m_level * (10 / 1.5)));

	if (m_hitpoints > getAttr(MAXHITPOINTS))
		m_hitpoints = getAttr(MAXHITPOINTS);

	if (Weapon() != 0)
		addDynamicBonuses(Weapon());//��������������ֵ�������
	if (Armor() != 0)
		addDynamicBonuses(Armor());//���ӻ��ߵ�����ֵ�������
}

//��������
item NPC::Weapon()
{
	return item();
}

item NPC::Armor()
{
	return item();
}

//�޸�װ����
void NPC::removeWeapon() {
	m_weapon = -1;
	recalculateStats();
}

void NPC::removeArmor() {
	m_armor = -1;
	recalculateStats();
}

void NPC::useWeapon(int p_index) {
	removeWeapon();
	m_weapon = p_index;
	recalculateStats();
}

void NPC::useArmor(int p_index) {
	removeArmor();
	m_armor = p_index;
	recalculateStats();
}

void NPC::useHealing(int p_index) {
	item itr = p_index;
	addBonuses(itr);
}

void NPC::useExp(int p_index) {
	item itr = p_index;
	addBonuses(itr);
}

//�ļ�����
ostream& operator<<(ostream& p_stream, NPC& p) {
	p_stream << "[NAME]           " << p.m_name << "\n";
	//p_stream << "[STATPOINTS]     " << p.m_statpoints << "\n";
	p_stream << "[ATTACKTYPE]     " << p.getType() << "\n";//�������ӵ�
	p_stream << "[EXPERIENCE]     " << p.m_exp << "\n";
	p_stream << "[LEVEL]          " << p.m_level << "\n";
	p_stream << "[ROOM]           " << p.m_room << "\n";
	p_stream << "[HITPOINTS]      " << p.m_hitpoints << "\n";
	p_stream << p.m_baseattributes;
	p_stream << "[WEAPON]         " << p.m_weapon << "\n";
	p_stream << "[ARMOR]          " << p.m_armor << "\n";

	return p_stream;
}

istream& operator>>(istream& p_stream, NPC& p) {
	string temp;
	int type;

	p_stream >> temp >> ws;
	getline(p_stream, p.m_name);
	//p_stream >> temp >> p.m_statpoints;
	p_stream >> temp >> type;
	p.setType(type);
	p_stream >> temp >> p.m_exp;
	p_stream >> temp >> p.m_level;
	p_stream >> temp >> p.m_room;
	p_stream >> temp >> p.m_hitpoints;
	p_stream >> p.m_baseattributes;
	p_stream >> temp >> p.m_weapon;
	p_stream >> temp >> p.m_armor;

	p.recalculateStats();

	return p_stream;
}


#include<iostream>
#include<vector>
using namespace std;

void attack1(int n) {
	if (n == 1) {
		while (Enemy[0].getHP() > 0) {
			Atk1(*patk, Enemy[0]);
		}
		if (Enemy[0].getHP() == 0) {
			cout << "ս��ʤ��!" << endl;
			system("pause");
			return 1;
		}
	}
	if (n == 2) {
		if (patk->getTarget() == 1) {
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 0; i < 2; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 1 && choose != 0) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 0) Atk1(*patk, Enemy[0]);
				else Atk1(*patk, Enemy[1]);
			}
			else {
				for (int i = 0; i < 2; i++) {
					if (Enemy[i].getHP() > 0) {
						Atk(*patk, Enemy[i]);
						break;
					}
				}
			}
		}
		if (patk->getTarget() == 2) {
			Atk(*patk, Enemy[0]);
			Atk(*patk, Enemy[1]);
		}
		if (Enemy[0].getHP() == 0 && Enemy[1].getHP() == 0) {
			cout << "ս��ʤ��!" << endl;
			system("pause");
			return 1;
		}
	}
	if (n == 3) {
		if (patk->getTarget() == 1) {
			if (Enemy[0].getHP() > 0) //�ж�ǰ�ž����Ƿ���
				Atk1(*patk, Enemy[0]);
			else if (Enemy[1].getHP() > 0 && Enemy[2].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 1; i < 3; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 1 && choose != 2) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 1) Atk1(*patk, Enemy[1]);
				else Atk1(*patk, Enemy[2]);
			}
			else {
				for (int i = 1; i < 3; i++) {
					if (Enemy[i].getHP() > 0) {
						Atk1(*patk, Enemy[i]);
						break;
					}
				}
			}
		}
		else if (patk->getTarget() == 2) {
			if (Enemy[0].getHP() > 0) {//�ж�ǰ�ž����Ƿ���
				cout << "Ҫ����˭��" << endl;
				for (int i = 1; i < 3; i++) {
					cout << i << "." << Enemy[0].Name() << " �� " << Enemy[i].Name() << endl;
				}
				cin >> choose;
				while (choose != 1 && choose != 2) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 1) {
					Atk1(*patk, Enemy[0]);
					Atk1(*patk, Enemy[1]);
				}
				else {
					Atk1(*patk, Enemy[0]);
					Atk1(*patk, Enemy[2]);
				}
			}
			else {
				Atk1(*patk, Enemy[1]);
				Atk1(*patk, Enemy[2]);
			}
		}
		else {
			Atk1(*patk, Enemy[0]);
			Atk1(*patk, Enemy[1]);
			Atk1(*patk, Enemy[2]);
		}
		if (Enemy[0].getHP() == 0 && Enemy[1].getHP() == 0 && Enemy[2].getHP() == 0) {
			cout << "ս��ʤ��!" << endl;
			system("pause");
			return 1;
		}
		break;
	}
	if (n == 4) {
		if (patk->getTarget() == 1) {
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 0; i < 2; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 0 && choose != 1) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 0) Atk1(*patk, Enemy[0]);
				if (choose == 1) Atk1(*patk, Enemy[1]);
			}
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() == 0)
				Atk1(*patk, Enemy[0]);
			if (Enemy[0].getHP() == 0 && Enemy[1].getHP() > 0)
				Atk1(*patk, Enemy[1]);
			else {
				if (Enemy[2].getHP() > 0 && Enemy[3].getHP() > 0) {
					cout << "Ҫ����˭��" << endl;
					for (int i = 2; i < 4; i++)
						cout << i << "." << Enemy[i].Name();
					cin >> choose;
					while (choose != 2 && choose != 3) {
						cout << "�������������룡" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cin >> choose;
					}
					if (choose == 2) Atk1(*patk, Enemy[2]);
					else Atk1(*patk, Enemy[3]);
				}
				else {
					for (int i = 2; i < 4; i++) {
						if (Enemy[i].getHP() > 0) {
							Atk1(*patk, Enemy[i]);
							break;
						}
					}
				}
			}
		}
		else if (patk->getTarget() == 2) {
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0) {//�ж�ǰ�ž����Ƿ���
				Atk1(*patk, Enemy[0]);
				Atk1(*patk, Enemy[1]);
			}
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() == 0) {
				Atk1(*patk, Enemy[0])
					cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk1(*patk, Enemy[2]);
				else Atk1(*patk, Enemy[3]);
			}
			if (Enemy[0].getHP() == 0 && Enemy[1].getHP() > 0) {
				Atk1(*patk, Enemy[1])
					cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk1(*patk, Enemy[2]);
				else Atk1(*patk, Enemy[3]);
			}
			else {
				Atk1(*patk, Enemy[2]);
				Atk1(*patk, Enemy[3]);
			}
		}
		if (patk->getTarget() == 3) {
			if (Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0) {
				Atk1(*patk, Enemy[0]);
				Atk1(*patk, Enemy[1]);
				cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Enemy[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk1(*patk, Enemy[2]);
				else Atk1(*patk, Enemy[3]);
			}
			else {
				Atk1(*patk, Enemy[2]);
				Atk1(*patk, Enemy[3]);
				for (int i = 0; i < 2; i++) {
					if (Enemy[i].getHP() > 0) {
						Atk1(*patk, Enemy[i]);
						break;
					}
				}
			}
		}
		if (patk->getTarget() == 4) {
			Atk1(*patk, Enemy[0]);
			Atk1(*patk, Enemy[1]);
			Atk1(*patk, Enemy[2]);
			Atk1(*patk, Enemy[3]);
		}
		if (Enemy[0].getHP() == 0 && Enemy[1].getHP() == 0 && Enemy[2].getHP() == 0) {
			cout << "ս��ʤ��!" << endl;
			system("pause");
			return 1;
		}
		break;
	}
}

void attack2(int n) {
	if (n == 1) {
		while (Me[0].getHP() > 0) {
			Atk2(*patk, Me[0]);
		}
		if (Me[0].getHP() == 0) {
			cout << "ս��ʧ��,����������" << endl;
			system("pause");
			return 1;
		}
	}
	if (n == 2) {
		if (patk->getTarget() == 1) {
			if (Me[0].getHP() > 0 && Me[1].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 0; i < 2; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 1 && choose != 0) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 0) Atk2(*patk, Me[0]);
				else Atk2(*patk, Me[1]);
			}
			else {
				for (int i = 0; i < 2; i++) {
					if (Me[i].getHP() > 0) {
						Atk2(*patk, Me[i]);
						break;
					}
				}
			}
		}
		if (patk->getTarget() == 2) {
			Atk2(*patk, Me[0]);
			Atk2(*patk, Me[1]);
		}
		if (Me[0].getHP() == 0 && Me[1].getHP() == 0) {
			cout << "ս��ʧ��,����������" << endl;
			system("pause");
			return 1;
		}
	}
	if (n == 3) {
		if (patk->getTarget() == 1) {
			if (Me[0].getHP() > 0) //�ж�ǰ�ž����Ƿ���
				Atk2(*patk, Me[0]);
			else if (Me[1].getHP() > 0 && Me[2].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 1; i < 3; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 1 && choose != 2) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 1) Atk2(*patk, Me[1]);
				else Atk2(*patk, Me[2]);
			}
			else {
				for (int i = 1; i < 3; i++) {
					if (Me[i].getHP() > 0) {
						Atk2(*patk, Me[i]);
						break;
					}
				}
			}
		}
		else if (patk->getTarget() == 2) {
			if (Me[0].getHP() > 0) {//�ж�ǰ�ž����Ƿ���
				cout << "Ҫ����˭��" << endl;
				for (int i = 1; i < 3; i++) {
					cout << i << "." << Me[0].Name() << " �� " << Me[i].Name() << endl;
				}
				cin >> choose;
				while (choose != 1 && choose != 2) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 1) {
					Atk2(*patk, Me[0]);
					Atk2(*patk, Me[1]);
				}
				else {
					Atk2(*patk, Me[0]);
					Atk2(*patk, Me[2]);
				}
			}
			else {
				Atk2(*patk, Me[1]);
				Atk2(*patk, Me[2]);
			}
		}
		else {
			Atk2(*patk, Me[0]);
			Atk2(*patk, Me[1]);
			Atk2(*patk, Me[2]);
		}
		if (Me[0].getHP() == 0 && Me[1].getHP() == 0 && Me[2].getHP() == 0) {
			cout << "ս��ʧ��,����������" << endl;
			system("pause");
			return 1;
		}
		break;
	}
	if (n == 4) {
		if (patk->getTarget() == 1) {
			if (Me[0].getHP() > 0 && Me[1].getHP() > 0) {
				cout << "Ҫ����˭��" << endl;
				for (int i = 0; i < 2; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 0 && choose != 1) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 0) Atk2(*patk, Me[0]);
				if (choose == 1) Atk2(*patk, Me[1]);
			}
			if (Me[0].getHP() > 0 && Me[1].getHP() == 0)
				Atk2(*patk, Me[0]);
			if (Me[0].getHP() == 0 && Me[1].getHP() > 0)
				Atk2(*patk, Me[1]);
			else {
				if (Me[2].getHP() > 0 && Me[3].getHP() > 0) {
					cout << "Ҫ����˭��" << endl;
					for (int i = 2; i < 4; i++)
						cout << i << "." << Me[i].Name();
					cin >> choose;
					while (choose != 2 && choose != 3) {
						cout << "�������������룡" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cin >> choose;
					}
					if (choose == 2) Atk2(*patk, Me[2]);
					else Atk2(*patk, Me[3]);
				}
				else {
					for (int i = 2; i < 4; i++) {
						if (Me[i].getHP() > 0) {
							Atk2(*patk, Me[i]);
							break;
						}
					}
				}
			}
		}
		else if (patk->getTarget() == 2) {
			if (Me[0].getHP() > 0 && Me[1].getHP() > 0) {//�ж�ǰ�ž����Ƿ���
				Atk2(*patk, Me[0]);
				Atk2(*patk, Me[1]);
			}
			if (Me[0].getHP() > 0 && Me[1].getHP() == 0) {
				Atk2(*patk, Me[0])
					cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk2(*patk, Me[2]);
				else Atk2(*patk, Me[3]);
			}
			if (Me[0].getHP() == 0 && Me[1].getHP() > 0) {
				Atk2(*patk, Me[1])
					cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk2(*patk, , Me[2]);
				else Atk2(*patk, Me[3]);
			}
			else {
				Atk2(*patk, Me[2]);
				Atk2(*patk, Me[3]);
			}
		}
		if (patk->getTarget() == 3) {
			if (Me[0].getHP() > 0 && Me[1].getHP() > 0) {
				Atk2(*patk, Me[0]);
				Atk2(*patk, Me[1]);
				cout << "Ҫ����˭��" << endl;
				for (int i = 2; i < 4; i++)
					cout << i << "." << Me[i].Name();
				cin >> choose;
				while (choose != 2 && choose != 3) {
					cout << "�������������룡" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> choose;
				}
				if (choose == 2) Atk2(*patk, Me[2]);
				else Atk2(*patk, Me[3]);
			}
			else {
				Atk2(*patk, Me[2]);
				Atk2(*patk, Me[3]);
				for (int i = 0; i < 2; i++) {
					if (Me[i].getHP() > 0) {
						Atk2(*patk, Me[i]);
						break;
					}
				}
			}
		}
		if (patk->getTarget() == 4) {
			Atk2(*patk, Me[0]);
			Atk2(*patk, Me[1]);
			Atk2(*patk, Me[2]);
			Atk2(*patk, Me[3]);
		}
		if (Me[0].getHP() == 0 && Me[1].getHP() == 0 && Me[2].getHP() == 0) {
			cout << "ս��ʧ��,����������" << endl;
			system("pause");
			return 1;
		}
		break;
	}
}


Fight::Fight(Array myArray, Elf* enemyElf)//���ҷ�������,��ʼ��ս��������˫��������������
{
	MyArray = myArray.ReadArray();//Myarray��Ϊ���ݵ�ԭʼ���ݣ��������ԭʼѪ��
	for (int i = 0; i < 4; i++) {
		Me[i] = *MyArray[i];//ʹ��Me������Ϊ������ֻ��ս���п�Ѫ�仯
	}
	for (int i = 0; i < 4; i++) {
		Enemy[i] = enemyElf[i];//ʹ��Enemy������Ϊ������ֻ��ս���п�Ѫ�仯
	}
}

int Fight::ProceedFight(int n, int m, ItemBag& myItem, ElfBag& myElf)//������ʶ��ʾ�Ƿ���Բ�׽������, IBag�Ǵ��뱳����Ʒ����
{
	int choose;
	int Round = 1;
	Elf* patk;
	Elf x;
	Turn();//�������˳��
	while (1) {
		for (int i = 0; i < m + n; i++) {
			//ʶ��Ϊ�ҷ�����
			if (BattleTurn[i][0] < n) {
				if (Me[BattleTurn[i][0]].getHP() > 0) {
					system("cls");
					cout << endl << "\t\t\t\t\t   ��ǰ�غϣ�" << Round;
					ShowBattle();
					patk = &Me[BattleTurn[i][0]];
					while (1) {
						cout << " " << patk->Name() << " Ҫ��ʲô��" << endl;
						cout << "1.����  2.ʹ�õ��� 3.����" << endl;
						cin >> choose;
						if (choose != 1 && choose != 2 && choose != 3) {
							cout << "�������������룡" << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							cin >> choose;
						}
						if (choose == 1) {

							attack1(n);
						}
						else if (choose == 2) {
							while (1) {
								cout << "Ҫʹ��ʲô���ߣ�";
								cout << "1.��ҩ 2.ȡ��" << endl;
								cin >> choose;
								while (choose != 1 && choose != 2) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
								}

								if (choose == 1) {
									cout << "��˭ʹ�ã�" << endl;
									for (int i = 0; i < n; i++) {
										cout << i << " ." << Me[i].Name();
									}
									cout << " 1.��ҩ 2.ȡ�� ";
									cin >> choose;
									while (choose != 1 && choose != 2) {
										cout << "�������������룡" << endl;
										cin.clear();
										cin.ignore(cin.rdbuf()->in_avail());
										cin >> choose;
									}
									if (choose == 2) break;
									else if (m_items < 1) {
										cout << "��ҩ�������㣡";
										system("pause");
										break;
									}
									else {
										UseMedicine(choose - 1, myItem);
										i++;
										break;
									}
								}
								else break;
							}
							i--; break;
						}
						//����
						else {
							if (log == 1) {
								cout << "����ս�����������ܣ�";
								system("pause"); system("cls");

							}
							else {
								if (rand() % 3 == 0) {
									cout << "����ʧ�ܡ�����������" << endl;
									system("pause"); system("cls");
									break;
								}
								else {
									cout << "������......" << endl;;
									system("pause"); system("cls");
									return 0;
								}
							}
						}
					}
				}
				Round++;
			}
			//ʶ��Ϊ�з�����
			else {
				attack2(n);
				Round++;
			}
		}
	}
}

void Fight::Turn(int n, int m)//0-2*n-1���δ����ҷ�nֻ���顢�з�nֻ���飻��ά����ÿ����Ԫ��һ����������ţ��ڶ�����Ӧ�����ٶ�
{
	int t[2];

	for (int i = 0; i < n; i++) {
		BattleTurn[i][0] = i;
		BattleTurn[i][1] = Me[i].getSpe();
	}

	for (int i = n; i < m + n; i++) {
		BattleTurn[i][0] = i;
		BattleTurn[i][1] = Enemy[i - n].getSpe();
	}

	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1 - j; i++) {
			if (BattleTurn[i][1] < BattleTurn[i + 1][1]) {
				t[0] = BattleTurn[i][0];
				t[1] = BattleTurn[i][1];
				BattleTurn[i][0] = BattleTurn[i + 1][0];
				BattleTurn[i][1] = BattleTurn[i + 1][1];
				BattleTurn[i + 1][0] = t[0];
				BattleTurn[i + 1][1] = t[1];
			}
		}
	}
}

void Fight::Atk1(Elf& atk, Elf& target)
{
	if (target.getHP() > 0) {
		if (rand() % 100 <= NPC.getAttr(3)) {
			cout << atk.Name() << " ������ " << target.Name();
			cout << "�� ���� " << target.Name() << " �㿪�˹���!" << endl;
			system("pause");
		}
		else {
			int hurt;
			hurt = atk.getAtk() - target.getDef();
			cout << atk.Name() << " ������ " << target.Name() << " , ";
			if (rand() % 100 <= NPC.getAttr(2)) {
				hurt *= 2;
				cout << "������Ҫ��! ";
			}
			if (Restrain(atk, target) == 1) {
				hurt *= 1.5;
				cout << "Ч����Ⱥ! ";
			}
			else if (Restrain(atk, target) == 0) {
				hurt *= 0.5;
				cout << "��Ч��΢ ";
			}
			if (hurt < 1) hurt = 1;
			cout << " ����� " << hurt << " ���˺���";
			target.ChangeHP(-hurt);
			system("pause");
		}
	}
}

void Fight::Atk2(Elf& atk, Elf& target)
{
	if (target.getHP() > 0) {
		if (rand() % 100 <= Enemy.m_dodging) {
			cout << atk.Name() << " ������ " << target.Name();
			cout << "�� ���� " << target.Name() << " �㿪�˹���!" << endl;
			system("pause");
		}
		else {
			int hurt;
			hurt = atk.getAtk() - target.getDef();
			cout << atk.Name() << " ������ " << target.Name() << " , ";
			if (rand() % 100 <= Enemy.m_hitpoints) {
				hurt *= 2;
				cout << "������Ҫ��! ";
			}
			if (Restrain(atk, target) == 1) {
				hurt *= 1.5;
				cout << "Ч����Ⱥ! ";
			}
			else if (Restrain(atk, target) == 0) {
				hurt *= 0.5;
				cout << "��Ч��΢ ";
			}
			if (hurt < 1) hurt = 1;
			cout << " ����� " << hurt << " ���˺���";
			target.ChangeHP(-hurt);
			system("pause");
		}
	}
}

void Fight::useHealing(int n)
{
	Me[n].addHitPoints(50);
	if (Me[n].getHP() > MyArray[n]->getHP())
		Me[n] = *MyArray[n];
	m_items - 1;
	cout << " " << Me[n].Name() << " �ָ���50������";
}

int Fight::Restrain(Elf& atk, Elf& target)//0Ϊ������������, 1Ϊ���������Ʊ�������, -1Ϊ�޿��ƹ�ϵ
{
	if ((atk.getTyp()) == 0 && (target.getTyp()) == 1) return 0;
	else if ((atk.getTyp()) == 1 && (target.getTyp()) == 2) return 0;
	else if ((atk.getTyp()) == 2 && (target.getTyp()) == 0) return 0;

	else if ((atk.getTyp()) == 1 && (target.getTyp()) == 0) return 1;
	else if ((atk.getTyp()) == 2 && (target.getTyp()) == 1) return 1;
	else if ((atk.getTyp()) == 0 && (target.getTyp()) == 2) return 1;

	else return -1;
	return 0;
}

void Fight::ShowMe1() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << (static_cast<player>Me[0])->getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << (static_cast<player>Me[0])->etLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << (static_cast<player>Me[0])->getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << sew(6) << (static_cast<player>Me[0])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------" << endl;
	cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowMe2() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << (static_cast<player>Me[0])->getName() << "|" << "\t\t\t\t|������" << left << sew(6) << (static_cast<npc>Me[1])->getName()<<"|"<<endl;
	cout << "        \t|�ȼ���" << left << sew(6) << (static_cast<player>Me[0])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << (static_cast<npc>Me[1])->getLevel()<< "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << (static_cast<player>Me[0])->getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << (static_cast<npc>Me[1])->getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << sew(6) << (static_cast<player>Me[0])->getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << (static_cast<npc>Me[1])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	
	cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowMe3() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << (static_cast<npc>Me[1])->getName() << "|" << "\t\t\t\t|������" << left << sew(6) << (static_cast<npc>Me[2])->getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << (static_cast<npc>Me[1])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << (static_cast<npc>Me[2])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << (static_cast<npc>Me[1])->getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << (static_cast<npc>Me[2])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << (static_cast<npc>Me[1])->getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << (static_cast<npc>Me[2])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "   ��   \t             \t|������" << left << sew(10) << (static_cast<player>Me[0])->getName() << "|" << endl;
	cout << "        \t             \t|�ȼ���" << left << sew(10) << (static_cast<player>Me[0])->getLevel() << "|" << endl;
	cout << "        \t             \t|���飺" << left << sew(10) << (static_cast<player>Me[0])->getExp() << "|" << endl;
	cout << "        \t             \t|��������" << left << sew(10) << (static_cast<player>Me[0])->getType() << "|" << endl;
	cout << "        \t             \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << endl;
	cout << "        \t             \t|ATTACK:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << endl;
	cout << "        \t             \t|CRITING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(2) << "|" << endl;
	cout << "        \t             \t|DODGING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << endl;
	cout << "        \t             \t|SPEED:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "--------------------------------------------------------------------------------\n\n";
}


void Fight::ShowMe4() {
	//cout << "---------------------------------- �����Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << sew(60) << (static_cast<npc>Me[2])->getName() << "|" << "\t\t\t\t|������" << left << sew(6) << (static_cast<npc>Me[3])->getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << (static_cast<npc>Me[2])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << (static_cast<npc>Me[3])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << (static_cast<npc>Me[2])->getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << (static_cast<npc>Me[3])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << (static_cast<npc>Me[2])->getAttackType() << "|" << "\t\t\t\t|��������" << left << sew(6) << (static_cast<npc>Me[3])->getAttackType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[3])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[3])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << (static_cast<npc>Me[3])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << (static_cast<npc>Me[3])->getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << sew(6) << (static_cast<npc>Me[2])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << (static_cast<npc>Me[3])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << sew(6) << (static_cast<player>Me[0])->getName() << "|" << "\t\t\t\t|������" << left << sew(10) << (static_cast<npc>Me[1])->getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << (static_cast<player>Me[0])->getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(10) << (static_cast<npc>Me[1])->getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << (static_cast<player>Me[0])->getExp() << "|" << "\t\t\t\t|���飺" << left << sew(10) << (static_cast<npc>Me[1])->getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << (static_cast<player>Me[0])->getType() << "|" << "\t\t\t\t|��������" << left << sew(10) << (static_cast<npc>Me[1])->getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(2) << "|"  << "\t\t\t\t|CRITING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << (static_cast<player>Me[0])->getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << (static_cast<npc>Me[1])->getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;

	cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy1() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << Enemy[0].getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << Enemy[0].getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << Enemy[0].getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << sew(6) << Enemy[0].getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << Enemy[0].getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << sew(6) << Enemy[0].getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << Enemy[0].getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << Enemy[0].getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << Enemy[0].getAttr(4) << "|" << endl;
	cout << "        \t---------------------" << endl;
	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy2() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << Enemy[0].getName() << "|" << "\t\t\t\t|������" << left << sew(6) << Enemy[1].getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << Enemy[0].getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << Enemy[1].getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << Enemy[0].getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << Enemy[1].getExp() << "|" << endl;
	cout << "   ��   \t|��������" << left << sew(6) << Enemy[0].getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << Enemy[1].getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << Enemy[0].getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << Enemy[1].getAttr(0) << "|" << endl;
	cout << "   ��   \t|ATTACK:" << left << sew(6) << Enemy[0].getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << Enemy[1].getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << Enemy[0].getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << Enemy[1].getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << Enemy[0].getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << Enemy[1].getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << Enemy[0].getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << Enemy[1].getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;

	//cout << "--------------------------------------------------------------------------------\n\n";
}

void Fight::ShowEnemy3() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "        \t             \t|������" << left << sew(6) << Enemy[0].getName() << "|" << endl;
	cout << "        \t             \t|�ȼ���" << left << sew(6) << Enemy[0].getLevel() << "|" << endl;
	cout << "        \t             \t|���飺" << left << sew(6) << Enemy[0].getExp() << "|" << endl;
	cout << "        \t             \t|��������" << left << sew(6) << Enemy[0].getAttackType() << "|" << endl;
	cout << "        \t             \t|MAXHITPOINTS:" << left << sew(6) << Enemy[0].getAttr(0) << "|" << endl;
	cout << "        \t             \t|ATTACK:" << left << sew(6) << Enemy[0].getAttr(1) << "|" << endl;
	cout << "        \t             \t|CRITING:" << left << sew(6) << Enemy[0].getAttr(2) << "|" << endl;
	cout << "        \t             \t|DODGING:" << left << sew(6) << Enemy[0].getAttr(3) << "|" << endl;
	cout << "   ��   \t             \t|SPEED:" << left << sew(6) << Enemy[0].getAttr(4) << "|" << endl;
	cout << "        \t             \t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << sew(6) << Enemy[1].getName() << "|" << "\t\t\t\t|������" << left << sew(6) << Enemy[2].getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << Enemy[1].getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << Enemy[2].getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << Enemy[1].getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << Enemy[2].getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << Enemy[1].getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << Enemy[2].getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << Enemy[1].getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << Enemy[2].getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << Enemy[1].getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << Enemy[2].getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << Enemy[1].getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << Enemy[2].getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << Enemy[1].getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << Enemy[2].getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << Enemy[1].getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << Enemy[2].getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;

	//cout << "--------------------------------------------------------------------------------\n\n";
}


void Fight::ShowEnemy4() {
	//cout << "---------------------------------- �з���Ϣ ----------------------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t|������" << left << sew(6) << Enemy[0].getName() << "|" << "\t\t\t\t|������" << left << sew(6) << Enemy[1].getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << Enemy[0].getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << Enemy[1].getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << Enemy[0].getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << Enemy[1].getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << Enemy[0].getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << Enemy[1].getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << Enemy[0].getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << Enemy[1].getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << Enemy[0].getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << Enemy[1].getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << Enemy[0].getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << Enemy[1].getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << Enemy[0].getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << Enemy[1].getAttr(3) << "|" << endl;
	cout << "   ��   \t|SPEED:" << left << sew(6) << Enemy[0].getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << Enemy[1].getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;
	cout << "   ��   \t|������" << left << sew(6) << Enemy[3].getName() << "|" << "\t\t\t\t|������" << left << sew(6) << Enemy[2].getName() << "|" << endl;
	cout << "        \t|�ȼ���" << left << sew(6) << Enemy[3].getLevel() << "|" << "\t\t\t\t|�ȼ���" << left << sew(6) << Enemy[2].getLevel() << "|" << endl;
	cout << "        \t|���飺" << left << sew(6) << Enemy[3].getExp() << "|" << "\t\t\t\t|���飺" << left << sew(6) << Enemy[2].getExp() << "|" << endl;
	cout << "        \t|��������" << left << sew(6) << Enemy[3].getType() << "|" << "\t\t\t\t|��������" << left << sew(6) << Enemy[2].getType() << "|" << endl;
	cout << "        \t|MAXHITPOINTS:" << left << sew(6) << Enemy[3].getAttr(0) << "|" << "\t\t\t\t|MAXHITPOINTS:" << left << sew(6) << Enemy[2].getAttr(0) << "|" << endl;
	cout << "        \t|ATTACK:" << left << sew(6) << Enemy[3].getAttr(1) << "|" << "\t\t\t\t|ATTACK:" << left << sew(6) << Enemy[2].getAttr(1) << "|" << endl;
	cout << "        \t|CRITING:" << left << sew(6) << Enemy[3].getAttr(2) << "|" << "\t\t\t\t|CRITING:" << left << sew(6) << Enemy[2].getAttr(2) << "|" << endl;
	cout << "        \t|DODGING:" << left << sew(6) << Enemy[3].getAttr(3) << "|" << "\t\t\t\t|DODGING:" << left << sew(6) << Enemy[2].getAttr(3) << "|" << endl;
	cout << "        \t|SPEED:" << left << sew(6) << Enemy[3].getAttr(4) << "|" << "\t\t\t\t|SPEED:" << left << sew(6) << Enemy[2].getAttr(4) << "|" << endl;
	cout << "        \t---------------------\t\t\t\t---------------------" << endl;

	//cout << "--------------------------------------------------------------------------------\n\n";
}
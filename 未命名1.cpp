#include<iostream>
#include<vector>
using namespace std;

void attack1(int n){
	if(n==1){
		while(Enemy[0].getHP() > 0){
		Atk1(*patk, Enemy[0]);
		}
		if(Enemy[0].getHP()==0){
		    cout << "ս��ʤ��!" << endl;
			system("pause");
			return 1;
		}
	}
	if(n==2){
	    if (patk->getTarget() == 1){
	    	if(Enemy[0].getHP()>0&&Enemy[1].getHP()>0) {
					    cout << "Ҫ����˭��" << endl;
						for (int i = 0; i < 2; i++)
						   	cout << i << "." << Enemy[i].Name();
						cin >> choose;
						while (choose != 1 && choose !=0) {
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
        if (patk->getTarget() == 2){
        	Atk(*patk, Enemy[0]);
			Atk(*patk, Enemy[1]);
		}
		if (Enemy[0].getHP() == 0 && Enemy[1].getHP() == 0) {
								cout << "ս��ʤ��!" << endl;
								system("pause");
								return 1;
							}
    }
    if(n==3){
		    if (patk->getTarget() == 1) {
				if (Enemy[0].getHP() > 0) //�ж�ǰ�ž����Ƿ���
					Atk1(*patk, Enemy[0]);
					else if(Enemy[1].getHP()>0&&Enemy[2].getHP()>0) {
					    	cout << "Ҫ����˭��" << endl;
							for (int i = 1; i < 3; i++)
						    	cout << i << "." << Enemy[i].Name();
							cin >> choose;
							while (choose != 1 && choose!= 2) {
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
	if(n==4){
		    if (patk->getTarget() == 1) {
				if (Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0) {
					cout << "Ҫ����˭��" << endl;
					    for (int i = 0; i < 2; i++)
				    	    cout << i << "." << Enemy[i].Name();
					    cin >> choose;
					    while (choose !=0 && choose != 1) {
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
				else{
					if(Enemy[2].getHP()>0&&Enemy[3].getHP()>0) {
				    	cout << "Ҫ����˭��" << endl;
							for (int i = 2; i < 4; i++)
						    	cout << i << "." << Enemy[i].Name();
							cin >> choose;
							while (choose != 2 && choose!= 3) {
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
					if (Enemy[0].getHP() > 0 && Enemy[1].getHP() == 0){
						Atk1(*patk, Enemy[0])
				    	cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Enemy[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
							}
							if (choose == 2) Atk1(*patk, Enemy[2]);
							else Atk1(*patk, Enemy[3]);
					}
					if (Enemy[0].getHP() == 0 && Enemy[1].getHP() > 0){
						Atk1(*patk, Enemy[1])
				    	cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Enemy[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
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
				if (patk->getTarget() == 3){
					if(Enemy[0].getHP() > 0 && Enemy[1].getHP() > 0){
						Atk1(*patk, Enemy[0]);
			            Atk1(*patk, Enemy[1]);
			            cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Enemy[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
							}
							if (choose == 2) Atk1(*patk, Enemy[2]);
							else Atk1(*patk, Enemy[3]);
					}
					else{
						Atk1(*patk, Enemy[2]);
						Atk1(*patk, Enemy[3]);
						for(int i=0;i<2;i++){
								if (Enemy[i].getHP() > 0) {
									Atk1(*patk, Enemy[i]);
									break;
						}
					}
				}
			}
			if (patk->getTarget() == 4){
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

void attack2(int n){
	if(n==1){
		while(Me[0].getHP() > 0){
		Atk2(*patk, Me[0]);
		}
		if(Me[0].getHP()==0){
		    cout << "ս��ʧ��,����������" << endl;
			system("pause");
			return 1;
		}
	}
	if(n==2){
	    if (patk->getTarget() == 1){
	    	if(Me[0].getHP()>0&&Me[1].getHP()>0) {
					    cout << "Ҫ����˭��" << endl;
						for (int i = 0; i < 2; i++)
						   	cout << i << "." << Me[i].Name();
						cin >> choose;
						while (choose != 1 && choose !=0) {
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
        if (patk->getTarget() == 2){
        	Atk2(*patk, Me[0]);
			Atk2(*patk, Me[1]);
		}
		if (Me[0].getHP() == 0 && Me[1].getHP() == 0) {
								cout << "ս��ʧ��,����������" << endl;
								system("pause");
								return 1;
							}
    }
    if(n==3){
		    if (patk->getTarget() == 1) {
				if (Me[0].getHP() > 0) //�ж�ǰ�ž����Ƿ���
					Atk2(*patk, Me[0]);
					else if(Me[1].getHP()>0&&Me[2].getHP()>0) {
					    	cout << "Ҫ����˭��" << endl;
							for (int i = 1; i < 3; i++)
						    	cout << i << "." << Me[i].Name();
							cin >> choose;
							while (choose != 1 && choose!= 2) {
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
	if(n==4){
		    if (patk->getTarget() == 1) {
				if (Me[0].getHP() > 0 && Me[1].getHP() > 0) {
					cout << "Ҫ����˭��" << endl;
					    for (int i = 0; i < 2; i++)
				    	    cout << i << "." << Me[i].Name();
					    cin >> choose;
					    while (choose !=0 && choose != 1) {
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
				else{
					if(Me[2].getHP()>0&&Me[3].getHP()>0) {
				    	cout << "Ҫ����˭��" << endl;
							for (int i = 2; i < 4; i++)
						    	cout << i << "." << Me[i].Name();
							cin >> choose;
							while (choose != 2 && choose!= 3) {
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
					if (Me[0].getHP() > 0 && Me[1].getHP() == 0){
						Atk2(*patk, Me[0])
				    	cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Me[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
							}
							if (choose == 2) Atk2(*patk, Me[2]);
							else Atk2(*patk, Me[3]);
					}
					if (Me[0].getHP() == 0 && Me[1].getHP() > 0){
						Atk2(*patk, Me[1])
				    	cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Me[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
							}
							if (choose == 2) Atk2(*patk, ,Me[2]);
							else Atk2(*patk, Me[3]);
					}
					else {
						Atk2(*patk, Me[2]);
						Atk2(*patk, Me[3]);
					}
				}
				if (patk->getTarget() == 3){
					if(Me[0].getHP() > 0 && Me[1].getHP() > 0){
						Atk2(*patk, Me[0]);
			            Atk2(*patk, Me[1]);
			            cout << "Ҫ����˭��" << endl;
						for (int i = 2; i < 4; i++)
						 	cout << i << "." << Me[i].Name();
						cin >> choose;
							while (choose != 2 && choose!= 3) {
									cout << "�������������룡" << endl;
									cin.clear();
									cin.ignore(cin.rdbuf()->in_avail());
									cin >> choose;
							}
							if (choose == 2) Atk2(*patk, Me[2]);
							else Atk2(*patk, Me[3]);
					}
					else{
						Atk2(*patk, Me[2]);
						Atk2(*patk, Me[3]);
						for(int i=0;i<2;i++){
								if (Me[i].getHP() > 0) {
									Atk2(*patk, Me[i]);
									break;
						}
					}
				}
			}
			if (patk->getTarget() == 4){
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
    	

Fight::Fight(Array myArray,	Elf *enemyElf)//���ҷ�������,��ʼ��ս��������˫��������������
{ 
	MyArray = myArray.ReadArray();//Myarray��Ϊ���ݵ�ԭʼ���ݣ��������ԭʼѪ��
	for (int i = 0; i < 4; i++) {
		Me[i] = *MyArray[i];//ʹ��Me������Ϊ������ֻ��ս���п�Ѫ�仯
	}
	for(int i=0 ; i<4 ; i++){	
		Enemy[i] = enemyElf[i];//ʹ��Enemy������Ϊ������ֻ��ս���п�Ѫ�仯
	}
}

int Fight::ProceedFight(int n, int m, ItemBag &myItem,ElfBag &myElf)//������ʶ��ʾ�Ƿ���Բ�׽������, IBag�Ǵ��뱳����Ʒ����
{
	int choose;
	int Round=1;
	Elf* patk;
	Elf x;
	Turn();//�������˳��
	while (1) {
		for (int i = 0; i < m+n; i++) {
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
								while (choose != 1 && choose!=2) {
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
									while (choose != 1 && choose!=2) {
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
							i--;break;
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

	for (int i = 0; i < n; i++){
		BattleTurn[i][0] = i;
		BattleTurn[i][1] = Me[i].getSpe();
	}

	for (int i = n; i < m+n; i++) {
		BattleTurn[i][0] = i;
		BattleTurn[i][1] = Enemy[i-n].getSpe();
	}

	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1 - j; i++) {
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

void Fight::Atk1(Elf &atk,Elf &target)
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
			else if(Restrain(atk, target) == 0) {
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

void Fight::Atk2(Elf &atk,Elf &target)
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
			else if(Restrain(atk, target) == 0) {
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
	m_items-1;
	cout <<" " << Me[n].Name()<<" �ָ���50������";
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

void Fight::ShowBattle1()//ս��ʱչʾ˫������
{
	cout <<endl << endl;
	cout << "\t| " << left << setw(9) << Me[0].getName() <<setw(4)<< "|" << "\t\t\t|";
	cout << "\t|�ȼ�:" <<left<<setw(9)<< Me[1].getLv()<<"|" << "\t\t\t|" ;
	cout << "\t\t\t |�ȼ�:" << left << setw(9) << Enemy[1].getLv() << "|"<< endl;
	cout << "\t|����:" << right <<setw(4)<< Me[1].getHP()<<"/"<<right<<setw(4)<<MyArray[1]->getHP()<<"|" << "\t\t\t|" ;
	cout << "\t\t\t |����:" << left << setw(9) << Enemy[1].getHP() << "|" << endl;
	cout << "\t|����:" << left << setw(9) << Me[1].getAtk() << "|" << "  --------------" << "\t|";
	cout << "\t --------------";
	cout << "\t |����:" << left << setw(9) << Enemy[1].getAtk() <<"|" << endl;
	cout << "\t|����:" << left << setw(9) << Me[1].getDef() << "| | " << left << setw(9) << Me[0].getName() << setw(4) << Me[0].putTyp() << "|" << "\t|";
	cout << "\t| " << left << setw(9) << Enemy[0].getName() << setw(4) << Enemy[0].putTyp() << "|";
	cout << " |����:" << left << setw(9) << Enemy[1].getDef() << "| " <<endl ;
	cout << "\t --------------" <<"\t |�ȼ�:" << left << setw(9) << Me[0].getLv() << "|" << "\t|" ;
	cout << "\t|�ȼ�:" << left << setw(9) << Enemy[0].getLv() << "|";
	cout << "  --------------" << endl;
	cout << "\t --------------" << "  |����:" << right << setw(4) << Me[0].getHP() << "/" << right << setw(4) << MyArray[0]->getHP() << "|" << "\t|";
	cout << "\t|����:" << left << setw(9) << Enemy[0].getHP() << "|";
	cout << "  --------------" << endl;
	cout << "\t| " << left << setw(9) << Me[2].getName() << setw(4) << Me[2].putTyp() << "|" << " |����:" << left << setw(9) << Me[0].getAtk() << "|" << "\t|" ;
	cout << "\t|����:" << left << setw(9) << Enemy[0].getAtk() << "|" ;
	cout << " | " << left << setw(9) << Enemy[2].getName() << setw(4) << Enemy[2].putTyp() << "|" << endl;
	cout << "\t|�ȼ�:" << left << setw(9) << Me[2].getLv() << "|" << " |����:" << left << setw(9) << Me[0].getDef() << "|" << "\t|" ;
	cout << "\t|����:" << left << setw(9) << Enemy[0].getDef() << "|" ;
	cout << " |�ȼ�:" << left << setw(9) << Enemy[2].getLv() << "|" << endl;
	cout << "\t|����:" << right << setw(4) << Me[2].getHP()  << "/" << right << setw(4) << MyArray[2]->getHP() << "|" << "  --------------" <<"\t|";
	cout << "\t --------------";
	cout << "  |����:" << left << setw(9) << Enemy[2].getHP() << "|" << endl;
	cout << "\t|����:" << left << setw(9) << Me[2].getAtk() <<"|" <<"\t\t\t|" ;
	cout << "\t\t\t |����:" << left << setw(9) << Enemy[2].getAtk() <<"|" << endl;
	cout << "\t|����:" << left << setw(9) << Me[2].getDef() << "|"<<"\t\t\t|" ;
	cout << "\t\t\t |����:" << left << setw(9) << Enemy[2].getDef() << "|" << endl;
	cout << "\t --------------" "\t\t\t\t|";
	cout << "\t\t\t  --------------"<<endl;
	cout << endl;
}

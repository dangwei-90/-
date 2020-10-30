// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ����¼ģʽ

// ����¼ģʽ : ����һ�������ĳ��״̬���Ա����ʵ���ʱ��ָ�����

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// ��ɫ��ӵ������״̬����
class Player {
public:
	void SetCurrentState(int vitality, int attack, int defence) {
		vitality_ = vitality;
		attack_ = attack;
		defence_ = defence;
	}

public:
	int vitality_ = 0;
	int attack_ = 0;
	int defence_ = 0;
};

// ����¼�����ڼ�¼ĳһ�׶ε�״̬
class Memento {
public:
	~Memento() {
		SAFE_DELETE(player_);
	}

	void GetPlayerState(Player* player) {
		player->vitality_ = player_->vitality_;
		player->attack_ = player_->attack_;
		player->defence_ = player_->defence_;
	}

	void SetPlayer(Player* player) {
		player_->vitality_ = player->vitality_;
		player_->attack_ = player->attack_;
		player_->defence_ = player->defence_;
	}

public:
	Player* player_ = new Player();
};

void print_player_state(Player* player) {
	printf("=====================\n");
	printf("vitality: %d \n", player->vitality_);
	printf("attack: %d \n", player->attack_);
	printf("defence: %d \n", player->defence_);
}

int main()
{
	// before pk boss
	Player* player = new Player();
	player->SetCurrentState(100, 100, 100);

	print_player_state(player);

	// memento
	Memento* memento = new Memento();
	memento->SetPlayer(player);
	print_player_state(player);

	// after pk boss
	player->SetCurrentState(0, 0, 0);
	print_player_state(player);

	// memento to player
	memento->GetPlayerState(player);
	print_player_state(player);

	SAFE_DELETE(memento);
	SAFE_DELETE(player);

	return 0;
}



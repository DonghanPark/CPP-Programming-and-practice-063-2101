#include <iostream>
#include "bet.h"
#include "card.h"
#include "win.h"
#include "hand_ranking.h"
#include "givecard.h"

using namespace std;

int main() {
	Card player;
	betting bet;
	Give_card test;
	Win test1;
	//201824470 �ڵ���. ������� 
	HandRank test2;
	HandRank test3;
	// 201824470 �ڵ���. ���� ���� �Դϴ�. 
	int result, ans1, ans2, round=1;

	while (bet.retpoint1(bet) > 0 && bet.retpoint2(bet) > 0) {
		cout << round << "��° ��� �Դϴ�" << endl;
		bet.printMoney();

		player.shuffle();
		player.dist();
		player.show1();
		player.show2();

		cout << "100���� �ڵ����� �⺻ ���ñ����� ���ϴ�" << endl;
		if (bet.deal() == -1) continue;
		test.Give_deck(player);
		cout << "100���� �ڵ����� �⺻ ���ñ����� ���ϴ�" << endl;
		if (bet.deal() == -1) continue;

		//201824470 �ڵ���. ������� 
		test2.checkHandRanking(player, test2, 1);
		test3.checkHandRanking(player, test3, 2);
		cout << "1. " << test2.returnHighestHandRanking() << endl;
		test2.printHighestSelectedCard();
		cout << "2. " << test3.returnHighestHandRanking() << endl;
		test3.printHighestSelectedCard();
		// 201824470 �ڵ���. ���� ���� �Դϴ�. 
		
		result = test1.round_Win(test2.returnHighestHandRanking(), test3.returnHighestHandRanking(), test2.returnSumOfHighestSelectedCard(), test3.returnSumOfHighestSelectedCard());
		bet.playerWin(result);
		bet.printMoney();

		cout << "player1 ��� �Ͻðڽ��ϱ�? yes : 1, no : 2" << endl;
		cin >> ans1;
		cout << "player2 ��� �Ͻðڽ��ϱ�? yes : 1, no : 2" << endl;
		cin >> ans2;
		if (ans1 == 2 || ans2 == 2)
			break;

		//201824470 �ڵ���. ������� 
		test2.initHandRankClass();
		test3.initHandRankClass();
		// 201824470 �ڵ���. ���� ���� �Դϴ�. 
		round++;
	}
	cout << endl;
	test1.final_Win(bet);
	bet.printMoney();

	return 0;
}

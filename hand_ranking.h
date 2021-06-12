#ifndef __HANDRANKING_H__  
#define __HANDRANKING_H__
#include "card.h"

class HandRank {
private:
	int highestSelectedCard[5];
	int highestHandRanking;
	int sumOfHighestSelectedCard;
public:
	HandRank() {
		highestHandRanking = 12;
		sumOfHighestSelectedCard = 0;
		for (int i = 0; i < 5; i++)
			highestSelectedCard[i] = 0;
	}
	int returnHighestSelectedCard() { // ī�� ��� �Լ� 
		for (int i = 0; i < 5; i++) {
			cout << highestSelectedCard[i] << " ";
		}
		cout << endl;
	}
	int returnSumOfHighestSelectedCard() { // ī�� �� �հ� 
		int sumOfHighestSelectedCard = 0;
		for (int i = 0; i < 5; i++) {
			sumOfHighestSelectedCard += highestSelectedCard[i];
		}
		return sumOfHighestSelectedCard;
	}
	void changeHighestSelectedCard(int* selectedCard) { // ���� ���� ī�� ���� 
		for (int i = 0; i < 5; i++) {
			highestSelectedCard[i] = selectedCard[i];
		}
		//cout << "end" << endl;
	}
	int returnHighestHandRanking() { // ���� ���� ���� ���� return 
		return highestHandRanking;
	}
	void changeHighestHandRanking(int handRanking) { // ���� ���� ���� ���� 
		highestHandRanking = handRanking;
	}
	void initHandRankClass() {
		highestHandRanking = 12;
		sumOfHighestSelectedCard = 0;
		for (int i = 0; i < 5; i++)
			highestSelectedCard[i] = 0;
	}
	void printHighestSelectedCard() {
		for (int i = 0; i < 5; i++) {
			int pattern = highestSelectedCard[i] / 13;
			int cardnumber = highestSelectedCard[i] % 13;

			switch (pattern) {
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			default:
				break;
			}

			if (cardnumber > 1 && cardnumber < 11)
				cout << cardnumber << " ";
			else {
				switch (cardnumber) {
				case 0:
					cout << "K ";
					break;
				case 1:
					cout << "A ";
					break;
				case 11:
					cout << "J ";
					break;
				case 12:
					cout << "Q ";
					break;
				}
			}
		}
		cout << endl;
	}

	int checkHandRanking(Card card, HandRank& handRank, int num);
	int combination(int myCard[], HandRank& handRank, int visited[], int index, int n, int r);
	int storeSelectedHandCardInfo(int selectedCard[]);
	int printHandRanking(int cardSuit[], int cardNum[]);
};

#endif

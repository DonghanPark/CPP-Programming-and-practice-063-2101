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
	int returnHighestSelectedCard() { // 카드 출력 함수 
		for (int i = 0; i < 5; i++) {
			cout << highestSelectedCard[i] << " ";
		}
		cout << endl;
	}
	int returnSumOfHighestSelectedCard() { // 카드 수 합계 
		int sumOfHighestSelectedCard = 0;
		for (int i = 0; i < 5; i++) {
			sumOfHighestSelectedCard += highestSelectedCard[i];
		}
		return sumOfHighestSelectedCard;
	}
	void changeHighestSelectedCard(int* selectedCard) { // 좋은 족보 카드 갱신 
		for (int i = 0; i < 5; i++) {
			highestSelectedCard[i] = selectedCard[i];
		}
		//cout << "end" << endl;
	}
	int returnHighestHandRanking() { // 현재 가장 높은 족보 return 
		return highestHandRanking;
	}
	void changeHighestHandRanking(int handRanking) { // 가장 높은 족보 변경 
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
				cout << "♠";
				break;
			case 1:
				cout << "◇";
				break;
			case 2:
				cout << "♣";
				break;
			case 3:
				cout << "♡";
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

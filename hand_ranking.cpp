#include "hand_ranking.h"

int HandRank::printHandRanking(int cardSuit[], int cardNum[]) {

	// Royal Straight Flush
	int fiveCardOfSameSuit = 0;
	for (int i = 0; i < 5; i++) {
		if (cardSuit[i] == 5)
			fiveCardOfSameSuit = 1;
	}
	int royalStraight = 0;
	for (int i = 10; i < 15; i++) {
		if (cardNum[i] > 0)
			royalStraight += 1;
	}
	if (fiveCardOfSameSuit && (royalStraight == 5)) {
		//cout << "Royal Straight Flush" << endl;
		return 0;
	}

	// Back Straight Flush
	int backStraight = 0;
	for (int i = 1; i < 6; i++) {
		if (cardNum[i] > 0)
			backStraight += 1;
	}
	if (fiveCardOfSameSuit && (backStraight == 5)) {
		//cout << "Back Straight Flush" << endl;
		return 1;
	}

	// Straight Flush
	int straight = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = i; j < i + 5; j++) {
			if (cardNum[j] > 0)
				straight += 1;
		}
		if (fiveCardOfSameSuit && (straight == 5)) {
			//cout << "Straight Flush" << endl;
			return 2;
		}
		straight = 0;
	}

	// Four Card
	for (int i = 1; i < 14; i++) {
		if (cardNum[i] == 4) {
			//cout << "Four Card" << endl;
			return 3;
		}
	}

	// Full House
	int triple = 0, twoPairs = 0;
	for (int i = 1; i < 14; i++) {
		if (cardNum[i] == 3)
			triple = 1;
		if (cardNum[i] == 2)
			twoPairs = 1;
	}
	if (triple && twoPairs) {
		//cout << "Full House" << endl;
		return 4;
	}

	// Flush
	for (int i = 0; i < 5; i++) {
		if (cardSuit[i] == 5) {
			//cout << "Flush" << endl;
			return 5;
		}
	}

	// Mountain
	int mountain = 0;
	for (int i = 10; i < 15; i++) {
		if (cardNum[i] > 0)
			mountain += 1;
	}
	if (mountain == 5) {
		//cout << "Mountain" << endl;
		return 6;
	}

	// Back Straight
	if (backStraight == 5) {
		//cout << "Back Straight" << endl;
		return 7;
	}

	// Straight
	straight == 0;
	for (int i = 1; i < 10; i++) {
		for (int j = i; j < i + 5; j++) {
			if (cardNum[j] > 0)
				straight += 1;
		}
		if (straight == 5) {
			//cout << "Straight" << endl;
			return 8;
		}
		straight = 0;
	}

	// Triple
	if (triple) {
		//cout << "Triple" << endl;
		return 9;
	}

	// Two Pairs
	for (int i = 1; i < 13; i++) {
		for (int j = i + 1; j < 14; j++) {
			if (cardNum[i] == 2 && cardNum[j] == 2) {
				//cout << "Two Pairs" << endl;
				return 10;
			}
		}
	}

	// One Pairs
	for (int i = 1; i < 14; i++) {
		if (cardNum[i] == 2) {
			//cout << "one Pairs" << endl;
			return 11;
		}
	}

	// No Pairs
	//cout << "No Pairs" << endl;
	return 12;

	return 0;
}

int HandRank::storeSelectedHandCardInfo(int selectedCard[]) {
	int cardSuitCount[5] = { 0, };
	int cardNumCount[15] = { 0, };

	//TODO #define ACE 14

	// TODO
	// enum 

	for (int i = 0; i < 5; i++) {
		int handCardSuit = selectedCard[i] / 13;
		int dividedCardNum = selectedCard[i] % 13;

		cardSuitCount[handCardSuit] += 1;
		// Spade == 0, Diamond == 1, Clover == 2, Heart == 3

		cardNumCount[dividedCardNum] += 1;
		if (dividedCardNum == 1) // ACE. exception handling
			cardNumCount[14] += 1;
		if (dividedCardNum == 0) //KING. exception handling
			cardNumCount[13] += 1;
	}

	//H, D, C, S
	return printHandRanking(cardSuitCount, cardNumCount);
}

int HandRank::combination(int myCard[], HandRank& handRank, int visited[], int index, int n, int r) {

	if (r == 0) {
		int* selectedCard = new int[5];
		int selectedCardIndex = 0;
		int handRanking = 0;

		for (int i = 0; i < 7; i++) {
			if (visited[i]) {
				selectedCard[selectedCardIndex] = myCard[i];
				selectedCardIndex++;
			}
		}

		handRanking = storeSelectedHandCardInfo(selectedCard);

		if (handRank.returnHighestHandRanking() > handRanking) {
			handRank.changeHighestHandRanking(handRanking);
			handRank.changeHighestSelectedCard(selectedCard);
		} // 가장 높은 족보 변경 
		else if (handRank.returnHighestHandRanking() == handRanking) {
			int sumOfSelectedCard = 0;
			for (int i = 0; i < 5; i++) {
				// TODO 1~13 compare 
				sumOfSelectedCard += selectedCard[i];
			}
			if (sumOfSelectedCard > handRank.returnSumOfHighestSelectedCard()) {
				handRank.changeHighestHandRanking(handRanking);
				handRank.changeHighestSelectedCard(selectedCard);
			}
		} // 족보 같은 경우 처리 

		delete[] selectedCard;

		return handRanking;
	}

	if (index == n) // false 중단 조건, r이 0이 아니고 index가 끝난 경우 처리 
		return 12;

	// 해당 index 선택 
	visited[index] = 1;
	combination(myCard, handRank, visited, index + 1, n, r - 1);

	// 해당 index 선택하지 않는 경우 
	visited[index] = 0;
	combination(myCard, handRank, visited, index + 1, n, r);
}

int HandRank::checkHandRanking(Card card, HandRank& handRank, int num) {
	int visited[7] = { 0, };
	int highestHandRanking = 10;
	int handRanking = 0;

	if (num == 1)
		combination(card.card1, handRank, visited, 0, 7, 5);
	else
		combination(card.card2, handRank, visited, 0, 7, 5);

	cout << endl;
	return 0;
}

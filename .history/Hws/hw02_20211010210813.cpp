#include <iostream>
#include <sstream>

#include <cstdlib>
#include <time.h>

using namespace std;

class Card {
  private:
    // suit contains values 1-4, to represent suits below
    // 1 - Diamonds, 2 - Hearts, 3 - Clubs, 4 - Spades
    int suit;
  // value contains values 1 - 13
  // Ace - 1, 2-10, J - 11, Q - 12, K - 13
  int value;

  public:
    Card() {
      suit = 0;
      value = 0;
    }

  Card(int suit, int value) {
    this -> suit = suit;
    this -> value = value;
  }

  void set(int s, int v) {
    suit = s;
    value = v;
  }

  int getSuit() {
    return suit;
  }

  int getValue() {
    return value;
  }

  // function to return a string that describes the card
  string as_string() {
    string card_desc = "";

    if (value >= 2 && value <= 10) {
      stringstream ss;
      ss << value;
      card_desc = card_desc + ss.str() + " of ";
    } else if (value == 1) {
      card_desc = card_desc + "Ace of ";
    } else if (value == 11)
      card_desc = card_desc + "Jack of ";
    else if (value == 12)
      card_desc = card_desc + "Queen of ";
    else
      card_desc = card_desc + "King of ";

    if (suit == 1)
      card_desc = card_desc + "Diamonds";
    else if (suit == 2)
      card_desc = card_desc + "Hearts";
    else if (suit == 3)
      card_desc = card_desc + "Clubs";
    else
      card_desc = card_desc + "Spades";

    return card_desc;
  }

  bool operator <= (Card card) {

    if (card.value == value)
      return true;
    else {
      if (card.value == 1)
        return true;
      if (value == 1)
        return false;
      if (value <= card.value)
        return true;

      return false;
    }
  }

  friend ostream & operator << (ostream & os,
    const Card & card);

};

ostream & operator << (ostream & os, Card & card) {
  os << card.as_string();
  return os;
}

class Deck {
  private:
    Card cards[52];
  // the inplay array holds a true/false value to indicate
  // if the card in the same position is currently in play
  // a card is "in play" if it has been drawn out of the deck
  bool inplay[52];

  public:
    // constructor will set suit and value for each of the
    // cards in the array
    Deck() {
      int count = 0;
      for (int i = 1; i <= 4; i++) {

        for (int j = 1; j <= 13; j++) {
          cards[count].set(i, j);
          count++;
        }
      }
    }

  void unplay() {
    for (int i = 0; i < 52; i++)
      inplay[i] = false;
  }

  // randomize/shuffle the deck of cards so that the
  // cards in the array are in a random order
  void shuffle() {
    for (int i = 0; i < 52; i++) {
      Card temp = cards[i];
      int random = rand() % 52;
      cards[i] = cards[random];
      cards[random] = temp;
    }

    unplay();
  }

  Card draw() {
    Card drawn;

    bool flag = false;
    int random;
    while (!flag) {
      random = rand() % 52;
      if (!inplay[random]) {
        drawn = cards[random];
        inplay[random] = true;
        flag = true;
      }
    }
    return drawn;
  }
};

class Game {
  private:
    Deck deck;
  public:
    // constructor will shuffle the deck
    Game() {
      deck.shuffle();
    }

  bool is_flush(Card hand[]) {
    bool flag = true;
    for (int i = 0; i < 4; i++) {
      if (hand[i].getSuit() != hand[i + 1].getSuit()) {
        flag = false;
        break;
      }
    }

    return flag;
  }

  void deal(Card hand[]) {
    for (int i = 0; i < 5; i++)
      hand[i] = deck.draw();
  }

};

int main() {
  srand(time(NULL)); // initialize the random generator
  Game poker;
  Card hand[5];

  poker.deal(hand);

  for (int i = 0; i < 5; i++) {
    cout << hand[i] << endl;
  }

  if (poker.is_flush(hand))
    cout << "Your hand is a flush" << endl;
  else
    cout << "No flush" << endl;

  Deck deck1;
  deck1.shuffle();
  Card card1, card2;

  card1 = deck1.draw();
  card2 = deck1.draw();

  if (card1 <= card2)
    cout << card2 << " beats or matches " << card1 << endl;
  else
    cout << card1 << " beats " << card2 << endl;

  return 0;

}
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string card_name(int card_number) {
    string number = "", kind="";
    int def_num = card_number / 4;
    int def_kind = card_number % 4;
    switch (def_kind) {
    case 0 :
        kind = " of Spades";
        break;
    case 1 :
        kind = " of Clubs";
        break;
    case 2 :
        kind = " of Diamonds";
        break;
    case 3 :
        kind = " of Hearts";
        break;
    }
    switch (def_num) {
    case 9 :
        number = "Jack";
        break;
    case 10 :
        number = "Queen";
        break;
    case 11 :
        number = "King";
        break;
    case 12 :
        number = "Ace";
        break;
    case 8 :
        number = "10";
        break;
    default:
        char c = def_num + 2 + '0';
        number += c;
        break;
    }
    return (number + kind);
}

bool card_priority(int card_1, int card_2) {
    return (card_1 > card_2);
}

void shuffle_deck(vector <int> &deck) {
    random_shuffle(deck.begin(),deck.end());
    return;
}

void deal(vector<int> deck, vector<int>& player, int card_number) {
    player.push_back(deck[card_number]);
    return;
}

void show_player_cards(vector<int> player) {
    for (int i=0; i<13; i++) cout << card_name(player[i]) << ' ';
    return;
}

int main()
{
    vector<int> deck;
    for (int i = 0; i < 52; i++) {
        deck.push_back(i);
    }
    shuffle_deck(deck);
    vector<int> player_1,player_2,player_3,player_4;
    for (int i=0; i<52; i++) {
        switch(i % 4) {
        case 0:
            deal(deck,player_1,i);
            break;
        case 1:
            deal(deck,player_2,i);
            break;
        case 2:
            deal(deck,player_3,i);
            break;
        case 3:
            deal(deck,player_4,i);
            break;
        }
    }
    cout << "Player 1 hand: ";
    show_player_cards(player_1);
    cout << endl;
    cout << "Player 2 hand: ";
    show_player_cards(player_2);
    cout << endl;
    cout << "Player 3 hand: ";
    show_player_cards(player_3);
    cout << endl;
    cout << "Player 4 hand: ";
    show_player_cards(player_4);
    cout << endl;
    return 0;
}

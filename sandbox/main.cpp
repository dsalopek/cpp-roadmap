#include <array>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "Random.h"

struct Card {
    enum Rank {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        max_rank,
    };

    enum Suit {
        clubs,
        diamonds,
        hearts,
        spades,
        max_suit,
    };

    static constexpr std::array<Rank, max_rank> allRanks{
        ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen,
        king
    };
    static constexpr std::array<Suit, max_suit> allSuits{
        clubs, diamonds, hearts, spades
    };

    friend char getRank(const Card &card) {
        constexpr std::array<char, max_rank> rankChars{
            'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
        };
        return rankChars[card.rank];
    }

    friend char getSuit(const Card &card) {
        constexpr std::array<char, max_suit> suitChars{'C', 'D', 'H', 'S'};
        return suitChars[card.suit];
    }

    friend std::ostream &operator<<(std::ostream &out, const Card &card) {
        return out << getRank(card) << getSuit(card);
    }

    friend int value(const Card &card) {
        static constexpr std::array<int, max_rank> rankValues{
            11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
        };
        return rankValues[card.rank];
    }

    Rank rank{};
    Suit suit{};
};

class Deck {
    static constexpr int deckSize = 52;

public:
    Deck() : m_cards{initializeDeck()}, m_cardIndex{0} {
    }

    const Card &dealCard() {
        assert(m_cardIndex < deckSize && "Deck::dealCard: out of cards");
        const Card &c = m_cards[m_cardIndex];
        m_cardIndex += 1;
        return c;
    }

    void shuffle() {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_cardIndex = 0;
    }

private:
    std::array<Card, 52> m_cards{};
    std::size_t          m_cardIndex{};

    std::array<Card, deckSize> initializeDeck() {
        std::array<Card, deckSize> deck{};
        std::size_t                index = 0;
        for (const auto suit: Card::allSuits)
            for (const auto rank: Card::allRanks)
                deck[index++] = Card{rank, suit};

        return deck;
    }
};

int main() {
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.
            dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.
            dealCard() << '\n';

    return 0;
}


import random
import time

#Defining constants
suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10,
         'Queen':10, 'King':10, 'Ace':11}

playing = True

#Defining classes
class Card:
    
    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
    
    def __str__(self):
        return f"{self.rank} of {self.suit}"

class Deck:
    
    def __init__(self):
        self.deck = []  # start with an empty list
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))
    
    def __str__(self):
        return str([str(i) for i in self.deck])
                                 
    def shuffle(self):
        random.shuffle(self.deck)
        
    def deal(self):
        return self.deck.pop()
    
class Hand:
    def __init__(self):
        self.cards = []  # start with an empty list as we did in the Deck class
        self.value = 0   # start with zero value
        self.aces = 0    # add an attribute to keep track of aces
    
    def add_card(self,card):
        self.cards.append(card)
        if card.rank == 'Ace' and self.value > 10:
            self.value += 1 
            self.aces += 1
        elif card.rank == 'Ace' and self.value <= 10:
            self.value += 11
            self.aces += 1
        else:
            self.value += values[card.rank]
        
    def adjust_for_ace(self):
        if self.aces == 1 and self.value > 21:
            self.value -= 10

class Chips:
    def __init__(self):
        self.total = 100  # This can be set to a default value or supplied by a user input
        self.bet = 0
        
    def win_bet(self):
        self.total += 1.5*self.bet
    
    def lose_bet(self):
        self.total -= self.bet
 
#Defining functions      
def take_bet(chips):
    while True:
        try:
            bet = int(input("How much would you like to wager? "))
            if bet > 0 and bet <= chips.total:
                chips.bet = bet
                break
            else:
                print("Wager exceeds chips balance!")
                continue
        except:
            print("Enter a positive integer as your wager")

def hit(deck,hand):
    hand.add_card(deck.deal())
    hand.adjust_for_ace()
    
def hit_or_stand(deck,hand):
    global playing  # to control an upcoming while loop
    while True:
        choice = input('Would you like to hit or stand?: ')

        if choice.lower() == 'hit':
            hit(deck,hand)
            break

        elif choice.lower() == 'stand':
            playing = False
            break
        
        else:
            print("Enter 'hit' or 'stand'")
            continue        

def show_some(player_h,dealer_h):
    print("\n\nPLAYER'S CARDS:")
    
    for i in player_h.cards:
        print(str(i))
        
    print(f"Player's hand value is :{player_h.value}")
    
    print("DEALER'S CARD:")
    print(str(dealer_h.cards[0]) + '\n\n')
    
def show_all(player,dealer):
    print("\n\nPLAYER'S CARDS:")
    
    for i in player_h.cards:
        print(str(i))
        
    print(f"Player's hand value is :{player_h.value}")
    
    print("DEALER'S CARDS:")
    
    for i in dealer_h.cards:
        print(str(i))
    print('\n\n')

def player_busts(player_h,player_c):
    if player_h.value>21:
        print('Player busts!')
        player_c.lose_bet()
        return True
        
def player_wins(player_h,dealer_h,player_c):
    if player_h.value <=21 and dealer_h.value <=21 and player_h.value > dealer_h.value:
        print('Player wins!')
        player_c.win_bet()
        return True

def dealer_busts(dealer_h,player_c):
    if dealer_h.value>21:
        print('Dealer busts!')
        player_c.win_bet()
        return True
        
def dealer_wins(player_h,dealer_h,player_c):
    if player_h.value <=21 and dealer_h.value <=21 and player_h.value < dealer_h.value:
        print('Dealer wins!')
        player_c.lose_bet() 
        return True
    
def push(player_h,dealer_h):
    if player_h.value <=21 and dealer_h.value <=21 and player_h.value == dealer_h.value:
        print('Game ends in a push!')
        return True
    
def replay():
    while True:
        s = input('Would you like to play again?: ')
        if  s.lower() == 'yes':
            playing = True
            return True
            break
        elif s.lower() == 'no':
            playing = False
            return False
            break
        else:
            print('Enter yes or no')
            continue

#Opening statement
print('Welcome to Blackjack!You will play against a computer dealer.You have 100 chips.')

# Setting up the Player's chips
player_c = Chips()

while True:
    # Create & shuffle the deck, deal two cards to each player
    deck = Deck()
    deck.shuffle()
    player_h = Hand()
    dealer_h = Hand()
    player_h.add_card(deck.deal())
    player_h.add_card(deck.deal())
    dealer_h.add_card(deck.deal())
    dealer_h.add_card(deck.deal()) 
    
    #The game
    while True:
        take_bet(player_c)

            # Show cards (but keep one dealer card hidden)
        show_some(player_h,dealer_h)

        #While the player is playing
        while playing:  # recall this variable from our hit_or_stand function

                # Prompt for Player to Hit or Stand
            hit_or_stand(deck,player_h)
            # Show cards (but keep one dealer card hidden)
            show_some(player_h,dealer_h)
            print ('\n'*2)

            a = player_busts(player_h,player_c)
                    # If player's hand exceeds 21, run player_busts() and break out of loop
            if a:
                break
            # If Player hasn't busted, play Dealer's hand until Dealer reaches 17
        if a:
             break

        while dealer_h.value <= 17:
            hit(deck,dealer_h)
            show_all(player_h,dealer_h)
            time.sleep(2)

                # Show all cards
        show_all(player_h,dealer_h)
        print ('\n'*2)
                # Run different winning scenarios
        if player_wins(player_h,dealer_h,player_c) or dealer_wins(player_h,dealer_h,player_c) or dealer_busts(dealer_h,player_c) or push(player_h,dealer_h):
            break
            # Inform Player of their chips total 

    print(f'Your chips total is {player_c.total}')
        # Ask to play again
    if not replay():
        break

#Closing statement
print("Bye! Have a nice day.")

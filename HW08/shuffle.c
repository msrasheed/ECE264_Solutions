// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks

	// starting from i = 0 -> size-1 copying into upper deck and lower decks
		// For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		// Update the size of the upper and lower decks after copying each element.
			// For example: upper_deck[i].size = i+1;
	int i; 
	for (i = 0; i < orig_deck.size - 1; i++)
	{
		strncpy(upper_deck[i].cards, orig_deck.cards, i+1);
		upper_deck[i].size = i+1;

		strncpy(lower_deck[i].cards, orig_deck.cards+i+1, orig_deck.size-i-1);
		lower_deck[i].size = orig_deck.size-i-1;
	}

		// Similarly perform the string copy, and size update operation on the lower deck.
			//For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
		    // For example: lower_deck[i].size = orig_deck.size -i - 1;
}
#endif

#ifdef TEST_INTER
void interleaveHelper(CardDeck upper_deck, CardDeck lower_deck, CardDeck new_deck, int upperIndex, int lowerIndex, int index)
{
	if (index == new_deck.size)
	{
		print_deck(new_deck);
		return;
	}

	if (upperIndex < upper_deck.size)
	{
		new_deck.cards[index] = upper_deck.cards[upperIndex];
		interleaveHelper(upper_deck, lower_deck, new_deck, upperIndex + 1, lowerIndex, index + 1);
	}
	if (lowerIndex < lower_deck.size)
	{
		new_deck.cards[index] = lower_deck.cards[lowerIndex];
		interleaveHelper(upper_deck, lower_deck, new_deck, upperIndex, lowerIndex + 1, index + 1);
	}

}
void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
    // Follow instructions in the README, to understand the working of the recursive function.
    // Use print_deck(…) to print each resulting order.
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
	CardDeck new_deck;
	new_deck.size = upper_deck.size + lower_deck.size;
	interleaveHelper(upper_deck, lower_deck, new_deck, 0, 0, 0);
}
#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
{
    // declare a variable to hold the number of pairs
        // we can say that we have only size-1 possibility of pairs
	int pairs = orig_deck.size - 1;

    // if number of pairs == 0; return;
    if (pairs == 0) {return;}

	// instantiate pointers to hold both upper and lower decks (after division)
	   // For example: CardDeck * upper_deck = NULL;
    CardDeck * upper_deck = NULL;
    CardDeck * lower_deck = NULL; 

	// allocate memory based on number of pairs
	   //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
    upper_deck = malloc(pairs * sizeof(CardDeck));
    lower_deck = malloc(pairs * sizeof(CardDeck));

	// call divideDeck to fill upper_deck and lower_deck
	divide(orig_deck, upper_deck, lower_deck);

	//run a loop through all the pairs
		// for each pair of upper and lower deck call interleave()
		// For example: interleave(upper_deck[i],lower_deck[i]);
	int i;
	for (i = 0; i < pairs; i++)
	{
		interleave(upper_deck[i], lower_deck[i]);
	}

    // free memory allocated to upper and lower deck.
    free(upper_deck);
    free(lower_deck);
}
#endif

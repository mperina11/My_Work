import java.util.InputMismatchException;
import  java.util.Scanner;
public class DeckOfCardsTest {
    private static int wager;
    public int RunDeckOfCardsTest() {

        char choice = 'y';                           // initialize choice
        while (choice == 'y' || choice == 'Y' ) {    // loop game unless user loses all funds or quits
            //-------------------------------------------------------------------------------------------------------------
            Scanner input = new Scanner(System.in);
            boolean continueloop = true;

            do {
                try {
                    System.out.print("Enter a wager to place\nwager:"); // get wager from user
                    wager = input.nextInt();
                    while (wager <= 0 || wager > BankBalance.getBalance()) {  // input validation
                        System.out.printf("Wager must be between 0-%d, please enter a new wager: ", BankBalance.getBalance());
                        wager = input.nextInt();
                    }
                    continueloop = false;
                }
                catch (InputMismatchException inputMismatchException){
                    System.err.printf("\nException: %s\n", inputMismatchException);
                    input.nextLine();
                    System.out.printf("You must enter an int. Please try again.\n");

                }

            } while (continueloop);
            //-------------------------------------------------------------------------------------------------------------
            DeckOfCards myDeckOfCards = new DeckOfCards();
            myDeckOfCards.shuffle(); // place Cards in random order
            Card[] hand = new Card[5]; // store five cards
            // get first five cards
            for (int i = 0; i < 5; i++) {
                hand[i] = myDeckOfCards.dealCard(); // get next card
                System.out.println(hand[i]);
            }
            // display result
            System.out.println("\nHand contains:");


            //------------------------------------------------------------------------
            // These methods work
            int a = myDeckOfCards.pairs(hand);          // a pair
            int b = myDeckOfCards.twoPairs(hand);                         // two pairs
            int c = myDeckOfCards.threeOfAKind(hand);   // three of a kind
            if (a > 0 || b > 0 || c > 0){
                System.out.println("\nYou win!");
                BankBalance.editBalance(wager);
            }
            else {
                System.out.println("Nothing, you lose!");
                BankBalance.editBalance(-wager);
            }
            //------------------------------------------------------------------------

            myDeckOfCards.fourOfAKind(hand); // four of a kind --- might work haven't seen it

            myDeckOfCards.flush(hand); // a flush
            myDeckOfCards.straight(); // a straight
            myDeckOfCards.fullHouse(); // a full house
            System.out.printf("\nBank balance is $%d", BankBalance.getBalance()); // output bank balance

            if (BankBalance.getBalance() == 0) { // if user loses all money in bank
                System.out.print("\nSorry. You busted!");
                System.out.print("\nThank you for using the Casino application");
                System.out.printf("\nTime of calculation is " + java.time.LocalDateTime.now().toString());
                System.exit(0);
            }
            System.out.print("\nWould you like to play again (Y/N):  "); // prompt user if they want to play again
            choice = input.next().charAt(0);
        }

        return BankBalance.getBalance();
    }
}





/*
 * Programmer Name: Martin Perina
 * Assignment Start:        12/6/2019
 * Assignment completion:   12/6/2019
 * Total Hours for Assignment: 4
 * Comments: I enjoyed this final program. I found it to be challenging and a
 *           good encapsulation of what was learned in this course.
 */


import java.util.Scanner;
import java.util.InputMismatchException;
public class CasinoTest {

    private static int choice;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean continueloop = true;
        System.out.println("---Welcome to the Casino Application---");
        while (true) {

            do {
                try {
                    System.out.printf("Bank balance is $%d\n", BankBalance.getBalance());
                    System.out.print("1: Craps\n2: Poker\n0: Exit\nPlease enter a 0, 1, or 2\nChoice: ");
                    choice = input.nextInt();
                    continueloop = false;
                }
                catch(InputMismatchException inputMismatchException){
                    System.err.printf("\nException: %s\n", inputMismatchException);
                    input.nextLine();
                    System.out.printf("You must enter an int. Please try again.\n");
                }

            } while (continueloop);


            switch (choice) {
              //Exit
                case 0:
                    System.out.println("Case 0 chosen\nApplication closing");
                    System.out.println("Thank you for using the Casino Application");
                    System.out.printf("\nYou finished with a Bank balance of $%d\n", BankBalance.getBalance());
                    System.out.printf("\nTime of calculation is " + java.time.LocalDateTime.now().toString());
                    System.exit(0);
                    break;
                    //--------------------------------------------------------------------------------------------------

              //Craps
                case 1:
                    System.out.println("\nStarting Craps...");
                    //call to craps
                    Craps craps = new Craps();
                    int x = craps.RunCraps();
                    System.out.println("\nExiting Craps...");
                    System.out.printf("Bank balance %d\n", x);
                    break;
                    //--------------------------------------------------------------------------------------------------

              //Poker
                case 2:
                    System.out.println("\nStarting Poker...");
                    //call to poker
                    DeckOfCardsTest deckofcardstest = new DeckOfCardsTest();
                    int y =deckofcardstest.RunDeckOfCardsTest();
                    System.out.println("\nExiting Poker...");
                    System.out.printf("Bank balance %d\n", y);
                    break;
                //--------------------------------------------------------------------------------------------------

               //Catch bad input
                default:                                    // need to throw exception for char/string
                    System.out.println("\nInvalid input.");
                    break;


            }
            System.out.println("\nWould you like to keep playing?");
        }

    } //end of main
} // end of class




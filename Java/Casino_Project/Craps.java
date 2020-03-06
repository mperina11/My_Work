
import java.security.SecureRandom;
import java.util.InputMismatchException;
import  java.util.Scanner;
public class Craps {

    // create secure random number generator for use in method rollDice
    private static final SecureRandom randomNumbers = new SecureRandom();

    // enum type with constants that represent the game status
    private enum Status {CONTINUE, WON, LOST};

    // constants that represent common rolls of the dice
    private static final int SNAKE_EYES = 2;
    private static final int TREY = 3;
    private static final int SEVEN = 7;
    private static final int YO_LEVEN = 11;
    private static final int BOX_CARS = 12;
    private static int wager;
    // plays one game of craps
    public int RunCraps(){


        char choice = 'y';                           // initialize choice
        while (choice == 'y' || choice == 'Y' ) {    // loop game unless user loses all funds or quits

            int myPoint = 0; // point if no win or loss on first roll
            Status gameStatus; // can contain CONTINUE, WON or LOST

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



            int sumOfDice = rollDice(); // first roll of the dice

            // determine game status and point based on first roll
            switch (sumOfDice) {
                case SEVEN: // win with 7 on first roll
                case YO_LEVEN: // win with 11 on first roll
                    gameStatus = Status.WON;
                    break;
                case SNAKE_EYES: // lose with 2 on first roll
                case TREY: // lose with 3 on first roll
                case BOX_CARS: // lose with 12 on first roll
                    gameStatus = Status.LOST;
                    break;
                default: // did not win or lose, so remember point
                    gameStatus = Status.CONTINUE; // game is not over
                    myPoint = sumOfDice; // remember the point
                    System.out.printf("Point is %d%n", myPoint);
                    break;
            }


            // while game is not complete
            while (gameStatus == Status.CONTINUE) { // not WON or LOST
                sumOfDice = rollDice(); // roll dice again
                String output = Chatter();    // output some chatter
                System.out.print(output);
                // determine game status
                if (sumOfDice == myPoint) { // win by making point
                    gameStatus = Status.WON;
                } else {
                    if (sumOfDice == SEVEN) { // lose by rolling 7 before point
                        gameStatus = Status.LOST;
                    }
                }
            }

            // display won or lost message
            if (gameStatus == Status.WON) {
                System.out.println("Player wins");
                BankBalance.editBalance(wager); //+= wager; // add wager to bank balance
            } else {
                System.out.println("Player loses");
                BankBalance.editBalance(-wager);
                //bankbalance -= wager; // subtract wager to bank balance
            }


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

    //------------------------------------------------------------------------ method for dice roll
    // roll dice, calculate sum and display results
    public static int rollDice() {
        // pick random die values
        int die1 = 1 + randomNumbers.nextInt(6); // first die roll
        int die2 = 1 + randomNumbers.nextInt(6); // second die roll

        int sum = die1 + die2; // sum of die values

        // display results of this roll
        System.out.printf("Player rolled %d + %d = %d%n", die1, die2, sum);

        return sum;
    }
    //-------------------------------------------------------------------------- method for chatter
    public static String Chatter(){
        String zero = "\nOh, you're going for broke, huh?\n";
        String one = "\nAw c'com, take a chance!\n";
        String two = "\nYour're up big. Now's time to cash in your chips!\n";
        String three = "\nYou must be feeling lucky!\n";
        String four = "\nYou're going to lose!\n";
        String five = "\nKeep going!\n";

        int index = randomNumbers.nextInt(4);
        int[] n = {0,1,2,3,4};
        String[] m = { zero, one, two, three, four};

        return m[n[index]];
    }
    //--------------------------------------------------------------------------
}






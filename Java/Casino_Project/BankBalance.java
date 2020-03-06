public class BankBalance {

    private static int balance = 1000;

    public BankBalance(int balance){ // assign balance to BankBalance
        if (balance > 0){
            this.balance = balance;
        }
    }

    public static void editBalance(int amount){ // add/sub from BankBalance from wager
        balance += amount;

    }

    public static int getBalance() { // get the balance from BankBalance
        return balance;
    }
}

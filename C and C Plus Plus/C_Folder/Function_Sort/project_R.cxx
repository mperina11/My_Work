
/*
 *            PROGRAMMER: Martin Perina 
 *         PROBLEM TITLE: Project 
 *    PROBLEM DEFINITION: Menu driven program to create, read, write, sort, and search 2d arrays 
 *                  DATE: 7/25/2019
 *     SYSTEM - HARDWARE: 16GB
 *            - SOFTWARE: NetBeans 9.0 and Geany 
 *         Input Devices: Keyboard
 *        Output Devices: Terminal 
 */
 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 
#include <stdlib.h>
#include <ctime>

using namespace std; 

// function prototypes---------------------------------------------------------
// the 6 required functions (0-5)  
int displayMenu();    // 0
string writeOut();    // 1
string writeRandom(); // 2
string readIn();      // 3
string sortColumn();  // 4
string searchColumn();// 5 

// functions for input validation, random generator, and output 
int is12();                                        // if int check and is 1 or 2 
int intTest();                                     // if int check
int dualCheck();                                   // if int and >0
long double unif(); 							   // random # between 0-1
void output_matrix(const long double m[], int rw, int cl); // output array to terminal 

// Main -----------------------------------------------------------------------
int main()
{
	// non-constants ----------------------------------------------------------
	char choice; 
	string call; 
	
		cout << "Welcome, this program can create, read, write, sort, ";
        cout << "and search two dimensional arrays." << endl; 
         
        do{ 	
	switch (displayMenu()) 							// calls function 0 
	{
	case 1: cout << "\nOption 1 selected." << endl; // calls function 1
				call = writeOut(); 
				cout << "\n" << call;
			break;
	case 2: cout << "\nOption 2 selected." << endl; // calls function 2
				call = writeRandom(); 
                cout << "\n" << call;
			break;
	case 3: cout << "\nOption 3 selected." << endl; // calls function 3
                call = readIn(); 
                cout << "\n" << call;                        
			break;
	case 4: cout << "\nOption 4 selected." << endl; // calls function 4
                call = sortColumn();
                cout << "\n" << call;
			break;
	case 5: cout << "\nOption 5 selected." << endl; // calls function 5
                call = searchColumn();
                cout << "\n" << call;
			break;
	default: cout << "\nNumber 1-5 not selected" << endl; // check for int 1-5
	}
	
	cout << "\n\n"; 
	cout << "Run again? (Y/N): ";
	cin >> choice; 
	} while (choice == 'Y' || choice == 'y');   		// loop to run program again 
	
	return 0;
}

// definition 0---------------------------------------------------------
int displayMenu(){
	int menu_choice; 
	
	cout << "\n\n"; 	
	cout << "Options" << endl; 
	cout << "1. Create your own array and write to file" << endl;
	cout << "2. Create a random size aray with random data (0-1) and write to file" << endl;
	cout << "3. Read in file and display contents to terminal" << endl;
	cout << "4. Read in file, Sort by a column, and write to file" << endl;
	cout << "5. Read in file, search for a value in a column, output position of value" << endl;  
	cout << "Choose an option (1-5): ";
	menu_choice = intTest(); 
	
return menu_choice; 	
}

// definition 1---------------------------------------------------------
 string writeOut(){
	string filename, check; 
	int row_num = 0;
	int col_num = 0; 
		
	cout << "Enter filename to write to: ";
		cin.ignore();
		getline(cin,filename,'\n'); 
        
	cout << "Enter the desired number of rows: ";
		row_num = dualCheck(); 
	cout << "Enter the desired number of columns: ";
		col_num = dualCheck(); 
	
	long double array_created [row_num] [col_num]; 
	for (int row = 0; row < row_num ; row++)
	{
		for (int col = 0; col < col_num; col++) 
		{
			cout << "Row " << (row + 1);
			cout << ", Column " << (col + 1) << ": ";
			cin >> array_created [row] [col]; 
		} 
		cout << endl; 
	}
	
	
	 ofstream output_file;	// output to file 
     output_file.open(filename.c_str());
    
        if (output_file)
        {
			 output_file << "UNSORTED" << endl;   
			 output_file << row_num << " " << col_num << " " << endl; 
			         
            
            for (int row = 0; row < row_num ; row++)
				{
				for (int col = 0; col < col_num; col++) 
				{
				output_file << setw(15) << fixed << setprecision(10);  
				output_file << array_created [row] [col]; 
				output_file << " "; 
				} output_file << endl; 
				}
        }
        else
        {
            cout << "ERROR: Could not open " << filename << endl;
            string check_f = "FAILED"; 
            return check_f;
        }
	        
	check = "Finished" ; 
	return check;
}

// definition 2---------------------------------------------------------
string writeRandom(){
	
	string filename, check; 
	cout << "Enter filename to write to: ";
		cin.ignore();
        getline(cin,filename,'\n');
       	
	srand(time(0)); 
	int row_num = 2 + rand()%9;
	int col_num = 2 + rand()%9; 
	
	 ofstream output_file;	// output to file 
     output_file.open(filename.c_str());
    
        if (output_file)
        {
			 output_file << "UNSORTED" << endl;   
			 output_file << row_num << " " << col_num << " " << endl; 			                     
				for (int row = 0; row < row_num ; row++)
			{ 
				for (int col = 0; col < col_num; col++) 
				{                
					output_file << setw(15) << fixed << setprecision(10) << unif(); 
					output_file << " "; 
				} 	output_file << endl;
			}            
        }
        else
        {
            cout << "ERROR: Could not open " << filename << endl;
            string check_f = "FAILED"; 
            return check_f; 
		}
	    
	check = "Finished" ; 
	return check;
}

// definition 3---------------------------------------------------------
string readIn()
{
    string filename_input, check, type; 
    cout << "Enter filename to read in: ";
    cin.ignore();
        getline(cin,filename_input,'\n');
    
    
	int rows, cols;		// open file
    int col_sorted;
    string sort_order;
    ifstream input_file;
    input_file.open(filename_input.c_str());
    
     if (input_file)
	 {
		 
	   input_file >> type; 
	  
           if (type == "UNSORTED")
           {
                input_file >> rows;
                input_file >> cols; 
           }
           
           if (type == "SORTED")
           {
               input_file >> rows;
               input_file >> cols;
               input_file >> col_sorted;
               input_file >> sort_order;
           }
          
       
       long double m[rows][cols]; 
       for(int r=0;r<rows; r++)
           for(int c=0;c<cols;c++)
               input_file >> m[r][c];
       
       input_file.close();
       cout << "\n"; 
       cout << " " << type << endl; 
       if (type == "SORTED"){
           cout << "was sorted by column: "; 
           cout << col_sorted << ", " << sort_order << endl; 
       }
       
       output_matrix((long double *)m,rows,cols); // output array to terminal 
    }
   else
   {
       cout << "ERROR: Could not open the file " << filename_input << endl;
       string check_f = "FAILED"; 
       return check_f;
    }
    
    check = "Finished";
    return check; 
}

// definition 4---------------------------------------------------------
string sortColumn()
{
	string filename_input, filename_output, check, type; 
    cout << "Enter filename to read in: ";
        cin.ignore();        
        getline(cin,filename_input,'\n');
    
        cout << "Enter filename to write to: "  ; 
        getline(cin,filename_output,'\n');
    
    ifstream input_file;		// open file
    input_file.open(filename_input.c_str());
    
     if (input_file)
	 {
		 long double x;
       int rows, cols;
	   input_file >> type; 
	   input_file >> rows;
       input_file >> cols; 
       
       long double m[rows][cols]; 
       for(int r=0;r<rows; r++)
           for(int c=0;c<cols;c++)
               input_file >> m[r][c];
       
       input_file.close();
       
        int col_sort, sort_option; 
        
    cout << "\nWith the first column being number 1. " << endl;
    cout << "There are " << cols << " columns in this array." << endl;
	cout << "Which column would you like to sort by? ";
    col_sort = dualCheck(); 
    col_sort -= 1; 
    cout << "\n"; 
    cout << "How would you like to sort the column?" << endl;
    cout << "For smallest to largest enter 1" << endl; 
    cout << "For largest to smallest enter 2" << endl; 
    cout << "Choose one: "; 
    sort_option = is12(); 
    string flag_sort; 
    
    if (sort_option == 1) // sorting smallest to largest 
    {
    bool swapped = true; 
    while (swapped) { 
		swapped = false;  
		for (int i = 0; i < rows -1; i++)
       {
		   if (m[i][col_sort] > m[i+1][col_sort]) 
		   {
			   swapped = true; 
			   for (int j = 0; j < cols; j++)
			   {
				   x = m[i][j];
				   m[i][j] = m[i+1][j];
				   m[i+1][j] = x;
			   }			   
		   } 
	   }    
      
	} flag_sort = "smallest_to_largest";
    }
      
    
    
    if (sort_option == 2) // sorting largest to smallest 
    {
	bool swapped = true; 
    while (swapped) {    
		swapped = false;
		for (int i = 0; i < rows - 1; i++)
       {
		   if (m[i][sort_option] < m[i+1][sort_option]) 
		   {
			   swapped = true; 
			   for (int j = 0; j < cols; j++)
			   {
				   x = m[i][j];
				   m[i][j] = m[i+1][j];
				   m[i+1][j] = x;
			   }			   
		   } 
		   		  
	   }    
      
	}  flag_sort = "largest_to_smallest";     
    }
    
     ofstream output_file;		  // output file 
     output_file.open(filename_output.c_str());
    
        if (output_file)
        {
			 output_file << "SORTED" << endl;   
			 output_file << rows << " " << cols << " " << endl;  
			 output_file << ++col_sort << " "; 
			 output_file << flag_sort << endl;         
            
            for (int row = 0; row < rows ; row++)
				{
				for (int col = 0; col < cols; col++) 
				{
				output_file << setw(15) << fixed << setprecision(10);
				output_file << m[row] [col]; 
				output_file << " "; 
				} output_file << endl; 
				}
         }
        else
        {
            cout << "ERROR: Could not open " << filename_output << endl;
            string check_f = "FAILED"; 
            return check_f;
        }
	
       
         }   // if input file end 
   else
   {
       cout << "ERROR: Could not open the file " << filename_input << endl;
       string check_f = "FAILED"; 
       return check_f;
    }
    
     check = "Finished";
    return check; 
}

// definition 5---------------------------------------------------------
string searchColumn()
{
        
    string filename_input, check, type; 
    cout << "Enter filename to read in: ";
        cin.ignore();
        getline(cin,filename_input,'\n');
   
     int rows, cols;		// open file
           int col_sorted;
           string sort_order;
    ifstream input_file;
    input_file.open(filename_input.c_str());
    
     if (input_file)
	 {
		            
	   input_file >> type; 
	  
           if (type == "UNSORTED")
           {
                input_file >> rows;
                input_file >> cols; 
           }
           
           if (type == "SORTED")
           {
               input_file >> rows;
               input_file >> cols;
               input_file >> col_sorted;
               input_file >> sort_order;               
           }
          
       
       long double m[rows][cols]; 
       for(int r=0;r<rows; r++)
           for(int c=0;c<cols;c++)
               input_file >> m[r][c];
       
   
    int col_search;
    long double value_look;  
    
    cout << "\nWith the first column being number 1. " << endl;
    cout << "There are " << cols << " columns in this array." << endl; 
    cout << "Which column would you like to search by? ";
    col_search = dualCheck(); 
    cout << "What value would you like to search for? "; 
    value_look = dualCheck(); 
     
    col_search--; 
    int index =0;
    int position = -1;
    bool found = false;  
    
//------FOR UNSORTED FILE----------------------------------------------------------
	if (type == "UNSORTED") // linear search
	{
          while (index < rows && !found){
                if (m[index][col_search] == value_look)
                {
                    found = true;
                    position = index; 
                } 
                index++; 
            }
            
           cout << "Position of " << value_look << " is: row " << ++position;
           cout << " column " << ++col_search << endl; 
	}
//-----FOR SORTED FILE-----------------------------------------------------------
    
    
	if (type == "SORTED") // binary search + check sort_order 
	{
            if (sort_order == "smallest_to_largest"){ // small to large 
                cout << "small to large" << endl; 
                int first = 0;
                int last = rows - 1;
                int middle;
                int position = -1;
                bool found = false; 
                
                while (!found && first <= last)
                {
                    middle = (first + last) / 2;
                    if (m[middle][col_search] == value_look)
                    {
                        found = true;
                        position = middle;
                    }
                    else if (m[middle][col_search] > value_look) 
                    last = middle - 1;
                    else 
                        first = middle + 1;                     
                }    
             cout << "Position of " << value_look << " is: row " << ++position;
             cout << " column " << ++col_search << endl;            
            }
            
            if (sort_order == "largest_to_smallest"){ // large to small 
                cout << "large to small" << endl;  
                 
                int first = 0;
                int last = rows - 1;
                int middle;
                int position = -1;
                bool found = false; 
                
                while (!found && first <= last)
                {
                    middle = (first + last) / 2;
                    if (m[middle][col_search] == value_look)
                    {
                        found = true;
                        position = middle;
                    }
                    else if (m[middle][col_search] < value_look) 
                    last = middle - 1;
                    else 
                        first = middle + 1;                     
                }    
             cout << "Position of " << value_look << " is: row " << ++position;
             cout << " column " << ++col_search << endl;
                
            }
            
            cout << "sorted file" << endl; 
	}

		
    input_file.close();
    } // if input file end 
    check = "Finished";
    return check; 
}


// definition for intCheck--------------------------------------------
int intTest()
{
	int A = 0;
	
while ( !(cin >> A) ){
	cin.clear();
	cin.ignore(10, '\n');
	cout << "Incorrect entry. Try again: "; 
}
return A;
}

// definition for dualCheck ------------------------------------  
int dualCheck()
{
int A;
	
while ( !(cin >> A) || (A <= 0) )
{
        cout << "Incorrect entry. Try again: ";
	cin.clear();
	cin.ignore(10, '\n');
}
return A;
	
}

//definition for unif---------------------------------------------------------
long double unif()
{	
	srand(time(0)); 
	int j = rand();
	return double(j) / double(RAND_MAX); 
}

//definition for output_matrix---------------------------------------------------------
void output_matrix(const long double m[], int rw, int cl)
{
	for(int r=0; r<rw; r++) // iterate through rows
   {
       for(int c=0; c<cl; c++) // iterate through the columns
       {
           cout << fixed << setprecision(10) << setw(10) << m[r*cl+c] << " ";
           //cout << "check"; 
       }
        cout << endl;

    }    
}

//definition for is12-----------------------------------------------------
int is12()
{
int A;
	
while ( !(cin >> A) || ((A != 1) && (A != 2)) )
{
        cout << "Must be 1 or 2. Try again: ";
	cin.clear();
	cin.ignore(10, '\n');
}
return A;
}




 

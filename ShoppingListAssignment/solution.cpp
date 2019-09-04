/* Mohammed Mogasbe
 Xcode on a Mac
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const string inputFileName= "shoppingList.txt"; //Constant input file name
const string outputFileName= "output.txt"; // Constant output file name
const double taxRate= 0.09; // Tax Rate Constant
void shoppingListHeader();
double costTax(double cost);
ifstream infile; //Allows Reading from Files
ofstream outfile; // Allows Writing to files
int main() // Function Main
{
    infile.open(inputFileName); // Opens Shopping List
    outfile.open(outputFileName); //Opens Output Text
    
    if(infile.fail()) // Error Check for Shopping List
    {
        cout<<"ERROR COULD NOT OPEN INPUT FILE: "<<inputFileName<<endl;
    }
    if(outfile.fail()) // Error Check for Output File
    {
        cout<<"ERROR COULD NOT OPEN OUTPUT FILE: "<<outputFileName<<endl;
    }
    
    string items; // Where the shopping Items are stored
    double cost; // Where their prices are stored
    double total=0; // Total Stored
    getline(infile,items); // Copies the line
    shoppingListHeader(); // Header Function
    while(infile>>items>>cost) // Loop that declares the items and numbers to the matching variables items and cost
    {
        
        if (items == "water"|| items == "banana") // banana and water have 0 tax
        {
            double taxAmount = 0 ; // New Variable that is made equal to the taxprice that was returned in function costTax()
            double subtotal= taxAmount + cost; // subtotals stored in here
            
            total += (taxAmount + cost) ; // total placed inside the loop so it adds all the totals together
            // Widths are 12, 10, 8 , 12
            outfile<<setw(12)<<left<<items<<flush;
            outfile<<setw(10)<<right<<setprecision(2)<<fixed<<cost<<flush;
            outfile<<setw(8)<<right<<setprecision(2)<<fixed<<taxAmount<<flush;
            outfile<<setw(12)<<right<<setprecision(2)<<fixed<<subtotal<<endl;
        }
        else // For the rest of the Items
        {
            double taxAmount =  costTax(cost); // New Variable that is made equal to the taxprice that was returned in function costTax()
            double subtotal= taxAmount + cost; // subtotals stored in here
            
            total += (taxAmount + cost) ; // total placed inside the loop so it adds all the totals together
            // Widths are 12, 10, 8 , 12
            outfile<<setw(12)<<left<<items<<flush;
            outfile<<setw(10)<<right<<setprecision(2)<<fixed<<cost<<flush;
            outfile<<setw(8)<<right<<setprecision(2)<<fixed<<taxAmount<<flush;
            outfile<<setw(12)<<right<<setprecision(2)<<fixed<<subtotal<<endl;
        }
    }
        outfile<<setw(42)<<"--------"<<endl;
        outfile<<setw(36)<<"Total:    "<<total<<endl;
    
    
    infile.close(); // Shopping List file is closed
    outfile.close(); // Output File is closed
    
    
    return 0;
}
void shoppingListHeader()
{
    // Widths are 12, 10, 8 , 12 //Header function
        outfile<<setw(12)<<left<<"Item"<<flush;
        outfile<<setw(10)<<right<<"Cost"<<flush;
        outfile<<setw(8)<<right<<"Tax"<<flush;
        outfile<<setw(12)<<right<<"Subtotal"<<endl;
        outfile<<setw(12)<<left<<"-----------"<<flush;
        outfile<<setw(10)<<right<<"------"<<flush;
        outfile<<setw(8)<<right<<"-----"<<flush;
        outfile<<setw(12)<<right<<"--------"<<endl;
    
}

double costTax(double cost)
{
    double newCost = taxRate*cost;
    return newCost; // returning
}

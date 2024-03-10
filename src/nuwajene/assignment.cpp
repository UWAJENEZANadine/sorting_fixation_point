/**
 * Author: Nadine Uwajeneza
 * 
 * Functionality: This program will produce the sorted fixation points based on the x and y coardinate. By reading the input from a file
 * and sorts the points, and display the  the list of sorted data in the output file. Furthermore, all the  sorted list are in the ascending order and if the points have the same x coardinates, the points should be listed based on 
 * y coordinate in the ascending oder. ultimately the points in with the same x and y should be listed as the first come.
 * 
 * Format of the input:
 * This program is will expect the first line in the file to be the number of the test case, followed by the fixation points with corresponding with the position index, and at the end of each test case or scanpath end by (-1, -1).
 * 
 * Format of the output
 * The out put contains the sorted fixation points based on the x and y coardinate in ascending oprder, and at the end of each test case gas the asterisk.
 * 
 * Solution strategy
 * This program sorting my input file with(X-coordinate and y-coordinate) using the quick sort algorthm. The points with the same x-coordinates are sorted by their y-coordinate in ascending order,
 * and if points have the similar x and y coordinates are sorted by their number.
 * 
 * 1. Define Structure
 * FixationPoints with number, x, y
 * 
 * 2. Define function SwapData
 * 3. Define function PartitionFile
 * 4.Define function QuicksortAlgorthm
 * 5. MainFunction:
 * 5.1. Open the input and output files
 * 5.2. Read number of test cases
 * 5.3.  For each test case:
 * 5.3.1. Initialize the array of Fixation Points 
 * 5.3.2. Read fixation points from my input file until termination condition of(-1, -1)
 * 5.3.3 call my function QuicksortAlgorthm to sort my fixation point in ascending order
 * 5.3.4. Write the Sorted fixation points to my output file and print them
 * 5.4. close the input and output file
 * 
 * Testing stategy
 * First test case:  The first test case has the normal fixation points without any similalr coardinate.
 * Second Test case: This second test case has some points of x coordinate which are the same, in the input file, and in the output file is going to be sorted by y-coardinate.
 * Third test case: This third test case contain some points which are similar in the file is going to do it based on the way they are arranged in the input file
 * The Fourth case: This fourth case in the mixes on the point with some x-coardinate which are similar and sort based on the x coardinate and also with x and y coordinate both are similar and write the output based on their index
 * The Fith test case: This case has only one fixation point
 * The sixth test case: This test case has the mostly the x-coardinate which are the same and, the out put is going to make sorting based on x
 * The seven test case: This test case has many duplicate x-coardinate number in scanpath, in the output are arranged in the order of y-coardinate
 * The eight test case: this test case has the x and y coardinate which are similar mixed with some x-coarinate which are similar and it is going to be sorted based on y-coardinate.
 * 
 * Complexity Analysis
 * Time Complexity: The time complexity of Quick sort algorthm is O(n log n) in average and best cases. in this program the Quick sort applied recursively to the arrya of fixation point , whic leading the overall of time complexity of O(nlog n)
 * space complexity: The space complexity of program is O(n), where n is the number of fixation points per test case, because of the space required to store the fixation points.
*/

#include <iostream>
#include <fstream>

//the use of the the standard namespace
using namespace std;

//structure to hold fixation 
struct FixationPoints{
    int number; 
    int x;
    int y;
};

//The function of swaping the pixation points
void swapData(FixationPoints& p1, FixationPoints& p2){
    FixationPoints temp = p1;
    p1 = p2;
    p2 = temp;
}

//the partition function for quick sort 
int partiftionFile(FixationPoints myArr[], int low, int high){

    //choose pivot and set pivot to the last element of the array
    FixationPoints pivotNum = myArr[high];

    //index of smaller elemnet
    int i = low - 1;
    //oiterate through the whole array from low to high
    for(int j=low; j < high; j++){
        if(myArr[j].x < pivotNum.x || (myArr[j].x == pivotNum.x && myArr[j].y < pivotNum.y)){
           //increment index of smll element
            i++;
           swapData(myArr[i],myArr[j]); 

        //handle the cases if x an y are the same
        }else if(myArr[j].x == pivotNum.x && myArr[j].y == pivotNum.y){
            if(myArr[j].number < pivotNum.number){
                i++;
                swapData(myArr[i],myArr[j]); 

            }

        }
    }
    //swap pivot element with elemnet at index i+1
    swapData(myArr[i + 1], myArr[high]); 
    return(i+1);//return index of pivot element

}

//Quick sort algorthm
void QuickSortAlgorthm(FixationPoints arry[], int low, int high){
    //when low is less than high
    if(low < high){
        int part = partiftionFile(arry, low, high); //pmake a partion of arrya
        QuickSortAlgorthm(arry, low, part - 1);  // before the pivot recursive sort
        QuickSortAlgorthm(arry, part+1, high);  //after the pivotrecursive sort 


    }
}


// int arr[1000][3];


int main(){

//open my input and output file
    ifstream myInputFile("../data/input.txt");
    ofstream myOutPutFile("../data/output.txt");

    myOutPutFile<<"nuwajene" << endl;

    int num_of_test_cases;
    //read the number of test case
    myInputFile >> num_of_test_cases;
   

    for(int i = 1; i <= num_of_test_cases; ++i){
        FixationPoints fix[1000] = {}; //assuming a maximum of 100 fixation points per test case
        int counter = 0; 
        while(true){
            int number, x, y ;
             myInputFile >> number >>x >>y;
              if(x  == -1 && y  == -1){
            break; //break the loop when the coardinates are -1
        } 
        if(counter <= 1000){
            fix[counter].number = number;
            fix[counter].x = x;
            fix[counter].y = y;
            counter++;
        }
        
        }
        
       //calling the quick sort function
        QuickSortAlgorthm(fix, 0, counter -1);
        for(int j = 0; j< counter; ++j){
            //display the sorted  fixation points
            myOutPutFile << fix[j].number<< " "<<fix[j].x << " " <<fix[j].y<<endl;
            cout << fix[j].number<< " "<<fix[j].x << " " <<fix[j].y<<endl;
       
        }
        myOutPutFile << "*************" <<endl;
        cout<< "*************" <<endl;
       
    }
          

    myInputFile.close();
    myOutPutFile.close();

    return 0;
}


/*
   Program Output you should get!   After
   you replace with your nMode function in
   provided class

The Sequential Array = {0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4}
Number of Modes = 5, Max Frequency = 4
The Mode Set  = {0,1,2,3,4}
The Sequential Array = {0,1,2,3,4,5,6,7,0,1}
Number of Modes = 2, Max Frequency = 2
The Mode Set  = {0,1}
The  Sequential Array = {0,1,2,3,4,5,6}
Number of Modes = 0, Max Frequency = 1
The Mode Set  = {}
The Random Array = {6,5,4,2,1,2,2}
Number of Modes = 1, Max Frequency = 3
The Mode Set  = {2}
The Random Array = {5,0,5,1,0,0,2,0,2,4,3,4,4,2}
Number of Modes = 1, Max Frequency = 4
The Mode Set  = {0}
*/

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 *
 * Created on September 14, 2010, 3:03 PM
 */

#include <stdlib.h>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "Mode.h"

int * fill_Array(int,int);
int * random_fill_Array(int,int);
void print_Array(string,int const *,int,int);

int main(int argc, char** argv) {
        //Read in or set the size of the array and it's limit values
        int array_size=20,max_value=4,per_line=20;
        srand(static_cast<unsigned int>(time(0)));
        //Create a dynamic 1 dimensional array
        int *one_Dim=fill_Array(array_size,max_value);
        //Print out and examine before solving the problem
        //with this test case
        print_Array("The Sequential Array = ",one_Dim,array_size,per_line);
        //Calculate the mode
        Mode *mode=new Mode(one_Dim,array_size);
        //Print the modes
        cout<<"The number of modes = "<<mode->get_numModes()<<", ";
        cout<<"The Frequency = "<<mode->get_Freq()<<endl;
        print_Array("The mode  = ",mode->get_Mode(),mode->get_numModes(),per_line);
        delete mode;
        //Now try a few other examples
        array_size=10;max_value=7;
        delete [] one_Dim;
        one_Dim=fill_Array(array_size,max_value);
        print_Array("The Sequential Array = ",one_Dim,array_size,per_line);
        mode=new Mode(one_Dim,array_size);
        //Print the modes
        cout<<"The number of modes = "<<mode->get_numModes()<<", ";
        cout<<"The Frequency = "<<mode->get_Freq()<<endl;
        print_Array("The mode  = ",mode->get_Mode(),mode->get_numModes(),per_line);
        delete mode;
        //Another example with no modes
        array_size=7;max_value=6;
        delete [] one_Dim;
        one_Dim=fill_Array(array_size,max_value);
        print_Array("The Sequential Array = ",one_Dim,array_size,per_line);
        mode=new Mode(one_Dim,array_size);
        //Print the modes
        cout<<"The number of modes = "<<mode->get_numModes()<<", ";
        cout<<"The Frequency = "<<mode->get_Freq()<<endl;
        print_Array("The mode  = ",mode->get_Mode(),mode->get_numModes(),per_line);
        delete mode;
        //Another example with a random fill
        array_size=7;max_value=6;
        delete [] one_Dim;
        one_Dim=random_fill_Array(array_size,max_value);
        print_Array("The Random Array = ",one_Dim,array_size,per_line);
        mode=new Mode(one_Dim,array_size);
        //Print the modes
        cout<<"The number of modes = "<<mode->get_numModes()<<", ";
        cout<<"The Frequency = "<<mode->get_Freq()<<endl;
        print_Array("The mode  = ",mode->get_Mode(),mode->get_numModes(),per_line);
        delete mode;
        array_size=14;max_value=5;
        delete [] one_Dim;
        one_Dim=random_fill_Array(array_size,max_value);
        print_Array("The Random Array = ",one_Dim,array_size,per_line);
        mode=new Mode(one_Dim,array_size);
        //Print the modes
        cout<<"The number of modes = "<<mode->get_numModes()<<", ";
        cout<<"The Frequency = "<<mode->get_Freq()<<endl;
        print_Array("The mode  = ",mode->get_Mode(),mode->get_numModes(),per_line);
        delete mode;
        //End of test
        delete [] one_Dim;
        return 1;
}
void print_Array(string eq,int const * a,int len,int pline){
        //Print as a set
        cout<<eq<<"{";
        for(int i=0;i<len-1;++i){
            cout<<a[i]<<",";
            if(i%pline==(pline-1))cout<<endl;
        }
        if(len>0)cout<<a[len-1]<<"}"<<endl;
        else cout<<"}"<<endl;
    }
    //This function creates a dynamic 1 dimensional array
    //of any size.  It is filled with numbers that repeat
    //{0,1,2,...,modit,0,1,2,...,modit,...,0,1,2,...,modit,etc...}
    //This is the only way to really test the mode function
    int * random_fill_Array(int array_size,int modit){
        int * fill=new int[array_size];
        for(int i=0;i<array_size;++i){
            fill[i]=rand()%(modit+1);
        }
        return fill;
    }
    //This function creates a dynamic 1 dimensional array
    //of any size.  It is filled with numbers that repeat
    //{0,1,2,...,modit,0,1,2,...,modit,...,0,1,2,...,modit,etc...}
    //This is the only way to really test the mode function
    int * fill_Array(int array_size,int modit){
        int *fill=new int[array_size];
        for(int i=0;i<array_size;++i){
            fill[i]=i%(modit+1);
        }
        return fill;
    }
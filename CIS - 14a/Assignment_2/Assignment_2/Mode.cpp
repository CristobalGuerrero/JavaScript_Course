/*
 * File:   Mode.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 14, 2010, 3:36 PM
 */
#include "Mode.h"

//Constructor
Mode::Mode(int *a,int s){
    //Copy the array
    this->bSize=s;
    this->b = new int[s];
        for(int i=0;i<s;++i){
            this->b[i]=a[i];
        }
    //Sort then find the mode
    this->b=this->mark_Sort(this->b,s);
    this->nMode();
}

//Utility function
int * Mode::mark_Sort(int *a,int len){
        for(int i=0;i<len-1;++i){
            for(int j=i+1;j<len;++j){
                if(a[i]>a[j]){
                    a[i]=a[i]^a[j];
                    a[j]=a[i]^a[j];
                    a[i]=a[i]^a[j];
                }
            }
        }
        return a;
}

//One way to do the mode
void Mode::nMode(){
        //First find the max_frequency
        int count=1;max_Freq=1;
        //cout<<"Max Frequency = "<<max_Freq<<endl;
        //Now to find the number of modes
        num_Modes=0;
        //cout<<"Number of Modes = "<<num_Modes<<endl;
        //Now to fill the array with modes
        m = new int[num_Modes];
}
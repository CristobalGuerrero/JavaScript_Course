/* 
 * File:   Mode.h
 * Author: Dr. Mark E. Lehr
 * Created on September 14, 2010, 3:36 PM
 */

#ifndef _MODE_H
#define	_MODE_H

class Mode {
private:
    int *b;//Sorted Array
    int bSize;//Size of Sorted Array;
    int max_Freq;//Frequency of the mode set,
    int num_Modes;//Number of Modes, size of Mode Array
    int *m;//Mode Array
    int *mark_Sort(int *,int);//Utility function for the class

public:
    Mode(int *,int);//Constructor inputing the initial
    ~Mode(){//Constructor inputing the initial
        delete []b;
        delete []m;
    }
    void nMode();//Main worker function
    int const * get_Sort()const{
        return b;
    }
    int const * get_Mode()const{
        return m;
    }
    int get_Freq()const{
        return max_Freq;
    }
    int get_numModes()const{
        return num_Modes;
    }
};

#endif	/* _MODE_H */


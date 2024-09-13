/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My solutions to problems from an interview at Zimmer Biomet (Montreal) using Codeshare.
//              Unfortunately, Codeshare is not not an online compiler. It had to be validated using another website with an
//              online compiler.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Question 1
// Compute the average value of array "data".

double ComputeAverage(double * data, unsigned int nbValues)
{
    double avg = 0;
    if (data != nullptr && nbValues != 0)
    {
        for (int i = 0; i < nbValues; i++)
        {
            avg += data[i];
        }
        avg = avg / nbValues;
    }
    return avg;
}

// Question 2
// Write a function that inverts the given string. You are allowed to use the function strlen() to find the length of the string.

void InvertString(char * myString)
{
    if (myString != nullptr)
    {
        string str(myString);
        int i = 0;
        for (auto ite = str.rbegin(); ite != str.rend(); ++ite)
        {
            myString[i] = *ite;
            i++;
        }
    }
}


// Question 3
// There are two problems in this code, and a few things that are correct but could be improved. Can you find them?

class Example
{
public:
    Example( int y = 10 ) { mData = y; }
    int getIncrementalData() const { return ++mData; }
    static int getCount() const
    {
        cout << "Data is " << mData << endl;
        return count;
    }

private:
    int mData;
    static int count;
};


//getIncrementalData() is const so it cannot change the content of mData (increment in this case)
//getCount() is static and cannot access the data


// I would remove the cout from getCount
// I would add a default constructor that would set the mData to 10
//      Example() : mData(10) { }
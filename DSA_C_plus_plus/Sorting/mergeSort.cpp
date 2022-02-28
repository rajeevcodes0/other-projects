#include<iostream>
using namespace std;

void mergeSort(long [],long,long);
void mergeFunction(long [], long, long);
void printArray(long [],long);

int main()
{
    long input[]={5,4,3,6,7,1,4,5,3,2,8,9,11};
    cout<<"Before mergeSort"<<endl;
    printArray(input,13);
    mergeSort(input,0,12);
    cout<<"After mergeSort"<<endl;
    printArray(input,13);
    return 0;
}

void mergeSort(long input[], long startI, long endI)
{

    if(startI==endI)
    {
        return;
    }
    else
    {
        long midPoint = (startI+endI)/2;

        mergeSort(input, startI, midPoint);
        mergeSort(input, midPoint+1, endI);
        mergeFunction(input,startI,endI);
    }
}

void mergeFunction(long input[], long startI, long endI)
{

    long midPoint=(startI+endI)/2;


    long totalElements = (endI-startI)+1; // parenthese is important here, else wrong value will be calculated


    long noOfElementsInArray1= (midPoint-startI)+1;


    long noOfElementsInArray2 = totalElements-noOfElementsInArray1;


    //we will create two new arrays of length m and n, copy the contents of main array

    long array1[noOfElementsInArray1]; //in actuallity it was noOfElementsInArray1, similarily for case below, and it caused error

    long array2[noOfElementsInArray1];


    //Filling array1 first;

    long i,j=0;
    for(i=startI; i<=midPoint; i++)
    {
        array1[j]=input[i];
        j++;
    }

    //Then filling array2;

    j=0;
    for(i=midPoint+1;i<=endI;i++)
    {
        array2[j]=input[i];
        j++;
    }

    //merge both arrays;

    i=0, j=0; long k=startI; //i points to array1, j points to array2, k points to the main input array

    while(i<noOfElementsInArray1 && j<noOfElementsInArray2)
    {
        if(array1[i]<=array2[j])
        {
            input[k]=array1[i];
            k++,i++;
        }
        else
        {
            input[k]=array2[j];
            k++,j++;
        }
    }

    //if one array gets exhausted

    if(i>=noOfElementsInArray1)//array1 is exhausted
    {
        while(j<noOfElementsInArray2)
        {
            input[k]=array2[j];//so array2 will be copied as it is
            k++,j++;
        }
    }
    else if(j>=noOfElementsInArray2) //array2 is exhausted
    {

        while(i<noOfElementsInArray1)
        {
            input[k]=array1[i];//so array1 will be copied as it is
            k++,i++;
        }
    }
}

void printArray(long input[], long length)
{
    long i;
    cout<<endl;
    for(i=0;i<length;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

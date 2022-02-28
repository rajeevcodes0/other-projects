#include<bits/stdc++.h>

using namespace std;

bool sortBySecond(pair<int,int>&, pair<int,int>&); //we must pass two elments of the vector to decide order

void printVector(vector< pair<int,int> >&);

int main()
{
    vector< pair<int,int> > vect;

    int arr[]={10,20,5,40};

    int arr1[]={30,60,20,50};

    int n= sizeof(arr)/sizeof(arr[0]);


    //inserting pairs into the vector
    for(long i=0; i<n; i++)
    {
        vect.push_back( make_pair(arr[i],arr1[i]) );
    }

	cout<<"Before sorting"<<endl;
	printVector(vect);

	//sorting is done on the basis of first member of the pair by default.
    sort(vect.begin(), vect.end()); //the second argument is the address that is exclusive, one more, for array we write sort(arr,arr+n)


    cout<<"after sorting"<<endl;
    printVector(vect);

    //sorting on the basis of the second member

    sort(vect.begin(), vect.end(), sortBySecond);

    cout<<"After sorting by second"<<endl;
    printVector(vect);



    return 0;

}


bool sortBySecond(pair<int,int>& a, pair<int,int>& b)
{
    return (a.second<b.second); //the order by which it should be sorted

    //the sorting should be done on the basis of second memeber of the pair
    // it should be in increasing order
}

void printVector(vector< pair<int,int> >& vect)
{
    //sizeof doesn't for passed array or vector, because that is just pointer;

    long i;
    for(i=0;i<4;i++)
    {
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }
    cout<<endl;
}

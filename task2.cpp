#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>

using namespace std;

//method to sort vector using bubble sort
//input is taken in input "in" vector
//output is stored in "out" vector
//both vectors are refrenced directly from main method so 
//nothing is to be returned
bool moveMin(vector<int>& in, vector<int>& out) {
	int a = in.size();

	//bubble sort
	for (int i = 0; i < a - 1; i++) {

		for (int j = 0; j < a - i - 1; j++) {

			if (in[j] > in[j + 1]) {
				int temp = in[j];
				in[j] = in[j + 1];
				in[j + 1] = temp;
			}
		}
	}

	//pushing sorted vector in "out" vector
	for (int i = 0; i < a; i++) {
		out.push_back(in[i]);
	}

	return true;
}



void main() {

	//using time seed for rand
	srand(time(0));

	//creating vectors 

	//in vector to store random values
	vector <int> in;
	//out vector to store values after bubble sort
	vector <int> out;
	//test vector to store values after in built sort method
	vector <int> test;

	//pushing 30 random numbers in vecotr 'in'
	for (int i = 0; i < 30; i++)
		in.push_back(rand() % 100 + 1);

	//pushing values of in vector into test vector
	for (int i = 0; i < in.size(); i++)
		test.push_back(in[i]);


	//sorting using inbuilt function
	sort(in.begin(), in.end());
	sort(test.begin(), test.end());


	//appending a random value at the end of vectors

	int randValue = rand() % 100 + 1;
	in.push_back(randValue);
	test.push_back(randValue);


	//displaying input array with last element un sorted
	cout << "Input Array:\n";
	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i] << " ";
	}

	//using moveMin function to sort, and storing the result in "out" vector
	moveMin(in, out);

	//again sorting "in" and "test"
	sort(in.begin(), in.end());
	sort(test.begin(), test.end());


	//displaying inbuilt method sorted array
	cout << "\nsorted array using sort() function \n";
	for (int i = 0; i < in.size(); i++)
	{

		cout << test[i] << " ";
	}
	
	//displaying bubble sorted array

	cout << "\n\nsorted array using movMin() function \n";

	for (int i = 0; i < out.size(); i++)
	{
	
		cout << out[i] << " ";
	}

	cout << "\n\n\n";


	//method to verify if both methods produce correct results
	bool areEqual = true;

	for (int i = 0; i < test.size(); i++)
	{
		if (test[i]!=out[i])
		{
			areEqual = false;
			break;
		}

	}
	//displaying result
	if (areEqual) {
		cout << "\nBoth Vectors are equal" << endl;
	}else
		cout << "\nBoth Vectors are equal" << endl;

}




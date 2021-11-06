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
//Complexity n^2+n
bool moveMin(vector<int> in, vector<int>& out) {
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


//Updated implementation:
//loop starts from the end and keeps swaping the elements until the 
//last element is at its correct position
//complexity 2n
bool UpdatedMoveMin(vector<int> in, vector<int>& out) {
	int a = in.size();

	//bubble sort
	for (int i = a - 1; i > 0; i--) {

			if (in[i] < in[i - 1]) {
				int temp = in[i];
				in[i] = in[i - 1];
				in[i - 1] = temp;
			}
	}

	//pushing sorted vector in "out" vector
	for (int i = 0; i < a; i++) {
		out.push_back(in[i]);
	}

	return true;
}

void testMovMin() {

	//creating vectors 

	//in vector to store random values
	vector <int> in;
	//out vector to store values after bubble sort double loop
	vector <int> out;
	//test vector to store values after bubble sort double loop
	vector <int> out2;

	for (int entries = 10; entries <= 100000; entries *= 10) {


		//using time seed for rand
		srand(time(0));
		//clearing vectors
		in.clear();
		out.clear();


		cout << "Entries: " << entries << endl;

		//pushing random numbers in vecotr 'in'
		for (int i = 0; i < entries; i++) {
			in.push_back(rand() % entries + 1);
			

		}
			
		//sorting using inbuilt function
		sort(in.begin(), in.end());
		

		//appending a random value at the end of vectors

		int randValue = rand() % 100 + 1;
		in.push_back(randValue);
		

		cout << "Starting Double Loop Implementation" << endl;
		//using moveMin function to sort, and storing the result in "out" vector
		moveMin(in, out);
		cout << "Completed Double Loop Implementation" << endl;

		cout << "Starting Single Loop Implementation" << endl;
		//using single loop moveMin 
		UpdatedMoveMin(in, out2);
		cout << "Completed Single Loop Implementation" << endl;


	}


}


void main() {

	
	
	testMovMin();


	

	




	
}




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
	//out vector to store values after bubble sort 
	vector <int> out;
	
	for (int entries = 10; entries <= 100000; entries *= 10) {


		time_t start, end;

		//using time seed for rand
		srand(time(0));
		//clearing vectors
		in.clear();
		out.clear();


		cout << "\n\nEntries: " << entries << endl;

		//pushing random numbers in vecotr 'in'
		for (int i = 0; i < entries; i++) {
			in.push_back(rand() % entries + 1);
			

		}
			
		//sorting using inbuilt function
		sort(in.begin(), in.end());
		

		//appending a random value at the end of vectors

		int randValue = rand() % 100 + 1;
		in.push_back(randValue);
		

		
		//using moveMin function to sort, and storing the result in "out" vector

		time(&start);
		moveMin(in, out);
		time(&end);
		
		double time_taken = double(end - start);
		cout << "Double Loop: " << fixed
			<< time_taken << " sec " << endl;
		
		
		//clearing vector
		out.clear();

		
		//using single loop moveMin 
		time(&start);
		UpdatedMoveMin(in, out);
		time(&end);
		time_taken = double(end - start);
		cout << "Single Loop: " << fixed
			<< time_taken << " sec " << endl;


	}


}


void main() {

	testMovMin();

}




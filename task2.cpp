#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>

using namespace std;

bool moveMin(vector<int>& in, vector<int>& out) {
	int a = in.size();
	for (int i = 0; i < a - 1; i++) {

		for (int j = 0; j < a - i - 1; j++) {

			if (in[j] > in[j + 1]) {
				int temp = in[j];
				in[j] = in[j + 1];
				in[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < a; i++) {
		out.push_back(in[i]);
	}

	return true;
}



void main() {
	srand(time(0));
	vector <int> in;
	vector <int> out;
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


	//appending a random value
	in.push_back(rand() % 100 + 1);
	test.push_back(rand() % 100 + 1);

	//using my function to sort, and storing the result in vector
	moveMin(in, out);


	sort(in.begin(), in.end());
	sort(test.begin(), test.end());


	cout << "Input Array:\n";
	for (int i = 0; i < in.size(); i++)
	{

		cout << in[i] << " ";
	}


	
	cout << "\nsorted array using sort() function \n";
	for (int i = 0; i < in.size(); i++)
	{

		cout << test[i] << " ";
	}





	cout << "\n\nsorted array using movMin() function \n";

	for (int i = 0; i < out.size(); i++)
	{
	
		cout << out[i] << " ";
	}

	cout << "\n\n\n";

	bool areEqual = true;

	for (int i = 0; i < test.size(); i++)
	{
		if (test[i]!=out[i])
		{
			areEqual = false;
			break;
		}

	}

	if (areEqual) {
		cout << "\nBoth Vectors are equal" << endl;
	}else
		cout << "\nBoth Vectors are equal" << endl;

}




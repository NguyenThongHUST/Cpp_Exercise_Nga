
#include <iostream>
#include <vector>
#include <ios> 
#include <limits>

using namespace std;

int getN()
{
	unsigned int n{0};
	while (true)
	{
		cout.flush();
		cout << "Enter N: ";
		cin >> n;
		if(!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else 
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if(n > 0)
				return n;
		}
	}
}	

void getArray(vector<int>& arr)
{
	for(auto& i : arr)
	{
		cout << "Enter element: ";
		cin >> i;
		cin.ignore();
	}
}

int maxDiff(vector<int>& arr)
{
    int max_diff = arr[1] - arr[0];

    int min_element = arr[0];
	for(int i = 1; i < arr.size(); i++)
	{     
		if (arr[i] - min_element > max_diff)                             
			max_diff = arr[i] - min_element;
			
		if (arr[i] < min_element)
			min_element = arr[i];                     
	}

	if(max_diff <= 0)
		return 0;
    return max_diff;
}

int main()
{
	int N {0};
	vector <int > Arr;
	
	N = getN();

	Arr.resize(N);
	getArray(Arr);

	int result = maxDiff(Arr);
	
	cout << "Result: "<< result;

	return 0;
}
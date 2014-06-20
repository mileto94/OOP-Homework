#include<iostream>
#include<string>

#include<map>
using namespace std;


template<typename T>
T median(T* collection, int size)
{
	return collection[int(size / 2)];
}

template<typename T>
T mode(T* collection, int size)
{
	map<T, int> objectsCounts;

	for(int i = 0; i < size; i++)
		objectsCounts[collection[i]] += 1;

	int max = 0;
	T key = collection[0];

	typedef map<T, int>::iterator iterator;
	for(iterator i = objectsCounts.begin(); i != objectsCounts.end(); i++)
	{
		if(i->second > max)
		{
			max = i->second;
			key = i->first;
		}
	}
	return collection[key];
}

template<typename T>
T average(T* collection, int size)
{
	T sum = 0;
	for(int i = 0; i < size; i++)
		sum += collection[i];
	return T(sum / size);
}

template<typename T>
T accumulate(T* collection, int size)
{
	T result = collection[0];
	for(int i = 1; i < size; i++)
	{
		result += T(collection[i]);
	}
	return result;
}

template<typename T>
bool all(T* collection, int size)
{
	int i = 0;
	bool flag = true;
	while(i < size && flag == true)
	{
		if(collection[i] == 0)
		{
			flag = false;
		}
		i++;
	}
	return flag;
}

template<typename T>
bool any(T* collection, int size)
{
	int i = 0;
	bool flag = false;
	while(i < size && flag == false)
	{
		if(collection[i] != 0)
		{
			flag = true;
		}
		i++;
	}
	return flag;
}

template<typename T1, typename T2>
T2* cast(T1* collection, int size)
{
	T2* result = new T2[size];
	for(int i = 0; i < size; i++)
	{
		result[i] = static_cast<T2>(collection[i]);
	}
	return result;
}

template<typename T>
T max(T* collection, int size)
{
	T maxItem = collection[0];
	for(int i = 1; i < size; i++)
	{
		if(collection[i] > maxItem)
		{
			maxItem = collection[i];
		}
	}
	return maxItem;
}

template<typename T>
T min(T* collection, int size)
{
	T minElement = collection[0];
	for(int i = 1; i < size; i++)
	{
		if(collection[i] < minElement)
		{
			minElement = collection[i];
		}
	}
	return minElement;
}

template<typename T>
T* reverse(T* collection, int size)
{
	T* reversed = new T[size];
	for(int i = 0; i < size; i++)
	{
		reversed[size - i - 1] = collection[i];
	}
	return reversed;
}

template<typename T>
T* take(T* collection, int size, int n)
{
	T* taken = new T[n];
	for(int i = 0; i < n; i++)
	{
		taken[i] = collection[i];
	}
	return taken;
}

template<typename T>
T* skip(T* collection, int size, int n)
{
	T* skipped = new T[size - n];
	for(int i = 0; i < size - n; i++)
	{
		skipped[i] = collection[i + n];
	}
	return skipped;
}

template<typename T>
void printArray(T* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<array[i]<<" ";
	}
	cout << endl;
}


int main()
{
	int numbers[] = { 0, 1, 2, 3, 4, 4, 5, 6, 7 };
	string strings[] = { "batman", "superman", "mickey mouse", "spiderman", "uti bachvarov" };
	int zeros[] = { 0, 0, 0, 0, 0 };
	
	int numbers_len = 9,
		strings_len = 5,
		zeros_len = 5;
	
	cout << median(strings, strings_len) << endl; // mickey mouse
	cout << mode(numbers, numbers_len) << endl; // 4
	cout << average(numbers, numbers_len) << endl; // 3
	cout << accumulate(numbers, numbers_len) << endl; // 32
	cout << accumulate(strings, strings_len) << endl; // "batmansupermanmickey mousespidermanuti bachvarov"
	cout << all(zeros, zeros_len) << endl; // false
	cout << all(numbers, numbers_len) << endl; // false
	cout << all(&numbers[1], numbers_len - 1) << endl; // true
	cout << any(zeros, zeros_len) << endl; // false
	cout << any(numbers, numbers_len) << endl; // true

	double arr[] = {2, 4, 5.32 , 6.66, 7.23};
	int* result = cast<double, int>(arr, 5);
	printArray(result, 5); // 2 4 5 6 7

	cout << max(numbers, numbers_len) << endl; // 7
	cout << min(numbers, numbers_len) << endl; // 0

	string* reversed = reverse(strings, strings_len); // reversed now contains { "uti bachvarov", "spiderman",  "mickey mouse", "superman",	"batman"}
	printArray(reversed, strings_len); // "uti bachvarov spiderman mickey mouse superman batman"

	string* taken = take(strings, strings_len, 2); // taken now contains { "batman", "superman" }
	printArray(taken, 2); // "batman superman"

	string* skipped = skip(strings, strings_len, 2); // skipped  now contains { "mickey mouse", "spiderman", "uti bachvarov"}
	printArray(skipped, strings_len - 2); // "mickey mouse spiderman uti bachvarov"

	return 0;
}
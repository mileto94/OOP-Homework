#include<iostream>
#include<string>

#include<map>
using namespace std;


template<typename T>
T median(T* collection, int size)
{
	//if(size % 2 == 0)
	//	return (collection[size / 2 - 1] + collection[size / 2]) / 2;
	//else
	//{
	//	return collection[size / 2];
	//}
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
		//result += static_cast<T>(collection[i]);
	}
	return result;
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
	cout << accumulate(strings, numbers_len) << endl; // "batmansupermanmickey mousespidermanuti bachvarov"
	//cout << all(zeros, zeros_len); // false
	//cout << all(numbers, numbers_len); // false
	//cout << all(&numbers[1], numbers_len - 1); // true
	//cout << any(zeros, zeros_len) // false
	//cout << any(numbers, numbers_len); // true
	//cout << max(numbers, numbers_len); // 7
	//cout << min(numbers, numbers_len); // 0
	//string* reversed = reverse(strings, strings_len); // reversed now contains { "uti bachvarov",						"spinderman",  "mickey mouse", "superman",	"batman"};
	//string* taken = take(strings, strings_len, 2); // taken now contains { "batman", "superman" };
	//string* skipped = skip(strings, strings_len, 2); // skipped  now contains { "mickey mouse",						"spinderman", "uti bachvarov"};
	return 0;
}
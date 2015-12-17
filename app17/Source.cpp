// METAPROGRAMMING => TEMPLATE METAPROGRAM
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <forward_list> // singly
#include <list> // doubly
using namespace std;
//
//class Sample
//{
//	virtual void F1() { }
//};

template<typename Iter>
using Value_type = typename Iter::value_type; // C’s value type

template<typename Container>
using Iterator_type = typename Container::iterator; // C’s iterator type

template<typename Iter>
using Iterator_category = typename iterator_traits<Iter>::iterator_category; // Iter’s category

template<typename Iter> // for random-access iterators
void sort_helper(Iter beg, Iter end, random_access_iterator_tag) // we can subscript into [beg:end)
{
	sort(beg, end); //standard algorith sort
}

template<typename Iter> // for forward iterators
void sort_helper(Iter beg, Iter end, forward_iterator_tag) // we can traverse [beg:end)
{
	vector<Iter::value_type> v{ beg, end }; // initialize a vector from [beg:end)
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), beg); // copy the elements back
}

template<typename TContainer>
void sort(TContainer& container)
{
	using Iter = Iterator_type<TContainer>;
	sort_helper(begin(container), end(container), Iterator_category<Iter>{});
}

void main()
{
	vector<int> v{ 3, 5, 2, 1 };
	sort(v);
	for (int item : v)
		cout << item << endl;

	forward_list<int> l{ 3, 5, 2, 1 };
	sort(l);

	for (int item : v)
		cout << item << endl;

	//cout << boolalpha << is_polymorphic<Sample>::value << endl;
	//cout << boolalpha << is_abstract<Sample>::value << endl;
	//cout << boolalpha << is_final<Sample>::value << endl;
	//cout << boolalpha << is_arithmetic<int>::value << endl;
	//cout << boolalpha << is_arithmetic<double>::value << endl;
	//cout << boolalpha << is_arithmetic<char>::value << endl;
	//cout << boolalpha << is_arithmetic<bool>::value << endl;
	//cout << boolalpha << is_arithmetic<string>::value << endl;
}
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

void reverse(std::vector<char>& s) {
	static int count = 0;
	static int size = s.size();

	int high = size - count - 1;
	

	if (count == (size / 2) || size <= 1 )
		return;

	char temp = s[high];
	s[count] = s[high];
	s[high] = temp;

	count += 1;
	
	return reverse(s);

}



int main()
{
	std::vector<char> vec = {'H', 'a', 'n', 'n', 'a', 'h'};

	reverse(vec);

	for (auto x : vec) {
		std::cout << x;
	}

}

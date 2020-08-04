// This program solves Project Euler problem 18: Maximum Path Sum I
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int triH = 4;
	vector<vector<int>> triangle;
	vector<vector<int>> valV(triH, vector<int>(triH));
	vector<vector<bool>> path(triH, vector<bool>(triH));

	vector<int> v1 = { 3 };
	vector<int> v2 = { 7 , 4 };
	vector<int> v3 = { 2, 4, 6 };
	vector<int> v4 = { 8, 5, 9, 3 };
	triangle.push_back((v1));
	triangle.push_back((v2));
	triangle.push_back((v3));
	triangle.push_back((v4));

	int numsInRow = triH;
	for(int i = 0; i < numsInRow; i++)
	{
		valV[triH-1][i] = triangle[triH-1][i];
	}
	numsInRow--;
	for(int j = triH-1; j > 0 ;j--)
	{
		for(int i = 0; i < numsInRow; i++)
		{
			if(valV[j][i] > valV [j][i+1])
			{
				valV[j - 1][i] = triangle[j - 1][i] + valV[j][i];
				path[j - 1][i] = false;
			}
			else
			{
				valV[j - 1][i] = triangle[j - 1][i] + valV[j][i+1];
				path[j - 1][i] = true;
			}
		}
		numsInRow--;
	}
	
}


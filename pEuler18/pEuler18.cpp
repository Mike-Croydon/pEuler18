// This program solves Project Euler problem 18: Maximum Path Sum I
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void importTriangle(vector<vector<int>> & triangle, const int & triH, fstream & triFile)
{
	vector<int> lineVec(triH, 0);
	int numsInLine = 1;
	for (int i = 0; i < triH; i++)
	{
		int digit;
		for (int j = 0; j < numsInLine; j++)
		{
			triFile >> digit;
			lineVec[j] = digit;
		}
		triangle.push_back(lineVec);
		numsInLine++;
	}
}


int main()
{
	//This creates the fstream and determines the height of the triangle
	fstream triFile;
	triFile.open("triangle.txt");
	string line;
	int triH = 0;
	while (!triFile.eof()) {
		getline(triFile, line);
		triH++;
	}
	triFile.clear();
	triFile.seekg(0, ios::beg);	//The clear and seek here resets the fstream object to the start of the file
	
	//initializing the input triangle vector, the value vector, and the path vector
	vector<vector<int>> triangle;
	vector<vector<int>> valV(triH, vector<int>(triH));
	vector<vector<bool>> path(triH, vector<bool>(triH));

	//This loop extracts the data from the text file, storing each line temporarily in lineVec and pushing it to the triangle vector
	importTriangle(triangle, triH, triFile);
	
	int numsInRow = triH;
	//Loop to create the final value vector of vectors
	for (int i = 0; i < numsInRow; i++)
	{
		valV[triH - 1][i] = triangle[triH - 1][i];
	}

	//This is the main loop that starts from the bottom of the triangle vector and calculates the max of each subtriangle
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


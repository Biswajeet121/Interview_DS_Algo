/*

      Problem Link : https://www.naukri.com/code360/problems/even-or-odd_7463066?topList=ninjas-sde-sheet&problemListRedirection=true&attempt_status=COMPLETED&leftPanelTabValue=PROBLEM

      Problem statement
      Write a program that uses bitwise AND operator to check if a given positive integer is even or odd.
      
*/

************************************************************ C++ ************************************************************

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	cin >> n;

	if(n & 1)
		cout<<"Odd"<<endl;
	else
		cout<<"Even"<<endl;
	return 0;
}

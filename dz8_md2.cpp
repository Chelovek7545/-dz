#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <fstream>
using namespace std;

void vector_error() {
	vector<int> v1;
	v1.at(5);
}

void string_error()
{
	string s1 = "s1cc2fhgfdhfgjg";
	int a = stoi(s1);
}

void fstream_error()
{
	string path = "myFile.txt";
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	fin.open(path);	
}

void myError()
{
	int age = -5;
	if (age < 0) { throw logic_error("log_error"); }
}

void err5()
{
	int length=2122;
	if (length > 256){
		throw length_error("out of length"); }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Какую ошибку вызовем сегодня? (от 1 до 5)" << endl;
	cin >> n;
	try {
		switch (n) {
		case 1:
			vector_error();
			break;
		case 2:
			string_error();
			break;
		case 3:
			
			fstream_error();
			break;
		case 4:
			myError();
			break;
		case 5:
			err5();
			break;
		default: cout << "Такой ошибки здесь нет" << endl;
		}
	}
	catch (const out_of_range& err)
	{
		cout << "out_of_range: " << err.what() << endl;
	}
	catch (const invalid_argument& err) 
	{ 
		cout << err.what() << endl; 
	}
	catch (const ifstream::failure& ex)
	{
		cout << ex.what() << endl;
	}
	catch (const logic_error& err) 
	{ 
		cout << err.what() << endl; 
	}
	catch (const length_error& err) 
	{ 
		cout << err.what() << endl; 
	}

	
}

// Write a description and declare all variables at the beggining of the
// functions
#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>

class MultiString {
	public: 
// Constructors & Destructor

	MultiString() {
		buf = NULL;
		strNumber = 0;
		std::cout << "Empty constructor works\n";
	};
	MultiString(int n) { 
		buf = new char* [strNumber = n];
        for (int i = 0; i < n; ++i) {
            buf[i] = NULL;
//            strcpy(buf[i], "Hello");
        }
		std::cout << "Constructor with n strings works\n"; 
	};
	MultiString(const MultiString &ms); // 
	~MultiString() {
		// Write a delete for each char*
		if (strNumber) 
			for (int i = 0; i < strNumber; ++i) {
				delete buf[i];
			}
		delete[] buf;
		std::cout << "The variable was deleted\n";
	};

// Methods
	
	MultiString& operator=(const MultiString &ms);
	char* operator[](int nIndex) const;
	MultiString& operator+=(const MultiString &);

	void MergeMultiStringExclusive(const MultiString &);
	char* Find(const char *pszSub) const;
	int GetLength() const;
	bool IsEmpty()const{	return strNumber == 0;};
	void Empty();
	void SetAt(int nIndex, const char* str);
	void PrintStr(int nIndex) const;
		
	private:
	char **buf;
	int strNumber;

};

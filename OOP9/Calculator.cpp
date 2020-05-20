/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 14th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Calculator.h"



using namespace std;
namespace sdds
{
	template <typename T, int N>
	Calculator<T, N>::Calculator() {
		result[0] = '\0';
	}

	template <typename T, int N>
	void  Calculator<T, N>::add(const T* value1, const T* value2) {
		*value1 =  result;
		*value2 =  result;
		for (int i = 0; i < N; i++) {
			T result[i] = value1[i] + value2[i];
		}
	};
	template <typename T, int N>
	void  Calculator<T, N>::subtract(const T* value1, const T* value2) {
		*value1 = result;
		*value2 = result;
		for (int i = 0; i < N; i++) {
			T result[i] = value1[i] - value2[i];
		}
	}
	template <typename T, int N>
	void  Calculator<T, N>::multiply(const T* value1, const T* value2) {
		*value1 =  result;
		*value2 =  result;
		for (int i = 0; i < N; i++) {
			T result[i] = value1[i] * value2[i];
		}
	};

	template <typename T, int N>
	void  Calculator<T, N>::divide(const T* value1, const T* value2) {
		*value1 =  result;
		*value2 =  result;
		for (int i = 0; i < N; i++) {
			T result[i] = value1[i] / value2[i];
		}
	};
	template <typename T, int N>
	ostream& Calculator<T, N>::display(ostream & os) const {
		for (int i = 0; i < N; i++) {
			os << result[i] << ",";
		}
		return os;
	}

}
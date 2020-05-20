// Calculator.h
// WS09 in-lab
#include <iostream>
#ifndef SDDS_CALCULATOR_H__
#define SDDS_CALCULATOR_H__



using namespace std;
namespace sdds
{
	template <typename T,int N>
	class Calculator {
		T result[N];
	public:
		Calculator() {
			for (int i = 0; i < N; i++) {
				result[i] = '\0';
			}
		}
		void add(const T* value1, const T* value2) {
			
			for (int i = 0; i < N; i++) {
				 result[i] = value1[i] + value2[i];
			}
		}
		void subtract(const T* value1, const T* value2) {
			
			for (int i = 0; i < N; i++) {
				 result[i] = value1[i] - value2[i];
			}
		}
		void multiply(const T* value1, const T* value2) {
			
			for (int i = 0; i < N; i++) {
				 result[i] = value1[i] * value2[i];
			}
		}
		void divide(const T* value1, const T* value2) {
			
			for (int i = 0; i < N; i++) {
				 result[i] = value1[i] / value2[i];
			}
		}
		ostream& display(ostream& os) const {
			for (int i = 0; i < N; i++) {
				if (i < N - 1) {
					os << result[i] << ",";
				}
				else
					os << result[i];
			}
			os << endl;
			return os;
		}
		
		Calculator<T,N>& operator+=(const T*value) {
			add(result, value);
			return *this;
		}
		Calculator<T, N>& operator-=(const T*value) {
			subtract(result, value);
			return *this;
		}
		Calculator<T, N>& operator*=(const T*value) {
			multiply(result, value);
			return *this;
		}
		Calculator<T, N>& operator/=(const T*value) {
			divide(result, value);
			return *this;
		}

	};
}
#endif // !
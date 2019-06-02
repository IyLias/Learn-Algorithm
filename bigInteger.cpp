#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <math.h>

#define MAXNUM	1001

using namespace std;

int results[MAXNUM], temp1[MAXNUM], temp2[MAXNUM], temp3[MAXNUM];

class Number { // includes Integer range

public:

	int arr[MAXNUM];
	int how_many_digit;

	bool is_minus;

	Number(int num) {

		int idx = MAXNUM - 1;
		int temp_num = num < 0 ? -num : num;
		how_many_digit = 0;

		while (temp_num) {

			if (temp_num < 10 && num < 0) {
				arr[idx--] = -(temp_num % 10);
				break;
			}

			arr[idx--] = temp_num % 10;
			temp_num /= 10;

			how_many_digit++;
		}

		for (; idx >= 0; idx--)
			arr[idx] = 0;

		if (num == 0)
			how_many_digit = 1;

		is_minus = num < 0 ? true : false;
	}

	void print_number() {

		for(int i=0;i<MAXNUM;i++)
			if (arr[i] != 0) {
				for (int k = i; k < MAXNUM; k++)
					printf("%d", arr[k]);
				printf("\n");
				break;
			}
	}

	int get_number() { // if number is not out of range in int

		int value = 0,cnt=0;

		for (int j = MAXNUM - 1;j > MAXNUM - 11; j--) {

			value += (pow(10, cnt) * (arr[j]<0?-arr[j]:arr[j]) );
			cnt++;
		}

		return (is_minus == true ? -value : value);
	}

	bool operator>(Number Num) {

		if (is_minus == true && Num.is_minus == false)
			return false;
		else if (is_minus == false && Num.is_minus == true)
			return true;
		else {

			if (is_minus == false && Num.is_minus == false) {



			}
			else {



			}

		}

	}

	Number& operator+(Number Num) {

		int carry = 0, value, rem;
		Number result(0);

		for (int i = MAXNUM - 1; i >= 0; i--) {

			rem = (arr[i] + Num.arr[i]+carry) % 10;
			value = arr[i] + Num.arr[i] + carry;

			result.arr[i] = rem;

			carry = (value >= 10 ? 1 : 0);
		}

		return result;
	}

	Number& operator*(Number Num) {

		int times = Num.get_number();

		Number result(0);

		for (int i = 0; i < times; i++)
			result = result.operator+(*this);

		return result;
	}

	Number& operator-(Number Num) {







	}

	void operator/(Number Num) {





	}

};


int main(void)
{
	int N, M;
	//scanf("%d %d", &N, &M);

	results[MAXNUM - 1] = 1, temp3[MAXNUM - 1] = 1;

	//for (int k = 1; k <= M; k++) {
	//}

	Number num1(-1477), num2(2580);

	Number result = num1.operator+(num2);
	result.print_number();

	//if (num2.operator>(num1))
	//	printf("num1 is bigger");

	num1.print_number();

	return 0;
}

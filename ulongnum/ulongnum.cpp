/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ul.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ul class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/
str ul::_tostring(int number) {
	char s1[120];
	sprintf(s1, "%d", number);
	char s[20];
	s[0] = '\0';
	strcat(s, s1);
	str result(s);
	/*str result("");
	while (number != 0) {
		result = number % 10 + '0' + result;
		number = number / 10;
	}*/

	return result;
}

int ul::_toint(const char& c) const {
	return (c - '0');
}

ul::ulongnum(int number, bool display) :_display(display), _value("") {
	_value = _tostring(number);
	//_length = _value.length();
}


ul::ulongnum(const char* number, bool display) : _display(display), _value("") {
	_value = number;
	//_length = _value.length();
}
//CIC - Better practice to make const char number. _value(number,display)
ul::ulongnum(char number, bool display) : _display(display), _value(number) {
	//_length = _value.length();
}

//no copy constructor needed. This calls str's copy constr which calls darrays copy constr. darrray takes care of everything
//Take care to do baseline init
ul::ulongnum(const ul& rhs): _display(rhs._display), _value(rhs._value) {
	//cout << "In ulongnum copy constructor" << endl;
	//CIC - commented 
	//_copy(rhs);
}

void ul::_copy(const ul& rhs) {
	this->_display = rhs._display;
	this->_value = rhs._value;
	//this->_length = this->_value.length();
}

ul& ul::operator=(const ul& rhs) {
	//cout << "In ulongnum equal operator" << endl;
	if (this != &rhs) {
		_copy(rhs);
	}
	return *this;
}

int ul::operator[](int i) const {
	if (i < 0 || i > this->_value.length() + 1) {
		assert(0);
	}

	return _toint(_value.getCharAt(i));
}
/*
ul operator-(const ul& u1, const ul& u2) {
	int borrow = 0;
	ul temp("");

	int l1 = u1._length - 1;
	int l2 = u2._length - 1;

	if (l1 < l2) assert(0);

	int i = l1, j = l2;

	while (i >= 0 && j >= 0) {
		int res = 0;
		int t = u1[i];
		if (borrow == 1) {
			if (u1[i] == 0) {
				t = 9;
			}
			else {
				t = u1[i] - 1;
			}
			borrow = 0;
		}

		if (u1[i] < u2[j]) {
			res = t + 10 - u2[j];
			borrow = 1;
		}
		else {
			res = t - u2[j];
		}

		temp._value = res + '0' + temp._value;
		i--; j--;
	}


	if (j >= 0) assert(0);

	while (i >= 0) {
		temp._value = u1[i] + '0' + temp._value;
		i--;
	}
	
	temp._value.reverse();
	int k = temp._value.length() - 1;
	while (temp._value[k] == '0' && k >= 0) {
		k--;
	}

	if (k < temp._value.length() - 1) {
		temp._value = temp._value.substr(0, k + 1);
	}
	temp._value.reverse();
	temp._length = temp._value.length();
	return temp;
}
*/
ul operator+(const ul& u1, const ul& u2) {
	//cout << "Adding obkects" << u1 << " " << u2 << endl;
	int carry = 0;
	//int i = u1._length - 1;
	//int j = u2._length - 1;
	int i = u1._value.length() - 1;
	int j = u2._value.length() - 1;
	ul temp("");
	while (i >= 0 && j >= 0) {
		int v1 = u1._value.getCharAt(i) - '0';
		int v2 = u2._value.getCharAt(j) - '0';
		//int sum = u1._value[i] + '0' + u2._value[j] + '0' + carry;
		int sum = v1 + v2 + carry;
		char mod = (sum % 10) + '0';
		temp._value = temp._value + mod;
		//temp._length = temp._value.length();
		carry = sum / 10;
		i--; j--;
	}

	if ( i != j ) {
	while (i >= 0) {
		int v1 = u1._value.getCharAt(i) - '0';
		//int sum = u1._value[i] + '0' + carry;
		int sum = v1 + carry;
		char mod = (sum % 10) + '0';
		temp._value = temp._value + mod;
		//temp._length = temp._value.length();
		carry = sum / 10;
		i--;
	}

	while (j >= 0) {
		int v2 = u2._value.getCharAt(j) - '0';
		//int sum = u2._value[j] + '0' + carry;
		int sum = v2 + carry;
		char mod = (sum % 10) + '0';
		temp._value = temp._value + mod;
		//temp._length = temp._value.length();
		carry = sum / 10;
		j--;
	}
	}

	if (carry == 1) {
		temp._value = temp._value + '1';
		//temp._length = temp._value.length();
	}

	//temp._length = temp._value.length();
	temp._value.reverse();
	return temp;
}


ul operator+(const ul& u1, int number) {
	//cout << "Adding " << u1 << " " << number << endl;
	//int l1 = u1._length - 1;
	int l1 = u1._value.length() - 1;
	int carry = 0;
	ul temp("");
	int i = l1;

	while(i >= 0 && number != 0 ) {
		int v1 = u1._value.getCharAt(i) - '0';
		int sum = v1 + (number%10) + carry;
		char mod = (sum%10) + '0';
		temp._value = temp._value + mod;
		//temp._length = temp._value.length();
		carry = sum/10;
		i--;
		number = number/10;
	}

	if(i != number) {
		while(i >= 0) {
			int v1 = u1._value.getCharAt(i) - '0';
			int sum = v1 + carry;
			char mod = (sum%10) + '0';
			temp._value = temp._value + mod;
			//temp._length = temp._value.length();
			carry = sum/10;
			i--;
		}

		while(number!=0) {
			int sum = number + carry;
			char mod = (sum%10) + '0';
			temp._value = temp._value + mod;
			//temp._length = temp._value.length();
			carry = sum/10;
			number = number/10;
		}
	}

	if(carry == 1) {
		temp._value = temp._value + '1';
		//temp._length = temp._value.length();
	}
	
	temp._value.reverse();
	//temp._length = temp._value.length();
	return temp;
}

ul operator+(int number, const ul& u2) {
	return u2 + number;
}

void ul::factorial(int range) {
	ul temp = 1;
	for(int i = 2; i <= range; i++) {
		temp = temp * i;
	}
	//temp._length = temp._value.length();
	*this = temp;
}

/*
ul operator*(const ul& u1, const ul& u2) {
	int l1 = u1._length - 1;
	int l2 = u2._length - 1;

	ul t1(u1);
	ul t2(u2);

	while (l1 < l2) {
		t1._value = '0' + t1._value;
		l1++;
	}

	while (l2 < l1) {
			t2._value = '0' + t2._value;
			l2++;
	}

	int m = t1._value.length();
	int m_2 = (m + 1) >> 1;

	if (m <= 2) {
		ul z = mult(u1, u2);
		return z;
	}

	ul u1l, u1h, u2l, u2h;
	u1l._value = t1._value.substr(0, m_2 - 1);
	u1h._value = t1._value.substr(m_2 - 1 , t1._value.length());

	u2l._value = t2._value.substr(0, m_2 - 1);
	u2h._value = t2._value.substr(m_2 - 1, t2._value.length());

	u1l._length = u1l._value.length();
	u1h._length = u1h._value.length();
	u2l._length = u2l._value.length();
	u2h._length = u2h._value.length();

	ul z0 = u1l * u2l;
	ul z1 = u1h * u2h;
	ul z2 = (u1l + u1h) * (u2l + u2h);
	z2 = (z2 - z0) - z1;

	for (int i = 0; i < (m_2 << 1); i++) {
		z0._value = z0._value + '0';
		z0._length = z0._value.length();
	}

	ul z = z0 + z1;

	for (int i = 0; i < m_2; i++) {
		z2._value = z2._value + '0';
		z2._length = z2._value.length();
	}



	z = z + z2;

	return z;
}
*/
ul operator*(const ul& u1, const ul& u2) {
	//int l1 = u1._length - 1;
	//int l2 = u2._length - 1;
	int l1 = u1._value.length() - 1;
	int l2 = u2._value.length() - 1;
	//CIC
	//Take care to always multiply bigger number by smaller number

	/*
	CIC
	const ul* p1 = &s1;
	const ul* p2 = &s2;

	if(s2.numdigit > 1.numdigit()) {
	p1 = &s2;
	p2 = &s1;
	}
	
	use *p2 and *p1 in the further calculations instead of s1 and s2
	*/
	ul sum("");
	int carry = 0;

	for(int i = l1; i >= 0; i-=2) {
		ul temp("");
		int numZero = i;
		while(numZero < l1) {
			temp._value = temp._value + '0';
			//temp._length = temp._value.length();
			numZero++;
		}
		int v1 = 0;
		if (i==0) {
			v1 = u1._value.getCharAt(i) - '0';
		} else {

			v1 = (u1._value.getCharAt(i-1) - '0')*10 + (u1._value.getCharAt(i) - '0') ;
		}
		for(int j = l2; j >= 0; j--) {
			int v2 = u2._value.getCharAt(j) - '0';
			//cout << v1 << " " << v2 << endl;
			int product = v1 * v2 + carry;
			char mod = (product % 10) + '0';
			carry = product/10;
			temp._value = temp._value + mod;
			//temp._length = temp._value.length();
		}

		if (carry > 10) {

			int i = 0;
			while(carry > 0) {
				temp._value = temp._value + ((carry%10)+'0');
				carry/=10;
			}
		} else if (carry > 0) {

			temp._value = temp._value + (carry + '0');
			//temp._length = temp._value.length();
			carry = 0;
		}
		
		temp._value.reverse();
		//cout << temp << endl;
		sum = sum + temp;
		//sum._length = sum._value.length();
	}
	
	
	
	
	
	
	
	
	/*
	for(int i = l1; i >= 0; i--) {
		ul temp("");
		int numZero = i;
		while(numZero < l1) {
			temp._value = temp._value + '0';
			//temp._length = temp._value.length();
			numZero++;
		}
		int v1 = u1._value.getCharAt(i) - '0';
		for(int j = l2; j >= 0; j--) {
			int v2 = u2._value.getCharAt(j) - '0';
			//cout << v1 << " " << v2 << endl;
			int product = v1 * v2 + carry;
			char mod = (product % 10) + '0';
			carry = product/10;
			temp._value = temp._value + mod;
			//temp._length = temp._value.length();
		}

		if (carry > 0) {
			temp._value = temp._value + (carry + '0');
			//temp._length = temp._value.length();
			carry = 0;
		}
		
		temp._value.reverse();
		//cout << temp << endl;
		sum = sum + temp;
		//sum._length = sum._value.length();
	}
	*/
	return sum;
}

/*
	for (int i = l1; i >= 0; i--) {
			for (int j = l2; j >= 0; j--) {
				int product = u1[i] * u2[j];
				ul prod(product);
				int numZeroj = j;
				while (numZeroj != l2) {
					prod._value = prod._value + '0';
					prod._length = prod._value.length();
					numZeroj++;
				}
				int numZeroi = i;
				while (numZeroi != l1) {
					prod._value = prod._value + '0';
					prod._length = prod._value.length();
					numZeroi++;
				}

				temp = prod + temp;
			}
		}
	temp._length = temp._value.length();
	return temp;
}
*/




ostream& operator<<(ostream& o, const ul& number) {
	o << number._value;
	return o;
}

bool operator==(const ul& u1, const ul& u2) {
	return (u1._value == u2._value);
}

bool operator==(const ul& u1, int number) {
	ul temp(number);
	return (u1._value == temp._value);
}

bool operator==(const ul& u1, const char* number) {
	ul temp(number);
	return (u1._value == temp._value);
}

//EOF



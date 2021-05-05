#include<iostream>

using namespace std;

template<class x>  class Calculator {
public:
	class Exception{};

	x calculate(x a,x b,string s){
		x ans;
		if (s == "+") {
			ans = a + b;
			cout << a << " + " << b << " = " << ans << endl << endl;
		} 
		else if(s == "-") {
			ans = a - b;
			cout << a << " - " << b << " = " << ans << endl << endl;
		}
		else if (s == "*") {
			ans = a * b;
			cout << a << " * " << b << " = " << ans << endl << endl;
		}
		else if (s == "/") {
			if (b != 0) {
				ans = a / b;
				cout << a << " / " << b << " = " << ans << endl << endl;
			}
			else {
				throw Exception();
			}
		}

	}
};

int main() {
	try {
		Calculator<double> calculator;
		double operand1, operand2;
		string symbol, answer;
		bool flag = true;
		do {
			cout << "Enter 1st operand: "; cin >> operand1;
			cout << "\nEnter operation sign: "; cin >> symbol;
			cout << "\nEnter 2nd operand: "; cin >> operand2;
			cout << "\n";

			calculator.calculate(operand1, operand2, symbol);
			cout << "\n";
			cout << "Do you want to exit? ( Y/N )" << endl;
			cin >> answer;
			if (answer == "Y") {
				flag = false;
			}
			else
				cout << "\n";
			continue;
		
		} while (flag);
	}
	catch (Calculator<int>::Exception) {
		cout << "Error!" << endl;
	}
	return 0;
}
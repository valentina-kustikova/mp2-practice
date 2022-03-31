#include <iostream>
#include <thread>
#include <chrono>


#include "menu.h"

void menu() {
	char operation;

	info();

	std::cout << "\t!Now we can start! " << '\n';
	std::cout << "\n----------------" << '\n';
	std::cout << "1. C = A * const ==> Type 'c'" << '\n';
	std::cout << "2. C = A + B ==> Type 's'" << '\n';
	std::cout << "3. C = A - B ==> Type 'd'" << '\n';
	std::cout << "4. C = A * B ==> Type 'm'" << "\n";
	std::cout << "5. clear console ==> Type 'r'" << "\n";
	std::cout << "6. Close console ==> Type 'q'" << "\n";
	std::cout << "----------------" << "\n\n";
	std::cout << "Ur choice: ";
	std::cin >> operation;
	try {
		switch (operation) {
		case 'c':
			multiplyByConstant();
			break;
		case 's':
			sum();
			break;
		case 'd':
			difference();
			break;
		case 'm':
			multiplyPolynomials();
			break;
		case 'r':
			clear_console();
			break;
		case 'q':
			exit(0);
			break;
		default:
			std::cout << "[!] Incorrect symbol \n";
			std::cout << "\t[~] exiting...";
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			exit(0);	
		}

	}
	catch (const std::runtime_error& rE) {
		std::cout << "\n-----------------------------------------------------------" << "\n";
		std::cout << rE.what() << '\n';
	}
	catch (const std::invalid_argument& iA) {
		std::cerr << "Invalid variable factor, u have to follow given rules!\n";
	}
}

void info() {
	std::cout << "To enter a polynomial you must apply the following rules:";
	std::cout << "\nCorrect monoms using given rules:\n";
	std::cout << "\ta. 8x^3*6y^5*2z^4\n";
	std::cout << "\tb. -6.3x*-5y^2*3z^0\n";
	std::cout << "\tc. 5x^1*3z^5*7y^2\n";
	std::cout << "\n Incorrect monoms examples:\n";
	std::cout << "\ta. 8xyz\n";
	std::cout << "\tb. 2x^-3*2z^2\n";
	std::cout << "\tc. 4x^2*3z*y\n";
	std::cout << "\n Correct polynomials example:\n";
	std::cout << "\ta. 5x^2*y^3*z^4*x^2 + 2x^1*y^2*z^4\n";
	std::cout << "\tb. 7x^4*y^3*z^4 + 15x^1*y^2*z^4\n";
	std::cout << "\tc. 7x^4*y^3*z^4 + 15x^1*y^2*z^4 + 3x^1*z^3*y^5\n\n";

}

void multiplyByConstant() {
	std::string entered_expression;
	double c;
	std::cout << "\nEnter the polynomial A: ";
	std::getline(std::cin >> std::ws, entered_expression);
	polinoms poli_1(entered_expression);
	std::cout << "\nEnter constant: ";
	std::cin >> c;
	std::cout << "\n-----------------------------------------------------------" << "\n";
	std::cout << "A * const = " << poli_1 * c << '\n';
	std::cout << "-----------------------------------------------------------" << "\n";
	char cont;
	std::cout << "Do you want to continue?\n";
	std::cout << "Type 'y' to continue or 'n' to exit: ";
	std::cin >> cont;
	if (cont == 'y') {
		poli_1.~polinoms();
		clear_console();
		menu();
	}
	else exit(0);
}

void sum() {
	std::string polynomial_1;
	std::string polynomial_2;
	std::cout << "\nEnter the polynomial A: ";
	std::getline(std::cin >> std::ws, polynomial_1);
	std::cout << "\nEnter the polynomial B: ";
	std::getline(std::cin >> std::ws, polynomial_2);
	polinoms A(polynomial_1);
	polinoms B(polynomial_2);
	std::cout << "\n-----------------------------------------------------------" << "\n";
	std::cout << "A + B = " << A + B << '\n';
	std::cout << "-----------------------------------------------------------" << "\n";
	char cont;
	std::cout << "Do you want to continue?\n";
	std::cout << "Type 'y' to continue or 'n' to exit: ";
	std::cin >> cont;
	if (cont == 'y') {
		A.~polinoms();
		B.~polinoms();
		clear_console();
		menu();
	}
	else exit(0);
}

void difference() {
	std::string polynomial_1;
	std::string polynomial_2;
	std::cout << "\nEnter the polynomial A: ";
	std::getline(std::cin >> std::ws, polynomial_1);
	std::cout << "\nEnter the polynomial B: ";
	std::getline(std::cin >> std::ws, polynomial_2);
	polinoms A(polynomial_1);
	polinoms B(polynomial_2);
	std::cout << "\n-----------------------------------------------------------" << "\n";
	std::cout << "A - B = " << A - B << '\n';
	std::cout << "-----------------------------------------------------------" << "\n";
	char cont;
	std::cout << "Do you want to continue?\n";
	std::cout << "Type 'y' to continue or 'n' to exit: ";
	std::cin >> cont;
	if (cont == 'y') {
		A.~polinoms();
		B.~polinoms();
		clear_console();
		menu();
	}
	else exit(0);
}

void multiplyPolynomials() {
	std::string polynomial_1;
	std::string polynomial_2;
	std::cout << "\nEnter the polynomial A: ";
	std::getline(std::cin >> std::ws, polynomial_1);
	std::cout << "\nEnter the polynomial B: ";
	std::getline(std::cin >> std::ws, polynomial_2);
	polinoms A(polynomial_1);
	polinoms B(polynomial_2);
	std::cout << "\n-----------------------------------------------------------" << "\n";
	std::cout << "A * B = " << A * B << '\n';
	std::cout << "-----------------------------------------------------------" << "\n";
	char cont;
	std::cout << "Do you want to continue?\n";
	std::cout << "Type 'y' to continue or 'n' to exit: ";
	std::cin >> cont;
	if (cont == 'y') {
		A.~polinoms();
		B.~polinoms();
		clear_console();
		menu();
	} else exit(0);
}

void clear_console() {
	system("cls");
}

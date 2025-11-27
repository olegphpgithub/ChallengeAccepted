#include <iostream>
#include <random>
#include <sstream>

int generate_minuend()
{
	int x = (rand() % 5 + 5) * 10;
	x += rand() % 5;
	return x;
}

int generate_subtrahend()
{
	int x = (rand() % 4 + 1) * 10;
	x += rand() % 4 + 5;
	return x;
}

int main()
{
	std::srand(static_cast<unsigned>(std::time(0)));

	while (true) {
		int minuend = generate_minuend();
		int subtrahend = generate_subtrahend();
		int difference = minuend - subtrahend;

		while (true) {
			std::cout << minuend << " - " << subtrahend << " = ";
			std::string input;
			std::getline(std::cin, input);

			try {
				std::stringstream ss;
				ss << input;
				int answer = 0;
				ss >> answer;
				if (ss.fail()) {
					throw std::exception("Wrong number");
				}
				if (answer == difference) {
					std::cout << "Right" << std::endl;
				}
				else {
					std::cout << "Wrong" << std::endl;
				}
				break;
			}
			catch (std::exception ex) {
				std::cout << ex.what() << std::endl;
			}
		}
	}
}

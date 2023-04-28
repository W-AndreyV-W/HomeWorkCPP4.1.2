#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>
#include <locale.h>


std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (std::holds_alternative<int>(get_variant())) {
		std::cout << "Результат Функции: " << std::get<int>(get_variant()) * 5 << std::endl;
	}
	else if (std::holds_alternative<std::string>(get_variant())) {
		std::cout << "Результат Функции: " << std::get<std::string>(get_variant()) << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(get_variant())) {
		std::vector<int> array = std::get<std::vector<int>>(get_variant());
		std::cout << "Результат Функции: ";
		std::for_each(array.begin(), array.end(), [&](int tmp) {
			std::cout << tmp << " ";
			});
		std::cout << std::endl;
	}
}
# include <iostream>
# include <string>

std::string spaces_str(std::string str);
bool is_spam(std::string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Пробелы в строке
	std::cout << "Task 1.\nEnter a string -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";

	// Задача 2. Блокировка спама
	std::cout << "Task 2.\nEnter a string -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спама не обнаружено!\n\n";

	// Задача 3. URL страница
	std::cout << "Task 3.\nURL-adress: ";
	std::string URL = "https://vk.com/home/music";
	std::cout << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find('/', domen_index) + 1;
	std::string protocol = URL.substr(0, domen_index - 3);
	std::string domen = URL.substr(domen_index, path_index - domen_index - 1);
	std::string path = URL.substr(path_index);
	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Доменное имя: " << domen << std::endl;
	std::cout << "Страница: " << path << std::endl;

	return 0;
}

std::string spaces_str(std::string str) {
	for (short i = str.length() - 1; i > 0; i--)
		str.insert(i, " ");
	return str;
}

bool is_spam(std::string str) {
	// Приведение строки к нижнему регистру для осуществеления неригистрозависимости
	for (short i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	const short spams_number = 4;
	std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};
	for (short i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true;
	return false;
}
#include <iostream> 
#include <Windows.h> 
#include <cstdlib> 
#include <fstream> 
#include <vector> 

using namespace std;

int proverka(int a)
{
	while (cin.fail() || a < 0 ||  a > 1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}

	return a;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::cin;
	using std::string;

	int num1, num2, num3, num4, num5, num6, num7, num8;

	ofstream out;
	out.open("questions.txt");

	ofstream bebe;
	bebe.open("questions1.txt");

	vector <bool> answer;

	cout << "Вы любите кошек? (1 - да, 0 - нет)";
	cin >> num1;
	num1 = proverka(num1);
	answer.push_back(num1);
	out << num1;

	cout << "Вас зовут Михаил? (1 - да, 0 - нет)";
	cin >> num2;
	num2 = proverka(num2);
	answer.push_back(num1);
	out << num2;

	cout << "Да? (1 - да, 0 - нет)";
	cin >> num3;
	num3 = proverka(num3);
	answer.push_back(num1);
	out << num3;

	cout << "Отпускаем группу? (1 - да, 0 - да)";
	cin >> num4;
	num4 = proverka(num4);
	answer.push_back(num1);
	out << num4;

	cout << "Никифор успеет сдать все вопросы до конца семестра? (1 - да, 0 - нет)";
	cin >> num5;
	num5 = proverka(num5);
	answer.push_back(num1);
	out << num5;

	cout << "Вам нравится ваше место работы/учёбы? (1 - да, 0 - нет)";
	cin >> num6;
	num6 = proverka(num6);
	answer.push_back(num1);
	out << num6;

	cout << "Вы любите играть в комп. игры? (1 - да, 0 - нет)";
	cin >> num7;
	num7 = proverka(num7);
	answer.push_back(num1);
	out << num7;

	cout << "В конце 4 курса будете отмечать с нами выпуск? (1 - да, 0 - нет)";
	cin >> num8;
	num8 = proverka(num8);
	answer.push_back(num1);
	out << num8;

	for (int i = 0; i < 8; i++) {
		bebe << answer[i];
	}


	system("pause");
	return 0;
}
#include <iostream> 
#include <Windows.h> 
#include <cstdlib> 
#include <fstream> 
#include <vector> 
#include <string>
#include <cmath>

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
	const int n = 8;

	ofstream out;
	out.open("questions.txt");

	vector <int> answer;

	cout << "Вы любите кошек? (1 - да, 0 - нет)";
	cin >> num1;
	num1 = proverka(num1);
	answer.push_back(num1);


	cout << "Вас зовут Михаил? (1 - да, 0 - нет)";
	cin >> num2;
	num2 = proverka(num2);
	answer.push_back(num2);


	cout << "Да? (1 - да, 0 - нет)";
	cin >> num3;
	num3 = proverka(num3);
	answer.push_back(num3);


	cout << "Отпускаем группу? (1 - да, 0 - да)";
	cin >> num4;
	num4 = proverka(num4);
	answer.push_back(num4);


	cout << "Никифор успеет сдать все вопросы до конца семестра? (1 - да, 0 - нет)";
	cin >> num5;
	num5 = proverka(num5);
	answer.push_back(num5);


	cout << "Вам нравится ваше место работы/учёбы? (1 - да, 0 - нет)";
	cin >> num6;
	num6 = proverka(num6);
	answer.push_back(num6);


	cout << "Вы любите играть в комп. игры? (1 - да, 0 - нет)";
	cin >> num7;
	num7 = proverka(num7);
	answer.push_back(num7);


	cout << "В конце 4 курса будете отмечать с нами выпуск? (1 - да, 0 - нет)";
	cin >> num8;
	num8 = proverka(num8);
	answer.push_back(num8);

	
	int perevod = 0;
	int degree = 0;

	for (int i = 7; i >= 0; i--) {
		perevod += answer[i] * (pow(2,degree));
		degree++;
	}
	
	char ascii = perevod;
	out << ascii;

	out.close();

	int a = 1;
	char ascii2[250];

	ifstream ofile("questions.txt");
	if (ofile.is_open()) {
		ofile >> ascii2;
		cout << ascii2;
	}
	


	system("pause");
	return 0;
}
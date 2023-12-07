#include <iostream> 
#include <Windows.h> 
#include <cstdlib> 
#include <fstream> 
#include <vector> 
#include <string>
#include <cmath>
#include <algorithm>

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

int proverka2(int a)
{
	while (cin.fail() || a < 1 || a > 8)
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

	int izmen = 0;

	cout << "Вы хотите изменить ответы на вопросы или просто ответить на них? (1 - изменить, 0 - ответить)";
	cin >> izmen;
	if (izmen == 0) {

	perehod:


		int num1, num2, num3, num4, num5, num6, num7, num8;
		const int n = 8;


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


		cout << "Отпускаем группу с ваших(-ей) пар(-ы)? (1 - да, 0 - да)";
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

		ofstream out;
		out.open("questions.txt");

		int perevod = 0;
		int degree = 0;

		for (int i = 7; i >= 0; i--) {
			perevod += answer[i] * (pow(2, degree));
			degree++;
		}

		char ascii = perevod;
		out << ascii;

		out.close();
	}
	else {
		char ascii2;

		ifstream ofile("questions.txt");
		if (!ofile.is_open()) {
			cout << "Вы ещё не ответили на вопросы:";
			cout << endl;
			goto perehod;
		}
		else {
			ofile >> ascii2;
		}

		int num = int(ascii2);

		if (num < 0) {
			num += 256;
		}

		vector <int> answers;

		while (num > 0) {
			answers.push_back(num % 2);
			num = num / 2;
		}

		reverse(answers.begin(), answers.end());

		int numques;
		
		cout << "На какой вопрос вы бы хотели изменить ответ? (Введите номер вопроса)";
		cin >> numques;
		numques = proverka2(numques);
		cout << "Введите новый ответ на вопрос:";
		int newans;
		cin >> newans;
		newans = proverka(newans);
		answers[numques-1] = newans;
	}



	system("pause");
	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void task1();
void task2();
void task3();
void task4();

int sum_between_min(int*, int);
int number_sum(int*, int);
int* create_array(int);

void filling_array(int*, int);
void check_input(int);
void bubbleSort(int*, int);
void print_array(int*, int);

bool last_and_first(int*, int);

int main()
{
	int number_of_task;

	cout << "List of tasks:\n";
	cout << "\tTask 1 \n";
	cout << "\tTask 2 \n";
	cout << "\tTask 3 \n";
	cout << "\tTask 4 \n";

	cin >> number_of_task;
	system("clear");

	switch (number_of_task)
	{
	case 1:
	{
		task1();
		break;
	}
	case 2:
	{
		task2();
		break;
	}
	case 3:
	{
		task3();
		break;
	}
	case 4:
	{
		task4();
		break;
	}
	default:
	{
		cout << "Invalid input" << endl;
	}
	}



	return 0;
}

//The program evaluates the expression using various loops in its implementation
void task1()
{
	const double I = 0.1, a = 2.3, change_x = 0.2;
	double x0 = 0.2, xn = 2.8, x = x0;
	int r = 0;

	cout << "Choose which loop to use:\n1.While\n2.do while\n3.for" << endl;
	cin >> r;

	switch (r)
	{
	case 1:
	{
		while (x >= x0 && x <= xn)
		{
			x = x + I * change_x;

			if (x < 1) { cout << 1.5 * pow(cos(x), 2) << endl; }
			else if (x == 1) { cout << 1.8 * a * x << endl; }
			else if (1 < x < 2) { cout << pow((x - 2), 2) + 6 << endl; }
			else cout << 3 * tan(x);
		}
	}
	break;
	case 2:
	{
		do {
			x = x + I * change_x;

			if (x < 1) { cout << 1.5 * pow(cos(x), 2) << endl; }
			else if (x == 1) { cout << 1.8 * a * x << endl; }
			else if (1 < x < 2) { cout << pow((x - 2), 2) + 6 << endl; }
			else cout << 3 * tan(x) << endl;
		} while (x >= x0 && x <= xn);
	}
	break;
	case 3:
	{
		for (x; x >= x0 && x <= xn; x = x + I * change_x)
		{
			if (x < 1) { cout << 1.5 * pow(cos(x), 2) << endl; }
			else if (x == 1) { cout << 1.8 * a * x << endl; }
			else if (1 < x < 2) { cout << pow((x - 2), 2) + 6 << endl; }
			else cout << 3 * tan(x) << endl;
		}
	}
	break;
	case 4: { cout << "Something is wrong with the numbers"; }
	}
}

void task2()
{
	int n;

	cout << "Select job number \n1\n2\n3\n4" << endl;
	cin >> n;


	switch (n)
	{
	case 1:
	{
		cout << "Select number n" << endl;
		cin >> n;
		cout << "Three-digit numbers are the sum of the digits that equal " << n << ":" << endl;

		for (int i = 101; i < 1000; i++)
		{
			if (i / 100 + i % 10 + ((i % 100) / 10) == n)
			{
				cout << i << endl;;
			}
		}
	}
	case 2:
	{
		cout << "Pairs of two-digit numbers:" << endl;

		int first_number = 10, second_number = 10;

		while (first_number != 100)
		{
			if ((first_number * 100 + second_number) % (first_number * second_number) == 0)
			{
				cout << first_number << " and " << second_number << endl;
				++second_number;
			}
			else
			{
				++second_number;
			}

			if (second_number == 100)
			{
				++first_number;
				second_number = 10;
			}

		}
	}
	case 3:
	{
		for (int i = 102; i != 1000; i++)
		{
			if ((i / 100) != (i % 10) && ((i % 100) / 10) != (i / 100) && ((i % 100) / 10) != (i % 10))
			{
				cout << i << endl;
			}
		}
	}
	case 4:
	{
		int m = 11, n = 11, changed_m, changed_n;

		while (m != 100)
		{
			changed_m = m / 10 + (m % 10) * 10;
			changed_n = n / 10 + (n % 10) * 10;

			if (m * n == changed_m * changed_n)
			{
				cout << m << " и " << n << endl;
				n++;
			}
			else { n++; }

			if (n == 100)
			{
				n = 11;
				m++;
			}
		}
	}
	}
}

void task3()
{
	int size, sum = 0;
	int* array;

	cout << "Enter the number of array elements(Integer)." << endl;
	cin >> size;
	check_input(size);

	array = create_array(size);
	filling_array(array, size);

	sum += sum_between_min(array, size);
	cout << sum;

	print_array(array, size);

	delete array;
}

void task4()
{
	int size;
	int* array;

	srand(time(NULL));

	size = rand() % 100;
	array = create_array(size);
	filling_array(array, size);
	bubbleSort(array, size);
	print_array(array, size);

	delete array;
}

void filling_array(int* array, int size)
{
	cout << "Enter values ​​to populate the array." << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int* create_array(int size)
{
	int* array = new int[size];
	return array;
}

void check_input(int a)
{
	if (a == 0)
	{
		cout << "Invalid input";
		exit(EXIT_SUCCESS);
	}
}

int sum_between_min(int* array, int  size)
{
	int min1 = 0, min2 = 1;
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[min1] > array[i] && last_and_first(array, min1)) min1 = i;
	}

	for (int i = 0; i < size; i++)
	{
		if ((array[min2] > array[i]) && (i != min1) && last_and_first(array, min2)) min2 = i;
	}

	if (min1 < min2)
	{
		while (min1 < --min2)
		{
			sum += array[min2];
		}
	}
	else {
		while (--min1 > min2)
		{
			sum += array[min1];
		}
	}

	return sum;
}

bool last_and_first(int* array, int a)
{
	int n = array[a] / 100;

	if ((n == array[a] % 10) && (n != 0)) return true;
	else return false;
}


int number_sum(int* array, int number)
{
	int sum = 0, n = array[number];

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

void bubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}

}

void print_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}
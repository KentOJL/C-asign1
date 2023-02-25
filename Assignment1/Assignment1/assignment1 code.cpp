#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a1, a2, a3, a0, b2, b1, b0 , delta, x1, x2, y1, y2, r, s, m, t, num_solution;
	cout << "Please enter your a3: ";
	cin >> a3;
	cout << endl;
	cout << "Please enter your a2: ";
	cin >> a2;
	cout << endl;
	cout << "Please enter your a1: ";
	cin >> a1;
	cout << endl;
	cout << "Please enter your a0: ";
	cin >> a0;
	cout << endl;

	if (a3 <= 0)
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	else
	{
		b2 = a3 * 3;
		b1 = a2 * 2;
		b0 = a1;

		delta = pow(b1, 2) - (4 * (long long)b2 * (long long)b0);

		if (delta < 0)
		{
			num_solution = 1;
		}

		else
		{
			x1 = ((-b1) - sqrt(delta)) / (2 * (long long)b2);
			x2 = ((-b1) + sqrt(delta)) / (2 * (long long)b2);
			y1 = ((a3)*pow(x1, 3)) + ((a2)*pow(x1, 2)) + (long long)a1 * x1 + a0;
			y2 = ((a3)*pow(x2, 3)) + ((a2)*pow(x2, 2)) + (long long)a1 * x2 + a0;

			if (y1 > 0 && y2 > 0)
				num_solution = 1;
			else if (y1 < 0 && y2 < 0)
				num_solution = 1;
			else if (y1 == 0 || y2 == 0)
				num_solution = 2;
			else if (y1 == 0 && y2 == 0)
			{
				cout << "Precison error" << endl;
				return 0;
			}
			else if (y1 > 0 && y2 < 0)
				num_solution = 3;
			else if (y1 < 0 && y2 > 0)
				num_solution = 3;
		}

		cout << num_solution << endl;

		if (num_solution == 1)
		{
			s = 1;
			while (((a3)*pow(s, 3)) + ((a2)*pow(s, 2)) + (long long)a1 * s + a0 <= 0)
				s = 2 * s;

			r = -1;
			while (((a3)*pow(r, 3)) + ((a2)*pow(r, 2)) + (long long)a1 * r + a0 >= 0)
				r = 2 * r;


			double y_m;
			bool stop = false;
			while (stop == false)
			{
				m = (r + s) / 2;
				y_m = ((a3)*pow(m, 3)) + ((a2)*pow(m, 2)) + (long long)a1 * m + a0;
				if (y_m == 0 || sqrt(pow((s - r), 2)) < 0.000001)
				{
					t = static_cast<double>(m);
					cout << fixed << setprecision(6);
					cout << t << endl;
					stop = true;
				}

				else if (y_m > 0)
					s = m;

				else if (y_m < 0)
					r = m;
			}

		}
	}
	system("Pause");
	return 0;
}
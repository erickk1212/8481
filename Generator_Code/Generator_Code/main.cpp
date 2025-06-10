#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
using ull = unsigned long long;
#define num 9099099909999099999

void c1()
{
	string s = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make matters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and flees to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 100 000, 0 500 000 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 100 000) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 11 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
	int len = s.size(), sum = -1, cur = 2932;
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
			for (int j = 0; j < cur; j++)
				cout << s[0];
		else
		{
			cur += sum;
			while (cur <= 0)
				cur += 2932;
			for (int j = 0; j < cur; j++)
				cout << s[i];
			sum -= 2;
		}
	}
}

void c2()
{
	ull a = 0, b = 1;
	for (int i = 0; i < 10000; i++)
	{
		cout << b;
		ull c = (a + b) % num;
		a = b;
		b = c;
		cout << ", ";
	}
	cout << "0.";
}

void c3()
{
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024 - i; j++)
		{
			if (i == 506 && j == 449) cout << ".####..##..##.######..##...##..##.....####...####..###..####.";
			if (i == 507 && j == 449) cout << "##..##.###.##...##...####..##.##.....##..##.##..##..##.##..##";
			if (i == 508 && j == 449) cout << "##..##.##.###...##..##..##.####.........##..##..##..##.##..##";
			if (i == 509 && j == 449) cout << "##..##.##..##...##..######.##.##......##....##..##..##.##..##";
			if (i == 510 && j == 449) cout << ".####..##..##...##..##..##.##..##....######..####...##..####.";
			if (i > 505 && i < 511 && j > 448 && j < 510)continue;
			cout << (i & j ? '.' : '#');
		}
		cout << '\n';
	}
}

bool xprime[400010];
void c4()
{
	int lntrck = 0;
	string s = to_string(num);
	for (int i = 2; i < 400002; i++)
	{
		if (i > 266649 && i < 266669) cout << s[i - 266650];
		else if (xprime[i]) cout << 1;
		else cout << 0;
		if (!xprime[i])
		{
			for (long long j = (long long)i * i; j < 400002; j += i)
				xprime[j] = true;
		}
		lntrck++;
		if (lntrck == 80)
		{
			cout << '\n';
			lntrck = 0;
		}
	}
}

// TODO
void c5()
{

}

// TODO
void c6()
{

}

// TODO
void c7()
{

}

// TODO
void c8()
{

}

// TODO
void c9()
{

}

using mtrx = vector<vector<int>>;
mtrx mtrxmlt(const mtrx& A, const mtrx& B)
{
	int n = A.size();
	mtrx res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			if (A[i][k])
				for (int j = 0; j < n; j++)
					res[i][j] ^= B[k][j];
	return res;
}
mtrx mtrxpow(mtrx base, long long pw = 9099099909999099999LL)
{
	int n = base.size();
	mtrx result(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		result[i][i] = 1;
	while (pw > 0)
	{
		if (pw % 2 == 1)
			result = mtrxmlt(result, base);
		base = mtrxmlt(base, base);
		pw /= 2;
	}
	return result;
}
mtrx ct(const vector<int>& flat, int n)
{
	mtrx A(n, vector<int>(n, 0));
	for (int i = 0; i < n * n; ++i)
		A[i / n][i % n] = flat[i];
	return mtrxpow(A);
}
void c10()
{
	cout << "a_i = a_{i-1} . a_{i-2}\n\na_1 = 0\n\na_2 = 0 1\n\n";
	vector<int> p = { 0 };
	vector<int> c = { 0, 1 };
	for (int i = 3; i < 20; i++)
	{
		vector<int> x = c;
		x.insert(x.end(), p.begin(), p.end());
		if (i < 16)
		{
			cout << "a_" << i << " = ";
			for (int j = 0; j < x.size(); j++)
			{
				cout << x[j];
				if (j != x.size() - 1) cout << " ";
				if ((j + 1) % 40 == 0 && j != x.size() - 1)
					if (i > 9)
						cout << "\n       ";
					else
						cout << "\n      ";
			}
			cout << "\n\n";
		}
		p = c;
		c = x;
	}
	vector<int>a = c;
	cout << "\n(A_i)^n = B_i (mod 2)\n\n";
	for (int i = 1; i < 71; i++)
	{
		mtrx b = ct(a, i);
		for (int x = 0; x < i; x++)
		{
			if (x == i / 2)
			{
				cout << "A_" << i << " = ";
			}
			else if (i > 9)
			{
				cout << "       ";
			}
			else
			{
				cout << "      ";
			}
			for (int y = 0; y < i; y++)
			{
				cout << a[x * i + y] << " ";
			}
			if (x == i / 2)
			{
				cout << "  B_" << i << " = ";
			}
			else if (i > 9)
			{
				cout << "         ";
			}
			else
			{
				cout << "        ";
			}
			for (int y = 0; y < i; y++)
			{
				cout << b[x][y];
				if (y < i - 1)cout << " ";
			}
			cout << '\n';
		}
		if (i < 70)cout << '\n';
	}
}

int main()
{
	int n;
	cin >> n;
	switch (n)
	{
	case 0:
		cout << "ONTAK 2010";
		break;
	case 1:
		c1();
		break;
	case 2:
		c2();
		break;
	case 3:
		c3();
		break;
	case 4:
		c4();
		break;
	case 5:
		c5();
		break;
	case 6:
		c6();
		break;
	case 7:
		c7();
		break;
	case 8:
		c8();
		break;
	case 9:
		c9();
		break;
	case 10:
		c10();
	}
	return 0;
}
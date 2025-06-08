#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
using ull = unsigned long long;

// TODO
void c1()
{

}

void c2()
{
	ull a = 0, b = 1;
	for (int i = 0; i < 10000; i++)
	{
		cout << b;
		ull c = (a + b) % 9099099909999099999;
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

// TODO
void c4()
{

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
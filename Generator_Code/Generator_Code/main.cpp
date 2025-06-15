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

void c5()
{
	string mon[12] = { "stycznia","lutego","marca","kwietnia","maja","czerwca","lipca","sierpnia","wrzesnia","pazdziernika","listopada","grudnia" };
	string one[20] = { "","pierwszy","drugi","trzeci","czwarty","piaty","szosty","siodmy","osmy","dziewiaty","dziesiaty","jedenasty","dwunasty","trzynasty","czternasty","pietnasty","szesnasty","siedemnasty","osiemnasty","dziewietnasty" };
	string ten[10] = { "","","dwudziesty","trzydziesty","czterdziesty","piecdziesiaty","szescdziesiaty","siedemdziesiaty","osiemdziesiaty","dziewiecdziesiaty" };
	string huns[4] = { "","setny","dwusetny","trzysetny" };
	string hunb[4] = { "","sto ","dwiescie ","trzysta " };
	string year[21] = { "dwutysiecznego","pierwszego","drugiego","trzeciego","czwartego","piatego","szostego","siodmego","osmego","dziewiatego",
		"dziesiatego","jedenastego","dwunastego","trzynastego","czternastego","pietnastego","szesnastego","siedemnastego","osiemnastego","dziewietnastego","dwudziestego" };
	for (int y = 0; y < 21; y++)
	{
		int cnt = 0;
		for (int m = 0; m < 12; m++)
		{
			int k;
			if (y % 4 == 0 && m == 1) k = 29;
			else if (m == 1) k = 28;
			else if (m == 3 || m == 5 || m == 8 || m == 10) k = 30;
			else k = 31;
			for (int d = 1; d <= k; d++)
			{
				++cnt;
				if (y == 7 && m == 3 && d == 1) { cout << "Pierwszego kwietnia jest prima aprilis.\n"; continue; }
				if (y == 13 && m == 5 && d == 1) { cout << "Pierwszego czerwca jest dzien dziecka.\n"; continue; }
				if (d < 20)
				{
					one[d][0] -= 32;
					cout << one[d];
					one[d][0] += 32;
				}
				else
				{
					ten[d / 10][0] -= 32;
					cout << ten[d / 10];
					ten[d / 10][0] += 32;
					if (d % 10) cout << " " << one[d % 10];
				}
				cout << ' ' << mon[m] << " to ";
				if (cnt % 100)
				{
					cout << hunb[cnt / 100];
					int t = cnt % 100;
					if (t < 20) cout << one[t];
					else
					{
						cout << ten[t / 10];
						if (t % 10) cout << " " << one[t % 10];
					}
				}
				else cout << huns[cnt / 100];
				cout << " dzien roku " << (y ? "dwa tysiace " : "") << year[y] << ".\n";
			}
		}
	}
	cout << "Koniec.";
}

const long long fact[21] = {
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800,
	39916800, 479001600, 6227020800, 87178291200, 1307674368000,
	20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000
};
void getT(ull n, vector<char>& chars, string& result)
{
	if (chars.empty()) return;
	int k = chars.size();
	ull f = fact[k - 1];
	ull i = n / f;
	result += chars[i];
	chars.erase(chars.begin() + i);
	getT(n % f, chars, result);
}
void c6()
{
	for (ull i = 1; i <= 20000; ++i)
	{
		ull n = i * i * i * i;
		ull t = n - 1;
		int k = 1;
		if (i == 10000)
		{
			cout << "T[" << n << "]=\"" << num << "\"\n";
			continue;
		}
		while (t >= fact[k])
		{
			t -= fact[k];
			k++;
		}
		vector<char> s;
		for (int j = 0; j < k; j++) s.push_back('a' + j);
		string res;
		getT(t, s, res);
		cout << "T[" << n << "]=\"" << res << "\"\n";
	}
}

void p0(int n)
{
	string s[5] = { ".####.","##..##","##..##","##..##",".####." };
	cout << s[n];
}
void p1(int n)
{
	string s[5] = { "###",".##",".##",".##",".##" };
	cout << s[n];
}
void p2(int n)
{
	string s[5] = { ".####.","##..##","...##.",".##...","######" };
	cout << s[n];
}
void p9(int n)
{
	string s[5] = { ".####.","##..##",".#####","....##",".####." };
	cout << s[n];
}
void pcm(int n)
{
	string s[5] = { ".......",".......",".......",".##....","..#...." };
	cout << s[n];
}
void pprd(int n)
{
	string s[5] = { "...","...","...",".##",".##" };
	cout << s[n];
}
void fill_line(int n)
{
	for (int i = 0; i < 1000 - n; ++i)
		cout << ".";
	cout << "\n";
}
void c7()
{
	int n = 0;
	string s = "1";
	vector<pair<string, int>> v;
	for (int i = 0; i <= 170; ++i)
	{
		int sum = 0;
		for (char c : s)
		{
			if (c == '1')
			{
				sum += 4;
			}
			if (c == '2')
			{
				sum += 7;
			}
			if (c == '0')
			{
				sum += 7;
			}
		}
		sum += 6;
		v.push_back({ s,sum });
		string s2;
		int carry = 0;
		for (char c : s)
		{
			s2.push_back((((c - '0') * 2 + carry) % 3) + '0');
			carry = ((c - '0') * 2 + carry) / 3;
		}
		if (carry > 0) s2.push_back(carry + '0');
		s = s2;
	}
	v.push_back({ "0.",9 });
	int j = 0;
	for (int i = 0; i < 171; ++i)
	{
		if (n + v[i].second > 1000)
		{
			for (int k = 0; k < 5; ++k)
			{
				for (int l = j; l < i; ++l)
				{
					int size = v[l].first.size();
					for (int m = 0; m < size; ++m)
					{
						char c = v[l].first[m];
						if (c == '0')
						{
							p0(k);
						}
						if (c == '1')
						{
							p1(k);
						}
						if (c == '2')
						{
							p2(k);
						}
						if (m != size - 1)
							cout << ".";
					}
					pcm(k);
				}
				fill_line(n);
			}
			n = 0;
			fill_line(n);
			j = i;
		}
		n += v[i].second;
	}
	n += 10;
	for (int k = 0; k < 5; ++k)
	{
		int size = v[170].first.size();
		for (int l = 0; l < size; ++l)
		{
			char c = v[170].first[l];
			if (c == '0')
			{
				p0(k);
			}
			if (c == '1')
			{
				p1(k);
			}
			if (c == '2')
			{
				p2(k);
			}
			if (c == '.')
			{
				pprd(k);
			}
			if (l != size - 1)
				cout << ".";
		}
		pcm(k);
		for (char c : v[171].first)
		{
			if (c == '0')
			{
				p0(k);
			}
			if (c == '1')
			{
				p1(k);
			}
			if (c == '2')
			{
				p2(k);
			}
			if (c == '.')
			{
				pprd(k);
			}
		}
		cout << ".";
		fill_line(n);
	}
	fill_line(0);
	fill_line(0);
	n = 0;
	string S[4] = {
		"01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200",
		"120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201",
		"0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010909909990999909999902010200120012",
		"0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001"
	};
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 5; ++k)
		{
			for (int j = 0; j < S[i].size(); ++j)
			{
				char c = S[i][j];
				if (c == '0')
				{
					p0(k);
					if (k == 0) n += 6;
				}
				if (c == '1')
				{
					p1(k);
					if (k == 0) n += 3;
				}
				if (c == '2')
				{
					p2(k);
					if (k == 0) n += 6;
				}
				if (c == '9')
				{
					p9(k);
					if (k == 0) n += 6;
				}
				cout << ".";
				if (k == 0) n += 1;
			}
			fill_line(n);
		}
		n = 0;
		if (i != 3) fill_line(n);
	}
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
mtrx mtrxpow(mtrx base, long long pw = num)
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
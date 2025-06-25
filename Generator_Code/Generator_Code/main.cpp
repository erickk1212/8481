#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<unordered_map>
using namespace std;
using ull = unsigned long long;
bool map[1003][1003];
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

unordered_map<char, string> deckey;
int chnum;
void decode(string s, int lvl)
{
	if (lvl == 2)
	{
		deckey[static_cast<char>(chnum + 32)] = s;
		++chnum;
		return;
	}
	decode(s + "1", lvl + 1);
	decode(s + "2", lvl + 1);
	decode(s + "3", lvl + 1);
	decode(s + "4", lvl + 1);
	decode(s + "5", lvl + 1);
	decode(s + "6", lvl + 1);
	decode(s + "7", lvl + 1);
	decode(s + "8", lvl + 1);
}
void c8()
{
	string enc = R"(_NM;;88 !()*)*1224BDDDDD\\\___^WV^VVVVUVNNMUMMM===;=;;;;8;8;## 8    ((()!))!))*))1)1112*22222BBBD4BDDDDDDDDGDGD\\\_G_G___W^^^^^WVV^VW_WVVMMMKMVVVWVVVUUKK;;;;MMNUUUUM;8;# 8;;=KM=KK;;   ! (#;;;;;;88 )!)))))   8#  )))12**1))!(((()))2*2BBBB21)1))1)222DDDD\DBD2222244DDGGG_G\\DDBDBDBDD\G__^^WWW__GD\GD_G_^VVVVNVVVV^^__W_WVWUVUNMMMUNVNV^VVVVVVNMMM=;=;KKMMMUUUUMMM;;;;8;8;;%;;KM====;K;8;#     ##8;;;;;#;8;   ()!)()(((   #    ()))1)1**)*))()!(()!)!))1*122222B2**)*))1)111224BDBDDDBDBBB422222B4BDDD\GD\\\\GDDDDDBDBDDDDDD\G____^_W___GGD\\GGG\__WV^VVVVV^VVV^^^_^_^_WWVWVVUVNUNNMUUUVUVVVVV^VVVVNVNNMMMKKKKM==MMMUNNNNMNMM==;=;;;8;;;;;;=;KKKKKKKK=;;K#;8888# 8 8888;;8;;;;;#;8888   ((()!!((!     8     )!))))))*))*))))()()!(()!)!)))*)***2*22212*1**)*))1)1*)12*22444BD4D4BD44422222B22B44BDDDDDDGDGD\D\DGDDBDDBDD4DBDDDDGDGGG\_________GGGGD\GGD\_G_G_^^^WVWVV^VV^V^^WW^_W_^_W^^^WVVVVVVUVNUUVNNUVNVVVVVVVVVVVVVVVUVNNNMMMMMKM=MMMMMNMUUUUNMUMMMKKK=;;K;;;;;K;;=;==;KM======;K=;;;;;#;##888#####8;#;8;;;;;8;;;8;8888#    (!!! ((!      8#      !!())!)))))))))))))()()!()!!()!)!)))))*)1**112*12*11111*)*))1)*)*)1***1222244444BBBBBBB4222222224244444D4DDDDDDGDDD\DDDDDDDDD4DBDBDBDDD4DDGDD\GGGGG_G__\__G_GGGGD\\GD\GGD\_GG____W^^WV^WV^WV^WWWWW^_W_^_^_^^^^^^V^VVVVVVUVVNUVUVUVVUVVVVVVVWVVVVVVVVVVVNVNNNMUMUMMMMMMMMMNMUUNNNNNNNMUMUMMM=KK=;K=;;K;=;;K;K=;KKKKKKM==KKKK=;K;K;;;;;#;8;#8;##88;#;#;#;;8;;;;;;;;8;;;#8;### 8      ( ( !     # 8# # #     (((()()())))!))))())()()!()!!!(()!()!)!))))))1)1*)11111111111**)*)*))1))1)*)*)*)1112*22222442BB442B42422222222222242BBBD4BDDD4DDDDDDDGDDDBDDDDBDBDBDBDBDBDBDDDDDDDDD\GD\\G\\_GG_G\\_GGGGGD\\GDGD\GD\GGGGGG_G____W^^^^^^WWWWWWWWW^_^__W__W_^_W^^^^^V^V^VVVVVVVUVVVUVVVNVVVVVVVVV^VVV^VVV^VVVVVVNVUVNUUUUUNMMUMMUMMUMUNMUUUUUUUUVNNNMUUMUMMMMKM==;KK=;K=;K=;K=;KKKKKM==KM=KKM====;K=;;K;;;;;;;#;8;8;8;8;8;8;;8;;;;;;;;;;;;;;;#;;;#;#8;### 8#             # # 8## 8# 8#       (((()!()!)())!)())!)!()!()!!!!!((((()!()!)!))))))))*))1*)1*)11**)1*)1*))1)*)))*)))1))1)*)**)1112*2*222224242B24224222222*22*2222222B4444BD4D4DBDDDD4DDDDDBDDD4DBDBDBD4BD4BDBD4DBDDBDDDDDGDDGD\GD\\\GG\\\\\\\\\GGD\GD\GDGDGDGD\D\\GGGGGG\_______W^_WW^^^_WW^_W_W__W_____^__^_W^^^^^WV^V^VV^VVVVVVVVVVVUVVVVWVVVVV^VV^VV^VWVVV^VVVVVVVVUVVNVNNUUUUUNMUNMUNMUNMUUUUUUUUVNNUUVNNNNNNNMUNMMMMMMKM========;KKK=====KKM=KM=KMKM=KM=KKKKK=;K=;;K;;;;;;;;;8;;;#;;8;;;#;;;;;;;;;;;;;;;=;;;;;;8;;;8;8;8;#### 8# 8 #   #  #  8# 8## 888### 88# #       (!!!!!(()!()!)!()!()!()!!!!!!!!!!!!!!!!!!!()!)!))!))))))*))*))1)1)1*)*)*)*))1))1)))*))))))1)))*))*)*)1*)1112*121222222222222222222*21212*212222222242BBBD44BDBD4DBDD4DD4DBDD4D4D4BD4BD4BBD4BBD4BD4D4D4DDD4DDDD\DDGDGDGD\GD\\GGD\\GGD\GD\GDGDGDD\DGDD\D\D\D\GD\GGGGG\_G________^_^_^_W_W_^______________^__W_W^^^^^WWVWVWVV^VVV^VVVVVV^VVVVV^VVWVVWVWVV^V^V^V^VWVVWVVVVVVVVVVNVUVUVNNUUUUUUUUUUUNNNNNNNNUUVNNUVNUVNUVNNUUVNNNNNMUNMMMMMMMMKM==KKM====KKKM=KKMKMKMKMM=MKMKMKM=KKKKKKK=;K;K;;K;;;;;;;;;;;;;;;;#;;;;;;;;;K;;;;=;;;;K;;;;;K;;;;#;;;8;;#8;#88;# 888# 8# # 8# # 88## 888888888888888## 8 8       ! (((((((()!!!(()!!!!((((!!! ((!! ((!! (((()!!()!)!)())))))))))))1))*))*))*))*)))*)))))))*)))))))))))))*)))1)1)1*)11***112*2*22*222*222122121212*12*12*12*2*2*222222242BBBBBBBD4BD4BD4D4D4BDBD4BD4BBD44BBBD44444BBBD4BD4BDBDBDDDD4DDDD\DDD\DGDD\D\GDGD\GDGD\D\D\DGDD\DD\DDGDDD\DD\DGDD\D\GD\\GGGG\\_G_\___________W_____________\___G_______^_^^_WWWWV^WV^WVWVV^VWVVWVVWVVWVVWVV^V^V^WVWV^WVWV^WVWVWVWVV^VVVWVVVVNVVVUVVNVNUVNUVNNUUUVNNNUUVNNUVNNVNUVNVNUVUVNVNUVUVNNUUVNNNMUUNMNMMMMMMMMKMKM=KMKM=KMKMKMKMMM=MMMM=MMMKMM=M=KM======;KK;K=;;K;;=;;;;;K;;;;;;;;;;K;;;;=;;;=;;=;;=;;=;;=;;;=;;;;;;;;;;;#;;#;#;#8;###8888#### 888#### 88888;####88;###888;##### 8# 8#        ! (! ((!!!!!!! (((((!! (!! ( (! ( (! (!! (((!((()!()!)!)()))()))))))))*))))))1)))))))))1))!))))))))))))!)))))*)))))1))1)1)1**)111112**12*1212121212*2*12**112**1112***112*1212122222222B42BBB44BBBBD44BBD4BBD44BBBD444444444442BBBBBBBBD44BBDBD4D4DBDDDDBDDDD\DDDDGDDGDDGDD\DGDD\DD\DD\DDGDDDDGDDDDDD\DDDD\DDD\DGDD\D\GD\\GGGGG\\_G_G_\___\_______\___\__\_\_\_\_\__G_\____G____W^_^^^_WWV^^WWV^WVWV^V^V^V^V^WVWVWV^WV^WV^WV^^WV^^WV^^WV^V^WVWVV^VV^VVVVVVVVVVNVVUVVNVNUVUVNUVUVNUVNUVNVNUVUVUVUVVNVUVUVVNVUVUVUVUVNUVNNUUUUUUNNMNMNMMMMMMMMMMMKMMKMMM=MMMMMKMMMMMMMMMMMMMMMM=M=KM==KKK===;K=;=;K;=;;K;;K;;=;;;=;;;K;;K;;K;=;;K;K;=;=;=;=;=;;K;;K;;=;;;;;;;;;;;8;;8;8;8;8;#88;###8888;#####888;###8;##8;#8;#8;#88;#88;##888888## 8 8  8      ( (! ! (! ((! (! ( (! ! !  ( !  ( ! ! ! (!! ((((()!!()!)!)!))!))()))))))))()))))))))))))))()))))!)))())))!)))))!)))))))*))))1))1)1*)**)11*******1112**12**112***1111111111111111111112**11212*22*222222B2B42B44442BBBBBBBBBBBBBBBBBB4442BB42BB442BB4442BBBBD44BBD4D4BDD4DD4DDDDDDDDDDDDDDD\DDDDGDDDD\DDDDD\DDDDDDDDDDDDDDDD\DDDDDDDDD\DDD\DD\D\D\GD\\GGGGGGGG\_G\_G_G_G_\_\__G_G_G_G\_\_G\_GG\_G\_G\_\_\_\_________^_^_WWW^^^^WWWV^^WWV^WV^WV^^WV^^WV^^WWWV^^^^^WWWWWV^^^WWV^WWV^V^V^V^VV^VVVVWVVVUVVVVVUVVVNVUVVNVUVUVUVVNVNVUVVNVVNVVNVVUVVVNVVUVVVNVVNVUVUVUVUVNUUVNNNNNNNMUNMUMUMMNMMMMMMMMMMMMMMMNMMMMNMMMUMMUMMNMMMMMMMMMMM=M=KM========;K=;K=;K;K=;;K;K;K;=;=;=;;K;K=;=;=;K=;=;K=;K=;=;K=;=;=;=;;=;;=;;;;;;;;;;;;;#;;8;;#;#;#8;#8;#8;#8;#88;#8;#8;#8;8;#;#8;8;8;#;#;#8;8;#8;#88;###888## 8# 8 8           !  ( ! !  (  (  !    (     !   !  ( ( (! (((((((()!!()!)!)!)())!))()))())))())))!)))()))!))!))!))!)())())())()))())))))))))))))*))*))1)1)1*)1**)111***************)111111***)11**)11***)111********112*12122*22222222B2B42B42B442B442BB42BB42B42B4242B2B4242B42B42BB4442BD4444BD4BD4D4DBDDBDDDD4DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDBDDDDDDDDBDDDDDDDDDDDDDD\DDDGDDGDGDGDGD\GGD\\\\\\\\_GGG\_G\\_G\_G\_GG\_GG\\_GGG\\\\_GGG\\\_GG\_G\_G_G__G_______W_W_WW^^_WWWWWWWWWWWWV^^^^^WWWWWWWWWWWWW^^^^^^_WWWWWWWWWWWV^^WWV^WVWVWVWVVWVVVV^VVVVVVVVVNVVVVUVVVUVVVUVVVNVVVNVVVUVVVVVNVVVVVUVVVVVVUVVVVVNVVUVVUVVNVNVNUVNUUVNNNNNNNMUUNMNMUMUMNMMNMMNMMNMMNMMUMUMNMNMUMUMUMUMUMUMNMMMUMMMMMMMKMKM=KM===KKK===;KK==;K=;K=;K=;K=;=;K=;K=;KK=;KK=;KK==;KK=;KK=;K==;=;K=;=;;K;=;;=;;;;;;;;;;;;;;8;;;#;;#;8;8;8;8;8;8;8;8;8;8;8;8;;#;#;8;;#;8;;8;;#;#;8;8;8;8;8;#8;##888888888# 8# #  8    8           !                             ( (! (!!! (()!!!(()!()!)!)!)!)!)())!)())!)())()())!)!)()()()()()()()()()())!)())()))())))))))))))*)))*))1)1)1)1*)*)11*)1**)11*)11**)11*)1**)1*)1*)1*)1*)*)1**)1*)11**)11111112**12*2*2*22222222222422B2B2B4242424242422B2422422B22B2422B2B2B42B42BBBB44BBBD44BD4BDBDBDD4DD4DDBDDDD4DDDDDBDDDDDDBDDDDDBDDDDBDDDBDDDBDDDBDDDBDDDDD4DDDDDDDDDDDDDGDDDGDDGDGDGDGD\GGD\GGGGD\\\\\\\_GGGGGGG\\\\\\\\\\\\\\\\\GGGGGGGGGD\_GGGGGG\\_G\_\_\__\________W_W_W^_W^^_W^^^_WWW^^^_WWW^^^_WW^_WW^_WW^_W^_WW^^_WW^^^^^^^^^^WWV^WV^WVWVWVV^VVWVVVVWVVVVVVVVVVVVVVVNVVVVVVVVVUVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVUVVVVVUVVVNVVNVNVNVNUVNUUVNNNNNNNNNMUUNMUNMUNMUNMNMUNMNMUNMUNMUNMUUNMUUNMUNNMUNMUMUNMNMMNMMMMMMMMMMKMKM=KM==KKKKKKKKKK===;KKK===;KK===;KKKK======;KKKKKKKKK=====;KK==;K==;=;K=;=;;K;;K;;;K;;;;;;;;;;;;;#;;;8;;;8;;8;;8;;8;;8;;8;;8;;;#;;;#;;8;;;;#;;;#;;;#;;#;;#;;#;#;8;#;#8;#88;####8#### 8# 8# # #  #   8   #    8   8  #  #  #  8  8  8   8         ( ( (! ((!!!!!!!!(()!!()!()!()!)!()!)!)!()()!()()!()()!()!()!()!()!()!()()!)!()())!)()))!)))()))))))))1))))1))*))1)*)*)*)*)*)1)1*)1)1*)*)1)1*)*)1)1)1)1)1)1)1)1)1)1)1*)*)1*)1*)1**)111111112**12*122*22*2222222222222422242222B222224222222222422222B22B24242B42BB44444444BBD44BD4D4BDBDBDD4DBDDBDD4DDBDDBDDBDDBDDBDDBDD4DD4DBDD4DBDD4DBDD4DD4DD4DDD4DDDDDD4DDDD\DDDDDGDDD\DGDD\D\GDGD\GD\\GD\\GGGD\\\GGGD\\\GGD\\\GGD\\GGD\GGD\\GD\\GGD\\\GGGD\\\\\_GGG\_G\_G_G__G__________W_^_^_W_W^_W_W^_W^_W_W^_W_W_W^_^_^_^_^_^_W_W^_W^_W^^_WWW^^^^WWWV^^WV^WV^V^VWVWVVWVVV^VVVVWVVVVVVVV^VVVVVVVVVVVWVVVVVVVVWVVVVVVWVVVVVVWVVVVVVVVVV^VVUVVVVVVVVNVVUVVUVVNVNUVUVNUUVNNUUUVNNNNNMUUUUNNNMUUUNNMUUUNNNMUUUUUNNNNNNNMUUUUUUNNNMUUNNMUNMUNMNMMNMMMMMMMMMMM=M=M=KM==KKM===KKKKKKKM==========KKKKKM===KKKM====KKKKM=========;KKK==;K=;K=;=;=;;K;=;;;K;;;;;=;;;;;;;;8;;;;;;;;#;;;;;#;;;;;8;;;;;;8;;;;;;;;8;;;;;;;;;8;;;;;;8;;;;#;;8;;#;8;;#8;8;#8;##88;###### 888# 8# 8# 8 8 8 8 8 8 8 8 8 8# # 8 8# # 8# # 8 8 8 8 8  8           ! ! (! ((!!! (((()!!!!(()!!(()!!()!!()!!()!!(()!!(()!!!(()!!!(()!!(()!(()!()!()()!)!)!)())()))()))))))))))))))1)))*)))1))1))1)*))1)*))1)*))1)*))1)*))*))1))1))1))1)*))*))1)*)*)*)*)*)1)1**)1**)11111112**11212*2*2*22*22212222222222*2222222122222*222212222222222222222B2B2B42B442BBBBBBBD444BD44BD4D4BD4D4D4D4D4D4D4D4D4D4D4D4D4BDBDBDBD4D4BDBDBD4D4D4D4D4D4D4DBDDBDDD4DDDD4DDDDDDDDDDD\DDDGDDD\DGDD\D\D\D\GDGD\GD\GD\GD\GD\GD\GD\D\GD\GD\GDGD\GDGD\GDGD\GD\GD\GD\GGD\\GGGGGGGGGGG\\_G\_\_\__G_______________W__W_^__^__W__W__W__^___W___W__^__^__W_W_W_W^_W^_WWW^^^^^^^WWV^^WV^WVWV^V^V^VWVV^VV^VVWVVV^VVV^VVV^VVV^VVV^VVV^VVWVVV^VV^VVWVVV^VVWVVVWVVVV^VVVVVVV^VVVVUVVVVVVUVVVNVVNVUVUVUVNUVUUVNUVNNUUUVNNNNNUUUUUUUUVNNNNNNNUUUUUVNNNNUUUUVNNNNUUUUUUUVNMUUUUUUNNMUNMUNMNMMUMMMMMMMMMMMMKMM=KMKM=KM=KM=KM==KM=KKM=KM==KM=KM=KM=KM=KM=KM=KM=KKM==KKKM======;KKK==;K=;K=;=;=;=;;K;=;;;=;;;;=;;;;;;;;;;;;;;=;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;=;;;;;;;;;;8;;;;;;;;#;;;8;;8;;#;8;8;8;#8;#88;##888888888888## 88## 88# 8## 8## 8## 88## 88## 88## 88# 88# 8# 8# 8 8 #  8           ( ! ( ((! ((!!! (((((((((((((()!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!((((()!!!(()!(()!)!()()()())!))!)))())))))))))))))))))*)))))1)))*))))1)))1)))*)))*))))*))))*))))*))))*))))1)))1))*))*))1)*)*)*)1)1*)1**)111*******112**12*12*2*2*2*2122*2122*2122122*212122*2*212122*2122*22122222*222222422B2B2B42BB442BBBBBBBD444BBD44BBD4BD4BD4BD4BD4BD44BD4BD4BD4BBD4BD4BBD4BD4BBD4BD4BD4D4BDBD4D4DBDBDDBDDBDDDDBDDDDDDDDDDDDDGDDDDGDDD\DD\DGDD\DGDGDD\D\D\D\D\D\D\DGDGDGDGDD\D\DGDGDD\D\DGDGDGDGDGDGDGD\D\GD\GD\\GD\\\\GGGGG\\\_GG\_G_G_G_\__\______\___________________________________W_____^__^__W_W_W^_W^^_WWWWWWWWWWV^^WV^WWVWV^WVWVWVWVWVWVWVV^VWVV^V^VWVV^VWVWVV^VWVWVV^V^V^VWVWVV^V^VWVV^VWVVWVVV^VVV^VVVVVWVVVVVVVUVVVVVVNVVUVVUVVNVNVUVNVNUVUVNUVNUUVNUVNNUVNNUVNNUVNNUVNUUVNUVNNUVNUVNUUVNUVNNUVNNUUVNNUUUUUUUUUUUUUNNMUNMUNMNMMUMMMUMMMMMMMMM=MM=MM=M=MKMKMKMKMKMKMM=M=M=MKMKMM=MKMKMM=M=M=M=KMKM=KM=KKM====KKKK====;KK=;K=;K=;=;=;=;;K;=;;=;;;K;;;K;;;=;;;;;K;;;;;K;;;;=;;;;;K;;;;=;;;;=;;;;K;;;;=;;;;;;K;;;;;;;;;;;;;;;;;8;;;;8;;;#;8;;#;#;#8;8;#8;##88;##888888;######## 8888888888888########################## 8888## 8# 8# 8 8 8 #             ( ! ! (! !! (! ((!! ((!!! ((!!! ((!!! ((!! ((! ((!! ((!!! (((!!!!!!!!!!!!((()!!()!()!)!()())!)())!)))!))))!))))))))))))))))))))))))))*)))))))))))))))1)))))))))))))))))))1)))))))*))))*)))*))*))*)*)*)*)*)1*)1*)11****)11112****112**12**12*12*2*12*12*1212*12*12*12*12*12*12*12*1212*2*2*2122*22222*222224224242B2B442B4442BBBBBBBBBBBD4444BBBBD444BBBD444BBBBD4444BBBBD4444BBBBD444BBD44BBD4BBD4BD4D4BDBDBDBDD4DD4DDD4DDDDD4DDDDDDDDDGDDDDDDGDDDD\DDD\DDGDDD\DD\DDGDDGDDGDDD\DD\DDGDDD\DDGDDD\DDGDDGDDGDDGDD\DGDD\D\D\GDGD\GD\GD\\GGD\\\\\\\\\_GG\_GG_G\_\_\_\__G__G__\___\___\___\___\___G__\___G__\____G_______________W_^_^_W^_W^^_WWW^^^^^WWWWV^^WWV^WV^^WV^WVWV^WV^V^WVWV^WVWV^WVWV^WVWV^WVWV^WV^V^WV^WVWV^V^WVWVWVWVWVV^VWVV^VVWVVVWVVVVVVVVV^NVVVVVVVVUVVVUVVVNVUVVNVUVUVVNVNVNUVUVUVNVNUVUVNVNUVUVNVNVNUVUVUVNVNVNUVUVUVNVNUVNVNUVNUVNUVNUUVNNUUUUUUUUUUUUNNMUUNMUMUMUMNMMMUMMMMMMMMMMMMMMMMMM=MMMKMMMMKMMMMM=MMMMM=MMMM=MMMKMMM=MKMM=M=M=KM=KM==KKKM=====;KKK==;KK=;K=;=;K;K=;=;;K;K;=;;K;;K;=;;=;;=;;=;;=;;=;;K;;K;;K;;K;=;;=;;K;;K;;K;;K;;=;;;K;;;K;;;;;K;;;;;;;;;;;;;8;;;;;#;;8;;8;;#;#;#;#;#8;#8;#8;#88;#88;##88;###88;###88;###88;###88;##88;###88;###888;#####8888888#### 88# 8# 8 8 8 #     8       (  ( !  ( (! ! ! (! ! (! ! (! ! (! ! ( (! ! ( (! ( (! (! (!! (!!! ((((((((((()!!!()!()!()!)!)!)!)!)())()))!)))!))))!))))))()))))))))!))))))))))!))))))))())))))))()))))))))))))))))))))))))))*))))1))*))*))1)1)*)1)1*)1*)1**)11*****)1111112******11112***1112***1112****1112****11112***112**112*12*12*121212212221222222222422B2B2B42B42B42BB4442BBB444442BBBBBBB44444442BBBBBB444442BBBBBB4444444444444BBBBD44BBD4BD4BD4BDBD4DBDBDD4DD4DDD4DDDD4DDDDDDDDDDDDDDDDDDDD\DDDDDDD\DDDDDD\DDDDDGDDDDDDGDDDDDDD\DDDDDD\DDDDDGDDDDD\DDD\DDD\DD\DGDD\DGDGDGDGD\GD\GD\\GGD\\\\\\\\\\\\_GG\_GG\_G\_G_G\_\_G_G_G_G_G\_\_\_\_\_\_G_G_G\_\_\_\_\_\__G_G__G__\_____________^__W_W_W^_WW^_WWW^^^^^^^^^^WWWWV^^^WWV^^WWV^^WV^^WWV^WWV^^WWV^WWV^^WWV^^WWV^WWV^^WV^WWV^WV^WV^WVWV^V^V^V^VWVV^VV^VVV^VVVVWVVVVVVVVVVVVVNVVVVVUVVVUVVVNVVUVVUVVNVVNVUVVNVUVVNVUVVNVUVVUVVNVUVVNVUVVUVVNVUVVNVUVUVVNVNVNVNVNVNUVNUVUUVNUVNNUUUUVNNNNMUUUUNNMUNMUNMNMNMMUMNMMMUMMMNMMMMMMNMMMMMMMMMUMMMMMMMUMMMMMMMMUMMMMMMMMMMMMMM=MM=MKMKMKM=KM=KKM===KKKKKK====;KK==;K=;K=;K=;K;K=;=;K;K;K=;=;=;=;=;=;=;=;=;=;=;=;K;K;K;K;K;K;K;K;K;K;K;K;=;;K;=;;K;;K;;=;;;;K;;;;;;;K;;;;8;;;;;;;8;;;;#;;#;;#;8;;#;#;#;#;#8;8;#8;8;#8;#8;#8;8;#8;#8;#8;#8;#8;#8;8;#8;#8;#8;#8;#8;#8;##8;##88;###88888888888### 8# 8# 8 8 8  8   #            !   (  !  !  (  (  (  (  (  (  (  (  ( !  ( ! ! ! ! ( (! ((! ((!!!!!!!!!!!!(()!!()!()!()!)!)!)!)!)())!)())())()))!))()))!)))!)))!))()))()))()))!)))!)))!))()))())))!))))()))))))!))))))))))))1)))))*)))*))*))*)*))1)1*)*)1*)1*)1*)11**)11***)1111*****)1111111*******)111111******)1111111111***11111112***112*12*12*2*2*21222*22222222222422B2424242B2B42B42B42B42BB42B42BB42B42BB42B42BB42B42BB42B442BB442BBB4444444444444BBBD44BD4BD4BD4D4D4D4D4DBDDBDDBDDDBDDDDD4DDDDDDD4DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDBDDDDDDDDDDDDDDDDDDDGDDDDDDDDDDGDDDDD\DDD\DD\DD\DGDGDGDGDGD\GD\GD\GGD\\GGGGGD\\\\_GGGGG\\\_GGG\\_G\\_GG\_GG\_GG\_GG\_GG\\_G\\_G\\_G\\_G\_G\_G\_G\_\_\_\__G__G____G_______^__^_^_^_^_W^_WW^_WWW^^^_WWWWWWWWWWWWWWWWWWWWWWWWV^^^^^^^^^^^^^^^^WWWWWWWWWWV^^^^^WWWV^^WWV^^WV^WV^WV^WVWV^VWVWVV^VWVVV^VVV^VVVVV^VVVVVVVVVVVVVVUVVVVVVVNVVVVUVVVVUVVVVNVVVUVVVUVVVVNVVVUVVVVNVVVUVVVUVVVVNVVVNVVUVVVNVVNVUVVUVUVVNVNVNVNUVNVNUVNNUVNNUUUUUVNNNMUUUUNNMUUNMUNMUNMNMUMUMNMNMNMMUMNMMUMNMMNMMUMNMMUMNMMUMNMMUMMUMMUMMUMMMUMMMMMMMMMMMMMMMKMM=M=M=KM=KM=KKKM============;KKK==;KK==;K=;KK=;K=;K==;K=;K=;K=;K=;K=;K==;K=;K=;K=;K=;K=;K=;K=;=;K=;=;K;K;K;K;K;=;;K;;K;;K;;;=;;;;;;K;;;;;;;;;8;;;;;;8;;;;#;;8;;;#;8;;8;;#;#;8;;#;#;#;8;8;8;8;8;8;;#;#;#;#;#;8;8;8;8;8;8;;#8;8;8;8;8;#;#8;#8;#8;#8;##88;##88888888888## 88# 8# 8 8 8 8 #   8    #                                   (       !    !  !  ! ! ! ! ( (!! (!!! (((((((()!!!!()!!()!(()()!()()!)!)!)!)!)!)!)()())!)!)())!)!)())!)()())!)())!)!)())!)())!)())!))!)()))!))()))()))))!)))))))))))))))))*))))*)))*))*))1)*))1)1)1)1*)*)1*)1*)1*)1*)1*)11*)1**)1**)1*)11*)11*)11*)11*)1**)11*)11**)11**)11****)11111111112***112*12*12*2*2*21222*22222222222222422422422B2B24242422B2B2B2B2B24242424242422B2B424242B2B42B42B42BB442BBB44444444BBBBD44BD4BBD4D4BD4D4D4D4DBDD4DBDDBDDBDDD4DDD4DDDD4DDDD4DDDD4DDDDD4DDDDBDDDDDBDDDDD4DDDDD4DDDDD4DDDDDDBDDDDDDDDDDDDDDDDDDDDDDDGDDDDD\DDD\DD\DGDD\DGDGDGD\D\GD\GD\GGD\\GGD\\\GGGGD\\\\\\\\\\\\\\\\\\\\\_GGGGGGGGGGGGGG\\\\\\\\\\\_GGGGG\\\\_GG\\_GG\_G\_G\_\_\_\__G___G___________^__W_^_^_W_W^_W^_W^_W^^_WW^_WWW^^_WW^^_WWW^^_WWW^^_WW^^^_WW^^^_WWW^^^^_WWWWWWWWWWWWWWWWV^^^WWV^WWV^WV^V^WVWV^VWVWVV^VWVVV^VVWVVVVWVVVVVVVV^VVVVVVVVVVVVVVVVVVNVVVVVVVVVVVVVVVNVVVVVVVVVVVVVUVVVVVVVVVVVVNVVVVVVVNVVVVVNVVVVNVVUVVVNVUVVUVUVVNVNUVUVNUVNUVNUVNNUUUVNNNNNNNNNNNMUUUNNNMUNNMUNNMUNMUNMUNMUNMNMUNMUNMUNMNMUNMUNMUNMNMUNMNMUNMNMNMNMNMNMMUMMNMMMMUMMMMMMMMMM=MM=M=M=M=KM=KM==KKM==KKKKKKKKKKKKKKKKK=====;KKKK===;KKK====;KKK===;KKK===;KKK===;KKK==;KK==;K==;K=;K=;K=;K=;=;=;K;K;=;;K;=;;=;;;K;;;;K;;;;;;;;;;;;;;;;;;;;;;#;;;;8;;;;8;;;8;;;#;;8;;;#;;#;;8;;8;;8;;;#;;#;;8;;8;;8;;;#;;#;;#;8;;8;;#;8;;#;8;8;8;8;8;8;#;#8;#8;##8;##8888;####### 888## 88# 8# # 8 8 8 8 #  8  8  #   8   8   8   8   8   8   8   #     #                (  ( ( ( ( (! ((! (((!!!!!!!!!!!!((()!!()";
	string s = "";
	int dx[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1,-1, 1,-1, 0, 1 };
	decode("", 0);
	for (int i = 0; i < enc.size(); ++i) s += deckey[enc[i]];
	s += "2";
	map[500][500] = true;
	int x = 500, y = 500;
	for (int i = 0; i < s.size(); i++)
	{
		x += dx[s[i] - '1'];
		y += dy[s[i] - '1'];
		map[x][y] = true;
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (map[i][j]) cout << "#";
			else cout << ".";
		}
		cout << "\n";
	}
}

struct line
{
	int type, x, y, len;
};
int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1,-1, 1 };
void draw(int dir, int y, int x, int n)
{
	while (n--)
	{
		if (x >= 0 && x < 1003 && y >= 0 && y < 1003)
		{
			map[x][y] = true;
		}
		x += dx[dir];
		y += dy[dir];
	}
}
void c9()
{
	string encoded = R"z(@ LL"#0!(@$+0!,L"O0&GH P 'I\-K@*AN W +'Z+\ ,"2--0-F$!U@.'; L 3$H#0 3M()D 5!, - 5&8"9 7$"!!07L6 R07M)"B08   4@9-H @ ;&. ^0;J_ W0;KW!10;M) :0;MD!" <!,$\@=CI!7 ?!@"O0?M6 %0?M<"/0@  !#0@!$ (0@!- 30@!A Q0@"3!10@#E =0@$# E@@*1 5 @FL+O A#V$7PB)] ( BLX$OPC R :@D*5 9 FM8+30H!& &0H!- 30H!A Q0H"3!!0H#5 A0H#W +0H$# E0H$I!E0H&/ )0H&9 30H&M!-0H'["!0H)] $0H*" +0H*.!/0H+>!:0H,Y / H-) !0H-+ -0H-9!- IA\'Z@IM' /@K)["! M&, K MID 2PN*# GPPA- 3PQ!4 ,@Q)["!0QG[ %@QLW"[@QL_ ' SK@!3 U#* LPU). N@ULW"YPV,[ - VJ> * W)D +PWAA ; X*B +PZAA ; \*>!2 \N"&C ])D &P]-) / ^*B!\0^*F +0^*R N0^+A ]0^,? '0^,G 10^,Y / ^-) " ^-* "0^-, ,0^-9 I0^.#!H0^@ !,0^A- 30^AA (0^AJ %0^AP ,0^A] 50^B3 40^BH B0^C+ K0^CW Q0^DI!C0^F- +0^F9 30^FM!-0^G[!90^I5 +0^IB "0^IE 70^I] A0^J? # ^JC !0^JE +0^JQ O0^KA \0^L> '0^LF 20^LY / ^M+ !0^M- +0^M9 I0^N# .1 '& '! GD+$! ID,,A!'= QQ!K# =Q"*K U1#JH &1#JO 81#K( 81#KA R1#L4 '1#L< /!$+> 6Q%-9 IQ%A] 51&MH :1&N#!:A'B7 %1'EJ N1'F9 31'FM C1'G1 31'GE 51'G[ UQ(A] 5A)B1 &A*B1 %!*LP'VQ+)L 0Q,I] AA-"* "Q-.4!7A-B+ "A.B' +1.FM 51.G# A1.GE 51.G[ Y1.HU +1.I! C1.IE .1.IT (1.I] $1.J" <1.J? #1.JC A1.K% 8!.K? !1.KA <1.K^ '1.L& J1.LQ '1.LY /1.M) /1.M9 31.MM 51.N# 41.N8 3A/"( ,!/#&&L!/K> 8Q0B3 SQ0KA ,!1E($(A2#/ )Q3B3 S!3IC !13IE 7Q3I] A13I^ -13J, 213J? #13JC K13K/ /!3K? !13KA &13KH +13KT '13K\ T13LQ '13LY /13M) /13M9 =13MW +13N# 7A4A[ ;A5A[ ;Q6O2 9A7#% 4Q7+N #17O2 "17O5 618  !,18!- 318!A 3!8!U !18!W %18!] 518"3 )18"= %18"C @18#$ "18#' O18#W Q18$I 2!8JX QQ9+R P!9N\ /!:!Z,7A:&K!CQ:.#!H1;%; ]1;&9 01;&J "1;&M W1;'E 51;'[ @1;(< +1;(H \1;)E %!<+> $Q=+A!/Q=J? #!=K@ '1>%V B1>&9 *1>&D (1>&M W1>'E 51>'[ :1>(6 +1>(B ?!>K> 'A?EU $Q?JC 5AA&' _!A@8(F!AK@ @!AN\ JABA? 3!BK>#*ACA? 3ACI0!6QDG6 .QDJ? #QE   8QFJC 51FK_ .1FL. B1FLQ '1FLY /1FM) /1FM9 I1FN# %!GHT 4!H#L'GQJ*D 1QJC' EQJJY &AKM_ GQL'E 5AL'Y *ALA+ S!M,, +AMA+ SQMC' EQN+  #QP+$ :AQ W ?QQ@9 41QDN :1QE) =1QEG 51QE] O1QFM W1QGE +1QGQ )1QG[ ?!QJX 'QQJY #AR'M )AR'Y $!R(T+G!RE< (QS(L (QS*V "!S,,&>QSJ] AATGT 0QU*Z (!UJX#TAVF<!41W!4 F!W![ !1W!] 51W"3 S1W#' 31W#; %1W#A +1W#M )!W#W !!W%< 5AW'C WQW'[ 7!W.\*\QWHU OQY#N (QZ@  8Q\@O =!\JB 'A]'C WQ]CM )Q]CW!1Q]K? MA^DO ;A_M7 /" +T 0R CM )" JB(!2 K4 #2 K8 &2 K? &2 KF .2 KU 72 L- ;2 LI '2 LQ '2 LY /2 M) ,2 M6 "2 M9 I2 N# Y2 N] 32 O1 :2!   -2! . *2! 9 )"! C !2! E 32! Y 32!!- M"!![ !2!!] 52!"3 S2!#' 7B!%'!1B!@6 $B!M5 -R"#7 5""%< IB"/$ (R"CW!12"ED @2"F% G2"FM ?2"G- +2"G9 +2"GE 52"G[ 72"H3 A2"HU 62"I, 82"IE 72"I] 82"J6 '2"J> $2"JC 52"JY B2"K< "2"K? *2"KJ *2"KU 72"L- ?2"LM #2"LQ '2"LY /2"M) (""M2 !2"M4 $2"M9 I2"N# Y""N] !R#(3 AB$ 1 2"$+X ,R$K? MR%,Q 'R%CW!12&-J 82&.# /B&@7 8B&N[ YR' 9 5B'@7 8B'M' /"(KT -B(M' /R),Y /"*KX -2+%9 #2+%= 62+%T X2+&M .2+&\ *R+A- MB,%' *B,D3 $R-#M )"-(Z(""-G&)S2-HI +2-HU %2-H[ F2-IB "2-IE 72-I] "2-J  '2-J( :2-JC 52-JY E2-K? 22-KR "2-KU #2-KY &2-L  ,2-L- C2-LQ '2-LY ""-L\ !2-L^ $2-M# %2-M) /2-M9 IB./J NB/$. "B/'Y 5R/IE 7B/I[ +"/KT$DB/LW "R0   "B0D+ 5R0F1 ;B0LW 'R1-) /"1KX >B1M1 )R2 $ 4R2#W 7B3&K!$B3OJ NR4(U %B4BW E"4C "[R4L- CB4LO 1B4OJ N25*> $25*C 525*Y E25+? 525+U #25+Y '25,! +"5,- !25,/ ?"5,O !25,Q '25,Y /"5-) !25-+ &25-2 &25-9 I25.# ;25.? =25.] ?25/= *"5/H !"5/J !25@  +25@, ,25@9 S25A- 425AB 8"5A[ !25A] 525B3 B"5BV !B5IO +R6E2 %B6M' /"7$2 )"7%<#=R7([ IR8DD DR9$X 0B9&K 8R9)$ @B9,K ?R9-9 I"9AF')R9E8 $B:'C =B;CU )B;IC -R;I] ER;L- C"<$2(P"<%& (R<%= >R<@9 S"=#% !"=#' !B=L= &R>$/ #R>FM 9B>LW 'R@$3 UB@+C %B@CK E"@E& )"@E,(M"A%' !BA,6 *RAE) #BB%% 'BB++ 32B-W +"B.# !2B.% W2B.] %2B/# *"B/. !2B/0 ;2B@  82B@9 ,2B@F F2BA- 92BAG 3"BA[ !2BA] 52BB3 (2BB< D2BC! %2BC' @2BCH $2BCM )2BCW -2BD% -2BD3 %2BD9 82BDR %2BDY (2BE" ""BE% !"BE' !2BE) "2BE- '"BG" -BBI5 ;BBJE #BBLO #BC+= ERCA] 5RCE- /BCN! IBDJA )BDLK &"EE& (BEN[ YBF$] /RFE) #BFL+ 7RFLQ 'BGB1 &BH,D 8RHE- /BI'% 9BI,+ 7"IG" "RIIE 7BIJ7 ;BJ#U )"JE& %RJLY /BK"* .RK%) #"K'")=BK.[ YRKE) #RKE=!/RKE\ PRKG' =RL)E 7BL*W 5BL.[ Y"LLJ(SRM%- /"ME& 8RME- /RMLQ &BN$M ;"N.# !RNB3 MRNE) #RNJC 5BO#K E"P-' !RPE- /RPE=!+BPHY %RQ-) /"RA[ !BRKS 5RRM) /BSAY 3BSC% %BSHS Y"SI* 7BTL+ 7RU%=!/BU+S 52U.O -2U.] N2U@  82U@9 R2UA- 92UAG .2UAV $"UA[ !2UA] 52UB3 .2UBB >2UC" $2UC' 72UC? -2UCM E2UD3 +2UD? ?2UD_ '"UE' !2UE) #2UE- *2UE8 $RUE=!/2UE? (2UEH )2UER >2UF1 ;2UFM 52UG# #2UG' 42UG< (2UGE 52UG[ T2UHP $2UHU %2UH[ /2UI+ 92UIE 32UIY #2UI] "2UJ  B"UJC !2UJE ,2UJR &2UJY E2UK? .2UKN $BV&K -BV*W 5RVA- 9BVB_ .RVI_ CBW*A EBWI[ 7RX)] 1RXE=!/2XGU %2XG[ N2XHJ *2XHU %2XH[ /2XI+ 92XIE 42XIZ ""XI] !2XI_ $2XJ$ 4BXM' 7"XM7 !RY-9 IRYJY [BYM5 -"Z%&%%RZGE 5RZM9 IR[%) #B\$1 E"\$Z!VR]%- /B]&= 8B]AE %B]K= .B^"P >B^L$ 03 +" $3 +' 13 +9 %3 +? 53 +U ,3 ," *3 ,- ;# @:"QC A? 8C K< DC KS 6C M' 7S!*/ 3C!*A )C"#% %C"N! ,C#.M KS#AG 3C#IC IS$&M 5C$LO %C%"_ 1S%%=!/C%+. 6S%C! %S%G[ *C&*7 ;S&+4 *S&H\ HC'+S [C'LI =#(+J 'C(.! %S(C' ES(JC 5C)-T <C).! $C)F$ /C*)[ 7S+(& N#+)X !S+*C 5C+-[ CS+K? 5C+M\ D#,)X#?C,+< D#,+J *C,LO %#-A[ !C-B1 5S..# *S.A] )#.H[ !C/#K ES/'# #C/AC!)C/HY %C/LI =S/N# Y#0C9 !C0GY 5C0JW "S1'' =C1C7 1C1ET 8#1KJ !C2*T 232/& E32@  8#2@9 !32@;!"32A> (32AG 3#2A[ !32A] (#2B& !32B( *32B3 M32C! %32C' &C2GY 5C2HS /#2KJ"GC3*W "S3B' +S3FM *#3I< &S3JY *S3N. NC4)[ ##4JT !C5*# '#5L@#+C6)C $C6)W 3S6*Y .S6C0 &S6KU 7C6L+ +#7)<&OS7KU 7C7M7 /#8A[ !C8HY %C8I> "C9)[ #S9+$ 6C9.! I#9.P 7C9AY 3S9B3 MS:#7 53:$< >3:$[ +3:%' %3:%- /3:%= &3:%D C3:&( 83:&A %3:&H $3:&M 53:'# #3:'' 23:': *#:'E !3:'G #3:'K /3:'[ I3:(E /#:(U !3:(W #3:([ .C:); AC:C% %C:HC IC;&  DS;)E $C;)W 3S;CM EC;GC =C;HS &C;JA ES=&M 5C=+^ *C=-7 /C=B_ 2C=E" (S=FM 5C=GC =S=IJ $S=K( BC>%; /C>-7 /C>JW 5C>L+ #C?(L RC?M' 7#@'E !C@)C 'S@)O )S@FM 5CA,& 2CB#% %CB$Y GSBDN %SBHU %CBKS )SBL- 3CCAE!+SCL- 3SD'  "CE"_ MSE#M ECE)C 'SE)Y #CE*W 5CE-' 7#E.P "SEDT &SEG# #SEH[ ACF%+ %#FNP 5CG"L :SG)] ESGG' "CGKI!'SH'# #SHG# #SI$[ +CI%% %#I'* !CI); A#I*N !3I*P (3I*Y F3I+@ &3I+G #3I+K )#I+U !3I+W 53I,- +#I,9 !3I,; %3I,A )3I,K %3I,Q #3I,U *3I-  (3I-) /3I-9 (3I-B @3I.# M3I.Q %3I.W "3I.Z "3I.] N3I@  8#I@9 !3I@; 43I@P I3IA: %CIJA ESJ'' =SJ', 83J*C *3J*N *3J*Y ACJG% #CJKS )CK(Y %SK.] +#K.^ !CKLO %CL$_ %SL'$ "#L.^ WCLG! 53LL* "3LL- 23LLA )3LLK "3LLN "3LLQ '3LLY /3LM) /#LM9 !#LN] !3M$% +#M$1 !3M$3 03M$D 63M$[ "3M$^ %3M%$ "3M%' %3M%- /3M%= GSM&M 5CM'$ "SM,B (SM-C ?CME; /SMG' =SMLA )SMN_ LCN(S YCN-7 /SND3 SCNG! 5CNI[ #CNLI "CO$Y :SO%' %SO+K )COGY 5COKI!'CP*A )CP+/ MSPC! %CPIW 3CPLE %CQ,O %SQLK %SR%- /SRLK %3S R 43S!' ?3S!G 3#S![ !3S!] 5#S"3 !3S"5 .3S"D B3S#' E3S#M <3S$* (3S$3 $3S$8 $3S$= 43S$R (3S$[ +3S%' %3S%- "3S%1 +3S%=!/3S&M '3S&U #3S&Z (3S'# #3S'' +3S'3 &3S': $3S'? %3S'E "SSC' ECSL? 3ST+U 7CT,I )#T@9 !#TB1 !STLQ 7CU*7 ;CU@7 8CUAW 1CUE+ %SULQ 7#V$1 !CV-' 7SVGE #SVI= 'CW$/ <CWFK!4SX$3 SSX'# #CXE% /SXGI 1CXGY (SY'E 5CY,? 3CYFK!?SZ%=!/SZ'' =CZ(Y %SZ*C ,#ZGC !CZIC 'SZIE 3C['@ :C[GA ;C\"1 5S\GE 5C\I[ #C]'P %C](S YS].# YC]L+ 7C^AE!-C^IW %D 'J &T ,- "D /C GD DU C4 G> &4 GE $T JP ZT M) /T!G[ YD!IQ -T!L0 0T!M) /D",O %T"G' %D"OJ N$#(: -D#)[ #D#,+ 6$#BF%PD#GC =T$'[ &T$IY #D%)W 3D%,I )T%@  8T&'. (T&(R "T&CM ET&I] E4&L^ *4&M) *$&M4 !4&M6 "4&M9 I4&N# 34&N7 E$&N] "4&N_ 74&O7 +4&OC (4'   #4' $ 4$' 9 "4' ; #4' ? U4'!5 14'!G 3$'![ "4'!] 54'"3 34'"G ?4'#' /D'*A <4'-N 44'.# 44'.8 D4'._ 64'/6 +4'/B )4'@  $4'@% 34'@; "4'@> U4'A4 24'AG 34'A] 54'B3 34'BG ?4'C' E4'CM "4'CP B4'D3 44'DH *4'DS 24'E' %4'E- K4'EY 24'F, #4'F0 <4'FM 54'G# #$'G( !4'G* $T'G[ YT'H" .T'HU %D(!Y 3T(E' %D(G% #T(H# QD(IC 'T(M9!CT)'E 5$)@9 !D)G% #D)KS )T)M9!C$*(: .D*,? 3T*,A )D*@7 8D*G! 5T*G7 -T*H[ AD+'Y ($+E- !D+G! 5D+JA -D,I; .D.KI FT/(1 CD/). %D/)C 'T/,K %D/GP ,$0%X "$1EX #T1GE 5$1H: $$2 9 !D2!E!-T2%' %D2)( .T2,Q 7D2D1 &D2G% "D2J3 7T3 ; DD3); .$3EX#>D3JA %$4':&-T4'[ %D4), 2D4,+ 7D4.[ %$4H: %T5%- KT5@0 (D5FK $D6$* >D6'C )D6FK SD6J; *T7(! SD7.U ;$7H: 8D7OJ N48A% 348A9 -48AG 3$8A[ !48A] 548B3 348BG ?48C' E48CM 848D& +48D3 S48E' %48E- '48E5 -T9D3 SD9HY %T9JC"'T: 9 >T:#@ ,T:&\ &D:'Y 5D:.[ "T:.] 4D;'9 3T;I= 'T<G[ Y$<HS !D<MQ 9T=G# #D=HQ "D=HY %T>+K AT>-) /$>HU !D>I[ #D?(N "$?/$ 7T?G' 3T?HW #T?IE 34@$6 *4@$A E4@%' %4@%- -4@%; #4@%? $4@%D 44@%Y ?4@&9 04@&J "4@&M 54@'# #$@'' !4@') &4@'0 *4@'; )4@'E (4@'N ,4@'[ '4@(# 04@(4 &4@(; 14@(M %4@(U #$@(Y !4@([ A4@)= '$@)E !4@)G 14@)Y #4@)] E4@*C -4@*Q 54@+' 8D@+S "T@CM $$@H" !4@H$ 04@H5 %4@H; $D@HK 4$@IJ #D@IW (DA(R "TA(U %TAHU %TAH[ ADAKP &TAM:!BTB&M 5DBHO 4$BIJ%OTC#R @$D(: *TD([ A$D)>"WTDHU %TDH[ ATDO2 9DE'% #DE'C )DE)N $DE+I!'DE@7 2TEA  FDECK!%$EM< #TF-9!1DG'! %TGH[ ADGII %4H)? %4H)E #$H)I !4H)K +$H)W !4H)Y #4H)] E4H*C =4H+! B4H+D ;4H,  ,4H,- 34H,A )4H,K %4H,Q 74H-) /$H-9 !4H-; "4H-> )4H-H N$H.7 !4H.9 C4H.] '4H/% $4H/* /4H/: 14H@  14H@2 &4H@9 +$HM< <TI@X NDIE+ %TIG; )$IH: %TIIY #DIM7 /DJ&[ /DJ'9 3DJIC %TK%Y SDK(6 <$K/$ )TKI] EDLE% &$LH:%_TM'# #DMH9 ?$MI= !TNGE 5DNI; #4O#T 64O$+ '4O$3 K$O$_ !4O%! %4O%' %4O%- K$O%Y !4O%[ &4O&" J4O&M $4O&R 04O'# #4O'' (4O'0 *4O'; )$O'E !4O'G 34O'[ 34O(/ '4O(7 #4O(; %4O(A 04O(R "4O(U %4O([ /4O)+ %4O)2 $4O)7 #$O); !$O)= !4O)? %4O)E %4O)K -4O)Y #4O)] '4O*% =4O*C K4O+/ &4O+6 V4O,- 34O,A )4O,K %4O,Q 74O-) #4O-- +4O-9 #4O-= .4O-L )4O-V *DO.[ CTOG( #TOL. 2DP$^ LDPEW KDPI7 "TQ(U %TQG, .DQM' 7DR&K 2DR)4 "$RI= !TS   8TSD3 2TSE' %DSI1 7TSI? %DT'% #TT([ A$U)= "4UF^ $4UG# #4UG' -4UG5 %4UG; )4UGE .4UGT &4UG[ &4UH" '4UH* 04UH; 24UHN &4UHU %4UH[ #4UH_ .4UI. )4UI8 $4UI? $4UIE %4UIK -4UIY #4UI] 44UJ2 04UJC CDV'! 5TV)? %$V- $#TVE- /4VF: (4VFC )4VFM 3$VG! !4VG# #4VG' /4VG7 #4VG; )4VGE 04VGV $4VG[ $4VH  '4VH( 24VH; 44VHP $4VHU %4VH[ %4VI! *4VI, -4VI: "$VI= !TVI? %4VIA #4VIE %4VIK -4VIY #4VI] $TW'J 0TW)F $TX-4 $$XI= !DY 7 8TY!G %TY'; )TY)E %TY,A )TYE< <DYGY $TYG[ #TYHU %TYI? %TYIE %TYIK 1TZM9!CTZN] ND[F8 @T[G_ ;T[N] NT\)K 1T\H[ "T\IE %T\IK 1T]$F @$]GY !D]LO %T^(^ (T^,K %T^E= ;D^GW 3T^JC"'T_@9!!T_G[ 'D_HY %T_IK 1E LI <U!!G 3E!&K #U!,Q /E!.7 $E"HS 9U"I] *E#&G OE#N2 ZU%&M 5%%)= !U%)] EU%I] 55%O; 05&   85& 9 -5& G _5&!G *5&!R (5&![ 75&"3 35&"G #5&"K!!5&#M E5&$3 E5&$Y -5&%' %5&%- ?5&%M (5&%V "5&%Y *5&&$ =5&&B *5&&M "5&&P 25&'# #5&'' 35&'; )5&'E #5&'I 15&'[ +U&)? %E&/J +E&D1 EE&E+ %%'$* &%''C !U(%Y #U('E 1E(BE 3E(GC )U(GV $U(I] EU))E %E)*A .U)-! 7E)E% #U)H; %U*%] .%*D*$*U+![ 7U+'[ ?E+E! OE,%W KU,)K 1U,EY ?U,HA 3E,O= AU-E' %E-G9 3E/,, DE/H9 ?U0'# #U0E- AE0J2 6U1F, @U2'' 3E2B1 7U3.] NU3@  8%4   "54 " 654 9 %U5 ! 7U5)] &U5-9 +56'H 256'[ 156(- $56(2 (56(; (U6HU %U7"3 3E7G% #U8*C"'U8J$ >E9CK ^U9E= ;E9G! 5U9H[ AE;%W KU;(; 9U;-E $U;JC"'E<&) #U<'; )E<)[ 1%<+\ >%=&2 -5=(+ /5=(; $5=(@ 45=(U %5=([ '5=)# 9%=)= !5=)? %5=)E %5=)K .5=)Z "5=)] 0U=LK %E=N[ .E>AY "E?GY 5U@ 9!AUA 9!,UA"G 4UA'E 5EA-7 %EAKG <EB%+ YUB&M 5%C)B GECD1 '%CEY !EDEW "EDFK SEE)I %EE.L OEF%T H5FC> L5FD, &5FD3 O5FE# )5FE- 35FEA 25FET #5FEY N5FFH $5FFM )5FFW +5FG# #5FG' 35FG; )5FGE &5FGL $5FGQ )5FG[ ?5FH; 7%FHS !5FHU %5FH[ 5EG)4 :EGD) CUGEY 6UH(U %%H)C !UH*C"'EI)A #EJGC )%JI= "UK([ AUKI? #%KK\ RUL  !ZUL'[ ?EL); /ULN] NUM'# #%MIC !UNIE %UO'' 3EOG9 3UP)? #EP+*!.EQ%+ +UQIK 1%R)C !US$F FUS&0 <US)E %ET)+ 1ETHY %5U F ;%U!" !5U!$ B5U!G 35U![ 75U"3 35U"G -5U"U Y5U#O ;5U$+ '5U$3 25U$F $5U$K 85U%$ (5U%- )5U%7 3UV)K 1UW(@ 4%WHH 'EWHS )5XF\ &5XG# #5XG( 25XG; )5XGE 55XG[ 95XH5 %5XH; (5XHD $5XHI (5XHR "5XHU %5XH[ '5XI# 35XI7 %%XI= !5XI? %5XIE %5XIK %5XIQ (5XIZ "5XI] E5XJC 65XJZ *5XK% 85XK> &5XKE 75XK] :5XL8 25XLK 55XM! 75XM9 L5XN& V5XN] 85XO6 55Y   :5Y ; N%Y!* !5Y!, (UY'; )%YBT!#EYG% #EZE+ +UZI] 7E[G! 5%[HH" U\(; -%\)= !%\HI !E](Y %U])? %E]HG -U^'E 5E^EW KE_$1 'U_)]#)F (S +V )E %F D_ DV!HU %F"%C 7F"/) -V"LK 5F#$)!CV#(I "V#)K 1F$H9 UV$HL (V$H[ A&%+\ &V%@ !TF&(G -V&E- -F&FK NV'/4 7V'L9 1&(K\ 8&)'[ !V)(U %F).["5V,([ AV,)]!!F-(9 O&-/> KV-E;!4V-M! 4F.%+ YV0LK 5V1![ 7V4@ !ZF4E+ Y&5+\!2V5I= 'V6!, NF7I[ 1V9IE %V;M! /V<,K 5V<IK #V="3 3V=)= 'V>IO -F?GC )V?LK 56@,' ,6@,4 6&@,K !6@,M &6@,T ,6@-! )6@-+!"6@.. ,F@II %&@N" *&A#, !6A#. %VA)E %VB%' %FCIC 'VD)K 1FDG9 3VE%-!!VEI]!!&F.""!VG"G (VG-! ;FGI; 3VIA[ ZVJM! QFK$1 '6L%H P6L&9 I6L'# #6L'' #6L'+ /6L'; _6L(; -6L(I +6L(U =6L)3 )6L)= '6L)E %6L)K 06L)] -6L*+ R6L*^ 96L+8 D6L+] MVL,K 56L,L .6LH+ /6M$G E6M%- 06M%> \6M&; G6M'# #&M'' !6M') )VM)] 9VMA[ (FNG% #FO$) KFPG!!'FQD1 '&U"E !&UD) !VW-! +F](1 WV^AG 3V_!4 FW"HV 3W(A[!#7*JP!D7*L5 C7*LY UG+JB 77,NF 67,N] N7-  !P7-!R (7-![ )7-"%"%7-$+ AG/'/ -W2![ TW2A[ -73ES (73E\!&73G# #73G' 373G; )73GE U73H; 973HU U73IK ?G4,E [W5)Q [G6'! MW7"N ZG9'9 GW;F3 )'>H, 37@)9 N7@*("%7@,. Q7@-  .GCN' %GFN! %7P#% ;7P#A'&7P*H!%7P+N#"7Q)'!B7Q*J!!7Q+L#_7Q@  N)z";
	vector<line> output;
	for (int i = 0; i < encoded.size(); i += 6)
	{
		unsigned long long bits = 0;
		for (int j = 0; j < 6; ++j)
		{
			bits <<= 6;
			bits |= encoded[i + j] - 32;
		}
		line d;
		d.type = (bits >> 34) & 0b11;
		d.y = (bits >> 23) & 0x7FF;
		d.x = (bits >> 12) & 0x7FF;
		d.len = bits & 0xFFF;
		output.push_back(d);
	}
	for (line it : output)
	{
		draw(it.type, it.x, it.y, it.len);
	}
	for (int i = 0; i < 1003; ++i)
	{
		for (int j = 0; j < 1003; ++j)
		{
			if (map[i][j]) cout << "#";
			else cout << ".";
		}
		cout << "\n";
	}
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
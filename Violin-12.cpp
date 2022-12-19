/*
	Name: Violin-12-5-3
	Copyright: ViolinOS
	Author: sunyx
	Date: 7/30/2019
	Description: This is Violin-12-5-3, add if, else, elif. 
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<thread>

#define SIGN_WEEK 6
#define SIGN_YEAR 2000

#define ll long long
#define rep(____i, ____beg, ____end) for(int ____i=____beg; ____i<____end; ____i++)
#define debug(____x) cout<<____x<<endl
#define bugema(____x) cout<<"DEBUG: "<<____x<<endl
#define bugmore(____x, ____y) cout<<"DEBUG: "<<____x<<" "<<____y<<endl
#define bugpause system("pause")
#define readfrom(____s) freopen(____s, "r", stdin)
#define wrtto(____s) freopen(____s, "w", stdout)

#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize(4)
#pragma G++ optimize(4)
#pragma GCC optimize(5)
#pragma G++ optimize(5)
#pragma GCC optimize(6)
#pragma G++ optimize(6)
#pragma GCC optimize(7)
#pragma G++ optimize(7)
#pragma GCC optimize(8)
#pragma G++ optimize(8)
#pragma GCC optimize(9)
#pragma G++ optimize(9)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")

#define qdo 262
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 528
#define re 576
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865

using namespace std;

const int desinf = 0x3f3f3f3f;
const int inf = 2147483647;
const int maxn = 1234;

//输入密码
string usx;
string codex;
string space;
string mailx;
string loginName;
int loginIndex;

//MENU: 文件夹

struct menu{
	string father; //上一级目录
	string name;
};

//FILE: 文件（除了文件夹之外的都叫文件）

struct file{
	string father;
	string name;
	string cont="\0";
};

//USER: 用户
 
struct user{
	string name;
	string code;
	string email;
	bool isBlocked;
	int txzLevel;
};

//volume : 盘

struct volume{
	string cont;
};

//信息
const int MAXN = 1000;

const string AdministratorCode = "admin";

vector<menu> mn[MAXN + 5];
vector<file> fl[MAXN + 5];
vector<user> us;
vector<string> his[MAXN + 5];
vector<volume> vol[MAXN + 5];
//map<string, string> intmap;
//map<string, string> strmap;
map<string, string> clamap;
map<string, vector<string> > setmap;

//共享文件夹

enum type_kind{
	AllHide = 1,AllShow = 2,PartShow = 3,PartHide = 4
};

struct sFile{
	string father;
	string name;
	string cont;
	type_kind kind;
	bool readOnly;
	vector<string> people;
	string creator;
}; 

struct sMenu{
	string father;
	string name;
	type_kind kind;
	bool readOnly;
	vector<string> people;
	string creator;
};

vector<sFile> shareFile;
vector<sMenu> shareMenu;

int windowHeight[MAXN + 5],windowWidth[MAXN + 5];

string fontColor[MAXN + 5],windowColor[MAXN + 5];

//GETDIGIT

int getdigit(int i)
{
	int ans=0;
	if(i==1)
		return 1;
	while(i)
	{
		i/=10;
		ans++;
	}
	return ans;
}

//CALCULATE

#define MAX_L 2005
#define ACCURACY 200
#define DISPLAY 30

class bign
{
public:
    int len, s[MAX_L];//????,????
//????
    bign();
    bign(const char*);
    bign(int);
    bool sign;//?? 1?? 0??
    string toStr() const;//??????,???????
    friend istream& operator>>(istream &, bign &); //?????
    friend ostream& operator<<(ostream &, bign &); //?????
//????
    bign operator=(const char*);
    bign operator=(int);
    bign operator=(const string);
//??????
    bool operator>(const bign &) const;
    bool operator>=(const bign &) const;
    bool operator<(const bign &) const;
    bool operator<=(const bign &) const;
    bool operator==(const bign &) const;
    bool operator!=(const bign &) const;
//??????
    bign operator+(const bign &) const;
    bign operator++();
    bign operator++(int);
    bign operator+=(const bign&);
    bign operator-(const bign &) const;
    bign operator--();
    bign operator--(int);
    bign operator-=(const bign&);
    bign operator*(const bign &)const;
    bign operator*(const int num)const;
    bign operator*=(const bign&);
    bign operator/(const bign&)const;
    bign operator/=(const bign&);
//?????????
    bign operator%(const bign&)const;//??(??)
    bign factorial()const;//??
    bign Sqrt()const;//????(????)
    bign pow(const bign&)const;//??
//???????
    void clean();
    bool checkZero();
    ~bign();
};

const bign Ten = bign(10);
const bign One = bign(1);
const bign Zero = bign(0);
const bign Acc = Ten.pow(ACCURACY);
#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b

bign::bign()
{
    memset(s, 0, sizeof(s));
    len = 1;
    sign = 1;
}

bign::bign(const char *num)
{
    *this = num;
}

bign::bign(int num)
{
    *this = num;
}

string bign::toStr() const
{
    string res;
    res = "";
    for (int i = min(DISPLAY, len) - 1; i >= 0; i--) {
        res += (char)(s[i] + '0');
        //cout << s[i] << " ";
    }
    //cout << endl;
    if (res == "")
        res = "0";
    if (!sign && res != "0")
        res = "-" + res;
    return res;
}

istream &operator>>(istream &in, bign &num)
{
    string str;
    in >> str;
    num = str;
    return in;
}

ostream &operator<<(ostream &out, bign &num)
{
    out << num.toStr();
    return out;
}

bign bign::operator=(const char *num)
{
    memset(s, 0, sizeof(s));
    char a[MAX_L] = "";
    if (num[0] != '-')
        strcpy(a, num);
    else
        for (int i = 1; i < strlen(num); i++)
            a[i - 1] = num[i];
    sign = !(num[0] == '-');
    len = strlen(a);
    for (int i = 0; i < strlen(a); i++)
        s[i] = a[len - i - 1] - 48;
    return *this;
}

bign bign::operator=(int num)
{
    if (num < 0)
        sign = 0, num = -num;
    else
        sign = 1;
    char temp[MAX_L];
    sprintf(temp, "%d", num);
    *this = temp;
    return *this;
}

bign bign::operator=(const string num)
{
    const char *tmp;
    tmp = num.c_str();
    *this = tmp;
    return *this;
}

bool bign::operator<(const bign &num) const
{
    if (sign ^ num.sign)
        return num.sign;
    if (len != num.len)
        return len < num.len;
    for (int i = len - 1; i >= 0; i--)
        if (s[i] != num.s[i])
            return sign ? (s[i] < num.s[i]) : (!(s[i] < num.s[i]));
    return !sign;
}

bool bign::operator>(const bign&num)const
{
    return num < *this;
}

bool bign::operator<=(const bign&num)const
{
    return !(*this > num);
}

bool bign::operator>=(const bign&num)const
{
    return !(*this < num);
}

bool bign::operator!=(const bign&num)const
{
    return *this > num || *this < num;
}

bool bign::operator==(const bign&num)const
{
    return !(num != *this);
}

bool bign::checkZero()
{
    for(int i = 0; i < len; i++) {
        if(s[i] != 0)
            return false;
    }
    return true;
}

bign bign::operator+(const bign &num) const
{
    if (sign ^ num.sign) {
        bign tmp = sign ? num : *this;
        tmp.sign = 1;
        return sign ? *this - tmp : num - tmp;
    }
    bign result;
    result.len = 0;
    int temp = 0;
    for (int i = 0; temp || i < (max(len, num.len)); i++) {
        int t = s[i] + num.s[i] + temp;
        result.s[result.len++] = t % 10;
        temp = t / 10;
    }
    result.sign = sign;
    return result;
}

bign bign::operator++()
{
    *this = *this + 1;
    return *this;
}

bign bign::operator++(int)
{
    bign old = *this;
    ++(*this);
    return old;
}

bign bign::operator+=(const bign &num)
{
    *this = *this + num;
    return *this;
}

bign bign::operator-(const bign &num) const
{
    bign b = num, a = *this;
    if (!num.sign && !sign) {
        b.sign = 1;
        a.sign = 1;
        return b - a;
    }
    if (!b.sign) {
        b.sign = 1;
        return a + b;
    }
    if (!a.sign) {
        a.sign = 1;
        b = bign(0) - (a + b);
        return b;
    }
    if (a < b) {
        bign c = (b - a);
        c.sign = false;
        return c;
    }
    bign result;
    result.len = 0;
    for (int i = 0, g = 0; i < a.len; i++) {
        int x = a.s[i] - g;
        if (i < b.len) x -= b.s[i];
        if (x >= 0) g = 0;
        else {
            g = 1;
            x += 10;
        }
        result.s[result.len++] = x;
    }
    result.clean();
    return result;
}

bign bign::operator * (const bign &num)const
{
    bign result;
    result.len = len + num.len;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < num.len; j++)
            result.s[i + j] += s[i] * num.s[j];

    for (int i = 0; i < result.len; i++) {
        result.s[i + 1] += result.s[i] / 10;
        result.s[i] %= 10;
    }
    result.clean();
    result.sign = !(sign ^ num.sign);
    return result;
}

bign bign::operator*(const int num)const
{
    bign x = num;
    bign z = *this;
    return x * z;
}
bign bign::operator*=(const bign&num)
{
    *this = *this * num;
    return *this;
}

bign bign::operator /(const bign&num)const
{
    bign ans;
    ans.len = len - num.len + 1;
    if (ans.len < 0) {
        ans.len = 1;
        return ans;
    }

    bign divisor = *this, divid = num;
    divisor.sign = divid.sign = 1;
    int k = ans.len - 1;
    int j = len - 1;
    while (k >= 0) {
        while (divisor.s[j] == 0) j--;
        if (k > j) k = j;
        char z[MAX_L];
        memset(z, 0, sizeof(z));
        for (int i = j; i >= k; i--)
            z[j - i] = divisor.s[i] + '0';
        bign dividend = z;
        if (dividend < divid) {
            k--;
            continue;
        }
        int key = 0;
        while (divid * key <= dividend) key++;
        key--;
        ans.s[k] = key;
        bign temp = divid * key;
        for (int i = 0; i < k; i++)
            temp = temp * 10;
        divisor = divisor - temp;
        k--;
    }
    ans.clean();
    ans.sign = !(sign ^ num.sign);
    return ans;
}

bign bign::operator/=(const bign&num)
{
    *this = *this / num;
    return *this;
}

bign bign::operator%(const bign& num)const
{
    bign a = *this, b = num;
    a.sign = b.sign = 1;
    bign result, temp = a / b * b;
    result = a - temp;
    result.sign = sign;
    return result;
}

bign bign::pow(const bign& num)const
{
    bign result = 1;
    for (bign i = 0; i < num; i++)
        result = result * (*this);
    return result;
}

bign bign::factorial()const
{
    bign result = 1;
    for (bign i = 1; i <= *this; i++)
        result *= i;
    return result;
}

void bign::clean()
{
    if (len == 0) len++;
    while (len > 1 && s[len - 1] == 0)
        len--;
}

bign bign::Sqrt()const
{
    if(*this < 0)return -1;
    if(*this <= 1)return *this;
    bign l = 0, r = *this, mid;
    while(r - l > 1) {
        mid = (l + r) / 2;
        if(mid * mid > *this)
            r = mid;
        else
            l = mid;
    }
    return l;
}

bign::~bign()
{
}

class BigFloat
{
public:
    bign integer, decimal;
    int leadzero = 0;

    BigFloat()
    {
        integer = bign(0);
        decimal = bign(0);
        leadzero = 0;
    }
    BigFloat(const char *str)
    {
        int idx = -1;
        for(int i = 0; i < strlen(str); i++) {
            if(str[i] == '.') {
                idx = i;
                break;
            }
        }
        char t[MAX_L] = "";
        if(idx == -1) {
            strncpy(t, str, strlen(str));
            integer = bign(t);
        } else {
            strncpy(t, str, idx);
            integer = bign(t);
            //cout << t << endl;
            idx++;
            while(str[idx] == '0') {
                idx++;
                leadzero++;
            }
            memset(t, 0, sizeof(t));
            strncpy(t, str + idx, strlen(str) - idx);
            //cout << t << endl;
            decimal = bign(t);
        }
    }

    BigFloat(int num)
    {
        *this = num;
    }

    BigFloat(string s)
    {
        *this = s;
    }

    friend istream& operator>>(istream &, BigFloat &);
    friend ostream& operator<<(ostream &, BigFloat &);

    BigFloat operator=(const char*);
    BigFloat operator=(int);
    BigFloat operator=(const string);

    bool operator==(const BigFloat &) const;
    bool operator!=(const BigFloat &) const;
    bool operator>(const BigFloat &) const;
    bool operator>=(const BigFloat &) const;
    bool operator<(const BigFloat &) const;
    bool operator<=(const BigFloat &) const;

    void clean();

    friend bign getBign(const BigFloat &b, bign x, bign y)
    {
        bign res;
        if(b.integer.sign)
            res = b.integer * x + b.decimal * Ten.pow(y - b.decimal.len - b.leadzero);
        else
            res = b.integer * x - b.decimal * Ten.pow(y - b.decimal.len - b.leadzero);
        return res;
    }

    friend BigFloat operator+(const BigFloat &a, const BigFloat &b)
    {
        bign c = getBign(a, Acc, ACCURACY);
        bign d = getBign(b, Acc, ACCURACY);
        bign res = c + d;
        //cout << c << endl << d << endl;
        //cout << res << endl;
        BigFloat ans;
        ans.integer = res / Acc;
        ans.decimal = res % Acc;
        ans.leadzero += max(0, ACCURACY - ans.decimal.len);
        ans.clean();
        //	cout << ans.integer << endl;
        //	cout << ans.decimal << endl;
        return ans;
    }

    BigFloat operator++();
    BigFloat operator++(int);
    BigFloat operator+=(const BigFloat&);

    friend BigFloat operator - (const BigFloat &a, const BigFloat &b)
    {
        bign c = getBign(a, Acc, ACCURACY);
        bign d = getBign(b, Acc, ACCURACY);
        bign res = c - d;
        //cout << res << endl;
        BigFloat ans;
        ans.integer = res / Acc;
        ans.decimal = res % Acc;
        ans.leadzero += max(0, ACCURACY - ans.decimal.len);
        //cout << ans.integer << " " << ans.decimal << endl;
        ans.clean();
        return ans;
    }

    BigFloat operator-=(const BigFloat&);

    friend BigFloat operator * (const BigFloat &a, const BigFloat &b)
    {
        bign c = getBign(a, Acc, ACCURACY);
        bign d = getBign(b, Acc, ACCURACY);
        bign res = c * d;
        //cout << res << endl;
        BigFloat ans;
        ans.integer = res / (Acc * Acc);
        ans.decimal = res % (Acc * Acc);
        ans.leadzero += max(0, ACCURACY + ACCURACY - ans.decimal.len);
        //cout << ans.integer << " " << ans.decimal << endl;
        ans.clean();
        return ans;
    }

    BigFloat operator*=(const BigFloat&);

    friend BigFloat operator / (const BigFloat &a, const BigFloat &b)
    {
        bign c = getBign(a, Acc * Acc, ACCURACY * 2);
        bign d = getBign(b, Acc, ACCURACY);
        //cout << c << endl << d << endl;
        bign res = c / d;
        //cout << res << endl;
        BigFloat ans;
        ans.integer = res / Acc;
        ans.decimal = res % Acc;
        ans.leadzero += max(0, ACCURACY - ans.decimal.len);
        //cout << ans.integer << " " << ans.decimal << endl;
        ans.clean();
        return ans;
    }

    BigFloat operator/=(const BigFloat&);
    
    string toString();
};

string BigFloat::toString(){
	string s = "";
    if(!integer.sign && integer.checkZero() && !decimal.checkZero())
        s+= "-";
    if(decimal == bign(0))
        s+= integer.toStr();
    else {
        s+= integer.toStr() + ".";
        for(int i = 0; i < leadzero; i++)
            s += "0";
        s += decimal.toStr();
    }
    return s;
}

istream &operator>>(istream &in, BigFloat &num)
{
    string str;
    in >> str;
    num = str;
    return in;
}

ostream &operator<<(ostream &out, BigFloat &num)
{
    if(!num.integer.sign && num.integer.checkZero() && !num.decimal.checkZero())
        cout << "-";
    if(num.decimal == bign(0))
        out << num.integer.toStr();
    else {
        out << num.integer.toStr() << '.';
        for(int i = 0; i < num.leadzero; i++)
            out << '0';
        out << num.decimal.toStr();
    }
    return out;
}

BigFloat BigFloat::operator=(const char *num)
{
    *this = BigFloat(num);
    return *this;
}

BigFloat BigFloat::operator=(int num)
{
    this->integer = bign(num);
    this->decimal = bign(0);
    this->leadzero = 0;
    return *this;
}

BigFloat BigFloat::operator=(const string num)
{
    const char *tmp;
    tmp = num.c_str();
    //cout << tmp << endl;
    *this = tmp;
    return *this;
}

void BigFloat::clean()
{
    integer.clean();
    reverse(decimal.s, decimal.s + decimal.len);
    decimal.clean();
    reverse(decimal.s, decimal.s + decimal.len);
    if(!decimal.sign) {
        decimal.sign = 1;
        if(integer.checkZero())
            integer.sign = 0;
    }
    //cout << integer << " " << decimal << endl;
}

BigFloat BigFloat::operator++()
{
    *this = *this + 1;
    return *this;
}

BigFloat BigFloat::operator++(int)
{
    BigFloat old = *this;
    ++(*this);
    return old;
}

BigFloat BigFloat::operator+=(const BigFloat &num)
{
    *this = *this + num;
    return *this;
}

BigFloat BigFloat::operator*=(const BigFloat&num)
{
    *this = *this * num;
    return *this;
}

BigFloat BigFloat::operator-=(const BigFloat&num)
{
    *this = *this - num;
    return *this;
}

BigFloat BigFloat::operator/=(const BigFloat&num)
{
    *this = *this / num;
    return *this;
}

bool BigFloat::operator==(const BigFloat&num)const
{
    return decimal == num.decimal && integer == num.integer;
}

bool BigFloat::operator!=(const BigFloat&num)const
{
    return !(*this == num);
}
bool BigFloat::operator<(const BigFloat &num) const
{
    //cout << integer.sign << " " << num.integer.sign << endl;
    if ((integer.sign ^ num.integer.sign))
        return num.integer.sign;
    if (integer.len != num.integer.len)
        return integer.len < num.integer.len;
    //cout << "OK" << endl;
    for (int i = integer.len - 1; i >= 0; i--)
        if (integer.s[i] != num.integer.s[i])
            return integer.sign ? (integer.s[i] < num.integer.s[i]) : (!(integer.s[i] < num.integer.s[i]));
    //cout << "OK" << endl;
    for (int i = 0; i < decimal.len; i++)
        if (decimal.s[i] != num.decimal.s[i])
            return integer.sign ? (decimal.s[i] < num.decimal.s[i]) : (!(decimal.s[i] < num.decimal.s[i]));
    return !integer.sign;
}

bool BigFloat::operator>(const BigFloat&num)const
{
    return num < *this;
}

bool BigFloat::operator<=(const BigFloat&num)const
{
    return !(*this > num);
}

bool BigFloat::operator>=(const BigFloat&num)const
{
    return !(*this < num);
}

string format(string str)
{
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-') {
            if(i == 0) {
                str.insert(0, 1, '0');
            } else if(str[i - 1] == '(') {
                str.insert(i, 1, '0');
            }
        }

    }
    return str;
}
int prior(char c)
{
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }

}
vector<string> hz(string str)
{
    vector<string> vs;
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        string tmp = "";
        switch(str[i]) {
        case '+':
        case '-':
        case '*':
        case '/':
            if(st.empty() || st.top() == '(') {
                st.push(str[i]);
            } else {
                while(!st.empty() && prior(st.top()) >= prior(str[i]) ) {
                    tmp += st.top();
                    vs.push_back(tmp);
                    st.pop();
                    tmp = "";
                }
                st.push(str[i]);
            }
            break;
        case '(':
            st.push(str[i]);
            break;
        case ')':
            while(st.top() != '(') {
                tmp += st.top();
                vs.push_back(tmp);
                st.pop();
                tmp = "";
            }
            st.pop();
            break;
        default:
            if((str[i] >= '0' && str[i] <= '9')) {
                tmp += str[i];
                while(i + 1 < str.size() && str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '.') {
                    tmp += str[i + 1]; //??????
                    ++i;
                }
                vs.push_back(tmp);
            }
        }
    }
    while(!st.empty()) {
        string tmp = "";
        tmp += st.top();
        vs.push_back(tmp);
        st.pop();
    }
    return vs;
}
BigFloat Result(vector<string> bh)
{
    stack<BigFloat> st;
    BigFloat num, op1, op2;
    for(int i = 0; i < bh.size(); i++) {
        string tmp = bh[i];
        if(tmp[0] >= '0' && tmp[0] <= '9') {
            num = tmp;
            st.push(num);
        } else if(bh[i] == "+") {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            st.push(op1 + op2);
        } else if(bh[i] == "-") {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            st.push(op1 - op2);
        } else if(bh[i] == "*") {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            st.push(op1 * op2);
        } else if(bh[i] == "/") {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            st.push(op1 / op2);
        }
    }
    return st.top();
}
BigFloat lastans = 0;
BigFloat solve(string str)
{
    str = format(str);
    vector<string> bh = hz(str);
    BigFloat k = Result(bh);
    lastans = k;
    return k;
}
string Replace(string str){
	string s = "";
	int len = str.length();
	for(int i = 0;i < len - 2;i++){
		if(toupper(str[i]) == 'A' && toupper(str[i + 1]) == 'N' && toupper(str[i + 2]) == 'S'){
		    s += lastans.toString();
		    i += 2;
		}else
		    s += str[i];
	}
	if(toupper(str[len - 1]) != 'A' || toupper(str[len - 2]) != 'N' || toupper(str[len - 3]) != 'S')
	s = s + str[len - 2] + str[len - 1];
	return s;
}
//FINISH

//STRING TO INT (NOT VERY USEFUL)

int s2i(string s)
{
	int num=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		int ppast=pow(10,s.size()-1-i);
		if('0'<=s[i]&&s[i]<='9')
			num+=(s[i]-'0')*ppast;
		else return inf;
	}
	return num;
}

//FINISH

//CALENDAR

void calendar(int week,int year)
{
     int month_day[14]={31,31,0,31,30,31,30,31,31,30,31,30,31,31};
     char month_name[12][10]={"January","February","March","Apirl","May","June","July","August","September","October","November","December"};
     int i,j,n,m,num0=0,num1=31,nweek0=week,nweek1;
     if(year%4==0)
     {
        if(year%100!=0) month_day[2]=29;
        else
        {
            if(year%400==0) month_day[2]=29;
            else month_day[2]=28;
        }
     }
     else month_day[2]=28;
     cout<<"\n";
     printf("The calendar of the year %d\n",year);
     for(m=0;m!=12;m+=2)
     {
          if(m-1<0)
          {
                   nweek0=week;
                   nweek1=(week+num1%7)>7?(week+num1%7)-7:(week+num1%7);
          }
          else
          {
              num0=num0+month_day[m-1]+month_day[m];
              nweek0=(week+num0%7)>7?(week+num0%7)-7:(week+num0%7);
              num1=num1+month_day[m]+month_day[m+1];
              nweek1=(week+num1%7)>7?(week+num1%7)-7:(week+num1%7);
          }
          printf("%-10s %2d               %-10s %2d\n=========================== ===========================\nSun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat\n",month_name[m],m+1,month_name[m+1],m+2);
          for(i=nweek0,j=nweek1,n=0;j!=nweek1-6*7;j--)
          {
             if(n<7)
             {
                if(i>0) cout<<"    ";
                if(i<=0)
                {
                     if(i>-month_day[m+1]) printf("%3d ",-i+1);
                     else cout<<"    ";
                }
                i--;
                j+=1;
                n++;
             }
             else
             {
                if(j>0) cout<<"    ";
                else if(j<=0)
                {
                     if(j>-month_day[m+2]) printf("%3d ",-j+1);
                     else cout<<"    ";
                }
                n++;
             }
             if(n==14)
             {
                  printf("\n");
                  n=0;
             }
          }
          printf("=========================== ===========================\n\n");
     }

}

void startWeek(int year)
{
    int start_week,days;
    if(year>SIGN_YEAR)
    {
        days=(year-SIGN_YEAR)*365+(year-SIGN_YEAR)/4-(year-SIGN_YEAR)/100+(year-SIGN_YEAR)/400+(((year-SIGN_YEAR)%4)+3)/4+((year-SIGN_YEAR)%400==0?0:((year-SIGN_YEAR)%100==0?1:0));
        start_week=(SIGN_WEEK+days%7)>7?(SIGN_WEEK+days%7)-7:(SIGN_WEEK+days%7);
    }
    else
    {
        days=(SIGN_YEAR-year)*365+(SIGN_YEAR-year)/4-(SIGN_YEAR-year)/100+(SIGN_YEAR-year)/400;
        start_week=(SIGN_WEEK-days%7)>0?(SIGN_WEEK-days%7):(SIGN_WEEK-days%7+7);
    }
    calendar(start_week,year);
}

//FINISH

//EXOR

void print_chessboard(char coord[][3]){
    int i=0;
    int index_x=0;
    int index_y=0;
    for(i=1;i<=153;i++){
        char out_ch = ' ';
        if((i%51==20)||(i%51==26)||(i%51==32)){
            out_ch=coord[index_x][index_y];
            index_x++;
            if(index_x<3){
                index_x=0;
                index_y++;
            }
        }
        else if((i%17==6)||(i%17==12)) out_ch = '|';
        else if((i>=35&&i<=51&&i!=40&&i!=46)||(i>=86&&i<=102&&i!=91&&i!=97)) out_ch='_';
        putchar(out_ch);
        if(i%17==0) printf("\n");
    }
}
void winer(char coord[][3], int *flag);

int computer(char coord[][3]){
    int flag=0;
    int index_x2=0;
    int index_y2=0;
    srand(unsigned(time(NULL)));
    while(1){
        index_x2=(2*rand()/RAND_MAX)%3;
        index_y2=(2*rand()/RAND_MAX)%3;
        if((coord[index_x2][index_y2]!='*')&&(coord[index_x2][index_y2]!='o')){
            coord[index_x2][index_y2]='o';
            winer(coord, &flag);
            if(flag == 1) return 1;
            return 0;
        }
    }
}

int player(char coord[][3], int index_x1, int index_y1){//玩家
    int flag=0;
    int ret=0;
    if((coord[index_x1][index_y1]=='*')||(coord[index_x1][index_y1]=='o')){
        printf("There has already had a chess.\n");
        return 0;
    }
    else{
        coord[index_x1][index_y1]='*';
        if(flag==1) return 1;
        ret=computer(coord);
        if(ret==1) return 1;
        print_chessboard(coord);
        winer(coord, &flag);
    }
    return 0;
}

void winer(char coord[][3],int *flag){
    char line_ch[8][4]={{coord[0][0],coord[1][1],coord[2][2]},{coord[0][0],coord[0][1],coord[0][2]},
                        {coord[0][0],coord[1][0],coord[2][0]},{coord[0][1],coord[1][1],coord[2][1]},
                        {coord[0][2],coord[1][2],coord[2][2]},{coord[1][0],coord[1][1],coord[1][2]},
                        {coord[2][0],coord[2][1],coord[2][2]},{coord[0][2],coord[1][1],coord[2][0]}};
    int i=0;
    for(i=0;i<8;i++){
        if(strcmp(line_ch[i],"***")==0){
            print_chessboard(coord);
            printf("\nCongratulations, you win the game.\n");
            *flag = 1;
            return;
        }
        else if(strcmp(line_ch[i],"ooo")==0){
            print_chessboard(coord);
            printf("\nSorry, you are lost.\n");
            *flag = 1;
            return;
        }
        else{
        	int count = 0;
        	for(int i = 0;i < 3;i++){
        		for(int j = 0;j < 3;j++){
        			if(coord[i][j] == '*' || coord[i][j] == 'o')
        			    count++;
				}
			}
			if(count == 9){
        	    print_chessboard(coord);
        	    printf("\nDraw!\n");
        	    *flag = 1;
        	    return;
        	}
		}
    }
}

//FINISH

//SILVERSPHERE

struct pic{
	int n,m;
	int a[15][15];
} mapp[10];

int mp[10][15][15];
int k,tot,latestLevel;
map<string,int> lev;
bool playx = true;

void DrawMap() 
    {
    	system("cls");
        printf("Press 'e' for exit the game,'r' for restart\n'c' for choose the level,'w a s d' for move.\n");
        printf("LEVEL:%d\n",k+1);
			for (int i = 0; i < mapp[k].n; i++)
			{
				for (int j = 0; j < mapp[k].m; j++)
				{
					switch (mapp[k].a[i][j])
					{
					case 0:
						printf("  ");  //0 空地
						break;
					case 1:
						printf("■");  //1 墙
						break;
					case 3:
						printf("☆");  //3 目的地
						break;
					case 4:
						printf("□");  //4 箱子
						break;
					case 5:             
						printf("♀");  //5代表的人
						break;
					case 7:  //4+3  箱子+目的地
						printf("★");
						break;
					case 8: //5+3  人+目的地
						printf("♀");
						break;
					}
				}
				printf("\n");
			}
		}

		void initt(){
			for(int t = 0;t < tot;t++){
				for(int i = 0;i < mapp[t].n;i++){
					for(int j = 0;j < mapp[t].m;j++)
					    mapp[t].a[i][j] = mp[t][i][j];
				}
		    }
		}

        void save(int nth){
        	fstream file("ViolinOS.map.cof", ios::out);
        	file.close();
			FILE * fid = fopen("ViolinOS.map.cof","w");
        	fprintf(fid,"%d\n",tot);
        	for(int t = 0;t < tot;t++){
        		fprintf(fid,"%d %d\n",mapp[t].n,mapp[t].m);
        		for(int i = 0;i < mapp[t].n;i++){
        			for(int j = 0;j < mapp[t].m;j++)
        			    fprintf(fid,"%d ",mp[t][i][j]);
    			    fprintf(fid,"\n");
				}
			}
			us[loginIndex].txzLevel = max(us[loginIndex].txzLevel,nth);
        	fclose(fid);
		}
		
		//玩游戏的过程
		void PlayGame()
		{
			int r, c;  //人的行和列
		
			//人到底在哪里. // 5   8
			for (int i = 0; i < mapp[k].n; i++)
			{
				for (int j = 0; j < mapp[k].m; j++)
				{
					if (mapp[k].a[i][j] == 5 || mapp[k].a[i][j] == 8)
					{
						r = i;
						c = j;
					}
				}
			}
		
			printf("%d %d\n", r, c);
		
			int dir = getch();
			int key;
		
			//上下左右  if else
			switch (dir)
			{
			
			case 119:   //Up
				//游戏的规则:
				//1.人的前面是空地.//2.人的前面是目的地.
				if (mapp[k].a[r - 1][c] == 0||mapp[k].a[r - 1][c] == 3)
				{
					mapp[k].a[r - 1][c] += 5;
					mapp[k].a[r][c] -= 5;
				}
				//3.人的前面是箱子
				//3.1箱子的前面是空地.
				//3.2箱子的前面是目的地.
				else if (mapp[k].a[r - 1][c] == 4 || mapp[k].a[r - 1][c] == 7)
				{
					if (mapp[k].a[r - 2][c] == 0 || mapp[k].a[r - 2][c] == 3)
					{
						mapp[k].a[r - 2][c] += 4;
						mapp[k].a[r - 1][c] += 1;
						mapp[k].a[r][c] -= 5;
					}
				}
		
				break;
		
			case 115: //Down
				if (mapp[k].a[r +1][c] == 0 || mapp[k].a[r + 1][c] == 3)
				{
					mapp[k].a[r + 1][c] += 5;
					mapp[k].a[r][c] -= 5;
				}
				//3.人的前面是箱子
				//3.1箱子的前面是空地.
				//3.2箱子的前面是目的地.
				else if (mapp[k].a[r + 1][c] == 4 || mapp[k].a[r + 1][c] == 7)
				{
					if (mapp[k].a[r+ 2][c] == 0 || mapp[k].a[r + 2][c] == 3)
					{
						mapp[k].a[r+ 2][c] += 4;
						mapp[k].a[r + 1][c] += 1;
						mapp[k].a[r][c] -= 5;
					}
				}
				break;
		
			case 97:    //Left
				if (mapp[k].a[r][c - 1] == 0 || mapp[k].a[r][c - 1] == 3)
				{
					mapp[k].a[r][c - 1] += 5;
					mapp[k].a[r][c] -= 5;
				}
				//3.人的前面是箱子
				//3.1箱子的前面是空地.
				//3.2箱子的前面是目的地.
				else if (mapp[k].a[r][c - 1] == 4 || mapp[k].a[r ][c - 1] == 7)
				{
					if (mapp[k].a[r][c - 2] == 0 || mapp[k].a[r][c - 2] == 3)
					{
						mapp[k].a[r][c - 2] += 4;
						mapp[k].a[r][c - 1] += 1;
						mapp[k].a[r][c] -= 5;
					}
				}
				break;
		
			case 100: // Right
				if (mapp[k].a[r][c + 1] == 0 || mapp[k].a[r][c + 1] == 3)
				{
					mapp[k].a[r][c + 1] += 5;
					mapp[k].a[r][c] -= 5;
				}
				else if (mapp[k].a[r][c + 1] == 4 || mapp[k].a[r][c+ 1] == 7)
				{
					if (mapp[k].a[r][c + 2] == 0 || mapp[k].a[r][c + 2] == 3)
					{
						mapp[k].a[r][c + 2] += 4;
						mapp[k].a[r][c + 1] += 1;
						mapp[k].a[r][c] -= 5;
					}
				}
				break;
		
		    case 99: // choose the level
		    	printf("Do you want to choose level? ('y' for Yes,'n' for no)\n");;
				key = 0;
				while(key != 121 && key != 110){
				    key = getch();
				}
		        if(key == 110)
		            break;
                printf("Which level do you want to choose? (press a number from 1 to %d)\n",max(latestLevel,k)+1);
                key = 0;
                while(1){
                	key = 0;
				    while(key < 49 || key > 57){
				        key = getch();
				    }
				    if(key >= 49 && key <= 49 + max(latestLevel,k))
				        break;
                    else
                        printf("You haven't passed this level. You can't choose it. Please choose another one.\n");
				}
				k = key - 49;
				break;		    	
		
			case 114: //restart Press R
			    initt();
			    break;
		 
			case 101: //exit Press E
				printf("Do you want to exit? ('y' for Yes,'n' for no)\n");
				key = 0;
				while(key != 121 && key != 110){
				    key = getch();
				}
		        if(key == 121){
		            playx = false;
		        }
		        break;		
			}	
		}
		
		void ini(){
			ifstream infile;
			infile.open("ViolinOS.map.cof");
			infile >> tot;
			for(int t = 0;t < tot;t++){
				infile >> mapp[t].n >> mapp[t].m;
				for(int i = 0;i < mapp[t].n;i++){
					for(int j = 0;j < mapp[t].m;j++){
					    infile >> mp[t][i][j];
					}
				}
			}
            k = us[loginIndex].txzLevel;
            infile.close();
		}
		
		bool Check(){ 
			bool f = true;
			for(int i = 0;i < mapp[k].n;i++){
				for(int j = 0;j < mapp[k].m;j++){
					if(mapp[k].a[i][j] == 3 || mapp[k].a[i][j] == 8)
					    f = false;
				}
			}
			return f;
		}
		
		void NextLevel(){ // 下一关 
		    system("cls");
		    DrawMap();
		    sleep(1);
			printf("Congratulations!!!\tMisson Passed!!!\n");
			printf("Press and key to continue...\n");
			while(!_kbhit()); // 等待键盘按下
			k++;
			save(k);
			if(k == tot){
				printf("Well Done!!!\t You passed all the missons!!!\n");
				printf("Press 'r' for restart,'e' for exit.\n");
				save(0);
				int key = getch();
				while(key != 114 && key != 101)
				    key = getch();
		        if(key == 114)
				    k = 0;
				else if(key == 101){
				    playx = false;
				}
			}
		}

void playSliverspare(){
	ini();
	initt();
	while (playx){
		DrawMap();
		PlayGame();
		if(Check())
			NextLevel();
	}
	playx=true;	
}

//FINISH

//EXOR
void playEXOR(){
    srand(unsigned(time(NULL)));
	int num=0;
 	int x=0;
  	int y=0;
   	int i=4;
	int ret=0;
	int is_play=0;
	char coordinate[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	computer(coordinate);
 	print_chessboard(coordinate);
  	while((i)){
   	    printf("Please input x and y to put the chess(0 to 2)\n(Example:\n0 0\t0 1\t0 2\n1 0\t1 1\t1 2\n2 0\t2 1\t2 2)\nInput -1 -1 to exit.\n");
        scanf("%d %d",&x,&y);
        if(x == -1 && y == -1)
            return;
	    if(x < 0 || x > 2 || y < 0 || y > 2){
  		    while(x < 0 || x > 2 || y < 0 || y > 2){
      		    printf("Wrong positon. Please input again.\n");
          		i++;
       	    	scanf("%d %d",&x,&y);
           	}
		}
  		ret=player(coordinate,x,y);
    	if(ret==1){
    		printf("Press any key to continune...\n");
    		while(!_kbhit());
    		return;
		}
     	if(ret==0)
	 	    i++;
   		i--;
    }
}
  
//FINISH

//2048

int const ROW = 4;  
int const COL = 4;  
int game[ROW][COL] = {0};  
  
//上下左右  
int const UP = 1;  
int const DOWN = 2;  
int const LEFT = 3;  
int const RIGHT = 4;  
  
//游戏所处的状态  
int const GAME_OVER = 1;  
int const GAME_WIN = 2;  
int const GAME_CONTINUE = 3;  
  
enum GameNum  
{  
    Game_2 = 2,  
    Game_4 = 4,  
    Game_8 = 8,  
    Game_16 = 16,  
    Game_32 = 32,  
    Game_64 = 64,  
    Game_128 = 128,  
    Game_256 = 256,  
    Game_512 = 512,  
    Game_1024 = 1024,  
    Game_2048 = 2048,  
};  
  
//打印所得的数组  
void Print()  
{  
    system("cls");
   	printf("Press ↑↓← →to play this game,'Esc' to exit.\n");
    for (int i = 0; i < ROW; ++i)  
    {  
        cout << "---------------------------------"<< endl;  
        for (int j = 0; j < COL; ++j)  
        {  
            if (game[i][j] == 0)  
            {  
                cout <<"|   \t";  
            }  
            else   
            {  
                cout <<"|   " << game[i][j] << "\t";  
            }  
        }  
        cout << "|" << endl;  
    }  
    cout << "---------------------------------"<< endl;  
}  
  
  
bool CreateNumber()  
{  
    int x = -1;  
    int y = -1;  
    int times = 0;  
    int maxTimes = ROW * COL;
    int whitch = rand() % 3;
    for(;game[x][y] != 0 && times <= maxTimes;times++){
        x = rand() % ROW;  
        y = rand() % COL;  
  	}
    //说明格子已经满了  
    if(times >= maxTimes)  
    {  
        return false;  
    }  
    else  
    {  
        GameNum num;  
        if(whitch == 0)  
        {  
            num = Game_2;  
        }  
        else if(whitch)  
        {  
            num = Game_4;  
        }  
        game[x][y] = num;  
    }  
  
    return true;  
}  
  
void Process(int direction)  
{  
    switch (direction)  
    {  
    case UP:  
        //最上面一行不动  
        for(int row = 1; row < ROW; ++row)  
        {  
            for(int crow = row; crow >= 1; --crow)  
            {  
                for(int col = 0; col < COL; ++col)  
                {  
                    //上一个格子为空  
                    if(game[crow-1][col] == 0)  
                    {  
                        game[crow-1][col] = game[crow][col];  
                        game[crow][col] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[crow-1][col] == game[crow][col])  
                        {  
                            game[crow - 1][col] *= 2;  
                            game[crow][col] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case DOWN:  
        //最下面一行不动  
        for(int row = ROW - 2; row >= 0; --row)  
        {  
            for(int crow = row; crow < ROW - 1; ++crow)  
            {  
                for(int col = 0; col < COL; ++col)  
                {  
                    //上一个格子为空  
                    if(game[crow + 1][col] == 0)  
                    {  
                        game[crow + 1][col] = game[crow][col];  
                        game[crow][col] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[crow + 1][col] == game[crow][col])  
                        {  
                            game[crow + 1][col] *= 2;  
                            game[crow][col] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case LEFT:  
        //最左边一列不动  
        for(int  col = 1; col < COL; ++col)  
        {  
            for(int ccol = col; ccol >= 1; --ccol)  
            {  
                for(int row = 0; row < ROW; ++row)  
                {  
                    //上一个格子为空  
                    if(game[row][ccol-1] == 0)  
                    {  
                        game[row][ccol - 1] = game[row][ccol];  
                        game[row][ccol] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[row][ccol - 1] == game[row][ccol])  
                        {  
                            game[row][ccol - 1] *= 2;  
                            game[row][ccol] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case RIGHT:  
        //最右边一列不动  
        for(int  col = COL - 2; col >= 0; --col)  
        {  
            for(int ccol = col; ccol <= COL - 2; ++ccol)  
            {  
                for(int row = 0; row < ROW; ++row)  
                {  
                    //上一个格子为空  
                    if(game[row][ccol + 1] == 0)  
                    {  
                        game[row][ccol + 1] = game[row][ccol];  
                        game[row][ccol] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[row][ccol + 1] == game[row][ccol])  
                        {  
                            game[row][ccol + 1] *= 2;  
                            game[row][ccol] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    }  
  
}  
  
//处理输入输出，返回上下左右  
int Input()  
{  
    //读取上下左右四个方向键  
    int upArrow = 0;  
    int downArrow = 0;  
    int leftArrow = 0;  
    int rightArrow = 0;  
    int direction = 0; 
    int key = 0;
    while (true)  
    {  	
        upArrow = GetAsyncKeyState(VK_UP);  
        downArrow = GetAsyncKeyState(VK_DOWN);  
        leftArrow = GetAsyncKeyState(VK_LEFT);  
        rightArrow = GetAsyncKeyState(VK_RIGHT);  
        key = getch();
  		
  		if(key == 101)
  			return -1;
        else if(upArrow)  
        {  
            direction = UP;  
            break;  
        }  
        else if(downArrow)  
        {  
            direction = DOWN;  
            break;  
        }  
        else if(leftArrow)  
        {  
            direction = LEFT;  
            break;  
        }  
        else if(rightArrow)  
        {  
            direction = RIGHT;  
            break;  
        }  
  
        Sleep(100);  
    }  
  
    return direction;  
}  
  
//判断游戏状态  
int Judge()  
{  
    //赢得游戏  
    for(int i = 0; i < ROW; ++i)  
    {  
        for(int j = 0; j < COL; ++j)  
        {  
            if(game[i][j] == 2048)  
            {  
                return GAME_WIN;  
                break;  
            }  
        }  
    }  
  
    //横向检查  
    for(int i = 0 ; i < ROW; ++i)  
    {  
        for(int j = 0; j < COL - 1; ++j)  
        {  
            if(!game[i][j] || (game[i][j] == game[i][j+1]))  
            {  
                return GAME_CONTINUE;  
                break;  
            }  
        }  
    }  
    //纵向检查  
    for(int j = 0; j< COL; ++j)  
    {  
        for(int i = 0; i < ROW -1; ++i)  
        {  
            if(!game[i][j] || (game[i][j] == game[i+1][j]))  
            {  
                return GAME_CONTINUE;  
                break;  
            }  
        }  
    }  
  
    //不符合上述两种状况，游戏结束  
    return GAME_OVER;  
  
}  
  
void play2048()  
{  
    //设置一个随机数种子
    START:
   	system("cls");
   	printf("Press ↑↓← →to play this game,'Esc' to exit.\n");
    srand((unsigned int)time(0));  
    memset(game,0,sizeof(game));
    CreateNumber();  
    CreateNumber();  
    Print();
    int direction = 0;
    int gameState = -1;  
    while(true)  
    {  
        direction = Input();  
  		if(direction == -1)
  		    return;
        gameState = Judge();  
        if(direction && gameState == GAME_CONTINUE)  
        {  
            Process(direction);  
            CreateNumber();  
            Print();  
            Sleep(100);
        }  
        else if(gameState == GAME_WIN)  
        {  
            Print();  
            cout << "You Win！" << endl;
            printf("Do you want to play again? Press 'y' for yes,'n' for no.\n");
			int key = getch();
			while(key != 'n' && key != 'y')
				key = getch();
		    if(key == 'n')
				return;
			else
			    goto START;
        }  
        else if(gameState == GAME_OVER)  
        {  
            Print();  
            cout <<"You Lose!" << endl;  
            printf("Do you want to play again? Press 'y' for yes,'n' for no.\n");
			int key = getch();
			while(key != 'n' && key != 'y')
				key = getch();
		    if(key == 'n')
				return;
			else
			    goto START;
        }  
    }
} 
//FINISH

//Guess Number
const int N = 2;
const int M = 3;
bool mord[M+1];
int maxc[M+1],c[M+1]= {0},np,point[10];
char name[10][20];

void color(int a) { //颜色函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void gotoxy(int x,int y) { //位置函数
	COORD pos;
	pos.X=2*x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void play();
void set_g(int set1);

void playGuess_Number(){
	map<int,string>ma;
	char chti[10]= {" ·>"};
	ma[1]="单人竞猜";
	ma[2]="多人竞猜";
	ma[N+1]="返回";
	int ch=1;
	system("color f0");
	while(1) {
		for(int i=1; i<=N+1; i++) {
			if(i==ch) {
				color(192);
				printf("%s",chti);
			} else {
				color(240);
				for(int i=1; i<=strlen(chti); i++)
					printf(" ");
			}
			cout<<ma[i];
			cout << endl;
			color(240);
		}
		char x;
		x=getch();
		if(x=='w'&&ch>1)ch--;
		if(x=='s'&&ch<N+1)ch++;
		if(x==13) {
			if(ch==N+1)
				return;
			switch(ch) {
				case 1:
					np=1;
					break;
				case 2:
					system("cls");
					printf("请输入玩家数：\n");
					cin>>np;
					break;
			}
			set_g(ch);
		}
		system("cls");
	}
}

void set_g(int set1) {
	system("cls");
	bool setmord[N+1][M+1]= {
		{1,0,0,0}, //空行
		{1,1,1,0},
		{1,1,1,1}
	};
	map<int,string>ma;
	char chti[10]= {" ·>"};
	ma[1]="难度";
	maxc[1]=4;
	ma[2]="噩梦";
	maxc[2]=3;
	ma[3]="自动跳过";
	maxc[3]=5;
	ma[M+1]="下一步";
	ma[M+2]="返回";
	int ch=1;
	system("color f0");
	for(int i=1; i<=M; i++)
		mord[i]=setmord[set1][i];
	while(1) {
		for(int i=1; i<=M+2; i++) {
			if(i<=M&&!mord[i])
				continue;
			if(i==ch) {
				color(192);
				printf("%s",chti);
			} else {
				color(240);
				for(int i=1; i<=strlen(chti); i++)
					printf(" ");
			}
			cout<<ma[i];
			cout << endl;
			if(i<=M) {
				gotoxy(20,i-1);
				int co=i==ch?192:240;
				for(int j=0; j<=maxc[i]; j++) {
					if(j!=c[i])co+=8;
					color(co);
					printf("%d",j);
					if(j!=c[i])co-=8;
					color(co);
					printf(" ");
				}
				gotoxy(0,i);
			}
			color(240);
		}
		char x;
		x=getch();
		if(x=='w'&&ch>1) {
			ch--;
			while(!mord[ch]&&ch<=M)ch--;
		}
		if(x=='s'&&ch<M+2) {
			ch++;
			while(!mord[ch]&&ch<=M)ch++;
		}
		if(ch<=M) {
			if(x=='d'&&c[ch]<maxc[ch])
				c[ch]++;
			if(x=='a'&&c[ch]>=1)
				c[ch]--;
		}
		if(x==13) {
			if(ch==M+2)
				return;
			if(ch==M+1)
				break;
		}
		system("cls");
	}
	system("cls");
	bool flag=0;
	for(int i=1; i<=np; i++) {
		if(flag||set1==1)printf("请输入玩家%d名字：\n",i);
		gets(name[i]);
		point[i]=0;
		if(!flag&&set1!=1) {
			i--;
			flag=1;
		}
	}
	Sleep(500);
	play();
	return;
}
void play() {
	system("cls");
	srand(time(NULL));
	int fw1,fw2=1,ans;
	if(c[1]==0)fw1=5000;
	else fw1=10000*c[1];
	ans=rand()%fw1+1;
	printf("数据范围1~%d\n",fw1);
	system("pause");
	system("cls");
	int findit=0,l=0,lnum,ld,lz,em;
	bool around=0;
	while(!findit) {
		printf("提示： ");
		if(c[2]==0)printf("未开启\n");
		else printf("%5d ~ %5d \n",fw2,fw1);
		printf("噩梦： ");
		if(em==1)printf("数变大了\n");
		if(em==-1)printf("数变小了\n");
		else printf("未发生\n");
		printf("\n上一回合：\n");
		if(around) {
			cout<<"玩家"<<l<<" "<<name[l]<<endl;
			if(ld!=2)printf("%d\n",lnum);
			if(ld==1)printf("大了 ");
			if(ld==-1)printf("小了 ");
			if(ld==0)printf("出错\n");
			if(ld==2)printf("被跳过\n");
			else
				switch(lz) {
					case 1:
						color(252);
						point[l]+=7;
						printf("近在眼前\n");
						break;
					case 2:
						color(253);
						point[l]+=5;
						printf("百步之遥\n");
						break;
					case 3:
						color(249);
						point[l]+=3;
						printf("仰望莫及\n");
						break;
					case 4:
						color(240);
						point[l]+=1;
						printf("远在天边\n");
						break;
				}
			color(240);
		} else {
			printf("无\n\n");
			around=1;
		}
		Sleep(500);
		l=l%np+1;
		printf("\n当前回合：\n");
		cout<<"玩家"<<l<<" "<<name[l];
		ld=rand()%10<c[3]?2:0;
		if(ld==2) {
			printf("\n回合被跳过\n");
			Sleep(2000);
			system("cls");
			continue;
		}
		printf(" 请猜数：\n");
		char readn[20];
		gets(readn);
		cout << readn << endl;
		if(readn == "exit"){
			cout << 1 << endl;
		    return;
		}
		lnum=0;
		for(int i=0; i<strlen(readn)&&readn[i]<='9'&&readn[i]>='0'; i++)
			lnum=lnum*10+readn[i]-'0';
		if(lnum<=0||lnum>=40000) {
			ld=0;
			lz=0;
		} else {
			if(lnum>ans) {
				ld=1;
				if(lnum<fw1)fw1=lnum;
			}
			if(lnum<ans) {
				ld=-1;
				if(lnum>fw2)fw2=lnum;
			}
			if(lnum==ans)findit=1;
			lz=abs(lnum-ans);
			if(lz<=10)lz=1;
			else if(lz<=100)lz=2;
			else if(lz<=1000)lz=3;
			else lz=4;
		}
		if(findit)
			printf("正确\n");
		else {
			if(ld==1)printf("大了 ");
			if(ld==-1) printf("小了 ");
			if(ld==0)printf("出错\n");
			switch(lz) {
				case 1:
					color(252);
					printf("近在眼前\n");
					break;
				case 2:
					color(253);
					printf("百步之遥\n");
					break;
				case 3:
					color(249);
					printf("仰望莫及\n");
					break;
				case 4:
					color(240);
					printf("远在天边\n");
					break;
			}
			color(240);
		}
		em=0;
		if(lz<=3&&c[2]) {
			em=rand()%2==0?-1:1;
			int em1;
			em1=rand()%(2*c[2]);
			if(em1*em>40000||em1*em<=0)em=em*-1;
			ans=ans+em*em1;
			if(em==1)
				fw1+=2*c[2];
			else
				fw2-=2*c[2];
		}
		Sleep(1000);
		system("cls");
	}
	point[l]+=20;
	printf("玩家%d %s 猜对了\n",l,name[l]);
	system("pause");
	system("cls");
	int poi=0;
	for(int i=1; i<=np; i++)poi+=point[i];
	poi=poi/100+1;
	for(int i=1; i<=np; i++) {
		point[i]=point[i]/poi;
		printf("玩家%d %s 得分 ",i,name[i]);
		if(point[i]>=50)color(254);
		else if(point[i]>=30)color(249);
		else if(point[i]>=20)color(250);
		else color(248);
		printf("%d\n",point[i]);
		color(240);
		Sleep(500);
	}
	system("pause");
}
//FINISH

//Russia
#define GameW 10
#define GameH 20
const int CtrlLeft = GameW*2+4 + 3;
struct Point {
    Point(){}
    Point(int x, int y) {_x = x, _y = y;}
    int _x, _y;
};
HANDLE g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE g_hInput  = GetStdHandle(STD_INPUT_HANDLE);
Point g_ptCursor(0,0);
BOOL isChecking = FALSE;
BOOL g_bGameOver = FALSE;
int g_nGameBack[GameH][GameW], Case;
int nowKeyInfo = -1;
int g_nDiff = 1;
int g_nLife = 1;
int g_nScore = 0;
bool exitRussia = false;
bool restartRussia = false;

void SetCursor(COORD cd) {
    SetConsoleCursorPosition(g_hOutput, cd);
}
void SetCursor(int x, int y){
    COORD cd = {x, y};
    SetCursor(cd);
}
void SetBlockCursor(int x, int y){
    COORD cd = {2*x + 2, y + 1};
    SetCursor(cd);
}
void SetBack(int x, int y, BOOL bk) {
    SetBlockCursor(x, y);
    if (bk) 
        printf("%s", "■");
    else
        printf("　");
}
bool Out(int x, int y) {
    return x < 0 || y < 0 || x >= GameW || y >= GameH; 
}
struct xBlock {
public:

    int len;
    int nowRotateID;
    BOOL mask[4][4][4];
    static vector <xBlock> List;
    xBlock() { len = 0; }
    xBlock(int l, char *str) {
        int i, j, k;
        len = l;
        memset(mask, FALSE, sizeof(mask));
        for(i = 0; i < l; i++) {
            for(j = 0; j < l; j++) {
                mask[0][i][j] = str[i*l + j] - '0';
            }
        }
        for(k = 1; k < 4; k++) {
            for(i = 0; i < len; i++) {
                for(j = 0; j < len; j++) {
                    mask[k][i][j] = mask[k-1][j][len-1-i];
                }
            }
        }
        nowRotateID = rand() % 4;
    }
    void rotate() {
        nowRotateID ++;
        if (nowRotateID >= 4)
            nowRotateID = 0;
    }
    BOOL getUnit(int x, int y, int roID) {
        if (roID == -1) {
            roID = nowRotateID;
        }
        return mask[roID][y][x];
    }
};
vector <xBlock> xBlock::List;
class Block {
public:

    int x, y;
    int ID;
    xBlock bk;
    void reset(xBlock *pbk) {
        bk = *pbk;
        x = 4, y = 0;
        ID = ++ Case;
        if(collide(0,0)) {
            lifeDown();
        }
        draw();
        *pbk = xBlock::List[rand() % xBlock::List.size()];
    }
    void lifeDown() {
        int i, j;
        for(i = 0; i < GameH; i++) {
            for(j = 0; j < GameW; j++) {
                SetBack(j, i, TRUE);
                Sleep(10);
            }
        }
        if(g_nLife > 1) {
            g_nLife --;
            for(i = g_nLife; i < 6; i++) {
                SetCursor(CtrlLeft + i, 15);
                printf("%c", ' ');
            }
            for(i = GameH-1; i >= 0; i--) {
                for(j = GameW-1; j >= 0; j--) {
                    SetBack(j, i, FALSE);
                    Sleep(10);
                    g_nGameBack[i][j] = 0;
                }
            }
        }else {
            g_bGameOver = TRUE;
        }
    }
    void erase() {
        int i, j;
        for(i = 0; i < bk.len; i++) {
            for(j = 0; j < bk.len; j++) {
                if (bk.getUnit(j, i, -1)) {
                    if(!Out(j+x, i+y) && g_nGameBack[i+y][j+x]) {
                        SetBack(j+x, i+y, FALSE);
                        g_nGameBack[i+y][j+x] = 0;
                    }
                }
            }
        }
    }
    void draw() {
        int i, j;
        for(i = 0; i < bk.len; i++) {
            for(j = 0; j < bk.len; j++) {
                if (bk.getUnit(j, i, -1)) {
                    if(!Out(j+x, i+y) && !g_nGameBack[i+y][j+x]) {
                        SetBack(j+x, i+y, TRUE);
                        g_nGameBack[i+y][j+x]  = ID;
                    }
                }
            }
        }
    }
    void draw(int x, int y) {
        int i, j;
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                SetCursor(x + 2*j, y + i);
                if (bk.getUnit(j, i, -1)) {    
                    printf("%s", "■");
                }else 
                    printf("　");
            }
        }
    }
    bool collide(int dx, int dy, int roID = -1) {
        int i, j;
        for(i = 0; i < bk.len; i++) {
            for(j = 0; j < bk.len; j++) {
                if (bk.getUnit(j, i, roID)) {
                    Point ptPos(j + x + dx, i + y + dy);
                    if(Out(ptPos._x, ptPos._y)
                    || g_nGameBack[ptPos._y][ptPos._x] && ID != g_nGameBack[ptPos._y][ptPos._x]) {
                        return TRUE;
                    }
                }
            }
        }
        return FALSE;
    }
    void rotate(int nTimes = 1) {
        int nextro = (bk.nowRotateID + nTimes) % 4;
        if(collide(0, 0, nextro)) {
            return ;
        }
        Beep(12000, 50);
        erase();
        bk.nowRotateID = nextro;
        draw();
    }
    BOOL changepos(int dx, int dy) {
        if(collide(dx, dy)) {
            return FALSE;
        }
        erase();
        x += dx;
        y += dy;
        draw();
        return TRUE;
    }
};
void GameInit() {
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize   = 100;
    SetConsoleCursorInfo(g_hOutput, &cursor_info);
    xBlock::List.push_back(xBlock(3, "010111000"));
    xBlock::List.push_back(xBlock(3, "110110000"));
    xBlock::List.push_back(xBlock(3, "111001000"));
    xBlock::List.push_back(xBlock(3, "111100000"));
    xBlock::List.push_back(xBlock(3, "110011000"));
    xBlock::List.push_back(xBlock(3, "011110000"));
    xBlock::List.push_back(xBlock(4, "1000100010001000"));
}
void DrawFrame(int x, int y, int nWidth, int nHeight) {
    int i;
    for(i = 0; i < nWidth; i++) {
        SetCursor(x + 2*i + 2, y);
        printf("%s", "一");
        SetCursor(x + 2*i + 2, y + nHeight+1);
        printf("%s", "┄");
    }
    for(i = 0; i < nHeight; i++) {
        SetCursor(x, y + i + 1);
        printf("%s", "┆");
        SetCursor(x + nWidth*2+2, y + i + 1);
        printf("%s", "┆");
    }        
    SetCursor(x, y);
    printf("%s", "┌");    
    SetCursor(x, y + nHeight+1);
    printf("%s", "└");
    SetCursor(x + nWidth*2+2, y);
    printf("%s", "┐");    
    SetCursor(x + nWidth*2+2, y + nHeight+1);
    printf("%s", "┘");
}
void MissionInit() {
    memset(g_nGameBack, FALSE, sizeof(g_nGameBack));
    Case = 1;
    int i;
    DrawFrame(0, 0, GameW, GameH);
    DrawFrame(GameW*2+4, 0, 6, GameH);
    SetCursor(CtrlLeft, 2);
    printf("Next");
    SetCursor(CtrlLeft, 8);
    printf("Speed");
    for(i = 0; i < g_nDiff; i++) {
        SetCursor(CtrlLeft + i, 9);
        printf("%d", 1);
    }
    SetCursor(CtrlLeft, 11);
    printf("Score");
    SetCursor(CtrlLeft, 12);
    printf("%d", g_nScore);
    SetCursor(CtrlLeft, 14);
    printf("Life");
    SetCursor(CtrlLeft + i, 15);
    printf("%d", g_nLife);
    SetCursor(CtrlLeft - 1.5, 16);
    printf("←→to move.");
    SetCursor(CtrlLeft - 1.5, 17);
    printf("↑to rotate.");
}
void CheckRussia() {
    isChecking = TRUE;
    int i, j, k;
    vector <int> line;
    for(i = 0; i < GameH; i++) {
        for(j = 0; j < GameW; j++) {
            if(!g_nGameBack[i][j])
                break;
        }
        if(j == GameW) {
            line.push_back(i);
        }
    }
    if(line.size()) {
        int nCount = 7;
        while(nCount --) {
            for(i = 0; i < line.size(); i++) {
                for(j = 0; j < GameW; j++) {
                    SetBack(j, line[i], nCount&1);
                }
            }
            Sleep(70);
        }
        for(i = 0; i < line.size(); i++) {
            for(j = 0; j < GameW; j++) {
                g_nGameBack[line[i]][j] = 0;
            }
        }
        for(i = 0; i < GameW; i++) {
            int next = GameH-1;
            for(j = GameH-1; j >= 0; j--) {
                for(k = next; k >= 0; k--) {
                    if(g_nGameBack[k][i]) 
                        break;
                }
                next = k - 1;
                BOOL is = (k >= 0);
                SetBack(i, j, is);
                g_nGameBack[j][i] = is;
            }
        }
        g_nScore += 2*line.size()-1;
        SetCursor(CtrlLeft, 12);
        printf("%d", g_nScore);
        if( g_nScore >= g_nDiff * g_nDiff * 10) {
            if(g_nDiff <= 6)
                g_nDiff ++;
        }
        if( g_nScore >= 50 * (g_nLife+1)) {
            if(g_nLife <= 6)
                g_nLife ++;
        }
    }
    isChecking = FALSE;
}

void playRussiaMain(){
    Block* obj = new Block();
    Block* buf = new Block();
    BOOL bCreateNew = FALSE;
    int nTimer = GetTickCount();
    int LastKeyDownTime = GetTickCount();
    GameInit();
    MissionInit();
    buf->bk = xBlock::List[rand() % xBlock::List.size()];
    while(1) {
    	if(exitRussia || restartRussia)
    	    return;
        if(!bCreateNew) {
            bCreateNew = TRUE;
            obj->reset(&buf->bk);
            if(g_bGameOver)
                break;
            buf->draw(CtrlLeft - 1, 4);
        }
        if (GetTickCount() - nTimer >= 1000 / g_nDiff) {
            nTimer = GetTickCount();
            if (!obj->collide(0, 1))
                obj->changepos(0, 1);
            else {
                CheckRussia();
                bCreateNew = FALSE;
            }
        }
        if (GetTickCount() - LastKeyDownTime >= 100) {
            if(FALSE == isChecking) {
                LastKeyDownTime = GetTickCount();
                if (GetAsyncKeyState(VK_UP)) {
                    obj->rotate();
                }
                if (GetAsyncKeyState(VK_LEFT)) {
                    obj->changepos(-1, 0);
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    obj->changepos(1, 0);
                }
                if (GetAsyncKeyState(VK_DOWN)) {
                    if( FALSE == obj->changepos(0, 2) )
                        obj->changepos(0, 1);
                }
            }
        }
    }
    SetCursor(8, 10);
    printf("Game Over");
    SetCursor(0, GameH+3);
    system("pause");
}

void checkRussiaEnd(){
	while(1){
		int key;
		key = getch();
		if(key == 101){
			exitRussia = true;
			return;
		}
	}
}

void playRussia(){
	thread russiaMain(playRussiaMain);
	thread checkEnd(checkRussiaEnd);
	checkEnd.join();
	russiaMain.join();
}

//FINISH

//Name PK

//FINISH

// INTRODUCE US
string introduce(){
    string s;
	s += "Violin Inc.\n";
	s += "Which is a computer operating system company which was founded in 2010 by William Han.\n";
	s += "It has 6 programmers. As William Han said,\n";
	s += "'I want to help more and more people to use their computer better.'\n";
	s += "You can find more about us on our webset.\n";
	s += "Do you want to visit our webset? (Press 'y' for yes,'n' for no)\n";
	int key = 0;
	while(key != 121 && key != 110){
	    key = getch();
	}
	if(key == 121)
    	ShellExecute(NULL, "open", "https://violinnet.icoc.bz", NULL, NULL, SW_SHOWNORMAL);
}

//FINISH

//window config

string changeFont,changeWindow;
int choose = 1,changeHeight,changeWidth,selection = 1;

void out();

void printSelection(){
	system("cls");
	printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
	printf("1.change the background color");
	if(choose == 1)
		printf(" <--");
	printf("\n");
	printf("2.change the font color");
	if(choose == 2)
		printf(" <--");
	printf("\n");
	printf("3.change the width and height of the window");
	if(choose == 3)
		printf(" <--");
	printf("\n");
	printf("4.reset to default configuration");
	if(choose == 4)
		printf(" <--");
	printf("\n");
}

void printSelection2(){
	system("cls");
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	printf("<1>use the key to change");
	if(selection == 1)
		printf(" <--");
    printf("\n");
	printf("<2>input height and width to change");
	if(selection == 2)
		printf(" <--");
    printf("\n");
}

void changeWindowColor(){
	string changeColor = "COLOR " + windowColor[loginIndex] + fontColor[loginIndex];
	system(changeColor.c_str());
}

void changeWindowSize(){
	char width[50],height[50];
	sprintf(width,"%d",windowWidth[loginIndex]);
	sprintf(height,"%d",windowHeight[loginIndex]);
	//cout << width << " " << height << endl;
	string cmd = "mode con:cols="+(string)width+" lines="+(string)height;
	system(cmd.c_str());
	/*
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rc = {0,0, windowWidth[loginIndex], windowHeight[loginIndex]};
	SetConsoleWindowInfo(hOut,true ,&rc);
	*/
}

void changeWH(){
	system("cls");
	int key = 0;
    double dur;
    clock_t start,end;
	if(selection == 1){
		start = clock();
		printf("Use 'w s' to change height,'a d' to change width.\n");
		printf("Press 'Esc' to exit.\n");
		printf("Width : %d\n",changeWidth);
		printf("Height : %d\n",changeHeight);
		while(1){
			key = getch();
			if(key != 0){
                end = clock();
    			dur = (double)(end - start);
    			if(dur/CLOCKS_PER_SEC < 0.02){
    				key = 0;
    			    continue;
    			}
				switch(key){
				    case 27:
			 			printf("Do you want to save the changes? ('y' for yes,'n' for no)\n");
						while(key != 121 && key != 110){
							key = getch();
						}
						if(key == 121){
							windowWidth[loginIndex] = changeWidth;
							windowHeight[loginIndex] = changeHeight;
							out();
						}
						else
							changeWindowSize();
						return;
						break;
					case 119: // up
					    changeHeight--;
						if(changeHeight <= 1){
						    changeHeight = 1;
						    MessageBox(NULL, ("Min Height!"), ("Warning"), MB_OK);
						}
						break;
		            case 115: // down
		            	changeHeight++;
		            	/*
						if(changeHeight > 39){
						    changeHeight = 39;
						    MessageBox(NULL, ("Max Height!"), ("Warning"), MB_OK);
						}*/
						break;
		            case 97: // left
		            	changeWidth--;
						if(changeWidth <= 1){
						    changeWidth = 1;
						    MessageBox(NULL, ("Min Width!"), ("Warning"), MB_OK);
						}
						break;
		            case 100: // right
		            	changeWidth++;
		            	/*
						if(changeWidth > 99){
						    changeWidth = 99;
						    MessageBox(NULL, ("Max Width"), ("Warning"), MB_OK);
						}
						*/
						break;
				}
				system("cls");
				printf("Use w s' to change height,'a d' to change width.\n");
				printf("Press 'Esc' to exit.\n");
				printf("Width : %d\n",changeWidth);
				printf("Height : %d\n",changeHeight);
				char width[50],height[50];
				sprintf(width,"%d",changeWidth);
				sprintf(height,"%d",changeHeight);
				string cmd = "mode con:cols="+(string)width+" lines="+(string)height;
				system(cmd.c_str());
				/*
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SMALL_RECT rc = {0,0, changeWidth, changeHeight};
				SetConsoleWindowInfo(hOut,true ,&rc);
				*/
				printf("Use 'w s' to change height,'a d' to change width.\n");
				printf("Press 'Esc' to exit.\n");
				printf("Width : %d\n",changeWidth);
				printf("Height : %d\n",changeHeight);
				start = clock();
				key = 0;
			}
	    }
	}else if(selection == 2){
		double nowWidth,nowHeight;
		printf("Please input the width and the height.\n");
		printf("Input '0 0' to exit.\n");
		while(1){
		    cin >> nowWidth >> nowHeight;
		    if(nowWidth == 0 && nowHeight == 0){
			 	printf("Do you want to save the changes? ('y' for yes,'n' for no)\n");
			 	key = 0;
				while(key != 121 && key != 110){
					key = getch();
				}
				if(key == 121){
					windowWidth[loginIndex] = changeWidth;
					windowHeight[loginIndex] = changeHeight;
					out();
				}
				else
					changeWindowSize();
				return;
			}
		    if(!(nowWidth >= 1 && nowHeight >= 1)){
		    	printf("Wrong size! Please input again!\n");
		    	continue;
			}
			changeWidth = nowWidth;
			changeHeight = nowHeight;
			char width[50],height[50];
			sprintf(width,"%d",nowWidth);
			sprintf(height,"%d",nowHeight);
			string cmd = "mode con:cols="+(string)width+" lines="+(string)height;
			system(cmd.c_str());		
			/*
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SMALL_RECT rc = {0,0, changeWidth, changeHeight};
			SetConsoleWindowInfo(hOut,true ,&rc);
			*/
			printf("Please input the width and the height.\n");
			printf("Input '0 0' to exit.\n");
		}
	}
}

string nowco;

void change(){
	system("cls");
	int key;
	if(choose == 1){
		printf("Change the background color. Press 'Esc' to exit.\n");
		printf("Please press a key within 0 - 9,A - F to change the color.\n");
		printf("0 : black     1 : blue         2 : green        3 : aqua\n");
		printf("4 : red       5 : purple       6 : yellow       7 : white\n");
		printf("8 : gray      9 : light blue   A : light green  B : powderblue\n");
		printf("C : light red D : light purple E : light yellow F : bright white\n");
		while(1){
			while(_kbhit()){
				key = getch();
				if(key == 27){
					printf("Do you want to save the changes? ('y' for yes,'n' for no)\n");
					while(key != 121 && key != 110){
						key = getch();
					}
					if(key == 121){
						windowColor[loginIndex] = changeWindow;
						out();
					}
					else
						changeWindowColor();
					return;
				}
				if(!((key >= 48 && key <= 57) || (key >= 97 && key <= 102))){
					printf("Wrong code. Please choose again.\n");
					break;
				}
				changeWindow = key;
				if(changeWindow == fontColor[loginIndex]){
					printf("The same color as the font. Please choose again.\n");
					break;
				}
				string changeColor = "COLOR " + changeWindow + fontColor[loginIndex];
				system(changeColor.c_str());
			}
	    }
	}
    if(choose == 2){
		printf("Change the font color. Press 'Esc' to exit.\n");
		printf("Please press a key within 0 - 9,A - F to change the color.\n");
		printf("0 : black     1 : blue         2 : green        3 : aqua\n");
		printf("4 : red       5 : purple       6 : yellow       7 : white\n");
		printf("8 : gray      9 : light blue   A : light green  B : powderblue\n");
		printf("C : light red D : light purple E : light yellow F : bright white\n");
		while(1){
			while(_kbhit()){
				key = getch();
				if(key == 27){
					printf("Do you want to save the changes? ('y' for yes,'n' for no)\n");
					while(key != 121 && key != 110){
						key = getch();
					}
					if(key == 121){
						fontColor[loginIndex] = changeFont;
						out();
					}
					else
						changeWindowColor();
					return;
				}
				if(!((key >= 48 && key <= 57) || (key >= 97 && key <= 102))){
					printf("Wrong code. Please choose again.\n");
					break;
				}
				changeFont = key;
				if(changeFont == windowColor[loginIndex]){
					printf("The same color as the window. Please choose again.\n");
					break;
				}
				string changeColor = "COLOR " + windowColor[loginIndex] + changeFont;
				system(changeColor.c_str());
				nowco=changeColor;
			}
	    }
	}
	else if(choose == 3){
		key = 0;
	    double dur;
	    clock_t start,end;
	    start = clock();
		printSelection2();
	    while(1){
            key = getch();
			if(key != 0){
	            end = clock();
	    		dur = (double)(end - start);
	    		if(dur/CLOCKS_PER_SEC < 0.1){
	    			key = 0;
	    			continue;
	    		}
				switch(key){
					case 27:
						return;
						break;
					case 119:
		            	selection--;
		            	if(selection < 1)
		            	    selection = 2;
						break;
					case 115:
						selection++;
						if(selection > 2)
						    selection = 1;
		                break;
	                case 13:
	                	changeWH();
	                	break;
				}
				printSelection2();
				start = clock();
				key = 0;
			}
	    }
	}else if(choose == 4){
		windowColor[loginIndex] = "8";
		fontColor[loginIndex] = "f";
		windowWidth[loginIndex] = 90;
		windowHeight[loginIndex] = 23;
		changeWindowColor();
		changeWindowSize();
		out();
	}
}

void windowConfig(){
	int key = 0,dur;
	choose = 1;
    DWORD start,end;
    start = GetTickCount();
	printSelection();
	while(1){
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					return;
					break;
				case 119:
	            	choose--;
	            	if(choose < 1)
	            	    choose = 4;
					break;
				case 115:
					choose++;
					if(choose > 4)
					    choose = 1;
	                break;
                case 13:
                	change();
                	break;
			}
			printSelection();
			start = GetTickCount();
			key = 0;
		}
    }
}

//CLOCK

string clock_num()
{
	time_t t;
	time(&t);
	return "Local time:" + string(ctime(&t));
}

//FINISH

//MUSIC

void start()
{
	int pai=400,ban=200;
	Beep(do,ban);
	Beep(re,pai);
	Beep(mi,pai);
	Beep(fa,pai);
	Beep(so,pai);
	Beep(la,pai);
	Beep(si,pai+ban);
}

void endx()
{
	int pai=400,ban=200;
	Beep(si,pai+ban);
	Beep(la,pai);
	Beep(so,pai);
	Beep(fa,pai);
	Beep(mi,pai);
	Beep(re,pai);
	Beep(do,pai);
}

//FINISH

//menu mn[12345];
//file fl[12345];
//user us[1234];

int key,cntEnter = 0;
int tim[105];
bool canLogin = false;

void printLogin();
void loginconf();

void printHeader(){
	system("cls");
	cout<<"Violin" << endl;
}

void initInformation(int index){
    mn[index].clear();
    fl[index].clear();
    his[index].clear();
    vol[index].clear();
    windowHeight[index] = 23;
	windowWidth[index] = 90;
    fontColor[index] = "f";
	windowColor[index] ="8";
}

string loginCode;
void codeinput()
{
	int key = 0;
	bool canFind = false,isWrong = false;
	memset(tim,0,sizeof(tim));
	codeInput:
	codex.clear();
	usx.clear();
    loginconf();
    printHeader();
    printf("Login : \n");
	if(isWrong){
	    cout<<"Wrong username or code. Forget your code? Press 'Esc' to register a new one.\n";
		sleep(1);
	}
	isWrong = false;
	printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
	key = 0;
	while(key != 13){
		key = getch();
	    if(key != 32 && key != 13 && key != 8 && key != 27){
		    usx += char(key);
	    	cout << char(key);
	    }
		if(key == 8){
		    if(usx.size() != 0){
		    	usx.erase(usx.length() - 1,1);
                cout << "\b \b";
            }
	    }
	    if(key == 13){
	    	cout << endl;
	    }
	    if(key == 27)
	    	return;
	}
	printf("Please input your password, press 'enter' to login, 'Esc' to exit.\n");
	key = 0;
	while(key != 13){
		key = getch();
	    if(key != 32 && key != 13 && key != 8 && key != 27){
		    codex += char(key);
	    	cout << '*';
	    }
		if(key == 8){
		    if(codex.size() != 0){
		    	codex.erase(codex.length() - 1,1);
		        cout << "\b \b";
		    }
	    }
	    if(key == 13)
	    	cout << endl;
	    if(key == 27)
	        return;
	}
	if(usx == "Administrator" && codex == AdministratorCode){
		system("cls");
		cout<<"Welcome, "<<usx<<".\n";	
		canLogin = true;
		loginIndex = MAXN + 1;
		initInformation(loginIndex);
		return;	
	}
	for(int i=0;i<us.size();i++)
	{
		if(usx==us[i].name)
		{
			canFind = true;
			int index = i;
			if(us[i].isBlocked == true){
				printf("Your username is blocked.\nPlease choose 'Forget your password' to reset your account.\n");
				printf("Please press any key to continue.\n");
                while(!_kbhit());
                return;
			}
			if(us[i].code==codex)
			{
				system("cls");
				cout<<"Welcome, "<<usx<<".\n";
				canLogin = true;
				loginIndex = i;
				loginCode=codex;
				return;
			}
			else
			{
				{
					tim[index]++;
					if(tim[index]<3){
						isWrong = true;
						goto codeInput;
					}

					else
					{
						cout << "Wrong username or code for 3 times! Your username is blocked.\n";
						cout << "You can register a new one or reset your account.\n";
						cout << "Please press any key to continue.\n";
					    us[index].isBlocked = true;
					    out();
					    while(!_kbhit());
						return;
					}
				}
			}
		}
	}
	if(!canFind){
		isWrong = true;
	    goto codeInput;
	}
}

//?ì2aóê??ê?·?o?·¨
bool isValidChar(char ch){
    if(ch >= 'a' && ch <= 'z') //26??D?D′×???
		return true;
    if(ch >= 'A' && ch <= 'Z') //26??′óD′×???
		return true;
    if(ch >= '0' && ch <= '9') //0~9
		return true;
    if(ch == '_' || ch == '-' || ch == '.' || ch == '@' ) //_-.@
		return true;
    return false;
}

bool isValidEmail(string strEmail){
    if(strEmail.length() < 5)
        return false;
    char ch = strEmail[0];
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
	    int atCount = 0,atPos = 0,dotCount = 0;
		for(int i = 1;i < strEmail.length();i++){
            ch = strEmail[i];
			if(isValidChar(ch)){
			    if(ch == '@'){
	     		    atCount++;
					atPos = i;
			    }else if(atCount > 0 && ch == '.')//@·?o?oóμ?"."o?
				    dotCount ++;
			}else
		        return false;
		}
		//?á?22?μ?ê?×?·??°@?±?ò???°.?±
        if(ch == '.')
		    return false;
	    //±?D?°üo?ò???2￠?ò??óDò???·?o??°@?±
		//@oó±?D?°üo??áéùò????á?àèy??·?o??°.?±
		if(atCount !=1 || dotCount < 1 || dotCount > 3)
		    return false;
		//5. 2??êDí3????°@.?±?ò??.@
		int x,y;
		x=strEmail.find("@.");
		y=strEmail.find(".@");
		if( x>0 || y>0 )
		    return false;
        return true;
    }
    return false;
}

void Register(){
    printHeader();
    printf("Register : \n");
	printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
	bool canUse;
	int key;
	while(1){
		usx.clear();
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    usx += char(key);
		    	cout << char(key);
		    }
			if(key == 8){
			    if(usx.size() != 0){
			    	usx.erase(usx.length() - 1,1);
	                cout << "\b \b";
	            }
		    }
		    if(key == 13){
		    	cout << endl;
		    }
		    if(key == 27)
		    	return;
		}
		if(usx == "Administrator"){
			printf("You can't use 'Administrator' as a username. Please input again.\n");
   			sleep(1);
 	    	printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");			
		    continue;
		}
    	canUse = true;
		if(usx.length()<=0)
		   	canUse=false;
		for(int i = 0;i < usx.length();i++){
			if(!((usx[i] >= '0' && usx[i] <= '9') || (usx[i] >= 'a' && usx[i] <= 'z') || (usx[i] >= 'A' && usx[i] <= 'Z') || usx[i] == '_')){
				canUse = false;
				break;
			}
		}
		if(canUse){
		    bool isUsed = false;
		    for(int i = 0;i < us.size();i++){
		    	if(us[i].name == usx){
		    		isUsed = true;
		    		break;
				}
			}
			if(isUsed){
				printf("This username has been registed. Please input again.\n");
        	    sleep(1);
        	    printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
			}else
			    break;
		}else{
        	printf("Username only contains 0 - 9,a - z,A - Z and _ . Please input again.\n");
        	sleep(1);
        	printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
        }
	}
	printf("Please input your password, press 'enter' to continue, 'Esc' to exit.\n");
	while(1){
		key = 0;
		codex.clear();
	    while(key != 13){
			key = getch();
			if(key != 32 && key != 13 && key != 8 && key != 27){
				codex += char(key);
				cout << '*';
			}
			if(key == 8){
				if(codex.size() != 0){
					codex.erase(codex.length() - 1,1);
				    cout << "\b \b";
				}
			}
			if(key == 13)
			    cout << endl;
            if(key == 27)
                return;
	    }
		canUse = true;
		for(int i = 0;i < codex.length();i++){
			if(!((codex[i] >= '0' && codex[i] <= '9') || (codex[i] >= 'a' && codex[i] <= 'z') || (codex[i] >= 'A' && codex[i] <= 'Z') || codex[i] == '_')){
				canUse = false;
				break;
			}
		}
		if(codex.length() < 3){
			printf("Password must be at leaset 3 characters. Please input again.\n");
			sleep(1);
			printf("Please input your password, press 'enter' to continue, 'Esc' to exit.\n");
		}
		else if(canUse)
		    break;
		else if(!canUse){
			printf("Password should only contains 0 - 9,a - z,A - Z and _ . Please input again.\n");
			sleep(1);
			printf("Please input your password, press 'enter' to continue, 'Esc' to exit.\n");
		}
	}
    printf("Please input your email, press 'enter' to continue, 'Esc' to exit.\n");
	while(1){
		key = 0;
		mailx.clear();
	    while(key != 13){
			key = getch();
			if(key != 32 && key != 13 && key != 8 && key != 27){
				mailx += char(key);
				cout << char(key);
			}
			if(key == 8){
				if(mailx.size() != 0){
					mailx.erase(mailx.length() - 1,1);
				    cout << "\b \b";
				}
			}
			if(key == 13)
			    cout << endl;
            if(key == 27)
                return;
	    }
	    if(isValidEmail(mailx)){
			bool isUsed = false;
		    for(int i = 0;i < us.size();i++){
			    if(us[i].email == mailx){
			    	isUsed = true;
			    	break;
				}
			}
			if(isUsed){
				printf("This email has been registed. Please input again.\n");
	        	sleep(1);
	        	printf("Please input your eamil, press 'enter' to continue, 'Esc' to exit.\n");
			}else
				break;
        }else{
			printf("Invalid email address. Please input again.\n");
			sleep(1);
			printf("Please input your email, press 'enter' to continue, 'Esc' to exit.\n");
		}
	}
	system("cls");
    printHeader();
    printf("Register : \n");
	printf("OK, you have registed successfully!\n");
	Sleep(500);
	user usrx;
	usrx.code=codex;
	loginCode = codex;
	usrx.name=usx;
	usrx.email = mailx;
	usrx.isBlocked = false;
	usrx.txzLevel = 1;
	us.push_back(usrx);
	sMenu sMenux;
	sMenux.father = "/";
	sMenux.name = usx;
	sMenux.kind = AllHide;
	sMenux.readOnly = true;
	sMenux.people.clear();
	sMenux.creator = usx;
	shareMenu.push_back(sMenux);
	loginIndex = us.size() - 1;
	initInformation(loginIndex);
	out();
	system("cls");
	cout<<"Welcome, "<<usx<<".\n";
	canLogin = true;
}


void forgetPassword(){
	int index;
	while(1){
		usx.clear();
		mailx.clear();
		printHeader();
		printf("Forget Password : \n");
		printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    usx += char(key);
		    	cout << char(key);
		    }
			if(key == 8){
			    if(usx.size() != 0){
			    	usx.erase(usx.length() - 1,1);
	                cout << "\b \b";
	            }
		    }
		    if(key == 13){
		    	cout << endl;
		    }
		    if(key == 27)
		    	return;
	    }
        printf("Please input your email, press 'enter' to continue, 'Esc' to exit.\n");
		key = 0;
		mailx.clear();
	    while(key != 13){
			key = getch();
			if(key != 32 && key != 13 && key != 8 && key != 27){
				mailx += char(key);
				cout << char(key);
			}
			if(key == 8){
				if(mailx.size() != 0){
					mailx.erase(mailx.length() - 1,1);
				    cout << "\b \b";
				}
			}
			if(key == 13)
			    cout << endl;
            if(key == 27)
                return;
	    }
	    //cout << usx << " " << mailx << endl;
	    bool isCorrect = false;
	    for(int i = 0;i < us.size();i++){
	    	//cout << us[i].email << endl;
	    	if(us[i].name == usx && us[i].email == mailx){
	    		isCorrect = true;
	    		index = i;
	    		break;
			}
		}
		if(isCorrect)
		    goto changePassword;
        else{
        	printf("Wrong username or email address. Please input again.\n");
        	Sleep(1500);
		}
	}
	changePassword:
	printf("Please input your new password, press 'enter' to continue, 'Esc' to exit.\n");
	while(1){
		key = 0;
		codex.clear();
	    while(key != 13){
			key = getch();
			if(key != 32 && key != 13 && key != 8 && key != 27){
				codex += char(key);
				cout << '*';
			}
			if(key == 8){
				if(codex.size() != 0){
					codex.erase(codex.length() - 1,1);
				    cout << "\b \b";
				}
			}
			if(key == 13)
			    cout << endl;
            if(key == 27)
                return;
	    }
		bool canUse = true;
		for(int i = 0;i < codex.length();i++){
			if(!((codex[i] >= '0' && codex[i] <= '9') || (codex[i] >= 'a' && codex[i] <= 'z') || (codex[i] >= 'A' && codex[i] <= 'Z') || codex[i] == '_')){
				canUse = false;
				break;
			}
		}
		if(codex.length() < 3){
			printf("New password must be at leaset 3 characters. Please input again.\n");
			sleep(1);
			printf("Please input your password, press 'enter' to continue, 'Esc' to exit.\n");
		}
		else if(canUse)
		    break;
		else if(!canUse){
			printf("New password should only contains 0 - 9,a - z,A - Z and _ . Please input again.\n");
			sleep(1);
			printf("Please input your new password, press 'enter' to continue, 'Esc' to exit.\n");
		}
	}
	system("cls");
	printf("OK, you have reset your password successfully.\n");
	Sleep(500);
	us[index].code = codex;
	us[index].isBlocked = false;
	out();
	system("cls");
	cout<<"Welcome, "<<usx<<".\n";
	for(int i = 0;i < us.size();i++){
	    if(usx == us[i].name){
	    	loginIndex = i;
	    	break;
		}
	}
	canLogin = true;
}

void resetPassword(){
	memset(tim,0,sizeof(tim));
	int index;
	while(1){
		usx.clear();
		printHeader();
		printf("Reset Password : \n");
		printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    usx += char(key);
		    	cout << char(key);
		    }
			if(key == 8){
			    if(usx.size() != 0){
			    	usx.erase(usx.length() - 1,1);
	                cout << "\b \b";
	            }
		    }
		    if(key == 13){
		    	cout << endl;
		    }
		    if(key == 27)
		    	return;
	    }
		printf("Please input your password, press 'enter' to login, 'Esc'\n");
		codex.clear();
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    codex += char(key);
		    	cout << '*';
		    }
			if(key == 8){
			    if(codex.size() != 0){
			    	codex.erase(codex.length() - 1,1);
			        cout << "\b \b";
			    }
		    }
		    if(key == 13)
		    	cout << endl;
		    if(key == 27)
		        return;
		}
	    //cout << usx << " " << mailx << endl;
	    bool isCorrect = false;
	    for(int i = 0;i < us.size();i++){
	    	if(us[i].isBlocked == true && us[i].name == usx){
				printf("Your username is blocked. \nPlease choose 'Forget your password' to reset your account.\n");
				printf("Please press any key to continue.\n");
                while(!_kbhit());
                return;
			}
	    	if(us[i].name == usx && us[i].code == codex){
	    		isCorrect = true;
	    		index = i;
	    		break;
			}
		}
		if(isCorrect)
		    goto ResetPassword;
        else{
        	for(int i = 0;i < us.size();i++){
        		if(us[i].name == usx){
        			tim[i]++;
        			//cout << tim[i] << endl;
        			if(tim[i] >= 3){
						cout << "Wrong username or code for 3 times! Your username is blocked.\n";
						cout << "You can register a new one or reset your account.\n";
						cout << "Please press any key to continue.\n";
					    us[i].isBlocked = true;
					    out();
					    while(!_kbhit());
						return;
					}
				}
			}
        	printf("Wrong username or password. Please input again.\n");
        	Sleep(1500);
		}
	}
	ResetPassword:
	printf("Please input your new password, press 'enter' to continue, 'Esc' to exit.\n");
	while(1){
		key = 0;
		codex.clear();
	    while(key != 13){
			key = getch();
			if(key != 32 && key != 13 && key != 8 && key != 27){
				codex += char(key);
				cout << '*';
			}
			if(key == 8){
				if(codex.size() != 0){
					codex.erase(codex.length() - 1,1);
				    cout << "\b \b";
				}
			}
			if(key == 13)
			    cout << endl;
            if(key == 27)
                return;
	    }
		bool canUse = true;
		for(int i = 0;i < codex.length();i++){
			if(!((codex[i] >= '0' && codex[i] <= '9') || (codex[i] >= 'a' && codex[i] <= 'z') || (codex[i] >= 'A' && codex[i] <= 'Z') || codex[i] == '_')){
				canUse = false;
				break;
			}
		}
		if(codex.length() < 3){
			printf("New password must be at leaset 3 characters. Please input again.\n");
			sleep(1);
			printf("Please input your password, press 'enter' to continue, 'Esc' to exit.\n");
		}
		else if(canUse)
		    break;
		else if(!canUse){
			printf("New password should only contains 0 - 9,a - z,A - Z and _ . Please input again.\n");
			sleep(1);
			printf("Please input your new password, press 'enter' to continue, 'Esc' to exit.\n");
		}
	}
	us[index].code = codex;
	loginCode = codex;
	us[index].isBlocked = false;
	out();
	system("cls");
	printf("OK, you have reset your password successfully.\n");
	printf("Do you want to login now? Press 'y' for yes, 'n' for no.\n");
	int key = 0;
	while(key != 121 && key != 110){
		key = getch();
	}
	if(key == 121){
	    system("cls");
	    cout<<"Welcome, "<<usx<<".\n";
	    for(int i = 0;i < us.size();i++){
	    	if(usx == us[i].name){
	    		loginIndex = i;
	    		break;
			}
		}
	    canLogin = true;
	}
}

void conf();

void deletUser(){
	int index;
	while(1){
		usx.clear();
		printHeader();
		printf("Delete User : \n");
		printf("Please input your username, press 'enter' to continue, 'Esc' to exit.\n");
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    usx += char(key);
		    	cout << char(key);
		    }
			if(key == 8){
			    if(usx.size() != 0){
			    	usx.erase(usx.length() - 1,1);
	                cout << "\b \b";
	            }
		    }
		    if(key == 13){
		    	cout << endl;
		    }
		    if(key == 27)
		    	return;
	    }
		printf("Please input your password, press 'enter' to login, 'Esc'\n");
		codex.clear();
		key = 0;
		while(key != 13){
			key = getch();
		    if(key != 32 && key != 13 && key != 8 && key != 27){
			    codex += char(key);
		    	cout << '*';
		    }
			if(key == 8){
			    if(codex.size() != 0){
			    	codex.erase(codex.length() - 1,1);
			        cout << "\b \b";
			    }
		    }
		    if(key == 13)
		    	cout << endl;
		    if(key == 27)
		        return;
		}
	    //cout << usx << " " << mailx << endl;
	    bool isCorrect = false;
	    for(int i = 0;i < us.size();i++){
	    	if(us[i].name == usx && us[i].code == codex){
	    		isCorrect = true;
	    		index = i;
	    		break;
			}
		}
		if(isCorrect)
		    goto DeletUser;
        else{
        	printf("Wrong username or password. Please input again.\n");
        	Sleep(1500);
		}
	}
	DeletUser:
	system("cls");
	printHeader();
	printf("Delete User :\n");
	printf("Do you really want to delete your user account? Press 'y' for yes, 'n' for no.\n");
	int key = 0;
	while(key != 121 && key != 110){
		key = getch();
	}
	if(key == 121){
		us.erase(us.begin() + index);
		for(int i = 0;i < shareMenu.size();i++){
			if(shareMenu[i].father == "/" && shareMenu[i].name == usx)
			    shareMenu.erase(shareMenu.begin() + i);
		}
		for(int i = 0;i < shareFile.size();i++){
			if(shareFile[i].father == "/" && shareFile[i].name == usx)
			    shareFile.erase(shareFile.begin() + i);
		}
		out();
		conf();
	}
}
//μ???éè??

void loginconf()
{
	freopen("ViolinOS.cof","r",stdin);
	us.clear();
	string ms;
	int totUser;
	cin >> totUser;
	for(int i = 0;i < totUser;i++){
		while(1){
			cin >> ms;
			if(ms=="usr:"){
				user usxx;
				cin >> usxx.name;
				cin>> usxx.code;
				cin >> usxx.email;
				cin >> usxx.isBlocked;
				cin >> usxx.txzLevel;
				us.push_back(usxx);
				break;
			}
		}
	}
	return;
}


//μ???

int loginCh = 1;

void printLogin(){
    loginconf();
	system("cls");
	cout<<"Violin" << endl;
	cout<<"Welcome";
	if(us.size())cout<<", "<<us[0].name;
	else cout<<".";
	for(int i=1;i<us.size();i++)cout<<", "<<us[i].name;
	printf("\n");
	printf("Press 'w s' to choose,'enter' to select.\n");
	printf("1.Login");
	if(loginCh == 1)
		printf(" <--");
	printf("\n");
	printf("2.Register");
	if(loginCh == 2)
		printf(" <--");
	printf("\n");
	printf("3.Forget Password");
	if(loginCh == 3)
		printf(" <--");
	printf("\n");
	printf("4.Reset Password");
	if(loginCh == 4)
		printf(" <--");
	printf("\n");
	printf("5.Delete User");
	if(loginCh == 5)
		printf(" <--");
	printf("\n");
	freopen("CONIN$","r",stdin);
}

void login()
{
    printLogin();
    /*
    for(int i = 0;i < us.size();i++){
    	cout << us[i].name << " " << us[i].code << " " << us[i].isBlocked << " " << endl;
	}
	*/
	int key,dur;
    DWORD start,end;
    start = GetTickCount();
	while(1){
	    key = getch();
        end = GetTickCount();
   		dur = (end - start);
   		if(dur < 100){
  			start = GetTickCount();
  			continue;
   		}
	    switch(key){
	        case 119:
        	    loginCh--;
	            if(loginCh < 1)
	            	loginCh = 5;
				break;
			case 115:
				loginCh++;
				if(loginCh > 5)
					loginCh = 1;
	            break;
            case 13:
				switch(loginCh){
					case 1 :
					    codeinput();
					    break;
			        case 2 :
			  	        Register();
			  	        break;
			        case 3 :
			            forgetPassword();
			            break;
                    case 4 :
              	        resetPassword();
              	        break;
           	        case 5 :
    	        	    deletUser();
    	        	    break;
				}
				if(canLogin)
				    goto goOut;
                break;
		}
		printLogin();
		start = GetTickCount();
	}	
	goOut:
	loginName = usx;
	changeWindowColor();
//	changeWindowSize();
	return;
}

//所有设置

string readtillendl();

void conf()
{
	int totUser;
	string s;
    for(int i = 0;i < MAXN;i++){
        mn[i].clear();
		fl[i].clear();
		his[i].clear();
		vol[i].clear();
		windowColor[i] = "";
		fontColor[i] = "";
	}
	us.clear();
	shareMenu.clear();
	shareFile.clear();
	system("COLOR 9f");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rc = {0,0, 80, 25};
	SetConsoleWindowInfo(hOut,true ,&rc);
	freopen("ViolinOS.cof","r",stdin);
	cin >> totUser;
	for(int t = 0;t < totUser;t++){
		while(1){
			cin>>s;
			if(s=="mn:")
			{
				cout << "Bug - Menu: \n";
				string mnx;
				menu mnxx;
				while(1)
				{
					cin>>mnx;
					if(mnx=="END")break;
					string mny=mnx;
					int pas=0;
					int i=0;
					while(i<mny.size())
					{
						if(mny[i]=='/')pas=i;
						i++;
					}
					if(pas>1)
					{
						mnxx.father=mnx.substr(0,pas);
					}
					else mnxx.father="/";
					mnxx.name=mny.substr(pas+1);
					mn[t].push_back(mnxx);
//					cout<<"[";
//					cout<<" OK ";
//					cout<<"]"<<mnxx.father<<";"<<mnxx.name<<"\n";
				}
			}
			if(s=="fl:")
			{
				system("cls");
				cout << "Bug - File: \n";
				file flxx;
				string flx;
				while(1)
				{
					cin>>flx;
					if(flx=="END")
						break;
					string fly=flx;
					int pas=0;
					int i=0;
					while(i<fly.size())
					{
						if(fly[i]=='/')pas=i;
						i++;
					}
					if(pas!=0)
					{
						flxx.father=flx.substr(0,pas);
					}
					else {
						flxx.father="/";
					}
					flxx.name=flx.substr(pas+1);
					getchar();
					//getline(cin,flxx.cont);
					flxx.cont = readtillendl();
					fl[t].push_back(flxx);
//					cout<<"[";
//					cout<<" OK ";
//					cout<<"]: FILE: "<<flxx.father<<";"<<flxx.name<<";"<<flxx.cont<<"\n";
				}
			}
			if(s=="his:")
			{
				system("cls");
				cout << "Bug - History: \n";
				string hsx;
				while(1)
				{
					cin>>hsx;
					if(hsx=="END")break;
					his[t].push_back(hsx);
//					cout<<"[";
//					cout<<" OK ";
//					cout<<"]"<<hsx<<"\n";
				}
			}
			if(s == "window:"){
				system("cls");
				cout << "Bug - Window: \n";
				string col;
				cin >> col;
				windowColor[t] = col.substr(0,1);
				fontColor[t] = col.substr(1,1);
//				cout << "[";
//				cout << " OK ";
//				cout << "]" << col << endl;
				cin >> windowWidth[t] >> windowHeight[t];
				changeWidth = windowWidth[t];
				changeHeight = windowHeight[t];
//				cout << "[";
//				cout << " OK ";
//				cout << "]" << "winowHieght&Width" << endl;
			}
			if(s=="vol:")
			{
				system("cls");
				cout << "Bug - Volume: \n";
				string volx;
				while(1){
					cin>>volx;
					if(volx == "END")
					    break;
					volume v;
					v.cont = volx;
					vol[t].push_back(v);
//					cout<<"[";
//					cout<<"OK";
//					cout<<"]"<<volx<<"\n";
				}
			}
			if(s=="ENDEND")
				break;
		}
		//Sleep(10000);
	}
	cin >> s;
	if(s == "share:"){
		while(1){
			system("cls");
			cout << "Bug - Share: \n";
			cin >> s;
			//cout << s << endl;
			if(s=="smn:"){
				string mnx,visits,creator;
				sMenu mnxx;
				int kind,len;
				bool readOnly;
				while(1){
					cin>>mnx;
					if(mnx=="END")break;
					cin >> creator;
					cin >> readOnly;
					cin >> kind;
					mnxx.creator = creator;
					mnxx.readOnly = readOnly;
					mnxx.kind = type_kind(kind);
					mnxx.people.clear();
					if(kind == 3 || kind == 4){
					    cin >> len;
						for(int i = 0;i < len;i++){
							cin >> visits;
							mnxx.people.push_back(visits);
						}
					}
					string mny=mnx;
					int pas=0;
					int i=0;
					while(i<mny.size()){
						if(mny[i]=='/')pas=i;
						i++;
					}
					//cout << mnx << " " << pas << endl;
					if(pas>1)
						mnxx.father=mnx.substr(0,pas);
					else
					    mnxx.father="/";
					mnxx.name=mny.substr(pas+1);
					//cout << mnxx.father << " " << mnxx.name << endl;
					//sleep(1);
					shareMenu.push_back(mnxx);
//					cout<<"[";
//					cout<<" OK ";
//					cout<<"]"<< "share: " << mnxx.father<<";"<<mnxx.name<<"\n";
				}
				continue;
			}
			else if(s=="sfl:"){
                sFile flxx;
			    string flx,visits,creator;
			    int kind,len;
			    bool readOnly;
			    while(1){
					cin>>flx;
					//cout << flx << endl;
					if(flx=="END")break;
					cin >> creator;
					string fly=flx;
					int pas=0;
					int i=0;
					while(i<fly.size()){
						if(fly[i]=='/')pas=i;
						i++;
					}
					if(pas!=1)
					    flxx.father=flx.substr(0,pas);
					else
					    flxx.father="/";
					flxx.name=flx.substr(pas+1);
					getchar();
					getline(cin,flxx.cont);
					cin >> readOnly;
					cin >> kind;
					flxx.creator = creator;
					flxx.readOnly = readOnly;
					flxx.kind = type_kind(kind);
					flxx.people.clear();
					if(kind == 3 || kind == 4){
					    cin >> len;
						for(int i = 0;i < len;i++){
							cin >> visits;
							flxx.people.push_back(visits);
						}
					}
					shareFile.push_back(flxx);
//					cout<<"[";
//					cout<<" OK ";
//					cout<<"]"<< "share : " << flxx.father<<";"<<flxx.name<<";"<<flxx.cont<<"\n";
			    }
			}
			else if(s == "ENDEND"){
			    system("cls");
			    break;
			}
		}
	}
	/*
	for(int i = 0;i < us.size();i++){
		printf("%s %s %s %d\n",us[i].name.c_str(),us[i].code.c_str(),us[i].email.c_str(),us[i].isBlocked);
	}
	sleep(5);
	*/
	return;
}

//输出（到配置文件）

void printout(int loginIndex, bool Check, int time)
{
	system("cls");
	for(int i=1;i<us.size();i++)
		cout<<"[OK]"<<us[i].name<<"\n";
	cout<<"mn:\n";
	for(int i=0;i<mn[loginIndex].size();i++)
	{
		if(mn[loginIndex][i].father!="/")cout<<"[OK]"<<mn[loginIndex][i].father<<"/"<<mn[loginIndex][i].name<<"\n";
		else if(mn[loginIndex][i].name!="\0")cout<<"[OK]"<<mn[loginIndex][i].father<<mn[loginIndex][i].name<<"\n";
	}
	cout<<"fl:\n";
	for(int i=0;i<fl[loginIndex].size();i++)
	{
		if(fl[loginIndex][i].father!="/"&&!fl[loginIndex][i].father.empty())cout<<"[OK]"<<fl[loginIndex][i].father<<"/"<<fl[loginIndex][i].name<<"\n";
		else if(!fl[loginIndex][i].name.empty())cout<<"[OK]"<<fl[loginIndex][i].father<<fl[loginIndex][i].name<<"\n";
		if(!fl[loginIndex][i].cont.empty())cout<<"[OK]"<<fl[loginIndex][i].cont<<"\n";
	}
	cout<<"his:\n";
	for(int i=0;i<his[loginIndex].size();i++)
	{
		cout<<"[OK]"<<his[loginIndex][i]<<"\n";
	}
	cout<<"vol:\n";
	for(int i=0;i<vol[loginIndex].size();i++)
	{
		cout<<"[OK]"<<vol[loginIndex][i].cont<<"\n";
	}
	if(Check)
	{
		cout<<time;
		Sleep(1000);
		for(int i=time-1; i>0; i--)
		{
			for(int j=0; j<getdigit(i+1); j++)
				cout<<"\b";
			if(getdigit(i+1)!=getdigit(i))
				cout<<" ";
			cout<<i;
			Sleep(1000);
		}
		system("cls");
		cout<<"Violin\n";
	}
	else
	{
		system("cls");
	}
}

void out()
{
    fstream file("ViolinOS.cof", ios::out);
    file.close();
	FILE * fid = fopen("ViolinOS.cof","w");
	fprintf(fid,"%d\n",us.size());
	for(int t=0;t<us.size();t++){
		fprintf(fid,"usr:\n");
		fprintf(fid,"%s\n%s\n%s\n%d\n%d\n",us[t].name.c_str(),us[t].code.c_str(),us[t].email.c_str(),us[t].isBlocked,us[t].txzLevel);
		fprintf(fid,"mn:\n");
		for(int i=0;i<mn[t].size();i++){
			if(mn[t][i].father!="/"&&mn[t][i].name!="\0")
				fprintf(fid,"%s/%s\n",mn[t][i].father.c_str(),mn[t][i].name.c_str());
			else if(mn[t][i].name!="\0")
			    fprintf(fid,"%s%s\n",mn[t][i].father.c_str(),mn[t][i].name.c_str());
		}
		fprintf(fid,"END\n");
	    fprintf(fid,"fl:\n");
		for(int i=0;i<fl[t].size();i++){
			if(fl[t][i].father!="/"&&!fl[t][i].father.empty()&&!fl[t][i].name.empty())
			{
			    fprintf(fid,"%s/%s\n",fl[t][i].father.c_str(),fl[t][i].name.c_str());
			    if(!fl[t][i].cont.empty())
			    	fprintf(fid,"%s\n",fl[t][i].cont.c_str());
			    else
			    	fprintf(fid, "%s\n", " ");
			}
			else if(!fl[t][i].name.empty()&&!fl[t][i].father.empty())
			{
			    fprintf(fid,"%s%s\n",fl[t][i].father.c_str(),fl[t][i].name.c_str());
			    if(!fl[t][i].cont.empty())
			    	fprintf(fid,"%s\n",fl[t][i].cont.c_str());
			    else
			    	fprintf(fid, "%s\n", " ");
			}	
		}
	    fprintf(fid,"END\nhis:\n");
		for(int i=0;i<his[t].size();i++)
		    fprintf(fid,"%s\n",his[t][i].c_str());
		fprintf(fid,"END\nwindow:\n");
		fprintf(fid,"%s%s\n",windowColor[t].c_str(),fontColor[t].c_str());
		fprintf(fid,"%d %d\n",windowWidth[t],windowHeight[t]);
		fprintf(fid,"END\nvol:\n");
		for(int i=0;i<vol[t].size();i++){
			fprintf(fid,"%s\n",vol[t][i].cont.c_str());
            fprintf(fid,"\n");
        }
		fprintf(fid,"END\nENDEND\n");
	}
	fprintf(fid,"share:\n");
	fprintf(fid,"smn:\n");
	for(int i=0;i<shareMenu.size();i++){
		if(shareMenu[i].father!="/"&&shareMenu[i].name!="\0")
			fprintf(fid,"%s/%s\n",shareMenu[i].father.c_str(),shareMenu[i].name.c_str());
		else if(shareMenu[i].name!="\0")
		    fprintf(fid,"%s%s\n",shareMenu[i].father.c_str(),shareMenu[i].name.c_str());
        fprintf(fid,"%s\n",shareMenu[i].creator.c_str());
		fprintf(fid,"%d\n",shareMenu[i].readOnly);
        type_kind a = shareMenu[i].kind;
		fprintf(fid,"%d\n",a);
  		if(shareMenu[i].kind != AllHide && shareMenu[i].kind != AllShow){
  			fprintf(fid,"%d\n",shareMenu[i].people.size());
   	        for(int j = 0;j < shareMenu[i].people.size();j++)
       	        fprintf(fid,"%s ",shareMenu[i].people[j].c_str());
       	    fprintf(fid,"\n");
		}
	}
	fprintf(fid,"END\n");
 	fprintf(fid,"sfl:\n");
	for(int i=0;i<shareFile.size();i++){
	    if(shareFile[i].father!="/"&&!shareFile[i].father.empty()&&!shareFile[i].name.empty()){
	        fprintf(fid,"%s/%s\n",shareFile[i].father.c_str(),shareFile[i].name.c_str());
	        fprintf(fid,"%s\n",shareFile[i].creator.c_str());
			fprintf(fid,"%s\n",shareFile[i].cont.c_str());
	    }else if(!shareFile[i].name.empty()&&!shareFile[i].father.empty()){
	        fprintf(fid,"%s%s\n",shareFile[i].father.c_str(),shareFile[i].name.c_str());
	        fprintf(fid,"%s\n",shareFile[i].creator.c_str());
		    fprintf(fid,"%s\n",shareFile[i].cont.c_str());
	    }
        fprintf(fid,"%d\n",shareFile[i].readOnly);
     	type_kind a = shareFile[i].kind;
		fprintf(fid,"%d\n",a);
  		if(shareFile[i].kind != AllHide && shareFile[i].kind != AllShow){
  			fprintf(fid,"%d\n",shareFile[i].people.size());
   		    for(int j = 0;j < shareFile[i].people.size();j++)
                fprintf(fid,"%s ",shareFile[i].people[j].c_str());
    	    fprintf(fid,"\n");
		}
	}
	fprintf(fid,"END\nENDEND\n");
	fclose(fid);
}

//键入
string nowmn = "/";
bool isLogout;
bool readfl=true;
int readind = 0;

pair<string, string> in();

string rdfmflx = "CON";
string pflx = "CON";
bool rdfmflag = false;
int past = 0;
int indel = 0;
int incnt = 0;

void readfm()
{
	incnt = 0;
	string flx;
	flx = in().second;
	rdfmflx = flx;
	rdfmflag = true;
	if(loginName!="Administrator")
	{
		if(!readfl)
		{
//			cout<<"readfrom a volume can only be used in super mode.\n";
			return ;
		}
	}
	else
	{
		if(!readfl) 
		{
//			cout<<"Warning: Using readfrom in volumes can be dangerous.\n";
//			cout<<3;
//			for(int i=2; i>0; i--)
//			{
//				Sleep(1000);
//				cout<<"\b"<<i;
//			}
//			cout<<endl;
		}
	}
	bool can=false;
	for(int i=0;i<vol[loginIndex].size();i++)
	{
		if(vol[loginIndex][i].cont==flx)
		{
			can=true;
			break;
		}
	}
	if(!can)
	{
		cout<<flx<<": "<<"is not exist\n";
		return ;
	}
	readfl=false;
	readind ++;
	flx+=".vol";
	freopen(flx.c_str(),"r",stdin);
	indel = 0;
	while (true) {
		pair<string, string> ans = in();
//		debug(ans.first + ": " + ans.second);
		if (ans.first == "ENDL" && readind <= 1) {
			readind = 0;
			rdfmflx = "CON";
			rdfmflag = false;
			readfl = true;
			freopen("CON","r",stdin);
			return;
		}
		if(ans.first == "ENDL"){
			readind --;
//			freopen(flx.c_str(), "r", stdin);
			return;
		}
	}
}



bool isFileValid(string namex,string father){
	for(int i = 0;i < namex.length();i++){
		if(namex[i] == '/' || namex[i] == '\\' || namex[i] == ':' || namex[i] == '*' || namex[i] == '<' || namex[i] == '>' || namex[i] == '|'){
		    printf("The filename shouldn't contains \"< > * / \\ | :\"\n");
			return false;
		}
	}
	//cout << namex << endl;
	int i = namex.length() - 1;
	while( i >= 0 && namex[i] != '.')
	    i--;
	if(i < 1 || i == namex.length() - 1){
		printf("The filename should have a '.' for the extension name.\n");
	    return false;
	}
	for(int i = 0;i < fl[loginIndex].size();i++){
		if(fl[loginIndex][i].father == father && fl[loginIndex][i].name == namex){
		    printf("The filename has already been used, please use another one.\n");
		    return false;
		}
	}
    return true;
}

bool isMenuValid(string namex,string father){
	for(int i = 0;i < namex.length();i++){
		if(namex[i] == '/' || namex[i] == '\\' || namex[i] == ':' || namex[i] == '*' || namex[i] == '<' || namex[i] == '>' || namex[i] == '|' || namex[i] == '.'){
		    printf("The Menuname shouldn't contains \"< > * / \\ | : .\"\n");
			return false;
		}
	}
	for(int i = 0;i < mn[loginIndex].size();i++){
		if(mn[loginIndex][i].father == father && mn[loginIndex][i].name == namex){
		    printf("The Menuname has already been used, please use another one.\n");
		    return false;
		}
	}
	return true;
}


bool conx=true;

pair <string, string> in();

string create(menu mnx)
{
	string ans;
	ans.clear();
	ans+=mnx.father;
	if(mnx.father!="/")
		ans+="/";
	ans+=mnx.name;
	return ans;
}

string create1(sMenu mnx)
{
	string ans;
	ans.clear();
	ans+=mnx.father;
	if(mnx.father!="/")
		ans+="/";
	ans+=mnx.name;
	return ans;
}

string mkdk() {
	string diskx;
	pair<string, string> ansx;
	ansx = in();
	diskx = ansx.second;
	volume v;
	v.cont = diskx;
	diskx+=".vol";
	string comm="echo.> ";
	comm+=diskx;
	system(comm.c_str());
	for(int i=0;i<vol[loginIndex].size();i++)
	{
		if(vol[loginIndex][i].cont==v.cont)
		{
			return diskx + ": " + "is already exist.\n";
		}
	}
	vol[loginIndex].push_back(v);
	return "True";
}

string lineinput() {
	string s;
	getline(cin, s);
	return s;
}

string readtillendl() {
	bool flxilamcn=1;
	string x;
	while(flxilamcn)
	{
		string s;
		s = lineinput();
		x += s;
		x += "\n";
		if(s=="ENDL")
		{
			flxilamcn=0;
			return x;
		}
	}
}

string wrtdk()
{
	string diskx;
	pair<string, string> ansx;
	ansx = in();
	diskx = ansx.second;
	volume v;
	v.cont = diskx;
	vol[loginIndex].push_back(v);
	diskx+=".vol";
	freopen(diskx.c_str(),"w",stdout);
	cout << readtillendl();
	freopen("CON", "w", stdout);
	return "True";
}

string rmmn(string fatherx)
{
	bool get=false;
	for(vector<menu>::iterator it = mn[loginIndex].begin();it != mn[loginIndex].end();it++){
		if(create(*it) == fatherx)
		{
		    mn[loginIndex].erase(it);
		    get=true;
		    break;
		}
	}
	if(!get){
		return fatherx + ": " + "There is no this menu.\n";
	}
	for(vector<menu>::iterator it = mn[loginIndex].begin();it != mn[loginIndex].end();it++){
		if(it->father == fatherx)
		{
		    mn[loginIndex].erase(it);
			rmmn(create(*it));
			break;
		}
	}
	for(vector<file>::iterator it = fl[loginIndex].begin();it != fl[loginIndex].end();it++){
		if(it->father == fatherx)
		{
		    fl[loginIndex].erase(it);
		    return "True";
		}
	}
	return "True";
}

string rnmn(){
	string mnx;
	pair<string, string> ansx;
	ansx = in();
	mnx = ansx.second;
	for(int i = 0;i < mn[loginIndex].size();i++){
		if(mn[loginIndex][i].father == nowmn && mn[loginIndex][i].name == mnx){
			printf("Please input the new name: \n");
			string namex;
			cin >> namex;
			if(!isMenuValid(namex,nowmn))
			    return namex + ": is not valid.\n";
			string src = nowmn + mn[loginIndex][i].name;
			//cout << src << endl;
			mn[loginIndex][i].name = namex;
			for(int j = 0;j < mn[loginIndex].size();j++){
				//cout << mn[loginIndex][j].father.substr(0,src.length()) << endl;
	            string rep = mn[loginIndex][j].father;
				if(rep.substr(0,src.length()) == src){
					//cout << rep.length() << endl;
				    mn[loginIndex][j].father =  nowmn + namex + rep.substr(src.length());
				    //cout << mn[loginIndex][j].father << endl;
				}
			}
			for(int j = 0;j < fl[loginIndex].size();j++){
			    string rep = fl[loginIndex][j].father;
				if(rep.substr(0,src.length()) == src)
				    fl[loginIndex][j].father =  nowmn + namex + rep.substr(src.length());
			}
			return "True";
		}
	}
	return mnx + ": There is no such menu.\n";
}

string rnfl(){
	string flx;
	pair<string, string> ansx;
	ansx = in();
	flx = ansx.second;
	for(int i = 0;i < fl[loginIndex].size();i++){
		if(fl[loginIndex][i].father == nowmn && fl[loginIndex][i].name == flx){
			printf("Please input the new name: \n");
			string namex;
			cin >> namex;
			if(!isFileValid(namex,nowmn))
			    return namex + ": Name is not valid.\n";
			fl[loginIndex][i].name = namex;
			return "True";
		}
	}
	return flx + ": There is no such file.\n";
}

string mkmn() {
	string mnx;
	pair<string, string> ansx;
	ansx = in();
	mnx = ansx.second;
	if(!isMenuValid(mnx,nowmn))
	    return mnx + ": Name is not valid.\n";
	for(int i = 0;i < mn[loginIndex].size();i++){
		if(mn[loginIndex][i].father == nowmn && mn[loginIndex][i].name == mnx){
			return mnx + ": Has already existed.\n";
		}
	}
	menu mnxx;
	mnxx.father=nowmn;
	mnxx.name=mnx;
	mn[loginIndex].push_back(mnxx);
	return "True";	
}

string mkfl() {
	string flx;
	pair<string, string> ansx;
	ansx = in();
	flx = ansx.second;
	if(!isFileValid(flx,nowmn))
		return flx + ": Name is not valid.\n";
	for(int i = 0;i < fl[loginIndex].size();i++){
		if(fl[loginIndex][i].father == nowmn && fl[loginIndex][i].name == flx){
			return flx + ": Has already existed.\n";
		}
	}
	file flxx;
	flxx.father=nowmn;
	flxx.name=flx;
	flxx.cont=" ";
	fl[loginIndex].push_back(flxx);
	return "True";
}

string chmn() {
	string chx;
	pair<string, string> ansx;
	ansx = in();
	chx = ansx.second;
    bool can=false;
    if(chx!="<"&&chx!="/"){
        for (int i=0;i<mn[loginIndex].size();i++) {
  		    if (mn[loginIndex][i].name==chx&&mn[loginIndex][i].father==nowmn) {
				if(nowmn!="/")
					nowmn+="/";
				nowmn+=chx;
                return "True";
                break;
            }
        }
    }else if(chx=="/"){
        nowmn="/";
        return "True";
    }else{
		for(int i=0;i<mn[loginIndex].size();i++){
		    string base="\0";
			base+=mn[loginIndex][i].father;
			if(base!="/")base+="/";
			    base+=mn[loginIndex][i].name;
			if(base==nowmn){
			    nowmn=mn[loginIndex][i].father;
			    break;
		    }
		}
		return "True";
    }
	if(!can) {
	    return chx + ": is no such menu.\n";
	}
}

string listMenu(){
	string x;
	x += "Menu:\n";
	for(int i=0;i<mn[loginIndex].size();i++){
	    if(mn[loginIndex][i].father==nowmn){
	        if(mn[loginIndex][i].father!="/")
				x += loginName + mn[loginIndex][i].father + "/" + mn[loginIndex][i].name + "\n";
			else 
				x += loginName + mn[loginIndex][i].father + mn[loginIndex][i].name + "\n";
	    }
	}
	x += "File:\n";
	for(int i=0;i<fl[loginIndex].size();i++){
	    if(fl[loginIndex][i].father==nowmn){
	        if(fl[loginIndex][i].father!="/")
				x += loginName + fl[loginIndex][i].father + "/" + fl[loginIndex][i].name + "\n";
			else
				x += loginName + fl[loginIndex][i].father + fl[loginIndex][i].name + "\n";
	    }
	}
	return x;
}

string rmfl(){
	string rmy;
	pair<string, string> ansx;
	ansx = in();
	rmy = ansx.second;
	bool get=false;
	for(vector<file>::iterator it = fl[loginIndex].begin();it != fl[loginIndex].end();it++){
	    if(it->father == nowmn&&it->name==rmy){
    	    fl[loginIndex].erase(it);
    		return "True";
	    }
	}
	return rmy + ": There is no this file.\n";
}

string getfl(){
    string flx;
	pair<string, string> ansx;
	ansx = in();
	flx = ansx.second;
 	bool can=false;
	for(int i=0;i<fl[loginIndex].size();i++){
	    if(fl[loginIndex][i].name==flx&&fl[loginIndex][i].father==nowmn){
  		    return fl[loginIndex][i].cont + "\n";
	    }
	}
	return flx + ": There is no this file.\n";
} 

//搜索
vector<pair<string,string> > result;
string str;
int searchSelect;

void print(){
	system("cls");
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	for(int i = 0;i < result.size();i++){
		int j = result[i].first.length() - 1;
		while(result[i].first[j] != '.' && j >= 0)
		    j--;
		string name;
		int pos;
		if(j > 0){
		    name = result[i].first.substr(0,j);
			pos = name.find(str);
			printf("%d. Name : ",i + 1);
			for(int k = 0;k < name.length();k++){
				if(k == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(k == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",name[k]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("%s",result[i].first.substr(j).c_str());
			printf("\t Path : %s",result[i].second.c_str());
		}else{
			pos = result[i].first.find(str);
			printf("%d. Name : ",i + 1);
			for(int j = 0;j < result[i].first.length();j++){
				if(j == pos)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(j == pos + str.length())
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",result[i].first[j]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("\t Path : %s",result[i].second.c_str());
		}
		if(searchSelect == i + 1)
		    printf(" <--");
		printf("\n");
	}
	if(result.size() <= 1)
	    printf("Total of %d result\n",result.size());
	else
	    printf("Total of %d results\n",result.size());	
}

void search(vector<menu> menuArray[],vector<file> fileArray[]){
	result.clear();
	cin >> str;
	system("cls");
	system("color 8f");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	int num = 0;
	for(int i = 0;i < menuArray[loginIndex].size();i++){
		menu index = menuArray[loginIndex][i];
		int pos = index.name.find(str);
		if(pos != string::npos && index.father.find(nowmn) != string::npos){
			result.push_back(make_pair(index.name,index.father));
			num++;
			printf("%d. Name : ",num);
			for(int j = 0;j < index.name.length();j++){
				if(j == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(j == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",index.name[j]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("\t Path : %s\n",index.father.c_str());
		}
	}
	for(int i = 0;i < fileArray[loginIndex].size();i++){
		file index = fileArray[loginIndex][i];
		int j = index.name.length() - 1;
		while(index.name[j] != '.' && j >= 0)
		    j--;
		string name = index.name.substr(0,j);
		int pos = name.find(str);
		if(pos != string::npos && index.father.find(nowmn) != string::npos){
			result.push_back(make_pair(index.name,index.father));
			num++;
			printf("%d. Name : ",num);
			for(int k = 0;k < name.length();k++){
				if(k == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(k == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",name[k]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("%s",index.name.substr(j).c_str());
			printf("\t Path : %s\n",index.father.c_str());
		}
	}
	if(num <= 1)
	    printf("Total of %d result\n",num);
	else
	    printf("Total of %d results\n",num);
	int key;
	searchSelect = num;
	double end,dur,start;
	while(1){
 	    print();
		key = getch();
		if(key == VK_ESCAPE)
		    return;
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 119:
	            	searchSelect--;
	            	if(searchSelect < 1)
	            	    searchSelect = num;
					break;
				case 115:
					searchSelect++;
					if(searchSelect > num)
					    searchSelect = 1;
	                break;
                case 13:
                	if(num != 0)
                	    nowmn = result[searchSelect - 1].second;
                	return;
                	break;
			}
			start = GetTickCount();
			key = 0;
		}		
	}
}
//FINISH 

//Games
int selectGames = 1;
const int totalGames = 5;

void playGames(){
	system("cls");
	string str = "color " + windowColor[loginIndex] + fontColor[loginIndex];
	switch(selectGames){
		case 1:
			playEXOR();
			break;
		case 2:
			playSliverspare();
			break;
		case 3:
			play2048();
			break;
		case 4:
			playGuess_Number();
			system(str.c_str());
			break;
		case 5:
			playRussia();
			break;
	}
}

void printGames(){
	system("cls");
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	printf("<1>EXOR");
	if(selectGames == 1)
		printf(" <--");
    printf("\n");
	printf("<2>Sliverspare");
	if(selectGames == 2)
		printf(" <--");
    printf("\n");
	printf("<3>2048");
	if(selectGames == 3)
		printf(" <--");
    printf("\n");
	printf("<4>Guess number");
	if(selectGames == 4)
		printf(" <--");
    printf("\n");
  	printf("<5>Russia");
	if(selectGames == 5)
		printf(" <--");
    printf("\n");

}

void runGames(){
    double end,dur,start;
	while(1){
 	    printGames();
		key = getch();
		if(key == VK_ESCAPE)
		    return;
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 119:
	            	selectGames--;
	            	if(selectGames < 1)
	            	    selectGames = totalGames;
					break;
				case 115:
					selectGames++;
					if(selectGames > totalGames)
					    selectGames = 1;
	                break;
                case 13:
                	playGames();
                	break;
			}
			start = GetTickCount();
			key = 0;
		}		
	}	
}
//FINISH

//共享文件夹
string nowUser;
int checkPermission(sMenu folder){
	int i = 1;
	while(nowmn[i] != '/' && i < nowmn.length())
	    i++;
	//cout << i << " " << nowmn.substr(1,i - 1) << endl;
	if(folder.creator == loginName)
	    return 1;
	if(nowUser == loginName)
	    return 1;
	bool canvis = false;
	//int a = folder.kind;
	//cout << a << endl;
		//cout << folder.name << endl;
		//cout << folder.name << " " << folder.father << endl;
			if(folder.name == loginName || folder.kind == AllShow)
				canvis = true;
 			else if(folder.kind == PartShow){
			    //cout << folder.people.size() << endl;
		        for(int j = 0;j < int(folder.people.size());j++){
		            //cout << folder.people[j] << " ";
			        if(folder.people[j] == loginName){
			            canvis = true;
			            break;
					}
				}
			}else if(folder.kind == PartHide){
		        canvis = true;
		        //cout << loginName << endl;
		        //cout << folder.people.size() << " " << folder.people[0] << endl;
				for(int j = 0;j < int(folder.people.size());j++){
					if(folder.people[j] == loginName){
					    canvis = false;
						break;
					}
				}
			}
	if(canvis){
		if(!folder.readOnly)
		    return 1;
        else 
            return 0;
	}else 
	    return -1;
}


int checkPermission(sFile folder){
	int i = 1;
	while(nowmn[i] != '/' && i < nowmn.length())
	    i++;
	//cout << i << " " << nowmn.substr(1,i - 1) << endl;
	//cout << nowUser << endl;
	if(folder.creator == loginName)
	    return 1;
	if(nowUser == loginName)
	    return 1;
	bool canvis = false;
		//cout << folder.name << endl;
		//cout << folder.name << " " << folder.father << endl;
			if(folder.name == loginName || folder.kind == AllShow)
				canvis = true;
 			else if(folder.kind == PartShow){
			    //cout << folder.people.size() << endl;
		        for(int j = 0;j < int(folder.people.size());j++){
		            //cout << folder.people[j] << " ";
			        if(folder.people[j] == loginName){
			            canvis = true;
			            break;
					}
				}
			}else if(folder.kind == PartHide){
		        canvis = true;
		        //cout << loginName << endl;
		        //cout << folder.people.size() << " " << folder.people[0] << endl;
				for(int j = 0;j < int(folder.people.size());j++){
					if(folder.people[j] == loginName){
					    canvis = false;
						break;
					}
				}
			}
	if(canvis){
		if(!folder.readOnly)
		    return 1;
        else 
            return 0;
	}else 
	    return -1;
}

int choosepm = 1;
sMenu chpmmn;

void printchpmSelection(sMenu folder){
	system("cls");
	printf("Now permission :\n");
	switch(folder.kind){
		case 1 :
			printf("Other the users can't visit.\n");
			break;
		case 2 :
			printf("All the users can visit.\n");
			break;
		case 3 :
			printf("Only the user : ");
			if(folder.people.size() != 0){
				printf("%s",folder.people[0].c_str());
				for(int i = 1;i < folder.people.size();i++)
				    printf(",%s",folder.people[i].c_str());
			}
			printf(" can visit.\n");
			break;
		case 4 : 
			printf("The user : ");
			if(folder.people.size() != 0){
				printf("%s",folder.people[0].c_str());
				for(int i = 1;i < folder.people.size();i++)
				    printf(",%s",folder.people[i].c_str());
			}
			printf(" can't visit.\n");
			break;
	}
	if(chpmmn.readOnly)
		printf("Visitors can only read it.\n");
	else
	 	printf("Visitors can read and modify it.\n");
	printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
	switch(choosepm){
		case 1 :
			printf("1.change the access permissions <--\n");
			printf("2.change the modify permissions\n");
			break;
		case 2 :
			printf("1.change the access permissions\n");
			printf("2.change the modify permissions <--\n");
			break;
	}
}

void changeRead(){
	int chooseChange = 1;
	int dur;
	DWORD start,end;
    start = GetTickCount();
	while(1){
		system("cls");
		printf("Now Permission.\n");
		if(chpmmn.readOnly)
		    printf("Visitors can only read it.\n");
		else
	 		printf("Visitors can read and modify it.\n");
		printf("ReadOnly : %s\n",(chpmmn.readOnly ? "true" : "false"));
		printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
		printf("Change readonly : \n");
		switch(chooseChange){
			case 1 :
				printf("1.True <--\n");
				printf("2.False\n");
				break;
			case 2 :
				printf("1.True\n");
				printf("2.False <--\n");
				break;
		}
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					return;
					break;
				case 119:
	            	chooseChange--;
	            	if(chooseChange < 1)
	            	    chooseChange = 2;
					break;
				case 115:
					chooseChange++;
					if(chooseChange > 2)
					    chooseChange = 1;
	                break;
                case 13:
                	switch(chooseChange){
                		case 1 :
                			chpmmn.readOnly = true;
                			break;
               			case 2 :
               				chpmmn.readOnly = false;
               				break;
					}
                	break;
			}
			start = GetTickCount();
			key = 0;
		}
    }
}

void changePeople1(){
	int chooseChangePart = 1;
	int dur;
	DWORD start,end;
    start = GetTickCount();
	string name;
	vector<string> names;
    int ok;
	while(1){
		system("cls");
		printf("Now Permission.\n");
		printf("Only the user : ");
		if(chpmmn.people.size() != 0){
			printf("%s",chpmmn.people[0].c_str());
			for(int i = 1;i < chpmmn.people.size();i++)
				printf(",%s",chpmmn.people[i].c_str());
		}
		printf(" can visit.\n");
		printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
		printf("Change can visit: \n");
		switch(chooseChangePart){
			case 1 :
				printf("1.Add user <--\n");
				printf("2.Delet user\n");
				break;
			case 2 :
				printf("1.Add user\n");
				printf("2.Delet user <--\n");
				break;
		}
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					return;
					break;
				case 119:
	            	chooseChangePart--;
	            	if(chooseChangePart < 1)
	            	    chooseChangePart = 2;
					break;
				case 115:
					chooseChangePart++;
					if(chooseChangePart > 2)
					    chooseChangePart = 1;
	                break;
                case 13:
                	switch(chooseChangePart){
                		case 1 :
					        while(1){
	                			system("cls");
						        printf("Users can visit : ");
						        for(int j = 0;j < chpmmn.people.size();j++)
						            cout << chpmmn.people[j] << " ";
       							cout << endl;
       							printf("Please input the username. Press 'Esc' to exit.\n");
								names.clear();
                			    name.clear();
                			    char ch;
							    while(1){
							        ch = getch();
							        if(ch == '\r'){ 
										ok = 0;
										names.push_back(name);
										name.clear();
							            break;
							        }else if(ch == '\b'){
							            if(name.length() > 0){
							                name.erase(name.length() - 1,1);
							                printf("\b \b");
							            }
							        }else if(ch == 27){ 
							            ok = -1;
							            break;
							        }else if(ch == 32){
							        	names.push_back(name);
							        	name.clear();
							        	printf(" ");
									}else{ 
							            char word = ch;
							            name += word;
							            printf("%c",word);
							        }
							    }
							    cout << endl;
								if(ok == 0){
						  		    bool Error = false;
									for(int i = 0;i < names.size();i++){
										bool exist = false;
										for(int j = 0;j < chpmmn.people.size();j++){
											if(chpmmn.people[j] == names[i]){
												exist = true;
												break;
											}
										}
										if(exist){
										    printf("The user %s already exists.\n",names[i].c_str());
										    Error = true;
										}else{
											bool canFind = false;
											for(int j = 0;j < us.size();j++){
												if(us[j].name == names[i]){
													canFind = true;
													break;
												}
											}
											if(canFind)
											    chpmmn.people.push_back(names[i]);
											else{
											    printf("There is no user called %s.\n",names[i].c_str());
											    Error = true;
											}
										}
									}
								    if(Error){
										printf("Press and key to continue...\n");
										while(!_kbhit());
										ch = getch();
									}
								}else
									break;
						    }
                			break;
               			case 2 :
					        while(1){
	                			system("cls");
						        printf("Users can't visit : ");
						        for(int j = 0;j < chpmmn.people.size();j++)
						            cout << chpmmn.people[j] << " ";
       							cout << endl;
       							printf("Please input the username. Press 'Esc' to exit.\n");
								names.clear();
                			    name.clear();
                			    char ch;
							    while(1){
							        ch = getch();
							        if(ch == '\r'){ 
										ok = 0;
										names.push_back(name);
										name.clear();
							            break;
							        }else if(ch == '\b'){
							            if(name.length() > 0){
							                name.erase(name.length() - 1,1);
							                printf("\b \b");
							            }
							        }else if(ch == 27){ 
							            ok = -1;
							            break;
							        }else if(ch == 32){
							        	names.push_back(name);
							        	name.clear();
							        	printf(" ");
									}else{ 
							            char word = ch;
							            name += word;
							            printf("%c",word);
							        }
							    }
							    cout << endl;
								if(ok == 0){
						  		    bool Error = false;
									for(int i = 0;i < names.size();i++){
										bool canFind = false;
										int id;
										for(int j = 0;j < us.size();j++){
											if(us[j].name == names[i]){
												canFind = true;
												id = j;
												break;
											}
									    }
										if(canFind)
											chpmmn.people.erase(chpmmn.people.begin() + id);
										else{
											printf("There is no user called %s in this queue.\n",names[i].c_str());
											Error = true;
										}
									}
									if(Error){
										printf("Press and key to continue...\n");
										while(!_kbhit());
										ch = getch();
									}
								}else
								    break;
			 			    }
               				break;
					}
                	break;
			}
			start = GetTickCount();
			key = 0;
		}
    }	
}

void changePeople2(){
	int chooseChangePart = 1;
	int dur;
	DWORD start,end;
    start = GetTickCount();
	string name;
	vector<string> names;
    int ok;
	while(1){
		system("cls");
		printf("Now Permission.\n");
		printf("Only the user : ");
		if(chpmmn.people.size() != 0){
			printf("%s",chpmmn.people[0].c_str());
			for(int i = 1;i < chpmmn.people.size();i++)
				printf(",%s",chpmmn.people[i].c_str());
		}
		printf(" can't visit.\n");
		printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
		printf("Change can't visit: \n");
		switch(chooseChangePart){
			case 1 :
				printf("1.Add user <--\n");
				printf("2.Delet user\n");
				break;
			case 2 :
				printf("1.Add user\n");
				printf("2.Delet user <--\n");
				break;
		}
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					return;
					break;
				case 119:
	            	chooseChangePart--;
	            	if(chooseChangePart < 1)
	            	    chooseChangePart = 2;
					break;
				case 115:
					chooseChangePart++;
					if(chooseChangePart > 2)
					    chooseChangePart = 1;
	                break;
                case 13:
                	switch(chooseChangePart){
                		case 1 :
					        while(1){
	                			system("cls");
						        printf("Users can visit : ");
						        for(int j = 0;j < chpmmn.people.size();j++)
						            cout << chpmmn.people[j] << " ";
       							cout << endl;
       							printf("Please input the username. Press 'Esc' to exit.\n");
								names.clear();
                			    name.clear();
                			    char ch;
							    while(1){
							        ch = getch();
							        if(ch == '\r'){ 
										ok = 0;
										names.push_back(name);
										name.clear();
							            break;
							        }else if(ch == '\b'){
							            if(name.length() > 0){
							                name.erase(name.length() - 1,1);
							                printf("\b \b");
							            }
							        }else if(ch == 27){ 
							            ok = -1;
							            break;
							        }else if(ch == 32){
							        	names.push_back(name);
							        	name.clear();
							        	printf(" ");
									}else{ 
							            char word = ch;
							            name += word;
							            printf("%c",word);
							        }
							    }
							    cout << endl;
								if(ok == 0){
						  		    bool Error = false;
									for(int i = 0;i < names.size();i++){
										bool exist = false;
										for(int j = 0;j < chpmmn.people.size();j++){
											if(chpmmn.people[j] == names[i]){
												exist = true;
												break;
											}
										}
										if(exist){
										    printf("The user %s already exists.\n",names[i].c_str());
										    Error = true;
										}else{
											bool canFind = false;
											for(int j = 0;j < us.size();j++){
												if(us[j].name == names[i]){
													canFind = true;
													break;
												}
											}
											if(canFind)
											    chpmmn.people.push_back(names[i]);
											else{
											    printf("There is no user called %s.\n",names[i].c_str());
											    Error = true;
											}
										}
									}
								    if(Error){
										printf("Press and key to continue...\n");
										while(!_kbhit());
										ch = getch();
									}
								}else
									break;
						    }
                			break;
               			case 2 :
					        while(1){
	                			system("cls");
						        printf("Users can't visit : ");
						        for(int j = 0;j < chpmmn.people.size();j++)
						            cout << chpmmn.people[j] << " ";
       							cout << endl;
       							printf("Please input the username. Press 'Esc' to exit.\n");
								names.clear();
                			    name.clear();
                			    char ch;
							    while(1){
							        ch = getch();
							        if(ch == '\r'){ 
										ok = 0;
										names.push_back(name);
										name.clear();
							            break;
							        }else if(ch == '\b'){
							            if(name.length() > 0){
							                name.erase(name.length() - 1,1);
							                printf("\b \b");
							            }
							        }else if(ch == 27){ 
							            ok = -1;
							            break;
							        }else if(ch == 32){
							        	names.push_back(name);
							        	name.clear();
							        	printf(" ");
									}else{ 
							            char word = ch;
							            name += word;
							            printf("%c",word);
							        }
							    }
							    cout << endl;
								if(ok == 0){
						  		    bool Error = false;
									for(int i = 0;i < names.size();i++){
										bool canFind = false;
										int id;
										for(int j = 0;j < us.size();j++){
											if(us[j].name == names[i]){
												canFind = true;
												id = j;
												break;
											}
									    }
										if(canFind)
											chpmmn.people.erase(chpmmn.people.begin() + id);
										else{
											printf("There is no user called %s in this queue.\n",names[i].c_str());
											Error = true;
										}
									}
									if(Error){
										printf("Press and key to continue...\n");
										while(!_kbhit());
										ch = getch();
									}
								}else
								    break;
			 			    }
               				break;
					}
                	break;
			}
			start = GetTickCount();
			key = 0;
		}
    }	
}

void changeVisited(){
	int chooseVisit = 1;
	int dur;
	DWORD start,end;
    start = GetTickCount();
	while(1){
		system("cls");
		printf("Now Permission.\n");
		switch(chpmmn.kind){
			case 1 :
				printf("Other the users can't visit.\n");
				break;
			case 2 :
				printf("All the users can visit.\n");
				break;
			case 3 :
				printf("Only the user : ");
				if(chpmmn.people.size() != 0){
					printf("%s",chpmmn.people[0].c_str());
					for(int i = 1;i < chpmmn.people.size();i++)
					    printf(",%s",chpmmn.people[i].c_str());
				}
				printf(" can visit.\n");
				break;
			case 4 : 
				printf("The user : ");
				if(chpmmn.people.size() != 0){
					printf("%s",chpmmn.people[0].c_str());
					for(int i = 1;i < chpmmn.people.size();i++)
					    printf(",%s",chpmmn.people[i].c_str());
				}
				printf(" can't visit.\n");
				break;
		}
		printf("Press 'Esc'to exit,'w s' to choose,'enter' to select.\n");
		printf("Change can visit: \n");
		switch(chooseVisit){
			case 1 :
				printf("1.Other users can't visit. <--\n");
				printf("2.All users can visit.\n");
				printf("3.Part of the users can visit.\n");
				printf("4.Part of the users can't visit.\n");
				break;
			case 2 :
				printf("1.Other users can't visit.\n");
				printf("2.All users can visit. <--\n");
				printf("3.Part of the users can visit.\n");
				printf("4.Part of the users can't visit.\n");
				break;
			case 3 :
				printf("1.Other users can't visit.\n");
				printf("2.All users can visit.\n");
				printf("3.Part of the users can visit. <--\n");
				printf("4.Part of the users can't visit.\n");
				break;
			case 4 :
				printf("1.Other users can't visit.\n");
				printf("2.All users can visit.\n");
				printf("3.Part of the users can visit.\n");
				printf("4.Part of the users can't visit. <--\n");
				break;
		}
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					return;
					break;
				case 119:
	            	chooseVisit--;
	            	if(chooseVisit < 1)
	            	    chooseVisit = 4;
					break;
				case 115:
					chooseVisit++;
					if(chooseVisit > 4)
					    chooseVisit = 1;
	                break;
                case 13:
                	switch(chooseVisit){
                		case 1 :
                			chpmmn.kind = AllHide;
                			break;
               			case 2 :
               				chpmmn.kind = AllShow; 
               				break;
   						case 3 :
   							if(chpmmn.kind != PartShow)
   							    chpmmn.people.clear();
   							chpmmn.kind = PartShow;
   							changePeople1();
   							break;
					    case 4 :
   							if(chpmmn.kind != PartHide)
   							    chpmmn.people.clear();
					    	chpmmn.kind = PartHide;
					    	changePeople2();
					    	break;
					}
                	break;
			}
			start = GetTickCount();
			key = 0;
		}
    }
}

void chpm(sMenu &folder){
	int key = 0,dur;
	choosepm = 1;
	chpmmn = folder;
    DWORD start,end;
    start = GetTickCount();
	while(1){
	    printchpmSelection(chpmmn);
	    key = getch();
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 27:
					printf("Do you want to save the changes? ('y' for yes,'n' for no)\n");
					while(key != 121 && key != 110){
						key = getch();
					}
					if(key == 121){
						folder = chpmmn;
						out();
					}
					return;
					break;
				case 119:
	            	choosepm--;
	            	if(choosepm < 1)
	            	    choosepm = 2;
					break;
				case 115:
					choosepm++;
					if(choosepm > 2)
					    choosepm = 1;
	                break;
                case 13:
                	switch(choosepm){
                		case 1 :
                			changeVisited();
                			break;
               			case 2 :
               				changeRead();
               				break;
					}
                	break;
			}
			start = GetTickCount();
			key = 0;
		}
    }	
}

void getpm(type_kind kind,bool readOnly,vector<string> people){
            printf("Now permission :\n");
			switch(kind){
				case 1 :
					printf("Other the users can't visit.\n");
					break;
				case 2 :
					printf("All the users can visit.\n");
					break;
				case 3 :
					printf("Only the user : ");
					if(people.size() != 0){
						printf("%s",people[0].c_str());
						for(int i = 1;i < people.size();i++)
						    printf(",%s",people[i].c_str());
					}
					printf(" can visit.\n");
					break;
				case 4 : 
					printf("The user : ");
					if(people.size() != 0){
						printf("%s",people[0].c_str());
						for(int i = 1;i < people.size();i++)
						    printf(",%s",people[i].c_str());
					}
					printf(" can't visit.\n");
					break;
			}
			//cout << readOnly << endl;
			if(readOnly)
				printf("Visitors can only read it.\n");
			else
			 	printf("Visitors can read and modify it.\n");	
}

vector<pair<string,string> > shareResult;
int shareSearchSelect;

void sharePrint(){
	system("cls");
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	for(int i = 0;i < shareResult.size();i++){
		int j = shareResult[i].first.length() - 1;
		while(shareResult[i].first[j] != '.' && j >= 0)
		    j--;
		string name;
		int pos;
		if(j > 0){
		    name = shareResult[i].first.substr(0,j);
			pos = name.find(str);
			printf("%d. Name : ",i + 1);
			for(int k = 0;k < name.length();k++){
				if(k == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(k == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",name[k]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("%s",shareResult[i].first.substr(j).c_str());
			printf("\t Path : %s",shareResult[i].second.c_str());
		}else{
			pos = shareResult[i].first.find(str);
			printf("%d. Name : ",i + 1);
			for(int j = 0;j < shareResult[i].first.length();j++){
				if(j == pos)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(j == pos + str.length())
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",shareResult[i].first[j]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("\t Path : %s",shareResult[i].second.c_str());
		}
		if(shareSearchSelect == i + 1)
		    printf(" <--");
		printf("\n");
	}
	if(shareResult.size() <= 1)
	    printf("Total of %d shareResult\n",shareResult.size());
	else
	    printf("Total of %d results\n",shareResult.size());
}

void shareSearch(vector<sMenu> menuArray,vector<sFile> fileArray){
	shareResult.clear();
	cin >> str;
	system("cls");
	system("color 8f");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
	printf("Press 'Esc' to exit,'w s' to choose,'enter' to select.\n");
	int num = 0;
	for(int i = 0;i < menuArray.size();i++){
		sMenu index = menuArray[i];
		if(checkPermission(index) == -1)
		    continue;
		int pos = index.name.find(str);
		if(pos != string::npos && index.father.find(nowmn) != string::npos){
			shareResult.push_back(make_pair(index.name,index.father));
			num++;
			printf("%d. Name : ",num);
			for(int j = 0;j < index.name.length();j++){
				if(j == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(j == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",index.name[j]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("\t Path : %s\n",index.father.c_str());
		}
	}
	for(int i = 0;i < fileArray.size();i++){
		sFile index = fileArray[i];
		if(checkPermission(index) == -1)
		    continue;
		int j = index.name.length() - 1;
		while(index.name[j] != '.' && j >= 0)
		    j--;
		string name = index.name.substr(0,j);
		int pos = name.find(str);
		if(pos != string::npos && index.father.find(nowmn) != string::npos){
			shareResult.push_back(make_pair(index.name,index.father));
			num++;
			printf("%d. Name : ",num);
			for(int k = 0;k < name.length();k++){
				if(k == pos)
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),908);
				else if(k == pos + str.length())
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
				printf("%c",name[k]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),911);
			printf("%s",index.name.substr(j).c_str());
			printf("\t Path : %s\n",index.father.c_str());
		}
	}
	if(num <= 1)
	    printf("Total of %d result\n",num);
	else
	    printf("Total of %d results\n",num);
	int key;
	shareSearchSelect = num;
	double end,dur,start;
	while(1){
 	    sharePrint();
		key = getch();
		if(key == VK_ESCAPE)
		    return;
		if(key != 0){
            end = GetTickCount();
    		dur = (end - start);
    		if(dur < 100){
    			key = 0;
    			start = GetTickCount();
    			continue;
    		}
			switch(key){
				case 119:
	            	shareSearchSelect--;
	            	if(shareSearchSelect < 1)
	            	    shareSearchSelect = num;
					break;
				case 115:
					shareSearchSelect++;
					if(shareSearchSelect > num)
					    shareSearchSelect = 1;
	                break;
                case 13:
                	nowmn = shareResult[shareSearchSelect - 1].second;
                	return;
                	break;
			}
			start = GetTickCount();
			key = 0;
		}		
	}
}

void runShare(){
	system("cls");
	string bfmn = nowmn;
	nowmn = "/" + loginName;
    nowUser = loginName; 
	string s;
	sMenu folder;
	cout<<"Violin\n";
	printf("You are in the shared folder now. Input 'exit' to exit.\n");
	printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
	while(s != "exit"){
	    cout << "User:" << nowmn << "/ ";
		cin >> s;
		if(s == "chus" || s == "changeuser"){
			string username;
			cin >> username;
			string bfUser = nowUser;
			nowUser = username;
			int k;
			bool canFind = false;
			for(int i = 0;i < shareMenu.size() && !canFind;i++){
				if(shareMenu[i].name == username && shareMenu[i].father == "/"){
			        k = checkPermission(shareMenu[i]);
			        canFind = true;
			        break;
			    }
			}
			if (username == "Administrator") {
				//printf("You can visit it.\n");
				nowmn = "/" + nowUser;
				system("cls");
				cout<<"Violin\n";
				printf("You are in the shared folder now. Input 'exit' to exit.\n");
				printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
			}
			else if(!canFind){
				nowUser = bfUser;
			    printf("There is no user called '%s'.\n",username.c_str());				
			}
			else if(k >= 0){
				//printf("You can visit it.\n");
				nowmn = "/" + nowUser;
				system("cls");
				cout<<"Violin\n";
				printf("You are in the shared folder now. Input 'exit' to exit.\n");
				printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
			}else if(k == -1){
				nowUser = bfUser;
	   		    printf("You don't have this permission.\n");
			}
	    }
	    
	    else if(s == "chmn" || s == "cd"){
		    string chx;
		    cin>>chx;
		    if(chx!="<"&&chx!="/"){
		    	int k;
		    	bool canFind = false;
				for(int i = 0;i < shareMenu.size() && canFind;i++){
					//cout << shareMenu[i].name << " " << shareMenu[i].father << endl;
					if(shareMenu[i].name == chx && shareMenu[i].father == nowmn && shareMenu[i].father != "/"){
				        k = checkPermission(shareMenu[i]);
				        canFind = true;
				        break;
				    }
				}
				if(!canFind)
					printf("There is no such menu.\n");
			    else if(k >= 0){
				    for(int i=0;i<shareMenu.size() && !canFind;i++){
			  		    if(shareMenu[i].name==chx&&shareMenu[i].father==nowmn){
							if(nowmn!="/")
							    nowmn+="/";
							nowmn+=chx;
							break;
			            }
			        }			    	
				}else if(k == -1){
					printf("You don't have this permission.\n");
				}
		    }else if(chx=="/"){
		        nowmn= "/" + nowUser;
		    }else{
				for(int i=0;i<shareMenu.size();i++){
				    string base="\0";
					base+=shareMenu[i].father;
					//cout << base << " " << nowmn << endl;
					if(base!="/")
					    base+="/";
					base+=shareMenu[i].name;
					//cout << base << endl;
					if(base==nowmn && shareMenu[i].father != "/"){
					    nowmn=shareMenu[i].father;
					    break;
				    }
				}
		    }
		}
	    
	    else if(s == "mkmn"){
			string mnx;
			cin>>mnx;
			int i = nowmn.length() - 1;
			while(nowmn[i] != '/')
			    i--;
			string name = nowmn.substr(i + 1);
			string father = nowmn.substr(0,i);
			if(i == 0)
			    father = "/";
			//cout << endl << nowmn << endl;
			//cout << name << " " << father << endl;
		    int k = 0;
			for(int i = 0;i < shareMenu.size();i++){
				if(shareMenu[i].name == name && shareMenu[i].father == father){
				    k = checkPermission(shareMenu[i]);
				    break;
				}
			}
			if(k == 1){
				if(!isMenuValid(mnx,nowmn))
				    goto BREAK;
				for(int i = 0;i < shareMenu.size();i++){
					if(shareMenu[i].father == nowmn && shareMenu[i].name == mnx){
						printf("There has already existed a menu called %s.\n",mnx.c_str());
						goto BREAK;
					}
				}
				sMenu sMenux;
				sMenux.creator = loginName;
				sMenux.father = nowmn;
				sMenux.name = mnx;
				sMenux.kind = AllHide;
				sMenux.readOnly = true;
				sMenux.people.clear();
				shareMenu.push_back(sMenux);
				//cout << shareMenu.size() << endl;
			}else 
			    printf("You don't have this permission.\n");
		}
	    
	    else if(s == "mkfl"){
			string flx;
			cin>>flx;
			int i = nowmn.length() - 1;
			while(nowmn[i] != '/')
			    i--;
			string name = nowmn.substr(i + 1);
			string father = nowmn.substr(0,i);
			if(i == 0)
			    father = "/";
			//cout << endl << nowmn << endl;
			//cout << name << " " << father << endl;
		    int k = 0;
			for(int i = 0;i < shareMenu.size();i++){
					//cout << shareMenu[i].father << " ";
				if(shareMenu[i].name == name && shareMenu[i].father == father){
				    k = checkPermission(shareMenu[i]);
				    //cout << "YES" << endl;
				    break;
				}
			}
			//cout << k << endl;
			if(k == 1){
				if(!isFileValid(flx,nowmn))
				    goto BREAK;
				for(int i = 0;i < shareFile.size();i++){
					if(shareFile[i].father == nowmn && shareFile[i].name == flx){
						printf("There has already existed a menu called %s.\n",flx.c_str());
						goto BREAK;
					}
				}
				sFile sFilex;
				sFilex.creator = loginName;
				sFilex.father = nowmn;
				sFilex.name = flx;
				sFilex.kind = AllHide;
				sFilex.readOnly = true;
				sFilex.people.clear();
				sFilex.cont = "";
				shareFile.push_back(sFilex);
				//cout << shareMenu.size() << endl;
			}else 
			    printf("You don't have this permission.\n");	    	
		}
		
		else if(s == "wrtfl"){
			string flx;
			cin >> flx;
		    int k = 0;
	     	bool can = false;
			for(int i = 0;i < shareFile.size();i++){
				if(shareFile[i].name == flx && shareFile[i].father == nowmn){
				    k = checkPermission(shareFile[i]);
				    can = true;
					if(k == 1){
					 	getchar();
						getline(cin,shareFile[i].cont);
					}else
	     			    printf("You don't have this permission.\n");
				    break;
				}
			}
			if(!can)
			    cout<<"There is no this file called " << flx <<  ".\n";			
		}
	    
	    else if(s == "rnmn"){
			string mnx;
			cin >> mnx;
			for(int i = 0;i < shareMenu.size();i++){
				if(shareMenu[i].father == nowmn && shareMenu[i].name == mnx){
					if(checkPermission(shareMenu[i]) == 1){
						printf("Please input the new name : \n");
						string namex;
						cin >> namex;
						if(!isMenuValid(namex,nowmn))
						    goto BREAK;
						string src = nowmn + "/" + shareMenu[i].name;
						//cout << src << endl;
						shareMenu[i].name = namex;
						for(int j = 0;j < shareMenu.size();j++){
							//cout << shareMenu[j].father.substr(0,src.length()) << endl;
				            string rep = shareMenu[j].father;
							if(rep.substr(0,src.length()) == src){
								//cout << rep.length() << endl;
							    shareMenu[j].father =  nowmn + "/" + namex + rep.substr(src.length());
							    //cout << shareMenu[j].father << endl;
							}
						}
						for(int j = 0;j < shareFile.size();j++){
						    string rep = shareFile[j].father;
							if(rep.substr(0,src.length()) == src)
							    shareFile[j].father =  nowmn + "/" + namex + rep.substr(src.length());
						}
					}else
					    printf("You don't have this permission.\n");
					goto BREAK;
				}
			}
			printf("There is no such menu.\n");
		}
		
		else if(s == "rnfl"){
			string flx;
			cin >> flx;
			//cout << nowmn << endl;
			for(int i = 0;i < shareFile.size();i++){
				//cout << shareFile[i].father << " " << shareFile[i].name << endl;
				if(shareFile[i].father == nowmn && shareFile[i].name == flx){
					//cout << "YES" << endl;
					if(checkPermission(shareFile[i]) == 1){
						//cout << "YES" << endl;
						printf("Please input the new name : \n");
						string namex;
						cin >> namex;
						if(!isFileValid(namex,nowmn))
						    goto BREAK;
						shareFile[i].name = namex;
					}else
					    printf("You don't have this permission.\n");
					goto BREAK;
				}
			}
			printf("There is no such menu.\n");
		}

		else if(s == "getfl" || s == "rdfl"){
			string flx;
			cin >> flx;
			for(int i = 0;i < shareFile.size();i++){
				if(shareFile[i].father == nowmn && shareFile[i].name == flx){
					if(checkPermission(shareFile[i]) == 1){
						cout << shareFile[i].cont << endl;
					}else
					    printf("You don't have this permission.\n");
					goto BREAK;
				}
			}
			printf("There is no such file.\n");
		}
	    
	    else if(s == "list" || s == "ls"){
		 	cout<<"Menu:\n";
			for(int i=0;i<shareMenu.size();i++){
			    if(shareMenu[i].father==nowmn && checkPermission(shareMenu[i]) >= 0){
			        if(shareMenu[i].father!="/")cout<<shareMenu[i].father<<"/"<<shareMenu[i].name<<"\n";
					else cout<< shareMenu[i].father<<shareMenu[i].name<<"\n";
			    }
			}
			cout<<"File:\n";
			for(int i=0;i<shareFile.size();i++){
			    if(shareFile[i].father==nowmn && checkPermission(shareFile[i]) >= 0){
			        if(shareFile[i].father!="/")cout<<shareFile[i].father<<"/"<<shareFile[i].name<<"\n";
					else cout<<shareFile[i].father<<shareFile[i].name<<"\n";
			    }
			}
		}

		else if(s == "rmmn"){
			string rmy;
			cin>>rmy;
			string src = nowmn + "/" + rmy;
			//cout << src << endl;
			bool canFind = false;
			//cout << nowmn << " " << rmy << endl;
			//cout << src << endl;
			//for(int i = 0;i < shareMenu.size();i++)
			    //cout << shareMenu	[i].father << " " << shareMenu[i].name << endl;
			for(int i = 0;i < shareMenu.size() && !canFind;i++){
				//cout << shareMenu[i].father << "/" << shareMenu[i].name << endl;
				//cout << shareMenu[i].father << " " << shareMenu[i].father.substr(0,src.length()) << endl;
				if((shareMenu[i].father == nowmn && shareMenu[i].name == rmy) || (shareMenu[i].father.length() >= src.length() && shareMenu[i].father.substr(0,src.length()) == src)){
					if(checkPermission(shareMenu[i]) < 1){
						printf("You don't have this permission.\n");
						goto BREAK;
					}
					shareMenu.erase(shareMenu.begin() + i);
					i--;
					canFind = true;
				}
			}
			for(int i = 0;i < shareFile.size();i++){
				if(shareFile[i].father.length() >= src.length() && shareFile[i].father.substr(0,src.length()) == src){
					shareFile.erase(shareFile.begin() + i);
					i--;
				}
			}
			if(!canFind)
			    printf("There is no such menu.\n");
		}

		else if(s == "chpm"){
			string url;
			cin >> url;
			if(url[0] == '.'){
			    if(url[1] == '.'){
			    	int i = nowmn.length() - 1;
			    	while(nowmn[i] != '/')
			    	    i--;
    				url = nowmn.substr(0,i) + url.substr(2);
				}else	 
				    url = nowmn + url.substr(1);
			}else if(url[0] == '<'){
				int i = nowmn.length() - 1;
				while(nowmn[i] != '/')
				    i--;
				url = nowmn.substr(0,i) + url.substr(1);
			}
			cout << url << endl;
			int i = url.length() - 1;
			while(i >= 0 && url[i] != '/')
			    i--;
			if(i < 0){
				printf("Wrong src!\n");
				out();
				continue;
			}
			string name = url.substr(i + 1);
			string father = url.substr(0,i);
			if(i == 0)
			    father = "/";
			//cout << name << " " << father << endl;
			bool canFind = false;
			for(int i = 0;i < shareMenu.size() && canFind;i++){
				if(shareMenu[i].name == name && shareMenu[i].father == father){
						if(checkPermission(shareMenu[i]) == 1){
							sMenu menux = shareMenu[i];
							//cout << "Menu" << endl;
							chpm(menux);
							shareMenu[i] = menux;
							system("cls");
							printf("Violin\n");
							printf("You are in the shared folder now. Input 'exit' to exit.\n");
							printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
						}else
						    printf("You don't have this permission.\n");
						canFind = true;
					    break;
				}
			}
			for(int i = 0;i < shareFile.size() && !canFind;i++){
				if(shareFile[i].name == name && shareFile[i].father == father){
					if(checkPermission(shareFile[i]) == 1){
							cout << "TRUE" << endl;
							cout << shareFile[i].readOnly << endl;
							sleep(5);
							sFile filex = shareFile[i];
							sMenu menux;
							menux.father = filex.father;
							menux.kind = filex.kind;
							menux.name = filex.name;
							menux.people = filex.people;
							menux.creator = filex.creator;
							menux.readOnly = filex.readOnly;
							//cout << "File" << endl;
							chpm(menux);
							shareFile[i].father = menux.father;
							shareFile[i].kind = menux.kind;
							shareFile[i].name = menux.name;
							shareFile[i].people = menux.people;
							shareFile[i].creator = menux.creator;
							shareFile[i].readOnly = menux.readOnly;						
							system("cls");
							printf("Violin\n");
							printf("You are in the shared folder now. Input 'exit' to exit.\n");
							printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
						}else
					        printf("You don't have this permission.\n");
						canFind = true;
						break;
					}
			}
			if(!canFind)
			    printf("There is no such menu or file.\n");
		}
		
		else if(s == "getpm"){
	        string url;
			cin >> url;
			if(url[0] == '.'){
			    if(url[1] == '.'){
			    	int i = nowmn.length() - 1;
			    	while(nowmn[i] != '/')
			    	    i--;
    				url = nowmn.substr(0,i) + url.substr(2);
				}else	 
				    url = nowmn + url.substr(1);
			}else if(url[0] == '<'){
				int i = nowmn.length() - 1;
				while(nowmn[i] != '/')
				    i--;
				url = nowmn.substr(0,i) + url.substr(1);
			}
			//else{
			//	printf("Wrong src!\n");
			//	continue;
			//}
			//cout << url << endl;
			int i = url.length() - 1;
			while(url[i] != '/' && i >= 0)
			    i--;
			string name,father;
			if(i == -1){
				name = url;
				father = nowmn;
			}else{
				name = url.substr(i + 1);
				father = url.substr(0,i);
			}
			if(i == 0)
			    father = "/";
			//cout << name << " " << father << endl;
			bool canFind = false;
			for(int i = 0;i < shareMenu.size();i++){
				if(shareMenu[i].name == name && shareMenu[i].father == father){
					if(shareMenu[i].creator == nowUser || nowUser == loginName){
						sMenu menux = shareMenu[i];
						//cout << "Menu" << endl;
						getpm(menux.kind,menux.readOnly,menux.people);
					}else
					    printf("You don't have this permission.\n");
					canFind = true;
				    break;
				}
			}
			//cout << name << " " << father << endl << endl;
			for(int i = 0;i < shareFile.size();i++){
				//cout << shareFile[i].name << " " << shareFile[i].father << endl;
				if(shareFile[i].name == name && shareFile[i].father == father){
					if(shareFile[i].creator == loginName || nowUser == loginName){
						sFile filex = shareFile[i];
						cout << "File" << endl;
						getpm(shareFile[i].kind,shareFile[i].readOnly,shareFile[i].people);
				    }else
				        printf("You don't have this permission.\n");
					canFind = true;
					break;
				}
			}
			if(!canFind)
			    printf("There is no such menu or file.\n");		
		}

		else if(s == "ss"){
			shareSearch(shareMenu,shareFile);
			system("cls");
			printf("You are in the shared folder now. Input 'exit' to exit.\n");
			printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
			string str = "color " + windowColor[loginIndex] + fontColor[loginIndex];
			system(str.c_str());	
		}

	    else if(s == "cls"){
			system("cls");
			cout<<"Violin\n";
			printf("You are in the shared folder now. Input 'exit' to exit.\n");
			printf("User account : %s\t Now using account : %s\n",loginName.c_str(),nowUser.c_str());
		}	    

		else if(s == "help" || s == "bz"){
			system("How_to_use.docx");
		}

		else if(s == "exit")
		    break;
        
        else 
            cout<<"There is no such commend.\n";
        BREAK:
        out();
	}
	nowmn = bfmn;
}

int done=0;
string cop;
bool noecho=false;
bool flagcommend = true;
bool ifecan = false;

string varr(pair<string, string> pans) {
	bool fl = false;
	string sss;
	map<string, string>::iterator iter;  
	iter = clamap.find(pans.second);
	if(iter != clamap.end()) {
		sss = iter->second;
		fl = true;
	} 
	if (!fl)
		sss = pans.second;
	return sss;
}

pair<string, string> deal(string s) {
	bool changeFromAdministrator;
	if(loginName == "Administrator")
	    changeFromAdministrator = true;
    else
    	changeFromAdministrator = false;
	pair<string, string> ans;
	flagcommend = true;
	his[loginIndex].push_back(s);
	if(s[0] == '#') {
		if(s[s.size() - 1] == '#') {
			cin >> s;
			return deal(s);
		}
		string ps;
		getline(cin, ps, '#');
		cin >> s;
		return deal(s);
	}
	if(s[0] == '"') {
		if(s[s.size() - 1] == '"') {
			string ss = "";
			for (int i = 1; i < s.size() - 1; i ++) {
				ss += s[i];
			}
			return make_pair(ss, ss);
		}
		string ss = "";
		string ps;
		getline(cin, ps, '"');
		s += ps;
		for (int i = 1; i < s.size(); i ++) {
			ss += s[i];
		}
		for(char i = 0; i < ps.size(); i ++) {
			if(ps[i] == ' ') {
				his[loginIndex].push_back("'");
			}
		} 
		return make_pair(ss, ss);
	}
	if(s=="version") {
		ans = make_pair(s, "Version: Violin-12.5, Copyright(c) Violin Inc, 2019 All Right reserved.");
	}
	else if(s == "ignore" || s == "ig") {
		in();
		cin >> s;
		return deal(s);
	}
	else if(s=="noecho") {
		noecho=true;
		ans = make_pair(s, "True");
	}
	
	else if(s=="mkmn")
	    ans = make_pair(s, mkmn());

	//新建文件

	else if(s=="mkfl")
	    ans = make_pair(s, mkfl());

	//改变现在所在的位置

	else if(s=="chmn" || s == "cd")
	    ans = make_pair(s, chmn());

	//输出在现在文件夹（目录）下的所有数值

	else if(s=="list"||s=="ls") {
		ans = make_pair(s, listMenu()); 
	}

	else if(s=="volume"||s=="vol") {
		string x;
		x += "Volumes:\n";
		for(int i=0;i<vol[loginIndex].size();i++)
			x += vol[loginIndex][i].cont + "\n";
		ans = make_pair(s, x);
	}

	else if(s=="delvol" || s == "rmvol") {
		string diskx;
		pair<string, string> ansx;
		ansx = in();
		diskx = ansx.second;
		bool can=false;
		for(int i=0;i<vol[loginIndex].size();i++)
		{
			if(diskx==vol[loginIndex][i].cont)
			{
				vol[loginIndex][i].cont.clear();
				ans.second = diskx + ": " + "had been moved.\n";
				can = true;
				ans.first = s;
				break;
			}
		}
		if(!can) {
			ans.second = diskx + ": There is no this volume.\n";
			ans.first = s;
		}
	}

	//重命名文件夹
	
	else if(s == "rnmn"){
		ans = make_pair(s, rnmn());
	} 
	
	else if(s == "rnfl"){
		ans = make_pair(s, rnfl());
	}

	//删除文件夹

	else if(s=="rmmn"||s=="delmn")
	{
		string rmy;
		pair<string, string> ansx;
		ansx = in();
		rmy = ansx.second;
		string fax;
		menu mnxx;
		mnxx.father=nowmn;
		mnxx.name=rmy;
		fax=create(mnxx);
		ans = make_pair(s, rmmn(fax));
	}

	//删除文件

	else if(s=="rmfl" || s == "delfl")
		ans = make_pair(s, rmfl());

	//输出文件（看文件）

	else if(s=="getfl" || s == "rdfl")
	    ans = make_pair(s, getfl());

	//输入文件（写文件）

	else if(s=="wrtfl")
	{
		string flx;
		pair<string, string> ansx;
		ansx = in();
		flx = ansx.second;
		bool can=false;
		for(int i=0;i<fl[loginIndex].size();i++)
		{
			if(fl[loginIndex][i].name==flx&&fl[loginIndex][i].father==nowmn)
			{
				getchar();
//				getline(cin,fl[loginIndex][i].cont);
//				fl[loginIndex][i].cont = readtillendl();
				fl[loginIndex][i].cont = readtillendl() + "\n";
				can = true;
				ans = make_pair(s, "True");
			}
		}
		if(!can) {
			ans = make_pair(s, flx + ": There is no this file.\n");
		}
	}

	//CALCULATE

	else if(s=="calc")
	{
	    string str = "";
	    BigFloat bf;
		while(true) {
			str += varr(in());
	    	if(str == "")
	    	    continue;
	        if(str[str.length() - 1] != '=') {
	            continue;
	        }
//	        cout << str << endl;
//	        str = str.substr(0, str.length() - 1);
	        str = Replace(str);
	        bf = solve(str);
//	        cout << bf << "\n";
			break;
	    }
	    ans = make_pair("calc", bf.toString());
	}

	//CALENDAR

	else if(s=="cale")
	{
		int yearx = 0;
		string yeary;
		pair<string, string> ansx;
		ansx = in();
		yeary = ansx.second;
		for (int i = 0; i < yeary.size(); i ++) {
			if (yeary[i] < '0' || yeary[i] > '9') {
				break;
				ans = make_pair("cale", ansx.first + ": " + ansx.second + "\n");
			}
			yearx *= 10;
			yearx += yeary[i] - '0';
		}
		startWeek(yearx);
		cout<<"\n";
		ans = make_pair(s, "True");
	}

	//DATE

	else if(s=="date")
	{
		ans = make_pair(s, clock_num() + "\n");
	}

	//寻找两个文件的不同

	else if(s=="fdif" || s == "fc")
	{
		int lenax,lenbx,finda=false,findb=false,na,nb;
		string ax;
		pair<string, string> ansx;
		ansx = in();
		ax = ansx.second;
		string bx;
		ansx = in();
		bx = ansx.second;
		for(int i=0;i<fl[loginIndex].size();i++)
		{
			if(fl[loginIndex][i].name==ax)
			{
				lenax=fl[loginIndex][i].cont.size();
				na=i;
				finda=true;
			}
			if(fl[loginIndex][i].name==bx)
			{
				lenbx=fl[loginIndex][i].cont.size();
				nb=i;
				findb=true;
			}
		}
		if(!finda) {
			cout<<ax<<": "<<"There is no this file.\n";
			ans = make_pair(s, "Not exist.");
		}
		if(!findb) {
			cout<<bx<<": "<<"There is no this file.\n";
			ans = make_pair(s, "Not exist.");
		}
		else
		{
			int cnt = 0;
			for(int i=0;i<min(lenax,lenbx);i++) {
				ans.second += "\t" + ax;
				ans.second += "; " + bx;
				if(fl[loginIndex][na].cont[i]!=fl[loginIndex][nb].cont[i]) {
					//cout<<"In "<<i<<", "<<ax<<" is "<<fl[loginIndex][na].cont[i]<<", but "<<bx<<" is "<<fl[loginIndex][nb].cont[i]<<"\n";
					ans.second += i + ": ";
					ans.second += fl[loginIndex][na].cont[i];
					ans.second += "; ";
					ans.second += fl[loginIndex][nb].cont[i];
					ans.second += "\n";
					cnt ++;
				}
			}
			if(lenbx>lenax)
			{
				ans.second += "For file" + bx + ", the rests are: \n";
				for(int i=lenax;i<lenbx+1;i++)
				{
					ans.second += fl[loginIndex][nb].cont[i];
					cnt ++;
				}
				cout << "\n";
			}
			else if(lenax<lenbx);
			{
				cout << "For file" << ax << ", the rests are: \n";
				for(int i=lenbx;i<lenax+1;i++)
				{
					cout<<fl[loginIndex][na].cont[i];
					ans.second += fl[loginIndex][na].cont[i];
					cnt ++;
				}
				ans.second += "\n";
			}
			ans.first = s;
		}
	}

	//拷贝文件

	else if(s=="cp")
	{
		string ax,bx,carx;
		int car;
		pair<string, string> ansx;
		ansx = in();
		ax = ansx.second;
		ansx = in();
		bx = ansx.second;
		bool cana=false,canb=false;
		for(int i=0;i<fl[loginIndex].size();i++)
		{
			if(fl[loginIndex][i].name==ax)
			{
				carx=fl[loginIndex][i].cont;
				cana=true;
			}
			if(fl[loginIndex][i].name==bx)
			{
				car=i;
				canb=true;
			}
		}
		if(!cana) {
			ans = make_pair(s, bx + ": There is no this file.\n");
		}
		else if(!canb) {
			ans = make_pair(s, bx + ": There is no this file.\n");
		}
		else { 
			fl[loginIndex][car].cont=carx;
			ans = make_pair(s, "True");
		}
	}

	else if(s=="usr" || s == "user")
	{
		if(loginName == "Administrator"){
			ans = make_pair("usr", "");
	        for(int i=0;i<us.size();i++) {
				ans.second += us[i].name;
				ans.second += "\n";
			}
	    }else {
			ans = make_pair(s, "Permission denied.");
	    }
	}

	//删除用户
	
	else if(s=="delusr"||s=="rmusr")
	{
		string usrx;
		printf("Please input the username.\n");
		cin>>usrx;
		if(usrx=="Administrator")
		{
			cout<<"Sorry, Administrator CANNOT be removed.\n";
		}
		else
		{
			bool can=false;
			for(int i=0;i<us.size();i++)
			{
				if(us[i].name==usrx)
				{
					cout<<"Please enter the code of "<<us[i].name<<".\n";
					string codex;
					cin>>codex;
					if(codex==us[i].code)
					{
						us[i].code="\0";
						us[i].name="\0";
						cout<<"Congratulations, "<<usrx<<" has been delete successfully.\n";
					}
					else
					{
						cout<<"Sorry, the code of "<<usrx<<" is wrong.\n";
					}
					can=true;
				}
			}
			if(!can)cout<<"User's name cannot be found.\n";
		}
	}

	else if(s=="mkusr")
	{
		string usx,codex;
		bool can=false;
		cin>>usx;
		for(int i=0;i<us.size();i++)
		{
			if(us[i].name==usx)
			{
				cout<<"Sorry, "<<usx<<" has already exist.\n";
				can=true;
			}
		}
		if(!can)
		{
			cout<<"Please input the code of "<<usx<<".\n";
			cin>>codex;
			user usxx;
			usxx.name=usx;
			usxx.code=codex;
			us.push_back(usxx);
			cout<<usxx.name<<" has been added.\n";
		}
		out();
	}
	

	else if(s=="history" || s == "his")
	{
		if(loginName == "Administrator"){
			cout << "Please input the username.\n";
			string usx;
			pair<string, string> ansx;
			ansx = in();
			usx = ansx.second;
			bool canFind = false;
			int index;
			for(int i = 0;i < us.size();i++){
				if(us[i].name == usx){
					canFind = true;
					index = i;	
				}
			}
			if(canFind){	
				printf("%s's history : \n",usx.c_str()); 
				for(int i=0;i<his[index].size();i++)
				    cout<<i<<": "<<his[index][i]<<"\n";
			}else 
			    cout << "There is no user called " << usx << endl; 
		}else{
			for(int i=0;i<his[loginIndex].size();i++)
			    cout<<i<<": "<<his[loginIndex][i]<<"\n";
		}
	}

	else if(s=="rmhis"||s=="rmhistory"||s=="delhis"||s=="delhistory")
	{
		ans.first = s;
		if(loginName == "Administrator"){
			cout << "Please input the username.\n";
			string usx;
			pair<string, string> ansx;
			ansx = in();
			usx = ansx.second;
			bool canFind = false;
			int index;
			for(int i = 0;i < us.size();i++){
				if(us[i].name == usx){
					canFind = true;
					index = i;
				}
			}
			if(canFind){
				his[index].clear();
				out();
				ans.second = "True";
			}else 
			    ans.second = "There is no user called " + usx; 
		}else
		{
			//his[loginIndex].clear();
			ans.second = "You don't have this permission!";
		}
	}

	//清屏
	else if(s == "cls" || s == "qp"||s=="clear"){
		system("cls");
		cout<<"Violin\n";
		ans.first = s;
		ans.second = "True";
	}

	//打开网站
	else if(s == "openweb" || s == "web" || s == "wz"){
		printf("Please input the url.\n");
		string st;
		pair<string, string> ansx;
		ansx = in();
		st = ansx.second;
		if(st.find('.') >= 0 && st.find('.') < st.length())
		    ShellExecute(NULL, "open", st.c_str(), NULL, NULL, SW_SHOWNORMAL);
           else
               ans.second = "Wrong url!\n";
        ans.first = s;
	}
	
	//更改窗口设置
	else if(s == "config" || s == "window" || s == "sz"){
		windowConfig();
		ans.first = s;
		ans.second = "True";
		system("cls");
		cout<<"Violin\n";
	}

	else if(s == "help" || s == "bz"){
		system("How_to_use.docx");
		ans.first = s;
		ans.second = "True";
	}

	//保存设置

	else if(s=="sync")
	{
		out();
		ans.first = s;
		ans.second = "True";
		//freopen("CONIN$","r",stdin);
		//freopen("CONOUT$","w",stdout);
	}

	else if(s=="mkdisk"||s=="mkdk"||s=="mkvol")
	{
		mkdk();
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "mntvol" || s == "mnt" || s == "mount") {
		string diskx;
		pair<string, string> ansx;
		ansx = in();
		diskx = ansx.second;
		volume v;
		v.cont = diskx;
		for(int i=0;i<vol[loginIndex].size();i++)
		{
			if(vol[loginIndex][i].cont==diskx)
			{
				ans.second = diskx + ": " + "is already exist.\n";
			}
		}
		vol[loginIndex].push_back(v);
		ans.second = "True";	
		ans.first = s;
	}

	else if(s=="wrtdisk"||s=="wrtdk"||s=="wrtvol")
	{
		wrtdk();
		ans.first = s;
		ans.second = "True";
	}

	else if((s=="rdfm"||s=="readfm"||s=="readfrom"))
	{
		past = his[loginIndex].size();
		readfm();
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s=="super"||s=="sudo")
	{
		if(loginName!="Administrator"||cop!="Administrator")
		{
//			cout << "Please input time: ";
			int pd;
			pd = s2i(varr(in()));
			if(pd == 0) {
				ans.second = "Time musn't be 0.\n"; 
			}
			else {
				cout<<"Please input "<<loginName<<"'s code: ";
				string x;
				x.clear();
				char ch;
				while(ch=getch())
				{
					if(ch=='\r')
						break;
					x+=ch;
				}
				if(x!=loginCode)
				{
					ans.second = "\nSorry, the code is not match.\n";
				}
				else {
					cout << "\n";
					cop=loginName;
					loginName="Administrator";
					done += pd;
					ans = in();
				}
			}
		}
		else
			ans.second = "You are already in Administrator mode.\n";
		ans.first = s;
	}

//	else if(s=="ENDVOL")
//	{
//		readfl=true;
//		cout<<"\n";
//		freopen("CONIN$","r",stdin);
//		return make_pair("ENDVOL", "True");
//	}

	else if(s=="pause")
	{
		int tx;
		tx = s2i(in().second);
		Sleep(1000*tx);
		ans.first = s;
		ans.second = "True";
	}

	//关机
	
	else if (s == "fastexit" || s == "fastshutdown") {
		if (loginName == "Administrator") {
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\tViolin\n";
			cout<<"\t\t\t\t";
			for(int i=0;i<7;i++)
			{
				cout<<".";
			}
			out();
			exit(0);
		}
		else {
			ans.second = "You don't have this permission.\n";
			ans.first = s;
		}
	} 

	else if(s=="shutdown" || s == "exit")
	{
		if (loginName == "Administrator") {
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\tViolin\n";
			cout<<"\t\t\t\t";
			for(int i=0;i<7;i++)
			{
				Sleep(300);
				cout<<".";
			}
//			endx();
			//printout(loginIndex, false, 0);
			out();
			exit(0);
		}
		else {
			ans.second = "You don't have this permission.\n";
			ans.first = s;
		}
	}

	else if (s == "fastreboot" || s == "fastrestart") {
		if (loginName == "Administrator") {
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\tViolin\n";
			cout<<"\t\t\t\t";
			for(int i=0;i<7;i++)
			{
				cout<<".";
			}
			out();
			system("start Violin-12.exe");
			exit(0);
		}
		else {
			ans.second = "You don't have this permission.\n";
			ans.first = s;
		}
	} 
	
	//????

	else if(s=="restart"||s=="reboot")
	{
		if (loginName == "Administrator") {
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\tViolin\n";
			cout<<"\t\t\t\t";
			for(int i=0;i<7;i++)
			{
				Sleep(300);
				cout<<".";
			}
//			endx();
			//printout(loginIndex, false, 0);
			out();
			system("start Violin-12.exe");
			exit(0);
		}
		else {
			ans.second = "You don't have this permission.\n";
		}
		ans.first = s;
	}

	//logout
	else if(s == "logout" || s == "dc"){
		printf("Do you want to logout now? Press 'y' for yes, 'n' for no.\n");
		int key = 0;
		while(key != 121 && key != 110){
			key = getch();
		}
		if(key == 121){
			isLogout = true;
			canLogin = false;
			nowmn="/";
			ans = make_pair("logout", "True");
		}
	}

	/*
	else if(s == "conf" || s == "config"){
	    conf();
		system("cls");
		cout<<"Violin\n";
	}
	*/

	//共享文件夹 share
	else if(s == "share"){
		runShare();
		ans.first = s;
		ans.second = "True";
		system("cls");
		cout<<"Violin\n";			
	} 

	//切换用户
	else if(s == "changeuser" || s == "chus"){
		//if(loginName == "Administrator" || changeFromAdministrator == true){
			//cout << "Please input the username.\n";
			cin >> usx;
			bool canFind = false;
			int index;
			for(int i = 0;i < us.size();i++){
				if(us[i].name == usx){
					canFind = true;
					index = i;
				}
			}
			if(canFind){
				loginName = usx;
				loginIndex = index;
			}
			else if (usx == "Administrator") {
				ans.second = "If you want to use Administrator's account, please use 'sudo' or 'super'.\n";
			}else 
			    ans.second = "There is no user called " + usx + ".\n"; 
	//	}else
	//	    cout << "You don't have this permission.\n";
		ans.first = s;
	} 

	else if(s=="copyright"||s=="author")
	{
		ans.second = "Viotry's first editor is William Klug Han (Klug_Han@outlook.com), editor is William Klug Han. \nSteve Zhu is our system tester. \nMartin Guan writes the website.\n";
		ans.first = s;
	}

	//介绍
	else if(s == "about" || s == "gy"){
		ans.second = introduce();
		ans.first = s;
	}
	
	else if(s == "game" || s == "games" || s == "yx"){
	    runGames();	
		system("cls");
		cout<<"Violin\n";
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "ss" || s == "search"){
		search(mn,fl);
		system("cls");
		printf("Violin\n");
		string str = "color " + windowColor[loginIndex] + fontColor[loginIndex];
		system(str.c_str());
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s=="piano")
	{
		string musx;
		musx = in().second;
		for(int i=0;i<musx.size();i++)
		{
			if(musx[i]=='0')Sleep(128);

			if(musx[i]=='1')Beep(do,100);
			if(musx[i]=='2')Beep(re,100);
			if(musx[i]=='3')Beep(mi,100);
			if(musx[i]=='4')Beep(fa,100);
			if(musx[i]=='5')Beep(so,100);
			if(musx[i]=='6')Beep(la,100);
			if(musx[i]=='7')Beep(si,100);

			if(musx[i]=='d')Beep(qdo,100);
			if(musx[i]=='r')Beep(qre,100);
			if(musx[i]=='m')Beep(qmi,100);
			if(musx[i]=='f')Beep(qfa,100);
			if(musx[i]=='s')Beep(qso,100);
			if(musx[i]=='l')Beep(qla,100);
			if(musx[i]=='t')Beep(qsi,100);

			if(musx[i]=='D')Beep(do1,100);
			if(musx[i]=='R')Beep(re1,100);
			if(musx[i]=='M')Beep(mi1,100);
			if(musx[i]=='F')Beep(fa1,100);
			if(musx[i]=='S')Beep(so1,100);
			if(musx[i]=='L')Beep(la1,100);
			if(musx[i]=='T')Beep(si1,100);
		}
		ans.first = s;
		ans.second = "True";
	}
	
	//Print Out:
	else if(s=="check")
	{
		if(loginName=="Administrator")
		{
			string usx;
			cout<<"Please input the name.\n";
			cin >> usx;
			int time;
			cout<<"Please input the time for checking.\n";
			cin>>time;
			bool canFind = false;
			int index;
			for(int i = 0;i < us.size();i++){
				if(us[i].name == usx){
					canFind = true;
					index = i;
				}
			}
			if(canFind)
				printout(index, true, time);
			else 
			    cout << "There is no user called " << usx<<"." << endl; 
		}
		else
		{
			int time;
			cout<<"Please input the time for check.\n";
			time = s2i(in().second);
			printout(loginIndex, true, time);
		}
	}
	
	else if(s == "rep") {
		int t;
		t = s2i(in().second);
		int past = his[loginIndex].size();
		pair <string, string> sf = in();
		ans.first = s;
		ans.second += sf.first + ": \n" +sf.second;
		string st;
		for(int i = past; i < his[loginIndex].size() - 1; i ++)
			st += his[loginIndex][i] + " ";
		st += his[loginIndex][his[loginIndex].size() - 1];
//		for (int i = 0; i < t; i ++) {
//			sstr << st;
//			string sp;
//			int j = 0;
//			while(sstr >> sp) {
//				cout << j << sp << "\n";
//				j ++;
//			}
//			pair<string, string> ansf = in();
//			if (ansf.first == ansf.second)
//				ans.second += ansf.first + ":\n There is no such commend.\n";
//			else
//				ans.second += ansf.first + ": \n" + ansf.second + "\n";
//		}
	}
	
	else if(s=="as")
	{
		string flx;
		cin>>flx;
		flx+=".cof";
		freopen(flx.c_str(), "w", stdout);
		pair<string, string> sf = in();
		cout << sf.first << ": " << sf.second << "\n";
		freopen("CONOUT$", "w", stdout);
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s=="get")
	{
		string flx;
		cin>>flx;
		flx+=".cof";
		string x="more ";
		x+=flx;
		system(x.c_str());
		ans.first = s;
		ans.second = "True";
	}

//	else if (s == "str") {
//		bool fl = false;
//		string name;
//		cin >> name;
//		his[loginIndex].push_back(name);
//		string num = in().second;
//		map<string, string>::iterator iter;  
//		iter = intmap.find(name);
//	    if(iter != intmap.end()) {
//	    	ans.second = "Already exist.\n";
//	    	fl = true;
//		}
//		if (!fl) {
//			strmap[name] = num;
//			ans.second = "True";
//		}
//		ans.first = s;
//	}
//	
//	else if (s == "int") {
//		bool fl = false;
//		string name;
//		cin >> name;
//		his[loginIndex].push_back(name);
//		string num = in().second;
//		map<string, string>::iterator iter;  
//		iter = strmap.find(name);
//	    if(iter != strmap.end()) {
//	    	ans.second = "Already exist.\n";
//	    	fl = true;
//		}
//		if (!fl) {
//			if(s2i(num) != inf)
//				intmap[name] = num;
//			ans.second = intmap[name];
//		}
//		ans.first = s;
//	}
	
	else if (s == "let") {
		bool fl = false;
		string name;
		name = in().second;
		string num = in().second;
		clamap[name] = num;
		ans.second = clamap[name];
		ans.first = s;
	}
	
	else if (s == "set") {
		bool fl = false;
		string name;
		string ki;
		name = in().second;
		bool flags = true;
		while(true) {
			string num = in().second;
			ki += num;
			ki += " ";
			if(num == ";") {
				break;
			}
			setmap[name].push_back(num);
		}
		ans.second = ki;
		ans.first = s;
	}
	
	else if(s == "setlist") {
		map<string, vector<string> >::iterator iter;  
		for (iter = setmap.begin(); iter != setmap.end(); iter ++) {
			ans.second += (iter->first + " ");
			for(int i = 0; i < iter->second.size(); i ++) {
				ans.second += (iter->second[i] + " ");
			}
			ans.second += "\n";
		}
		ans.first = s;
	}
	
	else if(s == "delset") {
		string name;
		name = in().second;
		setmap[name].clear();
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "destroy") {
		string name;
		string ki;
		name = in().second;
		ki = in().second; 
		bool get = false;
		vector<string> p = setmap[name];
		for(vector<string>::iterator iter = setmap[name].begin(); iter != setmap[name].end(); iter ++){
		    if(*iter == ki){
	    	    setmap[name].erase(iter);
//	    	    cout << "Es" << "\n";
	    		ans.second = "True";
	    		get = true;
	    		break; 
		    }
		}
		if (get == false)
			ans.second = ki + ": There is no this variety.\n";
		ans.first = s;
	}
	
	else if (s == "input") {
		incnt += 1;
		if(rdfmflag){
			freopen("CON", "r", stdin);
		}
		int now = his[loginIndex].size();
		string t = in().second;
		if(rdfmflag){
			indel += 1;
			string rdx = rdfmflx + ".vol";
			freopen(rdx.c_str(), "r", stdin);
			int t = 0;
			while(true) {
				string sss;
				cin >> sss;
				if(sss == "input") {
					t += 1;
				}
				if(t == incnt) {
					break;
				}
			}
		}
		ans.first = s;
		ans.second = t;
	}
	
	else if (s == "echo" || s == "output") {
		pair <string, string> pans = in();
//		bool fl = false;
		string sss;
//		map<string, string>::iterator iter;  
//		iter = clamap.find(pans.second);
//		if(iter != clamap.end()) {
//			sss = iter->second;
//			fl = true;
//		}
		sss = varr(pans); 
//		if (!fl)
//			sss = pans.second;
		cout << sss << "\n";
		ans.first = s;
		ans.second = "True";
	}
	
	else if (s == "var") {
		map<string, string>::iterator iter;  
		for (iter = clamap.begin(); iter != clamap.end(); iter ++) {
			ans.second += (iter->first + " " + iter->second + "\n");
		}
		ans.first = s;
	}
	
	else if (s == "delvar" || s == "rmvar") {
		map<string, string>::iterator iter;  
		for (iter = clamap.begin(); iter != clamap.end(); iter ++) {
			iter->second = iter->first;
		}
		ans.first = s;
		ans.second = "True";
	}
	
	else if (s == "there") {
		bool flags = false;
		string name = varr(in());
		string se = in().second;
		vector<string> p = setmap[se];
		for (int i = 0; i < p.size(); i ++) {
			if(p[i] == name) {
				flags = true;
			}
		}
		ans.first = s;
		if(flags == false)
			ans.second = "False";
		else
			ans.second = "True";
	}
	
	else if(s == "bas") {
		string ps = in().second;
		bool fl = false;
		string ts = clamap[ps];
		clamap[ps] = ps;
		in();
		clamap[ps] = ts;
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "cla") {
		string ps = in().second;
		ans.first = ps;
		ans.second = varr(make_pair(ps, ps));
	}
	
	else if(s == "if") {
		string ps = varr(in());
		if (ps == "True" || (s2i(ps) >= 1 && s2i(ps) != inf)) {
			while(in().second != ";") {
				continue;
			}
			ifecan = false;
		}
		else {
			string t;
			getline(cin, t, ';');
			ifecan = true;
		}
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "elif") {
		if(ifecan == false) {
			string t;
			getline(cin, t, ';');
			return make_pair(s, "False");
		}
		else {
			string ps = varr(in());
			if (ps == "True" || (s2i(ps) >= 1 && s2i(ps) != inf)) {
				while(in().second != ";") {
					continue;
				}
				ifecan = false;
			}
			else {
				string t;
				getline(cin, t, ';');
				ifecan = true;
			}
		}
		ans.first = s;
		ans.second = "True";
	}
	
	else if(s == "else") {
		if(ifecan == false) {
			string t;
			getline(cin, t, ';');
			return make_pair(s, "False");
		}
		else {
			while(in().second != ";") {
				continue;
			}
			ifecan = false;
		}
		ans.first = s;
		ans.second = "True";
	}
	
	else if (s == "ENDL") {
		ans.first = s;
		ans.second = s;
	}
	
	//若无此命令
	
	else {
		ans.first = s;
//		bool fl = false;
//		map<string, string>::iterator iter;  
//		iter = clamap.find(s);
//		if(iter != clamap.end()) {
//			ans.second = iter->second;
//			fl = true;
//		} 
//		if (!fl)
//			ans.second = s;
		ans.second = s;
	}
	if(done <= 0) {
		done = 0;
		loginName = cop;
	}
	out();
	done -= 1;
	return ans;
}

pair<string, string> in() {
	string s;
//	while(!sstr.eof()) {
//		sstr >> s;
//		cout << "D: " << s << "\n";
//		return deal(s);
//	}
	cin >> s;
	pair<string, string> p = deal(s);
	if(p.second != "True") {		
		return p;
	}
	else {
		return make_pair("True", "True");
	}
}


BOOL WINAPI HandlerRoutine(DWORD dwCtrlType){
    if( CTRL_CLOSE_EVENT == dwCtrlType ){
	    system("copy ViolinOS.cof.bak ViolinOS.cof");
	    //sleep(1);
	    exit(0);
    }
}

void checkClose(){
    while(1)
        SetConsoleCtrlHandler(HandlerRoutine, TRUE);
}

void runMain(){
	//system("mode con:cols=80 lines=500");
	Logout:
	isLogout = false;
    conf();
	system("color 9f");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\tViolin\n";
	cout<<"\t\t\t\t";
	for(int i=0;i<7;i++)
	{
		Sleep(300);
		cout<<".";
	}
	Sleep(500);
	login();
//	out();
	freopen("CONIN$","r",stdin);
//	start();
	system("copy ViolinOS.cof ViolinOS.cof.bak");
	cop=loginName;
	system("cls");
	cout<<"Violin\n";
	while (true) {
		if(!noecho||readfl)
			cout<<loginName << nowmn<<" ";
		pair<string, string> ans = in();
		if (ans.first == ans.second && ans.second == "True") {
			
		}
		else if (ans.first == ans.second)
			cout << ans.first << ": There is no such commend.\n";
		else
			cout << ans.first << ": \n" << ans.second << "\n";
		if(isLogout)
		    goto Logout;
	}
} 

int main(){
	thread t1(checkClose);
	thread t2(runMain);
	t1.join();
	t2.join();
}

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string add(string &first, string &second)
{
    int length = max(first.length(), second.length());
    string result(length,'0');
    int carry = 0;
    int i1 = first.length()-1;
    int i2 = second.length()-1;
    
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = i1 >= 0? first.at(i1) - '0' : 0;
        int secondBit = i2 >= 0? second.at(i2) - '0' : 0;
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        result[i] = sum;
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
        i1--; i2--;
    }
    if (carry)  result = '1' + result;
    return result;
}

string multiplyiSingleBit(string &a, string &b)
{  return to_string((a[0] - '0')*(b[0] - '0'));  }

string sub(string num1, string num2) {
    string s(max(num1.length(),num2.length()),'0');
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    bool lend(false);
    for(int i = 0;i < num1.length();i++)
    {
        int tmp = (num1[i] - '0') - ( i >= num2.length()? 0 : (num2[i] - '0') );
        if(lend) tmp--;
        if(tmp < 0) {
            tmp += 2;
            lend = true;
        } else lend = false;
        s[i] = ('0'+tmp);
    }
    
    reverse(s.begin(), s.end());
    
    while(s[0] == '0' && s.length() > 1)
        s = s.substr(1);
    return s;
}

string multiply(string &X, string &Y)
{
    int n = makeEqualLength(X, Y);
    
    if (n == 0) return "0";
    if (n == 1) return multiplyiSingleBit(X, Y);
    
    int fh = n/2;
    int sh = (n-fh);
    
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
    
    string P1 = multiply(Xl, Yl);
    string P2 = multiply(Xr, Yr);
    string temp1 = add(Xl, Xr);
    string temp2 = add(Yl, Yr);
    string P3 = multiply(temp1, temp2);
    
    int numof0 = 2*sh;
    string zeros(numof0,'0');
    string zeros2(sh,'0');
    
    while(P1.length() > 1 && P1[0] == '0') P1 = P1.substr(1);
    while(P2.length() > 1 && P2[0] == '0') P2 = P2.substr(1);
    while(P3.length() > 1 && P3[0] == '0') P3 = P3.substr(1);
    
    string t1 = sub(P3,P1);
    string t2 = sub(t1,P2);
    string tt1 = P1+zeros;
    string tt2 = t2+zeros2;
    string t3 = add(tt1, tt2);
    string res = add(t3,P2);
    while(res.length() > 1 && res[0] == '0') res = res.substr(1);
    return res;
}

int main(int argc, char **argv)
{
    /*
    string str = string(argv[1]);
    int k = stoi(str);
    k = (int)pow(2,k);
    string s(k,'1');
    multiply(s,s);
    return 0;*/
    
    
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n; in >> n;
    string num1,num2;
    in >> num1;
    in >> num2;

    string res = multiply(num1,num2);

    out << res;

    in.close();
    out.close();
    
    return 0;
}

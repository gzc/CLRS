#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

string multiply(string &num1, string &num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 2 + '0';
            carry = tmp / 2;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}


int main(int argc, char **argv) {
    /*
    string str = string(argv[1]);
    int k = stoi(str);
    k = (int)pow(2,k);
    string s(k,'1');
    multiply(s,s);
    return 0;
     */
 
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

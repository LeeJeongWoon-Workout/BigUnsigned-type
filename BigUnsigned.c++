#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class BigUnsigned {
   
    
   
    void set_list(int n) {
        vector<int> set(n+1,0);
        list=set;
    }
    public:
    vector<int> list;
    BigUnsigned() {vector<int> list(0);}
    BigUnsigned(unsigned long long n) {
        string s=to_string(n);
        for (int i=0;i<s.length();i++) {
            list.push_back(stoi(s.substr(i,1)));
        }
    }
    BigUnsigned(const BigUnsigned& b) {list=b.list;}

    BigUnsigned(string s) {
        for (int i=0;i<s.size();i++) {
            string k=s.substr(i,1);
            int m=stoi(k);
            list.push_back(m);
        }
    }

    friend BigUnsigned operator+(BigUnsigned& v1,BigUnsigned& v2) {
            vector<int> op1;
            vector<int> op2;
            BigUnsigned result;

        if (v1.list.size()>=v2.list.size()) {

            result.set_list(v1.list.size()+1);
            op1=v1.list;

            
            for (int i=0;i<v1.list.size()-v2.list.size();i++) {
                op2.push_back(0);
            }
            for (int i=0;i<v2.list.size();i++) {
                op2.push_back(v2.list[i]);
            }
        }
        else {
            op1=v2.list;
            result.set_list(v2.list.size()+1);
            for (int i=0;i<v2.list.size()-v1.list.size();i++) {
                op2.push_back(0);
            }
            for (int i=0;i<v1.list.size();i++) {
                op2.push_back(v1.list[i]);
            }
        }
        bool carry=false;

        for (int i=op1.size()-1;i>=0;i--) {
            int c=0;
            if (carry) c=1;
            
            result.list[i+1]=(op1[i]+op2[i]+c)%10;

            if ((op1[i]+op2[i]+c)/10==1) carry=true;
            else carry=false;
        }

        if (carry) result.list[0]=1;
        return result;
    }
    friend ostream& operator<<(ostream& os,const BigUnsigned& v) {
        string result="";
        if (v.list[0]!=0) {
        for (int i=0;i<v.list.size()-1;i++) {
            string k=to_string(v.list[i]);
            result+=k;
        }
        }
        else {
            for (int i=1;i<v.list.size()-1;i++) {
                string k=to_string(v.list[i]);
                result+=k;
            }
        }

        os<<result;
        return os;
    }

};

int main() {
    BigUnsigned b{"98721359872378376378378378375657156756854895489489648489457737837378863786786783598"};
    BigUnsigned b1(b);
    BigUnsigned b2{"978088237509238539897788549848978948948948645945621844894787487489489878979786978902"};

    cout<<b1+b2<<endl;
}
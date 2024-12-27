#include <iostream>
#include "String.h"

using namespace std;


void test()
{
    String s1;
    cout<<"Please input:";
    cin >> s1;
    cout << "s1 = " << s1 << endl;

    cout << endl << "String s2 = \"string\"" << endl;
    String s2 = "hello";
    cout << "s2 = " << s2 << endl;

    cout << endl << "s2 = \"world\"" <<  endl;
    s2 = "world";
    cout << "s2 = " << s2 << endl;

    cout << endl << "s2 = s2"<< endl;
    s2 = s2;
    cout << "s2 = " << s2 << endl;

    cout << endl << "String (\"W\")"<< endl;
    String s3("W");
    cout<<"s3 += \" welcome to string word\""<<endl;
    s3 += " welcome to string word";
    cout << "s3 = " << s3 << endl;

    cout<<endl<<"String s4(s2)"<<endl;
    String s4(s2);
    cout<<"s4:"<<s4<<endl;

    cout<<endl<<"s4 > s1"<<endl;
    cout<<(s4 > s1 ? s4 : s1)<<endl;
}


int main(int argc,char* argv[])
{
    test();
    return 0;
}


#include "String.h"
#include <cstring>
#include <vector>

using namespace std;

String::String()
:_pstr(new char[1]()){}

String::String(const char* el){
    if(el){
        _pstr = new char[strlen(el) + 1]();
        strcpy(_pstr,el);
    }else{
        _pstr = new char[1];
        _pstr[0] = '\0';
    }
}

String::String(const String& el)
    :_pstr(new char[strlen(el._pstr) + 1]()){
        strcpy(_pstr,el._pstr);
    }

String::~String(){
    if(_pstr){
        delete []_pstr;
        _pstr = nullptr;
    }
}

String& String::operator=(const String& el){
    if(this != &el){
        delete []_pstr;
        _pstr = nullptr;
        _pstr = new char[strlen(el._pstr) + 1]();
        strcpy(_pstr,el._pstr);
    }
    return *this;
}

String& String::operator=(const char* el){
    if(_pstr != el){
        delete []_pstr;
        _pstr = new char[strlen(el) + 1]();
        strcpy(_pstr,el);
    }
    return *this;
}  

String& String::operator+=(const String& el){
    size_t newLength = strlen(_pstr) + strlen(el._pstr);

    char* newStr = new char[newLength + 1]();
    strcpy(newStr,_pstr);
    strcat(newStr,el._pstr);
    delete []_pstr;
    _pstr = newStr;

    return *this;
}

String& String::operator+=(const char* el){
    String tmp;
    if(tmp._pstr){ delete []tmp._pstr; }
    tmp._pstr = new char[strlen(_pstr) + 1]();
    strcpy(tmp._pstr,_pstr);
    delete []_pstr;
    _pstr = nullptr;
    _pstr = new char[strlen(tmp._pstr) + strlen(el) + 1]();
    strcpy(_pstr,tmp._pstr);
    strcat(_pstr,el);
   
    return *this;

}


char& String::operator[](size_t index){
    if(index >= size()){
        throw out_of_range("Index out of range");
    }
    return _pstr[index];
}

const char& String::operator[](size_t index) const{
    if(index >= size()){
        throw out_of_range("Index out of range");
    }
    return _pstr[index];
}

size_t String::size() const{
    return strlen(_pstr);
}

const char* String::c_str()const{
    return _pstr;
}

bool operator==(const String& lhs,const String& rhs){
    return !strcmp(lhs._pstr,rhs._pstr);
}
bool operator!=(const String& lhs,const String& rhs){
    return strcmp(lhs._pstr,rhs._pstr);
}
bool operator<(const String& lhs,const String& rhs){
    return strcmp(lhs._pstr,rhs._pstr) < 0;
}
bool operator>(const String& lhs,const String& rhs){
    return strcmp(lhs._pstr,rhs._pstr) > 0;

}
bool operator<=(const String& lhs,const String& rhs){
    return strcmp(lhs._pstr,rhs._pstr) <= 0;
}
bool operator>=(const String& lhs,const String& rhs){
    return strcmp(lhs._pstr,rhs._pstr) >= 0;
}

ostream& operator<<(ostream& os,const String& el){
    if(el._pstr) os<<el._pstr;
    return os;
}

istream& operator>>(istream& is,String& el){
    if(el._pstr){
        delete []el._pstr;
        el._pstr = nullptr;
    }
    
    vector<char> buf;
    char ch;
    while((ch = is.get()) != '\n'){
        buf.push_back(ch);
    }

    if(!buf.empty()){
        el._pstr = new char[buf.size() + 1]();
        strncpy(el._pstr,&buf[0],buf.size());
    }
    return is;
}

String operator+(const String& lhs,const String& rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

String operator+(const String& lhs,const char* rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

String operator+(const char* lhs,const String& rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

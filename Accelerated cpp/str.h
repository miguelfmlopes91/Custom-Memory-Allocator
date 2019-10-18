//
//  str.h
//  Accelerated cpp
//
//  Created by Miguel Lopes on 17/10/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "Vec.h"
#include <string>
#include <sstream>
#include <iostream>

class Str{
public:
    typedef Vec<char>::size_type size_type;
    
    //default constructor, create an empty Str
    Str(){}
    
    //create a Str containing n copies of c
    Str(size_type n, char c): data(n,c){}
    
    //create a Str from a null-terminated array of char
    Str(const char* cp){
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    
    //create a Str from the range denoted by iterators b and e
    template<class In> Str(In b, In e){
        std::copy(b, e, std::back_inserter(data));
    }
    
    
    size_type size() const {return data.size();}
    
    //operators
    char& operator[](size_type i){
        return data[i];
    }
    const char& operator[](size_type i) const{
        return data[i];
    }
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::ostream& operator<<(std::ostream&, const Str&);
    Str operator+(const Str&, const Str&);
private:
    Vec<char> data;
};

std::istream& operator>>(std::istream& is, Str& s){
    //oblitare existing values
    s.data.clear();
    
    //read and discard leading whitespaces
    char c;
    while (is.get(c) && isspace(c)) {
        ; // nothing to do here except to test the condition
    }
    
    if (is) {
        do {
            s.data.push_back(c);
        } while (is.get(c) && !isspace(c));
        if (is) {
            is.unget();
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream&os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i){
        os << s[i];
    }
    return os;
}


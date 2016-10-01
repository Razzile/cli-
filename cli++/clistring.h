//
//  clistring.h
//  cli++
//
//  Created by callum taylor on 23/03/2016.
//  Copyright © 2016 Satori. All rights reserved.
//

#ifndef _clistring_
#define _clistring_
#include <string>

namespace cli {

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

    
//TODO: MOAR!!!!
class string {
public:
    string(std::string str) : base_(str) { }
    
    string(const char *str) : base_(std::string(str)) {} // being explicit
    
    string red() {
        string str = string(KRED + base_ + KNRM);
        return str;
    }
    
    string green() {
        string str = string(KGRN + base_ + KNRM);
        return str;
    }

    string yellow() {
        string str = string(KYEL + base_ + KNRM);
        return str;
    }

    string blue() {
        string str = string(KBLU + base_ + KNRM);
        return str;
    }

    string magenta() {
        string str = string(KMAG + base_ + KNRM);
        return str;
    }

    string cyan() {
        string str = string(KCYN + base_ + KNRM);
        return str;
    }

    string white() {
        string str = string(KWHT + base_ + KNRM);
        return str;
    }

    
    operator std::string() {
        return base_;
    }
    
    operator const char*() {
        return &base_[0];
    }
    
    std::string* operator->() {
        return &base_;
    }
    
    friend std::ostream& operator<< (std::ostream& stream, const string& string) {
        stream << string.base_;
        return stream;
    }
    
private:
    std::string base_;
};
    
};

#endif /* _clistring_ */

//
//  cli++.h
//  cli++
//
//  Created by callum taylor on 23/03/2016.
//  Copyright © 2016 Satori. All rights reserved.
//

#ifndef _cli___
#define _cli___

#include <stdio.h>
#include <unistd.h>
#include "clistring.h"

namespace cli {
    
class cli_handle {
public:
    static cli_handle& get_handle() {
        static cli_handle handle = cli_handle();
        return handle;
    }
    
    cli_handle() : inno(STDIN_FILENO), outno(STDOUT_FILENO) {}
    
    void set_in_fileno(int inno) { this->inno = inno; }
    void set_out_fileno(int outno) { this->outno = outno; }
    
    int in_fileno() const { return inno; }
    int out_fileno() const { return outno; }
    
private:
    int inno;
    int outno;
};
    
static void println(cli::string str, ...) {
    if (str->find('\n') == str->npos)
        str->push_back('\n');
    
    cli_handle& handle = cli_handle::get_handle();
    
    va_list list;
    va_start(list, str);
    vdprintf(handle.out_fileno(), str, list);
    va_end(list);
}
    
    
}

#endif /* _cli___ */

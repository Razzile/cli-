//
//  main.cpp
//  cli++
//
//  Created by callum taylor on 23/03/2016.
//  Copyright © 2016 Satori. All rights reserved.
//

#include <iostream>
#include "cli++.h"

int main(int argc, const char * argv[]) {
    cli::string str = "ayy lmao";
    cli::println(str.red());
}

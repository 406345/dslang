#pragma once

#include "stdio.h"
#include "string"
#include "scanner.hpp"

using namespace std;

vector<token> scan(const string &source)
{
    scanner scanner;
    auto ret = scanner.scan(source);
    printf("===============================\n");

    for (auto r : ret)
    {
        printf("[%s] is %s @ %d:%d\n", r.symbol.data(), TOKEN_TYPE_NAME[r.type].data(), r.line, r.position);
    }

    return ret;
}
void test(){
    auto fp = fopen("./sample.dlang", "rb");
    fseek(fp, 0, SEEK_END);
    auto size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = new char[size];
    fread(buffer, 1, size, fp);
    string source = string(buffer, size);

    // Parse stage
    auto tokens = scan(source);
    scan("\"abc;");
    scan("\"abc;\"");
    scan("fun test(a,b,c,d) test=a; c=b+c+d;end");
}
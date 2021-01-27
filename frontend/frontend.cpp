#include "stdio.h"
#include "scanner.hpp"

int main(int argc, char const *argv[])
{
    scanner scanner;
    
    auto fp = fopen("./sample.dlang", "rb");
    fseek(fp,0,SEEK_END);
    auto size = ftell(fp);
    fseek(fp,0,SEEK_SET);

    char* buffer =new char[size];
    fread(buffer,1,size,fp);
    string source = string(buffer,size);

    auto ret = scanner.scan(source);

    for(auto r: ret){
        printf("[%s] type=%d line=%d pos=%d\n", r.symbol.data(), r.type , r.line, r.position);
    }
    /* code */
    return 0;
    
}

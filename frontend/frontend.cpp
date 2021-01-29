#include "stdio.h"
#include "scanner.hpp"

void test(const string &source)
{
    scanner scanner;
    auto ret = scanner.scan(source);
    printf("===============================\n");

    for (auto r : ret)
    {
        printf("[%s] is %s @ %d:%d\n", r.symbol.data(), TOKEN_TYPE_NAME[r.type].data(), r.line, r.position);
    }

}
int main(int argc, char const *argv[])
{

    auto fp = fopen("./sample.dlang", "rb");
    fseek(fp, 0, SEEK_END);
    auto size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = new char[size];
    fread(buffer, 1, size, fp);
    string source = string(buffer, size);

    test(source);
    test("\"abc;");
    test("\"abc;\"");
    test("fun test(a,b,c,d) test=a; c=b+c+d;end");
 
    return 0;
}

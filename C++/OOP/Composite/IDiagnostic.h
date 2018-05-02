#include <iostream>
#include <string>

using namespace std;

class IDiagnostic {
public:
    virtual void runDiagnostics() = 0;
    virtual string getDianosticsResult() = 0;
};

#include "IDiagnostic.h"

class TouchScreenDiagnostics : public IDiagnostic {
public:
    TouchScreenDiagnostics();
    virtual ~TouchScreenDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

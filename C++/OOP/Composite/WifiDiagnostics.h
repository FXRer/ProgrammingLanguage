#include "IDiagnostic.h"

class WifiDiagnostics : public IDiagnostic {
public:
    WifiDiagnostics();
    virtual ~WifiDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

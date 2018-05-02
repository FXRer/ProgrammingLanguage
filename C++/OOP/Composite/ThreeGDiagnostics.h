#include "IDiagnostic.h"

class ThreeGDiagnostics : public IDiagnostic {
public:
    ThreeGDiagnostics();
    virtual ~ThreeGDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

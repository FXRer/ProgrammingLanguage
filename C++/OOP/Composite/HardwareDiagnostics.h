#include "DiagnosticComposite.h"

class HardwareDiagnostics : public DiagnosticComposite {
public:
    HardwareDiagnostics();
    virtual ~HardwareDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

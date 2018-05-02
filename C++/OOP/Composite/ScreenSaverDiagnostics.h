#include "IDiagnostic.h"


class ScreenSaverDiagnostics : public IDiagnostic {
public:
    ScreenSaverDiagnostics();
    virtual ~ScreenSaverDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

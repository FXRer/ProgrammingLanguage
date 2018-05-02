#include "DiagnosticComposite.h"

class NetworkDiagnostics : public DiagnosticComposite {
public:
	NetworkDiagnostics();
    virtual ~NetworkDiagnostics();

    void runDiagnostics();
    string getDianosticsResult();
};

#include "DiagnosticComposite.h"

class PhoneDiagnostics : public DiagnosticComposite {
public:
	PhoneDiagnostics();
    virtual ~PhoneDiagnostics();
	
    void runDiagnostics();
    string getDianosticsResult();
};

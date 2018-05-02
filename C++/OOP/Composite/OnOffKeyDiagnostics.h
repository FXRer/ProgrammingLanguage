#include "IDiagnostic.h"

class OnOffKeyDiagnostics : public IDiagnostic {
public:
	OnOffKeyDiagnostics();
    virtual ~OnOffKeyDiagnostics();
	
    void runDiagnostics();
    string getDianosticsResult()
};

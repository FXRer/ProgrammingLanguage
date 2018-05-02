#include "IDiagnostic.h"
#include "list"

class DiagnosticComposite : public IDiagnostic  {
public:
    DiagnosticComposite();
    virtual ~DiagnosticComposite();

    void runDiagnostics();
    string getDianosticsResult();

    void addChild(IDiagnostic *child);
    void removeChild(IDiagnostic *child);
    
    IDiagnostic* getChild(int i);
    
protected:
    list<IDiagnostic*> mCompositeObjs;
};


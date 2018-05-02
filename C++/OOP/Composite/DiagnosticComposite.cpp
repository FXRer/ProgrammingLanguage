#include "DiagnosticComposite.h"

DiagnosticComposite::DiagnosticComposite() {

}

DiagnosticComposite::~DiagnosticComposite() {

}

void DiagnosticComposite::runDiagnostics() {
    for (list<IDiagnostic*>::iterator it = mCompositeObjs.begin(); it != mCompositeObjs.end(); ++it )
        (*it)->runDiagnostics();
}

string DiagnosticComposite::getDianosticsResult() {
    string ret = "";
    for (list<IDiagnostic*>::iterator it = mCompositeObjs.begin(); it != mCompositeObjs.end(); ++it )
        ret += (*it)->getDianosticsResult() + "\n";
    return ret;
}

void DiagnosticComposite::addChild(IDiagnostic *child) {
    mCompositeObjs.push_back(child);
}

void DiagnosticComposite::removeChild(IDiagnostic *child) {
    // find and remove the child. not implemented yet.
}

IDiagnostic* DiagnosticComposite::getChild(int i) {
    // get the child at i. Not implemented yet.
}


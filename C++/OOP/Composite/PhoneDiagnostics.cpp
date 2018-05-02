#include "DiagnosticComposite.h"

PhoneDiagnostics::PhoneDiagnostics() {

}

PhoneDiagnostics::~PhoneDiagnostics() {

}

void PhoneDiagnostics::runDiagnostics() {
    cout << "running PhoneDiagnostics..." << endl;
    DiagnosticComposite::runDiagnostics();
}

string PhoneDiagnostics::getDianosticsResult() {
    string ret = "PhoneDiagnostics all tested Okay!\n";
    ret += DiagnosticComposite::getDianosticsResult();
    return ret;
}

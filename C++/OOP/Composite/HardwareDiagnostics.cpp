#include "HardwareDiagnostics.h"

HardwareDiagnostics::HardwareDiagnostics() {

}

HardwareDiagnostics::~HardwareDiagnostics() {

}

void HardwareDiagnostics::unDiagnostics() {
    cout << "running HardwareDiagnostics..." << endl;
    DiagnosticComposite::runDiagnostics();
}

string HardwareDiagnostics::getDianosticsResult() {
    string ret = "HardwareDiagnostics all tested Okay!\n";
    ret += DiagnosticComposite::getDianosticsResult();

    return ret;
}

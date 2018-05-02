#include "NetworkDiagnostics.h"

NetworkDiagnostics::NetworkDiagnostics() {

}

NetworkDiagnostics::~NetworkDiagnostics() {

}

void NetworkDiagnostics::runDiagnostics() {
    cout << "running NetworkDiagnostics..." << endl;
    DiagnosticComposite::runDiagnostics();
}

string NetworkDiagnostics::getDianosticsResult() {
    string ret = "NetworkDiagnostics all tested Okay!\n";
    ret += DiagnosticComposite::getDianosticsResult();
    return ret;
}

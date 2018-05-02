#include "PhoneDiagnostics.h"
#include "ScreenSaverDiagnostics.h"
#include "HardwareDiagnostics.h"
#include "NetworkDiagnostics.h"
#include "TouchScreenDiagnostics.h"
#include "OnOffKeyDiagnostics.h"
#include "WifiDiagnostics.h"
#include "ThreeGDiagnostics.h"

int main()
{
    DiagnosticComposite *phoneDiagnostics = new PhoneDiagnostics();

    IDiagnostic *screenSaverDiagnostics = new ScreenSaverDiagnostics();
    DiagnosticComposite *hardwareDiagnostics = new HardwareDiagnostics();
    DiagnosticComposite *networkDiagnostics = new NetworkDiagnostics();

    IDiagnostic *touchScreenDiagnostics = new TouchScreenDiagnostics();
    IDiagnostic *onOffKeyDiagnostics = new OnOffKeyDiagnostics();

    IDiagnostic *wifiDiagnostics = new WifiDiagnostics();
    IDiagnostic *threeGDiagnostics = new ThreeGDiagnostics();

    hardwareDiagnostics->addChild(touchScreenDiagnostics);
    hardwareDiagnostics->addChild(onOffKeyDiagnostics);

    networkDiagnostics->addChild(wifiDiagnostics);
    networkDiagnostics->addChild(threeGDiagnostics);

    phoneDiagnostics->addChild(screenSaverDiagnostics);
    phoneDiagnostics->addChild(hardwareDiagnostics);
    phoneDiagnostics->addChild(networkDiagnostics);

    cout << "Run diagnostics on the phone!" << endl;
    phoneDiagnostics->runDiagnostics();
    cout << "****\nGet the diagnostics result\n" << phoneDiagnostics->getDianosticsResult() << endl;
    return 0;
}

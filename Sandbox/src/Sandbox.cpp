
#include "Buzaka.h"

class SandboxApp : public Buzaka::Application {

};

Buzaka::Application* Buzaka::CreateApplication() {
    BZ_INFO("Sandbox creation.")
    return new SandboxApp();
}
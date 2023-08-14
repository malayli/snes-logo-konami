/*---------------------------------------------------------------------------------


    Konami Logo for SNES Projects


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "logo.h"

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

    dmaClearVram();

    initLogo();

    setFadeEffect(FADE_IN);
    WaitForVBlank();

    while (1) {
        updateLogo();

        spcProcess();

        // Wait vblank and display map on screen
        WaitForVBlank();
    }
    return 0;
}

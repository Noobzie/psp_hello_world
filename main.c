#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

#include "callback.h"

#define VERS 1 //Talk about this
#define REVS 0

PSP_MODULE_INFO("Hello World", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

int main(void)
{
    pspDebugScreenInit();
    setupExitCallback();
    
    while(isRunning())
    {
        pspDebugScreenSetXY(0, 0);
        printf("Super Mario Galaxy is veur mietjes!");
        sceDisplayWaitVblankStart();
    }
    
    sceKernelExitGame();
    
    return 0;
}

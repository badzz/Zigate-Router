/*****************************************************************************
 *
* MODULE:              JN-AN-1217
 *
 * COMPONENT:          app_zcl_task.h
 *
 * DESCRIPTION:       Base Device application - ZCL Interface
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/* Description.                                                             */
/* If you do not need this file to be parsed by doxygen then delete @file   */
/****************************************************************************/

/** @file
 * Add brief description here.
 * Add more detailed description here
 */

/****************************************************************************/
/* Description End                                                          */
/****************************************************************************/

#ifndef APP_ZCL_TASK_H_
#define APP_ZCL_TASK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
//#include "base_device.h"
#include "OnOff.h"
#include "Basic.h"
#include "Identify.h"
#include "PowerConfiguration.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct
{
    tsZCL_ClusterInstance sBasicServer;
	tsZCL_ClusterInstance sPowerConfigurationServer;
    tsZCL_ClusterInstance sIdentifyServer;
    tsZCL_ClusterInstance sOnOffServer;


} ts_ZigateRouterClusterInstances  __attribute__ ((aligned(4)));

typedef struct
{
    tsZCL_EndPointDefinition sEndPoint;

    /* Cluster instances */
    ts_ZigateRouterClusterInstances sClusterInstance;

    /* Mandatory server clusters */
    /* Basic Cluster - Server */
    tsCLD_Basic sBasicServerCluster;
    tsCLD_PowerConfiguration sPowerConfigServerCluster;
    tsCLD_OnOff sOnOffServerCluster;
    tsCLD_Identify sIdentifyServerCluster;
    tsCLD_OnOffCustomDataStructure sOnOffServerCustomDataStructure;
    tsCLD_IdentifyCustomDataStructure sIdentifyServerCustomDataStructure;



} ts_ZigateRouter;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void APP_ZCL_vInitialise(void);
PUBLIC void APP_ZCL_vSetIdentifyTime(uint16 u16Time);
PUBLIC void APP_cbTimerZclTick(void *pvParam);
PUBLIC void APP_ZCL_vTask(void);
PUBLIC void APP_ZCL_vEventHandler(ZPS_tsAfEvent *psStackEvent);
#ifdef CLD_IDENTIFY_10HZ_TICK
    PUBLIC void vIdEffectTick(uint8 u8Endpoint);
#endif
    PUBLIC teZCL_Status registerClusters (  uint8                         u8EndPointIdentifier,
            tfpZCL_ZCLCallBackFunction    cbCallBack,
            ts_ZigateRouter*    psDeviceInfo );
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

extern ts_ZigateRouter sBaseDevice;


#endif /* APP_ZCL_TASK_H_ */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

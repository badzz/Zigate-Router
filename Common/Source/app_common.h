/*****************************************************************************
 *
 * MODULE:             JN-AN-1217
 *
 * COMPONENT:          app_common.h
 *
 * DESCRIPTION:        Base Device application - common includes selector
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

#ifndef APP_COMMON_H_
#define APP_COMMON_H_


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define NETWORK_RESTART_TIME    ZTIMER_TIME_MSEC(1000)
#define POLL_TIME               ZTIMER_TIME_MSEC(5000)
#define POLL_TIME_FAST          ZTIMER_TIME_MSEC(250)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum
{
    E_STARTUP,
    E_RUNNING
} teNodeState;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern PUBLIC void vTAM_MLME_RxInCca(bool_t bEnable);

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef CLD_GREENPOWER
extern PUBLIC uint8 u8GPTimerTick;
extern PUBLIC tszQueue APP_msgGPZCLTimerEvents;
extern uint8 au8GPZCLEvent[];
extern uint8 u8GPZCLTimerEvent;
#endif

/* Macros take the buffer pointer and return the data */
#define ZNC_RTN_U64( BUFFER, i )  ( ( ( uint64 ) ( BUFFER )[ i ]  <<  56) |\
    ( ( uint64 ) ( BUFFER )[ i + 1 ]  << 48) |\
    ( ( uint64 ) ( BUFFER )[ i + 2 ]  << 40) |\
    ( ( uint64 ) ( BUFFER )[ i + 3 ]  << 32) |\
    ( ( uint64 ) ( BUFFER )[ i + 4 ]  << 24) |\
    ( ( uint64 ) ( BUFFER )[ i + 5 ]  << 16) |\
    ( ( uint64 ) ( BUFFER )[ i + 6 ]  << 8) |\
    ( ( uint64 ) ( BUFFER )[ i + 7 ] & 0xFF))\

#define ZNC_RTN_U32( BUFFER, i ) ( ( ( uint32 ) ( BUFFER )[ i ] << 24) |\
    ( ( uint32 ) ( BUFFER )[ i + 1 ]  << 16) |\
    ( ( uint32 ) ( BUFFER )[ i + 2 ]  << 8) |\
    ( ( uint32 ) ( BUFFER )[ i + 3 ] & 0xFF))\

#define ZNC_RTN_U16( BUFFER, i ) ( ( ( uint16 ) (BUFFER)[ i ] << 8) |\
    ( ( uint16 ) (BUFFER)[ i + 1 ] & 0xFF))\

/* Macros take the value and put it into a buffer */
#define ZNC_BUF_U8_UPD( BUFFER, U8VALUE, LEN)    (  ( *( (uint8*)( ( BUFFER ) ) ) = ( ( ( ( uint8 ) ( U8VALUE ) ) & 0xFF ) ) ) ,\
     ( ( LEN ) += sizeof( uint8 ) ) )

#define ZNC_BUF_U64_UPD( BUFFER, U64VALUE, LEN)    ( ( *(uint8*) ( BUFFER ) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 56) & 0xFF)),\
    ( *(uint8*) ( ( BUFFER ) + 1) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 48) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 2) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 40) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 3) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 32) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 4) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 24) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 5) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >> 16) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 6) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) >>  8) & 0xFF ) ),\
    ( *(uint8*) ( ( BUFFER ) + 7) = (uint8) ( ( ( ( uint64 ) ( U64VALUE ) ) & 0xFF ) ) ),\
    ( ( LEN ) += sizeof( uint64 ) ) )

#define ZNC_BUF_U32_UPD( BUFFER, U32VALUE, LEN )     ( ( *( uint8* )( BUFFER )   =  ( uint8 ) ( ( ( ( uint32 ) ( U32VALUE ) ) >> 24 ) & 0xFF ) ),\
    ( *( uint8* )( ( BUFFER ) + 1) =  ( uint8 ) ( ( ( ( uint32 ) ( U32VALUE ) ) >> 16 ) & 0xFF ) ),\
    ( *( uint8* )( ( BUFFER ) + 2) =  ( uint8 ) ( ( ( ( uint32 ) ( U32VALUE ) ) >> 8 ) & 0xFF ) ),\
    ( *( uint8* )( ( BUFFER ) + 3) =  ( uint8 ) ( ( ( ( uint32 ) ( U32VALUE ) ) & 0xFF ) ) ) ,\
    ( ( LEN ) += sizeof ( uint32 ) ) )


#define ZNC_BUF_U16_UPD( BUFFER, U16VALUE, LEN )     ( ( *( uint8* )( BUFFER )   =  ( uint8 )  ( ( ( ( uint16)( U16VALUE ) ) >> 8 ) & 0xFF ) ),\
    ( *( uint8* ) ( ( BUFFER ) + 1 )  =  ( uint8 )  ( ( ( ( uint16 )( U16VALUE ) ) ) & 0xFF ) ) ,\
    ( ( LEN ) += sizeof( uint16 ) ) )


/* Macros take buffer and return data and the next offset of within the buffer */
#define ZNC_RTN_U16_OFFSET(BUFFER, i, OFFSET )   ( ZNC_RTN_U16 (BUFFER, i) );\
( ( OFFSET ) += sizeof (uint16) )

#define ZNC_RTN_U32_OFFSET(BUFFER, i, OFFSET )   (  ZNC_RTN_U32 (BUFFER, i) );\
( ( OFFSET ) += sizeof (uint32) )

#define ZNC_RTN_U64_OFFSET(BUFFER, i, OFFSET )  (  ZNC_RTN_U64 (BUFFER, i) );\
( ( OFFSET ) += sizeof (uint64) )



#endif /*APP_COMMON_H_*/

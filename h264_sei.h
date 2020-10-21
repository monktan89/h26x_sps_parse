//
// Created by monktan on 2020/10/21.
//

#ifndef ZLMEDIAKIT_H264_SEI_H
#define ZLMEDIAKIT_H264_SEI_H



#include <stdint.h>

#include "bs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    int payloadType;
    int payloadSize;
    uint8_t* payload;
} sei_t;

sei_t* sei_new();
void sei_free(sei_t* s);

//D.1 SEI payload syntax
#define SEI_TYPE_BUFFERING_PERIOD 0
#define SEI_TYPE_PIC_TIMING       1
#define SEI_TYPE_PAN_SCAN_RECT    2
#define SEI_TYPE_FILLER_PAYLOAD   3
#define SEI_TYPE_USER_DATA_REGISTERED_ITU_T_T35  4
#define SEI_TYPE_USER_DATA_UNREGISTERED  5
#define SEI_TYPE_RECOVERY_POINT   6
#define SEI_TYPE_DEC_REF_PIC_MARKING_REPETITION 7
#define SEI_TYPE_SPARE_PIC        8
#define SEI_TYPE_SCENE_INFO       9
#define SEI_TYPE_SUB_SEQ_INFO    10
#define SEI_TYPE_SUB_SEQ_LAYER_CHARACTERISTICS  11
#define SEI_TYPE_SUB_SEQ_CHARACTERISTICS  12
#define SEI_TYPE_FULL_FRAME_FREEZE  13
#define SEI_TYPE_FULL_FRAME_FREEZE_RELEASE  14
#define SEI_TYPE_FULL_FRAME_SNAPSHOT  15
#define SEI_TYPE_PROGRESSIVE_REFINEMENT_SEGMENT_START  16
#define SEI_TYPE_PROGRESSIVE_REFINEMENT_SEGMENT_END  17
#define SEI_TYPE_MOTION_CONSTRAINED_SLICE_GROUP_SET  18
#define SEI_TYPE_FILM_GRAIN_CHARACTERISTICS  19
#define SEI_TYPE_DEBLOCKING_FILTER_DISPLAY_PREFERENCE  20
#define SEI_TYPE_STEREO_VIDEO_INFO  21

#ifdef __cplusplus
}
#endif


#endif //ZLMEDIAKIT_H264_SEI_H

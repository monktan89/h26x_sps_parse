//
// Created by monktan on 2020/10/21.
//

#include <iostream>

#include "h26x_sps_parse.h"
#include "h265_stream.h"

namespace monk {

int32_t H26xParseSPS::h264Parse(const uint8_t *data, uint32_t dataSize, H26xSPSInfo& info)
{
    if(data == nullptr || dataSize == 0) return -1;

    int32_t result = -1;
    h264_stream_t *h = h264_new();
    result = read_nal_unit(h, (uint8_t *)data, dataSize);
    if(result == -1){
        std::cout << "h265_read_nal_unit error." << std::endl;
        h264_free(h);
        return -1;
    }

    if(h->nal->nal_unit_type != NAL_UNIT_TYPE_SPS){
        std::cout << "input not sps data." << std::endl;
        h264_free(h);
        return -1;
    }

    info.width = h->info->width;
    info.height = h->info->height;
    info.profile_idc = h->info->profile_idc;
    info.level_idc = h->info->level_idc;
    info.fps = h->info->max_framerate;

    h264_free(h);

    return 0;
}

int32_t H26xParseSPS::h265Parse(const uint8_t *data, uint32_t dataSize, H26xSPSInfo& info)
{
    if(data == nullptr || dataSize == 0) return -1;

    int32_t result = -1;
    h265_stream_t *h = h265_new();
    result = h265_read_nal_unit(h, (uint8_t *)data, dataSize);
    if(result == -1){
        std::cout << "h265_read_nal_unit error." << std::endl;
        h265_free(h);
        return -1;
    }

    if(h->nal->nal_unit_type != NAL_UNIT_SPS){
        std::cout << "input not sps data." << std::endl;
        h265_free(h);
        return -1;
    }

    info.width = h->info->width;
    info.height = h->info->height;
    info.profile_idc = h->info->profile_idc;
    info.level_idc = h->info->level_idc;
    info.fps = h->info->max_framerate;

    h265_free(h);

    return 0;
}

}// end namespace monk

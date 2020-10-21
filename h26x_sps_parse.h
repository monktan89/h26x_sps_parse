//
// Created by monktan on 2020/10/21.
//

#ifndef ZLMEDIAKIT_H26X_SPS_PARSE_H
#define ZLMEDIAKIT_H26X_SPS_PARSE_H

#include <cstdint>

namespace monk {

struct H26xSPSInfo
{
    uint32_t profile_idc;
    uint32_t level_idc;

    uint32_t width;
    uint32_t height;
    uint32_t fps;       //SPS中可能不包含FPS信息

    H26xSPSInfo() {
        profile_idc = 0;
        level_idc = 0;

        width = 0;
        height = 0;
        fps = 0;
    }
};

class H26xParseSPS {
public:
    /*
     解析H264 SPS数据信息
     @param data SPS数据内容，需要Nal类型为0x7数据的开始(比如：67 42 00 28 ab 40 22 01 e3 cb cd c0 80 80 a9 02)
     @param dataSize SPS数据的长度
     @param info SPS解析之后的信息数据结构体
     @return success:0，fail:-1
     */
    static int32_t h264Parse(const uint8_t *data, uint32_t dataSize, H26xSPSInfo& info);

    /*
     解析H265 SPS数据信息
     @param data SPS数据内容
     @param dataSize SPS数据的长度
     @param info SPS解析之后的信息数据结构体
     @return success:0，fail:-1
     */
    static int32_t h265Parse(const uint8_t *data, uint32_t dataSize, H26xSPSInfo& info);
};

} // end namespace monk



#endif //ZLMEDIAKIT_H26X_SPS_PARSE_H

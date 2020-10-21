//
// Created by monktan on 2020/10/21.
//

#include <iostream>

#include "h26x_sps_parse.h"


int main(int argc, char **argv)
{
    unsigned char data_264[] = {
            0x67,0x64,0x00,0x16,0xac,0xb2,0x81,0x40,
            0x7b,0x42,0x00,0x00,0x03,0x00,0x02,0x00,
            0x00,0x03,0x00,0x3d,0x1e,0x2c,0x5c,0xb0};

    unsigned char data_265[] {
            0X42,0X01,0X01,0X01,0X60,0X00,0X00,0X03,0X00,0X80,0X00,0X00,0X03,0X00,0X00,
            0X03,0X00,0X5D,0XA0,0X02,0X80, 0X80,0X2D,0X16,0X59,0X5E,0X49,0X32,0XB8,0X04,0X00,0X00,0X03,
            0X00,0X04,0X00,0X00,0X03,0X00,0X64,0X20
    };

    monk::H26xSPSInfo h264_info;
    monk::H26xSPSInfo h265_info;

    int32_t result = -1;
    result = monk::H26xParseSPS::h264Parse(data_264, sizeof(data_264), h264_info);
    if(result != 0){
        std::cout << "H26xParseSPS::h264Parse failed." << std::endl;
        return -1;
    }

    std::cout << "h264_info: width: " << h264_info.width
        << " , height: " << h264_info.height
        << " , fps: " << h264_info.fps
        << std::endl;

    result = monk::H26xParseSPS::h265Parse(data_265, sizeof(data_265), h265_info);
    if(result != 0){
        std::cout << "H26xParseSPS::h264Parse failed." << std::endl;
        return -1;
    }

    std::cout << "h265_info: width: " << h265_info.width
              << " , height: " << h265_info.height
              << " , fps: " << h265_info.fps
              << std::endl;

    return 0;
}
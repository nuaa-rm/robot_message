//
// Created by mijiao on 23-11-20.
// 使用方式：在MESSAGE_START和MESSAGE_END之间定义自定义消息

#ifndef HID_COMMUNICATION_ROBOT_MESSAGE_H
#define HID_COMMUNICATION_ROBOT_MESSAGE_H

#define MESSAGE_START union nuc_data_t { \
uint8_t raw[63];

#define MESSAGE_END }; \
message_data(nuc_unpacked_data, {\
    uint8_t id;\
    nuc_data_t nuc_data;\
});

#ifdef __cplusplus
#include <cstdint>
#define message_data(name, data) struct  __attribute__((packed)) name##_t data name
#else
#include <stdint.h>
#define message_data(name, data) typedef struct __attribute__((packed)) data name##_t; name##_t name
#endif

MESSAGE_START

    message_data(aim_data, {
        float yaw;
        float pitch;
        uint8_t target_rate;
        uint8_t target_number;
        uint8_t success;
    });

    message_data(gimbal_and_config_data, {
        float pitch;
        float roll;
        float yaw;
        uint8_t is_pressing;
        uint8_t mode;
        uint8_t mode_config[8];
    });

    message_data(chassis_control_data, {
        int16_t forward_speed;
        int16_t panning_speed;
        int16_t rotate_speed;
    });

    message_data(referee_data, {
        uint8_t referee_send_data[32];
    });

    message_data(imu_data, {
        float x_gyro;
        float y_gyro;
        float z_gyro;
        float x_accel;
        float y_accel;
        float z_accel;
        float X;
        float Y;
        float Z;
        float W;
    });

    message_data(tyre_speed_data, {
        float x_pos;
        float y_pos;
        float robot_yaw_angle;
        float forward_speed;
        float panning_speed;
        float rotate_speed;
    });

MESSAGE_END

#undef MESSAGE_START
#undef MESSAGE_END

#endif //HID_COMMUNICATION_ROBOT_MESSAGE_H

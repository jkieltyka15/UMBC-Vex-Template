/**
 * \file umbc/vcontroller.hpp
 *
 * Contains the prototype for the ControllerInput. ControllerInput
 * stores controller values with a minimal memory footprint.
 */

#ifndef _UMBC_CONTROLLER_INPUT_HPP_
#define _UMBC_CONTROLLER_INPUT_HPP_

#include "pros/misc.hpp"

#include <cstdint>

using namespace pros;

namespace umbc {
class ControllerInput {

    private:
    std::uint8_t digital_l1 : 1;
    std::uint8_t digital_l2 : 1;
    std::uint8_t digital_r1 : 1;
    std::uint8_t digital_r2 : 1;
    std::uint8_t digital_up : 1;
    std::uint8_t digital_down : 1;
    std::uint8_t digital_left : 1;
    std::uint8_t digital_right : 1;
    std::uint8_t digital_x : 1;
    std::uint8_t digital_b : 1;
    std::uint8_t digital_y : 1;
    std::uint8_t digital_a : 1;

    std::int8_t analog_left_x;
    std::int8_t analog_left_y;
    std::int8_t analog_right_x;
    std::int8_t analog_right_y;

    public:
    /**
	 * Creates a controller input object and initializes all inputs to zero.
	 */
    ControllerInput();

    /**
	 * Gets the value of an analog input (joystick).
	 *
	 * \param channel
	 * 			  The analog input value to get.
	 * 			  Must be one of ANALOG_LEFT_X, ANALOG_LEFT_Y, ANALOG_RIGHT_X,
	 *        ANALOG_RIGHT_Y
	 *
	 * \return The value of the analog input: [-127, 127]
	 */
    std::int32_t get_analog(controller_analog_e_t channel);

    /**
	 * Gets the value of a digital input (button).
	 *
	 * \param button
	 * 			  The digital input value to get. Must be one of
	 *        DIGITAL_{RIGHT,DOWN,LEFT,UP,A,B,Y,X,R1,R2,L1,L2}
	 *
	 * \return The value of the digital input: 1 or 0
	 */
    std::int32_t get_digital(controller_digital_e_t button);

};
}

#endif // _UMBC_CONTROLLER_INPUT_HPP_
from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad


if __name__ == '__main__':

    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerStandard()

    # Basic gear state is Park state
    gear_state = {
        'P': 1,
        'D': 0,
        'R': 0,
        'N': 0
    }

    # Basic indicator state
    indicator_state = {
        'l': 0,
        'r': 0
    }

    while True:
        # Read data from gamepad
        gamepad_input = shanwan_gamepad.read_data()
        x, y, a, b, l, r = gamepad_input.button_x, gamepad_input.button_y, gamepad_input.button_a, gamepad_input.button_b, gamepad_input.button_l1, gamepad_input.button_r1

        # Select gear from the gamepad button
        if x:
            gear_state = {'P': 1, 'D': 0, 'R': 0, 'N': 0}
        elif y:
            gear_state = {'P': 0, 'D': 1, 'R': 0, 'N': 0}
        elif a:
            gear_state = {'P': 0, 'D': 0, 'R': 1, 'N': 0}
        elif b:
            gear_state = {'P': 0, 'D': 0, 'R': 0, 'N': 1}

        # Select indicator from the L1, R1 Button
        # 1. If L1, R1 button is pressed, indicator turn on
        # 2. If indicator is already 1 and pressed same button again, indicator turn off
        # 3. If left indicator is 1 and pressed right indicator, turn off the left and turn on the right(The same applies in the opposite case)
        if l:
            if indicator_state['l'] == 1:
                indicator_state['l'] = 0
            else:
                indicator_state['l'] = 1
                indicator_state['r'] = 0

        if r:
            if indicator_state['r'] == 1:
                indicator_state['r'] = 0
            else:
                indicator_state['r'] = 1
                indicator_state['l'] = 0


        print(gear_state, indicator_state)

        # Make throttle and steering value
        throttle = gamepad_input.analog_stick_right.y * 0.5
        steering = -gamepad_input.analog_stick_left.x

        # 1. Reverse movement is disabled even if the joystick is pulled backward
        # 2. If the gear state is P or N, the joystick isn't work
        if throttle < 0 or gear_state['P'] == 1 or gear_state['N'] == 1:
            throttle = 0

        # If the gear state is R, the car go back even when the joystick is pushed forward
        if gear_state['R'] == 1 and throttle > 0:
            throttle = -throttle

        print(f'throttle={throttle}, steering={steering}')


        piracer.set_throttle_percent(throttle)
        piracer.set_steering_percent(steering)


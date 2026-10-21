#include <superkarel.h>

void turn_right();
void sstep();
void step_back();
void mark_rooms();
void check_rooms_go_left();

int main() {
    turn_on("task7_2.kw");

    set_step_delay(100);
    mark_rooms();
    loop (2) {
        turn_left();
    }
    check_rooms_go_left();


    turn_off();
    return 0;
}

void check_rooms_go_left() {
    while (true) {
        if (right_is_clear()) {
            turn_right();
            sstep();
            if (beepers_present() && left_is_blocked()  && right_is_blocked()) {
                pick_beeper();
                step();
                while (no_beepers_present()) {
                    while (right_is_blocked() && front_is_clear()) {
                        step();
                        if (beepers_present() && left_is_blocked() && right_is_blocked()) {
                            pick_beeper();
                        }
                    }
                    if (right_is_clear()) {
                        turn_right();
                        sstep();
                        if (beepers_present() && left_is_blocked() && right_is_blocked()) {
                            pick_beeper();
                        }
                    }
                    else if (left_is_clear()) {
                        turn_left();
                        sstep();
                        if (beepers_present() && left_is_blocked() && right_is_blocked()) {
                            pick_beeper();
                        }
                    }
                    else if (left_is_blocked() && right_is_blocked() && front_is_blocked()) {
                        loop (2) {
                            turn_left();
                        }
                        sstep();
                        if (beepers_present() && left_is_blocked() && right_is_blocked()) {
                            pick_beeper();
                        }
                    }
                }
                if (beepers_present() && left_is_blocked() && right_is_blocked()) {
                    pick_beeper();
                    step();
                    turn_right();
                    step();
                }
            }
            else {
                step_back();
                turn_left();
                step();
            }
        }
        else {
            step();
        }
    }
}

void mark_rooms() {
    while (front_is_clear()) {
        if (left_is_clear()) {
            turn_left();
            step();
            loop (2) {
                put_beeper();
            }
            step_back();
            turn_left();
            if (front_is_clear()) {
                step();
            }
        }
        else {
            if (front_is_clear()) {
                step();
            }
        }
    }
    if (left_is_clear()) {
        turn_left();
        step();
        loop (2) {
            put_beeper();
        }
        step_back();
        turn_left();
        if (front_is_clear()) {
            step();
        }
    }
    loop (3) {
        put_beeper();
    }
}

void sstep() {
    if (front_is_clear()) {
        step();
    }
}

void turn_right() {
    loop (3) {
        turn_left();
    }
}

void step_back() {
    loop (2) {
        turn_left();
    }
    step();
}
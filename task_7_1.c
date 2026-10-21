#include <superkarel.h>

void turn_right();
void step_back();
void mark_enter();
void room_check_main();
void room_check_sup();

int main() {
        turn_on("task7_2.kw");
        
        set_step_delay(100);
        mark_enter();
        loop (3) {
            put_beeper();
        }
        room_check_main();
        room_check_sup();

        turn_off();
        return 0;
}

void room_check_sup() {
    loop (3) {
        put_beeper();
    }
    loop (2) {
        turn_left();
    }
    while (true) {
        if (right_is_clear()) {
            turn_right();
            step();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    step();
                    while (right_is_blocked()) {
                        if (front_is_clear()) {
                            step();
                        }
                        else {
                            turn_left();
                        }
                    }
                }
                else {
                    put_beeper();
                    step_back();
                    turn_right();
                    if (front_is_clear()) {
                        step();
                    }
                    else {
                        loop (2) {
                            turn_left();
                        }
                        while (no_beepers_present() && front_is_clear()) {
                            step();
                        }
                        if (beepers_present()) {
                            pick_beeper();
                            if (beepers_present() && facing_east()) {
                                while (beepers_present()) {
                                    pick_beeper();
                                }
                                return;
                            }
                        }
                    }
                }
            }
            else {
                step_back();
                turn_right();
                if (front_is_clear()) {
                    step();
                }
                else {
                    loop (2) {
                        turn_left();
                    }
                    while (no_beepers_present() && front_is_clear()) {
                        step();
                    }
                    if (beepers_present()) {
                            pick_beeper();
                            if (beepers_present() && facing_east()) {
                                while (beepers_present()) {
                                    pick_beeper();
                                }
                                return;
                            }
                        }
                }
            }
        }
        if (front_is_clear()) {
            step();
        }
    }
    if (right_is_clear()) {
            turn_right();
            step();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    step();
                    while (right_is_blocked()) {
                        if (front_is_clear()) {
                            step();
                        }
                        else {
                            turn_left();
                        }
                    }
                }
                else {
                    put_beeper();
                    step_back();
                    turn_right();
                    if (front_is_clear()) {
                        step();
                    }
                    else {
                        loop (2) {
                            turn_left();
                        }
                        while (no_beepers_present() && front_is_clear()) {
                            step();
                        }
                        if (beepers_present()) {
                            pick_beeper();
                            if (beepers_present() && facing_east()) {
                                while (beepers_present()) {
                                    pick_beeper();
                                }
                                return;
                            }
                        }
                    }
                }
            }
            else {
                step_back();
                turn_right();
                if (front_is_clear()) {
                    step();
                }
                else {
                    loop (2) {
                        turn_left();
                    }
                    while (no_beepers_present() && front_is_clear()) {
                        step();
                    }
                    if (beepers_present()) {
                        pick_beeper();
                        if (beepers_present() && facing_east()) {
                            while (beepers_present()) {
                                pick_beeper();
                            }
                            return;
                        }
                    }
                }
            }
        }
    
}

void room_check_main() {
    while (true) {
        while (right_is_blocked()) {
            if (front_is_clear()) {
                step();
                if (left_is_blocked() && right_is_blocked() && beepers_present()) {
                    pick_beeper();
                }
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        pick_beeper();
                        return;
                    }
                    else {
                        put_beeper();
                    }
                }
            }
            else {
                turn_left();
            }
        }
        turn_right();
        step();
        if (left_is_blocked() && right_is_blocked() && beepers_present()) {
            pick_beeper();
        }
        if (front_is_blocked() && beepers_present() && right_is_blocked()) {
            loop (3) {
                pick_beeper();
            }
            return;
        }
    }
}

void mark_enter() {
    while (front_is_clear()) {
        if (left_is_clear()) {
            turn_left();
            step();
            loop (2) {
                put_beeper();
            }
            step_back();
            turn_left();
        }
        step();
    }
    if (left_is_clear()) {
        turn_left();
        step();
        loop (2) {
            put_beeper();
        }
        step_back();
        turn_left();
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

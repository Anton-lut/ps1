#include <superkarel.h>

void turn_right();
void sstep();
void step_back();
void mark_rooms();
void check_rooms();
void final_check();
void one_room_check();

int main() {
    turn_on("task_7.kw");

    set_step_delay(200);
    mark_rooms();
    loop (2) {
        turn_left();
    }
    check_rooms();
    final_check();

    turn_off();
    return 0;
}

void one_room_check() {
    pick_beeper();
    step();
    while (no_beepers_present()) {
        while (front_is_clear() && right_is_blocked() && no_beepers_present()) {
            step();
        }
        if (right_is_clear()) {
            turn_right();
            step();
        }
        else if (front_is_blocked()) {
            turn_left();
            sstep();
        }
    }
    pick_beeper();
    step();
    turn_right();
}

void final_check() {
    loop (3) {
        put_beeper();
    }
    loop (2) {
        turn_left();
    }
    while (front_is_clear() && left_is_blocked()) {
        step();
        if (right_is_clear()) {
            turn_right();
            step();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    put_beeper();
                    one_room_check();
                }
                else {
                    put_beeper();
                    step_back();
                    turn_right();
                    sstep();
                }
            }
            else {
                step_back();
                turn_right();
                sstep();
            }
        }
    }
    if (front_is_blocked) {
        loop (2) {
            turn_left();
        }
        while (no_beepers_present()) {
            step();
        }
        while (beepers_present()) {
            pick_beeper();
        }
        return;
        }
    }



void check_rooms() {
    while (true) {
        while (front_is_clear() && right_is_blocked()) {
            step();
            if (right_is_blocked() && left_is_blocked() && beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        return;
                    }
                    else {
                        put_beeper();
                    }
                }
                step();
                if (beepers_present() && front_is_blocked() && right_is_blocked()) {
                    pick_beeper();
                    if (beepers_present()) {
                        pick_beeper();
                        if (beepers_present()) {
                            return;
                        }
                        else {
                            put_beeper();
                        }
                    }
                }
            }
            if (beepers_present() && front_is_blocked() && right_is_blocked()) {
               pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        return;
                    }
                    else {
                        put_beeper();
                    }
                }
            }
        }
        if (right_is_clear()) {
            turn_right();
            step();
            if (right_is_blocked() && left_is_blocked() && beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        return;
                    }
                    else {
                        put_beeper();
                    }
                }
            }
        }
        else if (front_is_blocked()) {
            turn_left();
            sstep();
            if (right_is_blocked() && left_is_blocked() && beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        return;
                    }
                    else {
                        put_beeper();
                    }
                }
            }
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

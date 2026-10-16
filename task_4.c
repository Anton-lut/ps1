#include <superkarel.h>

void turn_right();
void recover();
void next_line();
void go_back();
void check_line();
void face_to_north();

int main() {
        turn_on("task_4.kw");

        set_step_delay(100);
        while (true) {
            check_line();
            next_line();
            if (front_is_blocked() && right_is_blocked() && facing_east()) {
                check_line();
                next_line();
                break;
            }
        }

        turn_off();
        return 0;
}

void face_to_north() {
    while (!facing_north()) {
        turn_left();
    }
}

void check_line() {
    face_to_north();
    while (front_is_clear()) {
        if (beepers_present()) {
            break;
        }
        step();
    }
    if (beepers_present()) {
        recover();
    }
    else {
        go_back();
    }
}

void turn_right() {
    loop (3) {
        turn_left();
    }
}

void go_back() {
        loop (2) {
            turn_left();
        }
        while (front_is_clear()) {
            step();
        }
}

void recover() {
        face_to_north();
        while (front_is_clear()) {
            step();
        }
        loop (2) {
            turn_left();
        }
        while (front_is_clear()) {
                if (no_beepers_present()) {
                    put_beeper();
                }
                step();
                if (no_beepers_present()) {
                    put_beeper();
                }
        }
}

void next_line() {
    turn_left();
    if (front_is_clear()) {
        step();
    }
}    

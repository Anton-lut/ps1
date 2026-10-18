#include <superkarel.h>

void search_x_centre();
void search_y_centre();
void face_to_north();
void face_to_south();
void face_to_east();
void face_to_west();
void sstep();
void clear_x_line();
void clear_y_line();
void create_frame();
void go_end();

int main() {
        turn_on("task_5.kw");

        set_step_delay(10);
        search_x_centre();
        clear_x_line();
        search_y_centre();
        clear_y_line();
        create_frame();
        sstep();
        go_end();

        turn_off();
        return 0;
}

void go_end() {
    face_to_north();
    sstep();
    face_to_east();
    while (true) {
        if (beepers_present()) {
            pick_beeper();
        }
        if (beepers_present()) {
            break;
        }
        if (no_beepers_present()) {
            put_beeper();
            sstep();
        }
    }
    face_to_south();
    step();
    while (no_beepers_present()) {
        sstep();
    }
    loop (2) {
        pick_beeper();
    }
    face_to_north();
}

void create_frame() {
    while (front_is_clear()) {
        step();
    }
    put_beeper();
    put_beeper();
    face_to_west();
    step();
    while (true) {
        if (front_is_clear()) {
            if (no_beepers_present()) {
                put_beeper();
            }
            sstep();
        }
        if (beepers_present()) {
            break;
        }
        if (front_is_blocked() && right_is_blocked()) {
            turn_left();
        }
    }
}
void clear_y_line() {
    face_to_south();
    while (front_is_clear()) {
            step();
    }
    face_to_north();
    if (beepers_present()) {
        pick_beeper();
    }
    while (front_is_clear()) {
        step();
        if (beepers_present()) {
            pick_beeper();
        }
    }
    face_to_south();
    while (no_beepers_present()) {
        step();
    }
    put_beeper();
    face_to_north();
}


void clear_x_line() {
    face_to_south();
    if (front_is_blocked() && left_is_blocked()) {
        face_to_west();
    }
    else {
        face_to_east();
        while (front_is_clear()) {
            step();
        }
        face_to_south();
        if (front_is_blocked() && left_is_blocked()) {
            face_to_west();
        }
    }
    if (beepers_present()) {
        pick_beeper();
    }
    while (front_is_clear()) {
        step();
        if (beepers_present()) {
            pick_beeper();
        }
    }
    face_to_east();
    while (no_beepers_present()) {
        step();
    }
    face_to_north();
}


void search_y_centre() {
    while (true) {
        step();
        while (front_is_clear() && no_beepers_present()) {
            step();
        }
        face_to_south();
        if (no_beepers_present()) {
            put_beeper();
        }
        else {
            step();
            put_beeper();
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
                return;
            }
            else {
                 put_beeper();
            }
        }
        step();
        while (front_is_clear() && no_beepers_present()) {
            step();
        }
        face_to_north();
        if (no_beepers_present()) {
            put_beeper();
        }
        else {
            step();
            put_beeper();
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
                return;
            }
            else {
                put_beeper();
            }
        }
    }
}


void search_x_centre() {
    face_to_south();
    if (front_is_blocked() && left_is_blocked()) {
        face_to_west();
    }
    else {
        face_to_east();
        while (front_is_clear()) {
            step();
        }
        face_to_south();
        if (front_is_blocked() && left_is_blocked()) {
            face_to_west();
        }
        else {
            while (front_is_clear()) {
                step();
            }
        }
        if (front_is_blocked() && left_is_blocked()) {
            face_to_west();
        }
    }
    put_beeper();
    while (true) {
        step();
        while (front_is_clear() && no_beepers_present()) {
            step();
        }
        face_to_east();
        if (no_beepers_present()) {
            put_beeper();
        }
        else {
            step();
            put_beeper();
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
                return;
            }
            else {
                 put_beeper();
            }
        }
        step();
        while (front_is_clear() && no_beepers_present()) {
            step();
        }
        face_to_west();
        if (no_beepers_present()) {
            put_beeper();
        }
        else {
            step();
            put_beeper();
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
                return;
            }
            else {
                put_beeper();
            }
        }
    }
}

void face_to_north() {
    while (!facing_north()) {
        turn_left();
    }
}

void face_to_south() {
    while (!facing_south()) {
        turn_left();
    }
}

void face_to_east() {
    while (!facing_east()) {
        turn_left();
    }
}

void face_to_west() {
    while (!facing_west()) {
        turn_left();
    }
}

void sstep() {
    if (front_is_clear()) {
        step();
    }
}

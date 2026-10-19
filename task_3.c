#include <superkarel.h>

void spick_beeper();
void sstep();
void turn_right();
void face_to_north();
void face_to_south();
void face_to_east();
void face_to_west();
void search_beeper1();
void search_beeper2();
void search_max_line();
void place_to_max();
void finish();
void collect();
void sort();

int main() {
        turn_on("task_3.kw");

        set_step_delay(100);
        face_to_east();
        collect();
        face_to_south();
        while (front_is_clear()) {
            step();
        }
        face_to_west();
        search_beeper1();
        search_max_line();
        search_beeper1();
        place_to_max();
        while (beepers_in_bag()) {
            face_to_west();
            sstep();
            search_beeper2();
            place_to_max();
        }
        while (true) {
            sort();
            pick_beeper();
            if (no_beepers_present()) {
                put_beeper();
                break;
            }
            put_beeper();
        }
        face_to_west();
        while (front_is_clear()) {
            step();
        }
        face_to_east();

        turn_off();
        return 0;
}

void spick_beeper() {
    pick_beeper();
    if (beepers_present()) {
        put_beeper();
    }
}

void sort() {
    face_to_south();
    while (beepers_present()) {
        sstep();
    }
    face_to_north();
    sstep();
    while(true) {
        pick_beeper();
        if (no_beepers_present()) {
            put_beeper();
            step();
        }
        else {
            while (front_is_clear()) {
                step();
                pick_beeper();
            }
            break;
        }
    }
    face_to_west();
    step();
    while (front_is_clear()) {
        step();
        if (right_is_blocked() && no_beepers_present()) {
            break;
        }
    }
    face_to_south();
    while (beepers_in_bag()) {
        put_beeper();
        step();
    }
    face_to_north();
    while (front_is_clear()) {
        step();
    }
    face_to_east();
    while (front_is_clear()) {
        step();
    }
}

void search_beeper2() {
        face_to_west();
        step();
        while (true) {
            if (beepers_present()) {
                spick_beeper();
                if (beepers_present()) {
                    face_to_south();
                    sstep();
                }
                if (no_beepers_present()) {
                      put_beeper();
                      return;
                }
            }
            if (front_is_blocked()) {
                face_to_south();
                sstep();
                if (right_is_blocked()) {
                    face_to_east();
                }
                if (left_is_blocked()) {
                    face_to_west();
                    step();
                }
            }
            sstep();
        }
}

void place_to_max() {
    pick_beeper();
    face_to_east();
    while (no_beepers_present()) {
        sstep();
    }
    pick_beeper();
    if (no_beepers_present()) {
        put_beeper();
        sstep();
        while (no_beepers_present()) {
            sstep();
        }
            pick_beeper();
            if (no_beepers_present()) {
                put_beeper();
                sstep();
                while (no_beepers_present()) {
                    sstep();
                }
            }
            else {
                put_beeper();
            }
    }
    else {
        put_beeper();
    }
    face_to_north();
    while (front_is_clear()) {
        put_beeper();
        step();
    }
    put_beeper();
}

void search_max_line() {
    face_to_east();
    put_beeper();
    step();
    while (front_is_clear()) {
        if (no_beepers_present()) {
            put_beeper();
            step();
        }
    }
    loop (3) {
        put_beeper();
    }
    face_to_north();
    while (front_is_clear()) {
        step();
        if (beepers_present()) {
            break;
        } 
    }
    put_beeper();
    while (front_is_clear()) {
        step();
        loop (2) {
                put_beeper();
        }
    }
    face_to_south();
    while (true) {
        step();
        if (no_beepers_present()) {
            put_beeper();
        }
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    break;
                }
                else {
                    put_beeper();
                    put_beeper();
                }
            }
            else {
                put_beeper();
            }
        }
    }
    face_to_west();
    while (true) {
        step();
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                pick_beeper();
                break;
            }
        }
    }
}

void collect() {
    step();
    while (true) {
        if (no_beepers_present() && front_is_blocked() && left_is_blocked()) {
            return;
        }
        if (beepers_present()) {
            pick_beeper();
            face_to_south();
            if (front_is_clear()) {
                step();
            }
            else {
                face_to_north();
                step();
                face_to_south();
            }
        }
        if (no_beepers_present() && facing_east()) {
            step();
            if (no_beepers_present() && front_is_blocked() && left_is_blocked()) {
                return;
            }
        }
        if (no_beepers_present() && facing_south()) {
            face_to_north();
            step();
            put_beeper();
            if (front_is_clear() && right_is_blocked()) {
                return;
            }
            else {
                while (front_is_clear()) {
                        step();
                }
                face_to_east();
                step();
            }
            face_to_east();
        }
    }
}

void search_beeper1() {
    while (true) {
        while (front_is_clear()) {
            if (beepers_present()) {
                return;
            }
            sstep();
            if (beepers_present()) {
                return;
            }
        }
        face_to_north();
        step();
        if (beepers_present()) {
            return;
        }
        if (left_is_blocked()) {
            face_to_east();
        }
        if (right_is_blocked()) {
            face_to_west();
        }
    }
}

void turn_right() {
    set_step_delay(0);
    loop (3) {
        turn_left();
    }
    set_step_delay(100);
}

void face_to_north( ) {
    set_step_delay(0);
    while (!facing_north()) {
        turn_left();
    }
    set_step_delay(100);
}

void face_to_south() {
    set_step_delay(0);
    while (!facing_south()) {
        turn_left();
    }
    set_step_delay(100);
}

void face_to_east() {
    set_step_delay(0);
    while (!facing_east()) {
        turn_left();
    }
    set_step_delay(100);
}

void face_to_west() {
    set_step_delay(0);
    while (!facing_west()) {
        turn_left();
    }
    set_step_delay(100);
}

void sstep() {
    if (front_is_clear()) {
        step();
    }
}

#include <superkarel.h>

void check_max_line();
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
void put_in_one();

int main() {
        turn_on("task_3.kw");

        set_step_delay(10);
        face_to_east();
        collect();
        face_to_south();
        while (front_is_clear()) {
            if (front_is_clear()) {
                step();
            }
            else {
                break;
            }
        }
        face_to_west();
        search_beeper1();
        face_to_north();
        while (front_is_clear()) {
            step();
        }
        face_to_east();
        while (front_is_clear()) {
            step();
        }
        face_to_west();
        while (right_is_clear()) {
            step();
        }
        loop (2) {
            put_beeper();
        }
        face_to_south();
        while (front_is_clear()) {
            step();
        }
        face_to_west();
        search_beeper1();
        search_max_line();
        search_beeper2();
        place_to_max();
        put_in_one();
        sort();
        face_to_west();
        while (front_is_clear()) {
            step();
        }
        face_to_east();

        turn_off();
        return 0;
}

void put_in_one() {
    while (true) {
        search_beeper2();
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
                break;
            }
            else {
                put_beeper();
                place_to_max();
            }
        }
    }
}

void spick_beeper() {
    pick_beeper();
    if (beepers_present()) {
        put_beeper();
    }
}

void sort() {
    while (true) {
        face_to_south();
        while (front_is_clear()) {
            step();
        }
        face_to_north();
        while (front_is_clear()) {
            if (beepers_present()) {
                pick_beeper();
                if (no_beepers_present()) {
                    put_beeper();
                }
            }
            step();
        }
        if (beepers_present()) {
            pick_beeper();
            if (no_beepers_present()) {
                put_beeper();
            }
            face_to_west();
            step();
            while (beepers_present() && front_is_clear()) {
                step();
                if (right_is_clear()) {
                    step();
                }
            }
            while (right_is_clear()) {
                step();
                while (beepers_present()) {
                    step();
                }
            }
            face_to_south();
            while (beepers_in_bag()) {
                put_beeper();
                sstep();
            }
            face_to_north();
            while (front_is_clear()) {
                step();
            }
            face_to_east();
            while (front_is_clear()) {
                step();
            }
            face_to_west();
            while (right_is_clear()) {
                step();
            }
            pick_beeper();
            if (beepers_present()) {
                put_beeper();
            }
            else {
                put_beeper();
                break;
            }
        }
    }
}

void search_beeper2() {
        face_to_south();
        while (front_is_clear()) {
            step();
        }
        face_to_east();
        while (front_is_clear()) {
            step();
        }
        face_to_west();
        while (no_beepers_present()) {
            step();
        }
        while (true) {
            step();
            while (front_is_clear() && no_beepers_present()) {
                step();
            }
            if (beepers_present()) {
                return;
            }
            else {
                face_to_east();
                while (no_beepers_present()) {
                    step();
                }
                face_to_north();
                if (front_is_clear()) {
                        step();
                        face_to_west();
                }
                else {
                    return;
                }
            }
        }
}

void place_to_max() {
    pick_beeper();
    face_to_east();
    while (no_beepers_present()) {
        step();
    }
    face_to_north();
    while (front_is_clear()) {
        put_beeper();
        step();
    }
    put_beeper();
}

void check_max_line() {
    loop (3) {
        put_beeper();
    }
    face_to_north();
    step();
    while (front_is_clear()) {
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                break;
            }
            else {
                put_beeper();
                while (front_is_clear()) {
                    put_beeper();
                    step();
                }
                put_beeper();
            }
        }
        sstep();
    }
    if (front_is_blocked() && no_beepers_present()) {
        face_to_south();
        step();
        while (no_beepers_present()) {
            sstep();
        }
        while (beepers_present()) {
            pick_beeper();
        }
        face_to_west();
        step();
        check_max_line();
    }
}

void search_max_line() {
    face_to_east();
    put_beeper();
    step();
    while (front_is_clear()) {
        if (no_beepers_present()) {
            step();
        }
    }
    check_max_line();
    pick_beeper();
    face_to_south();
    while (true) {
        sstep();
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
                put_beeper();
            }
        }
        else {
            put_beeper();
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
                put_beeper();
                while (front_is_clear()) {
                    step();
                }
                face_to_east();
            }
        }
        if (no_beepers_present() && facing_east()) {
            if (front_is_clear()) {
                step();
            }
            if (front_is_blocked()) {
                break;
            }
            if (no_beepers_present() && front_is_blocked() && left_is_blocked()) {
                return;
            }
        }
        if (no_beepers_present() && facing_south()) {
            face_to_north();
            sstep();
            put_beeper();
            if (front_is_clear() && right_is_blocked()) {
                return;
            }
            else {
                while (front_is_clear()) {
                        step();
                }
                face_to_east();
                sstep();
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
    loop (3) {
        turn_left();
    }
}

void face_to_north( ) {
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

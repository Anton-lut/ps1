#include <superkarel.h> 

void collect_beepers();
void face_to_north();
void face_to_south();
void face_to_east();
void face_to_west();

int main() {
        turn_on("task_6.kw");
        
        set_step_delay(100);
        collect_beepers();

        turn_off();
        return 0;
}

void collect_beepers() {
    while (true) {
        step();
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    if (beepers_present()) {
                        pick_beeper();
                        if (beepers_present()) {
                            pick_beeper();
                            break;
                        }
                        else {
                            face_to_east();
                        }
                    }
                    else {
                        face_to_south();
                    }
                }
                else {
                    face_to_west();
                }
            }
            else {
                face_to_north();
            }
        }
    }
}

void face_to_north() {
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

void face_to_east(){
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
